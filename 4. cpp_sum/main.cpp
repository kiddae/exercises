#include <iostream>
using std::cout;
using std::cin;
using std::endl;

float sum(float t[3][4])
{
    float sum = 0;
    /* version classique
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
            sum += t[i][j];
        }
    }
    */
    // Formalisme pointeur
    // La solution consiste à convertir t en pointeur `float*` au lieu de `float*[4]`
    float* adt = (float *)t;
    for (int i=0; i<12; i++)
    {
        sum += *(adt + i);
    }
    return sum;
}

int main()
{
    float tableau[3][4] = {4.5, 3.2, 5.4, 1.2,2.3, 5.3, 1.2};
    cout << sum(tableau) << endl;
}

