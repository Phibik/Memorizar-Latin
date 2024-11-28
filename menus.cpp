#include "funcions.cpp"

void mostrarMenu()
{
    cout << '\n';
    cout << "$$+=============############=============+$$\n";
    cout << "|>=============+#   MENU   #+=============<|\n";
    cout << "$$+=============############=============+$$\n";
    cout << '\n';
    cout << " Selecciona las familas de palabras con los numeros.\n";
    cout << " Por ejemplo \"1 2\" selecciona \"comunes\" y \"comdia\".\n";
    cout << '\n';
    cout << "   1. Palabras comunes\n";
    cout << "   2. Palabras sobre comida\n";
    cout << "   #. Salir (introducir cualquier numero)\n";
    cout << "\n\n";
}

void mostrarOpcions()
{
    cout << '\n';
    cout << "$$+==========###############=============+$$\n";
    cout << "|>==========+#  OPCIONES   #+=============<|\n";
    cout << "$$+==========###############=============+$$\n";
    cout << '\n';
    cout << "   1. Traduir\n";
    cout << "   2. Endevinar\n";
    cout << "   3. Traduir/Endevinar\n";
    cout << "   4. Diccionari\n";
    cout << "   #. Sortir (introduir qualsevol nombre)\n";
    cout << "\n\n";
}

void menuTraduccions(const MapaParaula& paraules)
{
    cout << '\n';
    cout << "|>=========--+#  TRADUCCIONS  #+--=============<|\n";
    cout << "$$+===========+###############+===============+$$\n";
    cout << '\n';
    cout << "   1. Traduir del llatí\n";
    cout << "   2. Traduir al llatí\n";
    cout << "   3. Traduir del/al llatí\n";
    cout << "\n\n";

    int opcio;
    cin >> opcio;
    switch (opcio)
    {
        case 1: traduirLlati(paraules); break;
        case 2: traduirAlLlati(paraules); break;
        case 3: traduccions(paraules); break;
    }
}

void menuEndevinacions(const MapaParaula& paraules)
{
    cout << '\n';
    cout << "|>=========--+#  ENDEVINACIONS  #+--=============<|\n";
    cout << "$$+===========+#################+===============+$$\n";
    cout << '\n';
    cout << "   1. Endevinar genere\n";
    cout << "   2. Endevinar declinació\n";
    cout << "   3. Endevinar genere/declinació\n";
    cout << "\n\n";

    int opcio;
    cin >> opcio;
    switch (opcio)
    {
        case 1: endevinarGenere(paraules); break;
        case 2: endevinarDeclinacio(paraules); break;
        case 3: endevinacions(paraules); break;
    }
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

