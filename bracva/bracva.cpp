//
// Created by Marin on 31.10.2015..
//

#include<stdio.h>
#include<math.h>
#include <iostream>
using namespace std;

const double eps = 0.000001;

double f(double x, double y, int N, double koordinate[3001][2]) {

    double sum = 0.0;
    for (int i = 1; i <= N; i++){
        double uX = koordinate[i][0] - x;
        double uY = koordinate[i][1] - y;
        sum += sqrt(uX*uX + uY*uY);
    }
    return sum;
}

int main (void){

    double koordinate[3001][2];

    int N;
    cin >> N;

    double loX = 1000;
    double loY = 1000;
    double hiX = 0;
    double hiY = 0;

    int i;
    for (i = 1; i <= N; i++){
        cin >> koordinate[i][0];
        cin >> koordinate[i][1];
    }

    double x = 0;
    double y = 0;

    for (i = 0; i < 200; i++){
        double mid1 = (loX + loX + hiX) / 3;
        double mid2 = (loX + hiX + hiX) / 3;
        double midY = loY + (hiY - loY) / 2;

        if (f(mid1, midY, N, koordinate) + eps  < f(mid2, midY, N, koordinate)){
            hiX = mid2;
        }else{
            loX = mid1;
        }

        mid1 = (loY + loY + hiY) / 3;
        mid2 = (loY + hiY + hiY) / 3;
        double midX = loX + (hiX - loX) / 2;

        if (f(midX, mid1, N, koordinate) + eps  < f(midX, mid2, N, koordinate)){
            hiY = mid2;
        }else{
            loY = mid1;
        }
    }

    x = (loX + hiX)/2;
    y = (loY + hiY)/2;

    double d = f(x, y, N, koordinate);

    printf("%.4f", d);
    return 0;
}

