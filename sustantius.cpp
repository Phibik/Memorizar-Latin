#include "sustantius.h"

void Sustantiu::mostrar() const
{
    Paraula::mostrar();
    cout << "Género:      " << genere[0];

    switch (genere.size())
    {
    case 2: cout << ", " << genere[1]; break;
    case 3: cout << ", " << genere[1] << ", " << genere[2]; break;
    }

    cout << '\n';
    cout << "Declinación: ";

    for (int i = 0; i < declinacio.size(); ++i)
    {
        if (declinacio[i] == "1")
            cout << "1ra ";
        else if (declinacio[i] == "2")
            cout << "2na ";
        else if (declinacio[i] == "3")
            cout << "3ra ";
        else if (declinacio[i] == "4")
            cout << "4ta ";
        else if (declinacio[i] == "5")
            cout << "5na ";
    }

    cout << '\n';
    cout << "Comentario: " << comentari << "\n\n";

    cout << "+=====================================================+\n";
    cout << "|    Cas    |      Singular      |       Plural       |\n";
    cout << "+===========+====================+====================+\n";

    mostrarCas(NS);
    mostrarCas(GS);
    mostrarCas(DS);
    mostrarCas(AS);     // es gestionen el plurals
    mostrarCas(ABS);
    mostrarCas(VS);
    mostrarCas(LS); 

    cout << "+===========+====================+====================+\n\n";
}

void Sustantiu::mostrarCas(const int& cas) const
{
    if (cas == LS && (!casos[LS].empty() || !casos[LP].empty()))
    {
        cout << "+-----------+--------------------+--------------------+\n";
        cout << "|  Locatiu  |";

	for (int i = 0; i < max(casos[LS].size(), casos[LP].size()); ++i)
        {
            if (i > 0)
                cout << "|           |";
            
            if (i >= casos[LS].size())
                cout << setw(20) << " ";
            else
            {
                int longitud = longitudVisual(casos[LS][i]);
                int distancia = (20 - longitud) / 2;
                for (int i = 0; i < distancia; ++i)
                    cout << " ";

                cout << casos[LS][i];

                for (int i = 0; i < distancia; ++i)
                    cout << " ";
                if ((20 - longitud) % 2 != 0) cout << " ";
            }

            cout << "|";

            if (i >= casos[LP].size())
                cout << setw(20) << " ";
            else
            {
                int longitud = longitudVisual(casos[LP][i]);
                int distancia = (20 - longitud) / 2;
                for (int i = 0; i < distancia; ++i)
                    cout << " ";

                cout << casos[LP][i];

                for (int i = 0; i < distancia; ++i)
                    cout << " ";
                if ((20 - longitud) % 2 != 0) cout << " ";
            }
            
            cout << "|\n";
        }
    }
    else if (cas != LS)
    {
        switch (cas)
        {
        case NS: cout << "| Nominatiu |"; break;
        case GS: cout << "|  Genitiu  |"; break;
        case DS: cout << "|   Datiu   |"; break;
        case AS: cout << "| Acusatiu  |"; break;
        case ABS: cout << "|  Ablatiu  |"; break;
        case VS: cout << "|  Vocatiu  |"; break;
        }

        for (int i = 0; i < max(casos[cas].size(), casos[cas + 6].size()); ++i)
        {
            if (i > 0)
                cout << "|           |";
            
            if (i >= casos[cas].size())
                cout << setw(20) << " ";
            else
            {
                int longitud = longitudVisual(casos[cas][i]);
                int distancia = (20 - longitud) / 2;
                for (int i = 0; i < distancia; ++i)
                    cout << " ";

                cout << casos[cas][i];

                for (int i = 0; i < distancia; ++i)
                    cout << " ";
                if ((20 - longitud) % 2 != 0) cout << " ";
            }
                

            cout << "|";

            if (i >= casos[cas + 6].size())
                cout << setw(20) << " ";
            else
            {
                int longitud = longitudVisual(casos[cas + 6][i]);
                int distancia = (20 - longitud) / 2;
                for (int i = 0; i < distancia; ++i)
                    cout << " ";

                cout << casos[cas + 6][i];

                for (int i = 0; i < distancia; ++i)
                    cout << " ";
                if ((20 - longitud) % 2 != 0) cout << " ";
            }
            
            cout << "|\n";
        }

        if (cas != VS)
            cout << "+-----------+--------------------+--------------------+\n";
    }
}






