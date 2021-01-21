#include <iostream>
#include <climits>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    const int TABLEN = 10;
    int tab[TABLEN];
    cout << "Insert " << TABLEN << " elements:" << endl;
    for (int i=0; i<TABLEN; i++) cin >> tab[i];

    int maximum = -INT_MAX;
    int minimum = INT_MAX;

    // USING ARRAY ELEMENTS
    /* for (int i=0; i<TABLEN; i++)
    {
        maximum = (tab[i] > maximum) ? tab[i] : maximum;
        minimum = (tab[i] < minimum) ? tab[i] : minimum;
    }*/

    // USING POINTER PROPERTIES 
    for (int i=0; i<TABLEN; i++)
    {
        maximum = (*(tab+i) > maximum) ? *(tab+i) : maximum;
        minimum = (*(tab+i) < minimum) ? *(tab+i) : minimum;
    }

    cout << "Maximum is " << maximum << endl;
    cout << "Minimum is " << minimum << endl;
}

