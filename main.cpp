/*#include "menus.cpp"

int main()
{
    system("chcp 65001 > nul");	// per imprimer utf8
    srand(time(0)*156);         // seed rand()



    // totes les paraules
    const int nMapas { 2 };
    MapaParaula paraules[nMapas] =
    {
        llegirParaules("s_comuns.txt"), 
        llegirParaules("s_menjar.txt")
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
            case 4: mostrarDiccionari(paraules[entrada]); break;
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

int main()
{
    system("chcp 65001 > nul");	// per imprimer utf8
    Paraula p("scribere", {"escriure"}, "");
    p.mostrar();
    Sustantiu s("scribere", {"escriure"}, "", {"m"}, {"1"});
    s.agregarCas(0, "ns");
    s.agregarCas(1, "");
    s.mostrar();
}