#include <iostream>
#include <climits>
using std::cout;
using std::endl;

int main()
{
    int tab[10] = {3,2,6,4,7,3,2,5,4,2};
    int maximum = -INT_MAX;
    int minimum = INT_MAX;

    // USING ARRAY ELEMENTS
    /* for (int i=0; i<10; i++)
    {
        cout << "Elements: " << tab[i] << endl;
        maximum = (tab[i] > maximum) ? tab[i] : maximum;
        minimum = (tab[i] < minimum) ? tab[i] : minimum;
    }*/

    // USING POINTER PROPERTIES 
    for (int i=0; i<10; i++)
    {
        cout << "Elements: " << *(tab+i) << endl;
        maximum = (*(tab+i) > maximum) ? *(tab+i) : maximum;
        minimum = (*(tab+i) < minimum) ? *(tab+i) : minimum;
    }

    cout << "Maximum is " << maximum << endl;
    cout << "Minimum is " << minimum << endl;
}

