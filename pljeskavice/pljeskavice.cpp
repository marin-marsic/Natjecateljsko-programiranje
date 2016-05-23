//
// Created by Marin on 31.10.2015..
//

#include <iostream>
using namespace std;

long peci;
long pljeskavica;
long vremena[1000001];

int f(long vrijeme) {

    long broj = pljeskavica;
    for (int i = 1; i <= peci; i++){
        broj -= (vrijeme/vremena[i]);
    }

    return broj <= 0;
}

int main (void){

    cin >> peci;
    cin >> pljeskavica;

    long lo = 0;
    long hi = 0;

    for (int i = 1; i <= peci; i++){
        cin >> vremena[i];

        if (vremena[i] > hi){
            hi = vremena[i];
        }
    }

    hi *= ((pljeskavica + peci) / peci);

    while (lo < hi) {

        if (lo + 1 == hi){
            break;
        }

        long  mid = lo + (hi - lo) / 2;
        if (f(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }

        if (lo + 1 == hi){
            break;
        }
    }

    if (f(lo)){
        cout << lo;
    }else{
        cout << hi;
    }

    return 0;
}