#pragma once

#include "llibreries.h"
#include "paraules.h"

class Adjectiu: public Paraula
{
public:

private:
    vector<string> genere;	        // m, f, n
    vector<string> declinacio;	    // tipus de declinació
    vector<vector<string>> casos;
};