/*#include "menus.cpp"

int main()
{
    system("chcp 65001 > nul");	// per imprimer utf8
    srand(time(0)*156);         // seed rand()



    // totes les paraules
    const int nMapas { 2 };
    MapaParaula paraules[nMapas] =
    {
        llegirParaules("s_comunes.txt"), 
        llegirParaules("s_comida.txt")
    };



    int entrada;
    int opcio;
    do
    {
        mostrarMenu();
        cin >> entrada;
        
        if (entrada <= nMapas && entrada > 0)
        {
            --entrada;
            mostrarOpcions();
            cin >> opcio;

            switch (opcio)
            {
            case 1: menuTraduccions(paraules[entrada]); break;
            case 2: menuEndevinacions(paraules[entrada]); break;
            case 3: traduirEndevinar(paraules[entrada]); break;
            case 4: diccionari(paraules[entrada]); break;
            default: continue;
            }
        }
        else
            break;
    }
    while (true);
    



    return 0;
}

*/

// probes (funcionen)
#include "paraules.cpp"
#include "sustantius.cpp"

string llegirFragment(string& linea, const string& caracter)
{
    size_t pos = linea.find(caracter);
    string fragment; 

    // recollir fragment
    if (pos == string::npos)
    {
        fragment = linea;
        linea = "";
    }
    else
    {
        fragment = linea.substr(0, pos);
        linea.erase(0, pos + 1);
    }
        
    // eliminar el primer espai
    if (!fragment.empty() && fragment.at(0) == ' ')
        fragment.erase(0, 1);

    return fragment;
}

ptr<Paraula> llegirSustantiu(const string& paraula, const vector<string>& traduccio, const string& comentari, string& linea)
{
    string genereString = llegirFragment(linea, ";");
    string declinacioString = llegirFragment(linea, ";");

    // vectoritzar generes i declinacions
    vector<string> genere, declinacio;
    int aux { 0 };
    while (genereString != "" && aux++ < 10)
        genere.push_back(llegirFragment(genereString, ","));
    while (declinacioString != "" && aux++ < 10)
        declinacio.push_back(llegirFragment(declinacioString, ","));
    
    // creació Sustantiu
    Sustantiu sustantiu(paraula, traduccio, comentari, genere, declinacio);

    // processar casos
    for (int i = NS; i <= LP; ++i)
    {
        string cas = llegirFragment(linea, ";");

        int aux { 0 };
        while (cas != "" && aux++ < 10)
            sustantiu.agregarCas(i, llegirFragment(cas, ","));
    }

    return make_shared<Sustantiu>(sustantiu);
}

ptr<Paraula> llegirAdjectiu(const string& paraula, const vector<string>& traduccio, const string& comentari, string& linea)
{
    return nullptr;
}

ptr<Paraula> llegirVerb(const string& paraula, const vector<string>& traduccio, const string& comentari, string& linea)
{
    return nullptr;
}

MapaParaula llegirParaules(const string& nomArxiu)
{
    ifstream arxiu("./paraules/" + nomArxiu);
    MapaParaula paraules;

    if (!arxiu.is_open())
    {
	    cerr << "Error al obrir l'arxiu " << nomArxiu << endl;
	    return paraules;
    }

    string linea;
    while (getline(arxiu, linea))
    {
        // llegir primers fragments
        string paraula = llegirFragment(linea, ";");
        string traduccioString = llegirFragment(linea, ";");
        string comentari = llegirFragment(linea, ";");
        
        // vectoritzar traduccio
        vector<string> traduccio;
        while (traduccioString != "")
            traduccio.push_back(llegirFragment(traduccioString, ","));
        
        // lectura concreta
        ptr<Paraula> ptrParaula;

        if (nomArxiu[0] == 's')
            ptrParaula = llegirSustantiu(paraula, traduccio, comentari, linea);
        else if (nomArxiu[0] == 'a')
            ptrParaula = llegirAdjectiu(paraula, traduccio, comentari, linea);
        else if (nomArxiu[0] == 'v')
            ptrParaula = llegirVerb(paraula, traduccio, comentari, linea);
        
        // inserir ptrParaula i traduccions
        paraules.p[paraula] = ptrParaula;
        for (int i = 0; i < traduccio.size(); ++i)
            paraules.t[traduccio[i]].insert(paraula);
    }

    arxiu.close();
    return paraules;
}


void diccionari(const MapaParaula& paraules)
{
    string paraulesLlati = "\nParaules en llatí:\n";
    for (auto it = paraules.p.begin(); it != paraules.p.end(); ++it)
    {
        paraulesLlati += it->first;
        auto jt = it;
        if (jt != paraules.p.end() && ++jt != paraules.p.end())
            paraulesLlati += ", ";
    }
    paraulesLlati += "\n";

    string paraulesTraduides = "\nParaules Traduïdes:\n";
    for (auto it = paraules.t.begin(); it != paraules.t.end(); ++it)
    {
        paraulesTraduides += it->first;
        auto jt = it;
        if (jt != paraules.t.end() && ++jt != paraules.t.end())
            paraulesTraduides += ", ";
    }
    paraulesTraduides += "\n\n";

    cout << paraulesLlati << paraulesTraduides;
    cout << "Inspeccionar parala (\"0\" per sortir): ";
    string entrada;
    cin >> entrada;
    cout << "\n\n";
    while (entrada != "0")
    {
        if (paraules.p.find(entrada) != paraules.p.end())
        {
            paraules.p.at(entrada)->mostrar();
            cout << "\n";
        }
        else if (paraules.t.find(entrada) != paraules.t.end())
        {
            if (paraules.t.at(entrada).size() == 1)
                paraules.p.at(*(paraules.t.at(entrada).begin()))->mostrar();

            else
            {
                string novaEntrada = entrada;
                while (novaEntrada != "0")
                {
                    // mostrar totes les possibles paraules
                    cout << "Palabras con la traduccion \"" << novaEntrada << "\":\n";
                    for (auto it = paraules.t.at(entrada).begin(); it != paraules.t.at(entrada).end(); ++it)
                    {
                        if (it != paraules.t.at(entrada).begin())
                            cout << ", ";
                        cout << *it;
                    }
                    cout << "\n";

                    // rebre novaEntrada i comprobarla
                    cout << "\nEscribe la palabra que quieras ver (0 para salir): ";
                    cin >> novaEntrada;

                    if (paraules.p.find(novaEntrada) != paraules.p.end())
                    {
                        paraules.p.at(novaEntrada)->mostrar();
                        novaEntrada = "0";
                    }
                    else
                        cout << "\n\nNo se ha encontrado la palabra";

                    cout << "\n\n";
                }
            }
        }
        else
            cout << "\n\nNo s'ha trobat.\n";

        cout << paraulesLlati << paraulesTraduides;
        cout << "Inspeccionar parala (\"0\" per sortir): ";
        cin >> entrada;
        cout << "\n\n";
    }

    cout << "\n\n";
}



int main()
{
    system("chcp 65001 > nul");	// per imprimer utf8
    srand(time(0)*156);         // seed rand()

    const int nMapas { 2 };
    MapaParaula paraules[nMapas] =
    {
        llegirParaules("s_comunes.txt"), 
        llegirParaules("s_comida.txt")
    };

    //paraules[1].p["mālum"]->mostrar();
    //paraules[0].p["domus"]->mostrar();

    diccionari(paraules[0]);
}