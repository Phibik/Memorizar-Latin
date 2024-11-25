#include "paraules.cpp"

void traduir(string& entrada, string& resposta, const string& paraula, const string& traduccio, const Paraula& p)
{
    cout << "Paraula:   " << paraula << '\n';
    cout << "Traducció: ";
    cin >> entrada;
    cout << "\n";

    if (entrada != "0")
    {
        if (entrada == traduccio)
        {
            cout << "   ##############\n";
            cout << "   #  CORRECTE  #\n";
            cout << "   ##############\n\n";
        }
        else
        {
            cout << "  ################\n";
            cout << "  #  INCORRECTE  #\n";
            cout << "  ################\n\n";
            cout << "Paraula correcta: " << traduccio << "\n\n";
        }

        cout << "Inspeccionar paraula (s/n): ";
        cin >> resposta;
        cout << '\n';
        if (resposta == "s")
            p.mostrarParaula();
        
        cout << "Per sortir escriu \"0\"\n\n";
    }
}

void traduirLlati(const MapaParaula& paraules)
{
    cout << "\nPer sortir escriu \"0\"\n\n";
    string entrada;
    string resposta;
    do
    {
        auto it = paraules.p.begin();
        int r = rand() % paraules.p.size();
        advance(it, r);

        string p = it->second.getParaula();
        string t = it->second.getTraduccio();

        traduir(entrada, resposta, p, t, it->second);
        
    } while (resposta != "0" && entrada != "0");
}

void traduirAlLlati(const MapaParaula& paraules)
{
    cout << "\nPer sortir escriu \"0\"\n\n";
    string entrada;
    string resposta;
    do
    {
        auto it = paraules.p.begin();
        int r = rand() % paraules.p.size();
        advance(it, r);

        string p = it->second.getTraduccio();
        string t = it->second.getParaula();

        traduir(entrada, resposta, p, t, it->second);
        
    } while (resposta != "0" && entrada != "0");
}

void traduccions(const MapaParaula& paraules)
{
    cout << "\nPer sortir escriu \"0\"\n\n";
    string entrada;
    string resposta;
    do
    {
        auto it = paraules.p.begin(); 
        int r = rand() % paraules.p.size();
        advance(it, r);

        int mode = rand() % 2;
        string p, t;
        switch (mode)
        {
        case 0:
            p = it->second.getTraduccio();
            t = it->second.getParaula();
            cout << "+===> Traduir al llatí <===+\n";
            break;
        
        case 1:
            p = it->second.getParaula();
            t = it->second.getTraduccio();
            cout << "+===> Traduir del llatí <===+\n";
            break;
        }

        traduir(entrada, resposta, p, t, it->second);
        
    } while (resposta != "0" && entrada != "0");
}

void endevinarDeclinacio(const MapaParaula& paraules)
{
    // EL VOCATIU NO FA FALTA EXCEPTE SI ES DIFERENT AL NOMINATIU
    cout << "\nPer sortir escriu \"0\"\nCasos -> NS, GS, DS, AS, ABS, LS...";
}

void endevinarGenere(const MapaParaula& paraules)
{

}

void endevinacions(const MapaParaula& paraules)
{
    int mode = rand() % 2;
}

void traduirEndevinar(const MapaParaula& paraules)
{
    int mode = rand() % 2;
}


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
        string genere = llegirFragment(linea, ";");
        string declinacio = llegirFragment(linea, ";");
        string traduccio = llegirFragment(linea, ";");
        string comentari = llegirFragment(linea, ";");
        
        // vectoritzar generes i declinacions
        vector<string> declinacioVec, genereVec;
        int aux { 0 };
        while (genere != "" && aux++ < 10)
            genereVec.push_back(llegirFragment(genere, ","));
        aux = 0;
        while (declinacio != "" && aux++ < 10)
            declinacioVec.push_back(llegirFragment(declinacio, ","));

        // inicialitza paraula
        Paraula novaParaula(paraula, genereVec, declinacioVec, traduccio, comentari);

        // processar casos
        for (int i = NS; i <= LP; ++i)
        {
            string cas = llegirFragment(linea, ";");

            int aux { 0 }; // evitar bucle infinit per si de cas
            while (cas != "" && aux++ < 10)
                novaParaula.agregarCas(i, llegirFragment(cas, ","));
        }

        paraules.p[paraula] = novaParaula;
        paraules.t[traduccio] = paraula;
    }

    arxiu.close();
    return paraules;
}





