#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <cmath>
#include <fstream>
#include <map>

using namespace std;

enum Casos {
    NS = 0,  // Nominativo Singular
    GS = 1,  // Genitivo Singular
    DS = 2,  // Dativo Singular
    AS = 3,  // Acusativo Singular
    ABS = 4, // Ablativo Singular
    VS = 5,  // Vocativo Singular
    NP = 6,  // Nominativo Plural
    GP = 7,  // Genitivo Plural
    DP = 8,  // Dativo Plural
    AP = 9,  // Acusativo Plural
    ABP = 10, // Ablativo Plural
    VP = 11, // Vocativo Plural
    LS = 12, // Locativo Singular
    LP = 13 // Locativo Plural
};

typedef struct MapaParaula {
    map<string, Paraula> p;
    map<string, string> t;
} MapaParaula;