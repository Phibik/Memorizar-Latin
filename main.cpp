#include "menus.cpp"

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
    //diccionari(paraules[0]);

    string entrada;
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
