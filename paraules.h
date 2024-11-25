#include "llibreries.h"

class Paraula
{
public:
    Paraula() { casos.resize(14); }
    Paraula(const string& paraula, const vector<string>& genere, const vector<string>& declinacio,
        const string& traduccio, const string& comentari = ""): paraula(paraula),
	    genere(genere), declinacio(declinacio), traduccio(traduccio), comentari(comentari)
        { casos.resize(14); }

    string getParaula() const { return paraula; }
    vector<string> getGenere() const { return genere; }
    vector<string> getDeclinacio() const { return declinacio; }
    string getTraduccio() const { return traduccio; }
    string getComentari() const { return comentari; }
    vector<vector<string>> getCasos() const { return casos; }
    vector<string> getCas(const int& n) const { return casos[n]; }

    void agregarCas(const int& cas, const string& forma)
	    { casos[cas].push_back(forma); }
    void mostrarParaula() const;

private:
    string paraula;	// paraula en llatí
    vector<string> genere;	// m, f, n
    vector<string> declinacio;	// tipus de declinació 
    string traduccio;
    string comentari;	// comentari
    vector<vector<string>> casos; // casos

    void mostrarCas(const int& cas) const;
    int longitudVisual(const string& str) const;
};

typedef struct MapaParaula {
    map<string, Paraula> p;
    map<string, string> t;
} MapaParaula;