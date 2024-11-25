#include "funcions.cpp"

void mostrarMenu()
{
    cout << '\n';
    cout << "$$+=============############=============+$$\n";
    cout << "|>=============+#   MENU   #+=============<|\n";
    cout << "$$+=============############=============+$$\n";
    cout << '\n';
    cout << "   1. Paraules comuns\n";
    cout << "   2. Paraules sobre menjar\n";
    cout << "   #. Sortir (introduir qualsevol nombre)\n";
    cout << "\n\n";
}

void mostrarOpcions()
{
    cout << '\n';
    cout << "$$+==========###############=============+$$\n";
    cout << "|>==========+#   OPCIONS   #+=============<|\n";
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

void mostrarDiccionari(const MapaParaula& paraules)
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
            paraules.p.at(entrada).mostrarParaula();
            cout << "\n";
        }
        else if (paraules.t.find(entrada) != paraules.t.end())
        {
            paraules.p.at(paraules.t.at(entrada)).mostrarParaula();
            cout << "\n";
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

