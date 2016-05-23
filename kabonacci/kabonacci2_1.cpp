//
// Created by Marin on 3.12.2015..
//

#include <iostream>
#include <math.h>
using namespace std;

unsigned long long matrica[12][12] = {{0,0,0,0,0,0,0,0,0,0,0,0},
                                      {0,0,1,0,0,0,0,0,0,0,0,0},
                                      {0,0,0,1,0,0,0,0,0,0,0,0},
                                      {0,0,0,0,1,0,0,0,0,0,0,0},
                                      {0,0,0,0,0,1,0,0,0,0,0,0},
                                      {0,0,0,0,0,0,1,0,0,0,0,0},
                                      {0,0,0,0,0,0,0,1,0,0,0,0},
                                      {0,0,0,0,0,0,0,0,1,0,0,0},
                                      {0,0,0,0,0,0,0,0,0,1,0,0},
                                      {0,0,0,0,0,0,0,0,0,0,1,0},
                                      {0,1,1,1,1,1,1,1,1,1,1,0},
                                      {0,1,1,1,1,1,1,1,1,1,1,1}};

void pomnozi(unsigned long long  a[][12], unsigned long long  b[][12], unsigned long long c[][12], unsigned long long  M, int size)//multiply matrix a and b. put result in c
{
    int i,j,k;
    for(i = 11 - size; i < 12; i++)
    {
        for( j = 11 - size; j < 12; j++)
        {
            c[i][j]=0;
            for(k = 11 - size; k < 12; k++)
            {
                c[i][j]+=(a[i][k]*b[k][j]);
                c[i][j]=c[i][j]%M;
            }
        }
    }

}

void matpow(unsigned long long Z[][12], unsigned long long n, unsigned long long ans[][12], unsigned long long M, int size)  //find ( Z^n )% M and return result in ans
{

    unsigned long long temp[12][12];
    int i,j;
    while(n > 0)
    {
        if(n&1)
        {
            pomnozi(ans, Z, temp, M, size);
            for(i = 11 - size; i < 12; i++)
                for(j = 11 - size; j < 12; j++)
                    ans[i][j]=temp[i][j];
        }
        pomnozi(Z, Z, temp, M, size);
        for(i = 11 - size; i < 12; i++)
            for(j = 11 - size; j < 12; j++)
                Z[i][j]=temp[i][j];


        n=n/2;
    }
    return;

}

int main() {

    unsigned long long a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;

    unsigned long long result[12][12] = {{0,0,0,0,0,0,0,0,0,0,0,0},
                                         {0,0,1,0,0,0,0,0,0,0,0,0},
                                         {0,0,0,1,0,0,0,0,0,0,0,0},
                                         {0,0,0,0,1,0,0,0,0,0,0,0},
                                         {0,0,0,0,0,1,0,0,0,0,0,0},
                                         {0,0,0,0,0,0,1,0,0,0,0,0},
                                         {0,0,0,0,0,0,0,1,0,0,0,0},
                                         {0,0,0,0,0,0,0,0,1,0,0,0},
                                         {0,0,0,0,0,0,0,0,0,1,0,0},
                                         {0,0,0,0,0,0,0,0,0,0,1,0},
                                         {0,1,1,1,1,1,1,1,1,1,1,0},
                                         {0,1,1,1,1,1,1,1,1,1,1,1}} ;//modify matrix a[][] for other recurrence relations

    unsigned long long broj = 0;

    if(b > a)
    {
        matpow(matrica, b-a-1, result, c, a);

        for (int i = 11 - a; i < 11; i++){
            broj +=(result[11][i]);    //final multiplication of Z^(n-2) with the initial terms of the series
        }
        broj += a;
    }
    else
        broj = b;

   /* for (int i = 1; i < 12; i++){
        for (int j = 0; j < 12; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << broj % c;
    return 0;
}