//
// Created by Marin on 10.11.2015..
//

#include <iostream>

using namespace std;

int main() {

    long N;
    cin >> N;

    int trgovina[3][150001];

    for (int i = 1; i <= N; i++){
        cin >> trgovina[0][i];
    }
    for (int i = 1; i <= N; i++){
        cin >> trgovina[1][i];
    }
    for (int i = 1; i <= N; i++){
        cin >> trgovina[2][i];
    }

    trgovina[1][1] = trgovina[0][1];
    trgovina[2][1] = trgovina[0][1];

    trgovina[2][2] = trgovina[1][2];

    for (int i = 2; i <= N; i++){
        trgovina[0][i] += trgovina[0][i-1];

        int min2 = trgovina[0][i-1];
        if (min2 > trgovina[1][i-1]){
            min2 = trgovina[1][i-1];
        }
        trgovina[1][i] += min2;

        int min3 = trgovina[1][i-1];
        if (min3 > trgovina[2][i-1]){
            min3 = trgovina[2][i-1];
        }
        trgovina[2][i] += min3;
    }

    cout << trgovina[2][N];

    return 0;
}