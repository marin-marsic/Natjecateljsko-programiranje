//
// Created by Marin on 4.11.2015..
//

//
// Created by Marin on 2.11.2015..
//

#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

unsigned long from, to;
vector<long> stablo;
unsigned long offset;

unsigned long long sumiraj(unsigned long i, unsigned long lo, unsigned long hi){

    if (from >= hi || to <= lo) return 0;
    if (lo >= from && hi <= to) return stablo[i];

    return (sumiraj( 2*i, lo, (lo+hi)/2) + sumiraj( 2*i + 1, (lo+hi)/2, hi));
}

unsigned long long sumiraj(unsigned long lo, unsigned long hi){

    from = lo;
    to = hi;
    return sumiraj(1, 0, offset);
}

void set(unsigned long i, long value){
    i += offset;

    stablo[i] += value;
    if (stablo[i] > 1000000000){
        stablo[i] = 1000000000;
    }

    if (stablo[i] < 0){
        stablo[i] = 0;
    }

    for (i /= 2; i > 0; i /= 2){
        stablo[i] = stablo[2*i] + stablo[2*i + 1];
    }
}

int main() {

    unsigned long N;
    cin >> N;

    // stvori stablo
    for (offset = 1; offset < N; offset *= 2);
    stablo.resize(2*offset);

    unsigned long K;
    cin >> K;

    for (unsigned long i = 0; i < K; i++){
        string naredba;
        unsigned long a;
        long b;

        cin >> naredba;
        cin >> a;
        cin >> b;

        if (naredba.compare("posadka") == 0){
            set(a, b);
        }else if (naredba.compare("razgruzka") == 0){
            set(a, -b);
        }else if (naredba.compare("kontora") == 0){
            cout << sumiraj(a, b+1) << endl;
        }

        /* for (int i = 0; i < 2*offset; i++){
            cout << stablo[i] << " ";
        }
        cout << endl;  */
    }
    return 0;
}
