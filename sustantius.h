#include "paraules.cpp"

class Sustantiu: public Paraula
{
public:

private:
    vector<string> genere;	        // m, f, n
    vector<string> declinacio;	    // tipus de declinació
    vector<vector<string>> casos;
};