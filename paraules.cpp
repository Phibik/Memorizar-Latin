#include "paraules.h"

void Paraula::mostrar() const
{
    cout << "Palabra:     " << paraula << '\n';
    cout << "Traducción:  ";

    for (int i = 0; i < traduccio.size(); ++i)
    {
        if (i != 0)
            cout << ", "  << traduccio[i];
        else
            cout << traduccio[i];
    }

    cout << '\n';
}

int Paraula::longitudVisual(const string& str) const
{
    int longitud = str.length();
    for (int i = 0; i < str.length() + 1; ++i)
    {
        string s;
        s += str[i];
        s += str[i + 1];
        if (s == "ā" || s == "ē" || s == "ī" || s == "ō" || s == "ū" || s == "ȳ" ||
            s == "Ā" || s == "Ē" || s == "Ī" || s == "Ō" || s == "Ū" || s == "Ȳ")
                --longitud;
    }
    
    return longitud;
}

