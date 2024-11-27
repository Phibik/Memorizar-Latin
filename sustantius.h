#pragma once

#include "llibreries.h"
#include "paraules.h"

class Sustantiu: public Paraula
{
public:
    Sustantiu() { casos.resize(14); }
    Sustantiu(const string& p, const vector<string>& t, const string& c, const vector<string>& g, const vector<string>& d);
    Sustantiu(const Sustantiu& S);
    Sustantiu& operator=(const Sustantiu& S);
    ~Sustantiu() {}

    vector<string> getGenere() const { return genere; }
    vector<string> getDeclinacio() const { return declinacio; }
    vector<vector<string>> getCasos() const { return casos; }
    vector<string> getCas(const int& n) const { return casos[n]; }

    void mostrar() const override;

    void agregarCas(const int& cas, const string& forma) { casos[cas].push_back(forma); }

private:
    vector<string> genere;	        // m, f, n
    vector<string> declinacio;	    // tipus de declinació
    vector<vector<string>> casos;   // { {N1, N2...}, {G1, G2...}... }

    void mostrarCas(const int& cas) const;
};

Sustantiu::Sustantiu(const string& p, const vector<string>& t, const string& c, const vector<string>& g, const vector<string>& d)
{
    Paraula::operator=(Paraula(p, t, c));
    genere = g;
    declinacio = d;
    casos.resize(14);
}

Sustantiu::Sustantiu(const Sustantiu& S)
{
    Paraula::operator=(Paraula(S.paraula, S.traduccio, S.comentari));
    genere = S.genere;
    declinacio = S.declinacio;
    casos = S.casos;
}

Sustantiu& Sustantiu::operator=(const Sustantiu& S)
{
    if (this != &S)
    {
        Paraula::operator=(S);
        genere = S.genere;
        declinacio = S.declinacio;
        casos = S.casos;
    }
    return *this;
}




