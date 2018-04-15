#include "cards.h"
#include <cstdlib>
#include <iostream>

Card::Card(){ // construct a random card
    int r = 1 + rand() % 4;
    switch (r) {// pick random suit
        case 1: suit = OROS;
            break;
        case 2: suit = COPAS;
            break;
        case 3: suit = ESPADAS;
            break;
        case 4: suit = BASTOS;
            break;
        default: break;
    }
    r = 1 + rand() % 10;
    switch (r) { // pick random rank
        case 1: rank = AS;
            break;
        case 2: rank = DOS;
            break;
        case 3: rank = TRES;
            break;
        case 4: rank = CUATRO;
            break;
        case 5: rank = CINCO;
            break;
        case 6: rank = SEIS;
            break;
        case 7: rank = SIETE;
            break;
        case 8: rank = SOTA;
            break;
        case 9: rank = CABALLO;
            break;
        case 10: rank = REY;
            break;
        default: break;
    }
}

