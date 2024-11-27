#pragma once

#include "llibreries.h"
#include "paraules.h"

class Paraula
{
public:
    Paraula() {}
    Paraula(const string& p, const vector<string>& t, const string& c): paraula(p), traduccio(t), comentari(c) {}
    Paraula(const Paraula& P): paraula(P.paraula), traduccio(P.traduccio), comentari(P.comentari) {}
    Paraula& operator=(const Paraula& P);
    virtual ~Paraula() = default;

    string getParaula() const { return paraula; }
    vector<string> getTraduccio() const { return traduccio; }
    string getComentari() const { return comentari; }

    virtual void mostrar() const;

protected:
    string paraula;             // paraula en llatí
    vector<string> traduccio;   // paraula en castellà (varies traduccions)
    string comentari;	        // comentari

    int longitudVisual(const string& str) const;
};

Paraula& Paraula::operator=(const Paraula& P)
{
    if (this != &P)
    {
        paraula = P.paraula;
        traduccio = P.traduccio;
        comentari = P.comentari;
    }
    return *this;
}

typedef struct MapaParaula
{
    map<string, Paraula> p;
    map<string, string> t;
} 
MapaParaula;