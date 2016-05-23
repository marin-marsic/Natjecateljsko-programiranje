//
// Created by Marin on 3.12.2015..
//

#include <iostream>
#include <math.h>
using namespace std;

int main() {

    long N;
    cin >> N;

    short polje[10000001];
    long brojac = 0;

    for (int i = 2; i <= N; i++){

        if (polje[i] == 0){

            for (int j = i; j <= N; j+= i){

                long b = j;
                polje[j] = 1;
                while (b % i == 0 && b > 1) {
                    brojac++;
                    b /= i;
                }
            }
        }
    }

    cout << brojac;
    return 0;
}