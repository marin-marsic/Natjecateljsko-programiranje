//
// Created by Marin on 31.10.2015..
//

#include <iostream>
using namespace std;

unsigned long  N;
unsigned long niz[1000001];
unsigned long skupljenoPoreza(unsigned long  granica) {

    unsigned long suma = 0;
    for (unsigned long i = 1; i <= N; i++) {
        if (niz[i] > granica) {
            suma += niz[i] - granica;
        }
    }
    return suma;
}

int main (void){

    cin >> N;
    unsigned long  potrebno;
    cin >> potrebno;

    unsigned long lo = 0;
    unsigned long hi = 0;

    for (unsigned long i = 1; i <= N; i++) {
        cin >> niz[i];
        if (niz[i] > hi) {
            hi = niz[i];
        }
    }

    unsigned long granica = 0;

    while (lo != hi) {
        unsigned long  mid = lo + (hi - lo) / 2;
        if (skupljenoPoreza(mid) < potrebno) {
            hi = mid;
        } else {
            lo = mid;
        }

        if (lo + 1 == hi){
            break;
        }
    }

    granica = lo;
    if (lo + 1 == hi){
        if (skupljenoPoreza(lo) < potrebno) {
            granica = hi;
        }
    }
    cout << ("%d", granica);

    return 0;
}