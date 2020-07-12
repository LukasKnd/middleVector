#include <iostream>

#include "middleVector.h"

using namespace std;

int main()
{
    middleVector<int> v;

    v.addLast(5);
    v.addLast(7);
    v.addLast(8);
    v.addLast(9);
    v.add(2, 20); // add number 20 to index 2
    v.remove(0); // remove number at index 0

    //Print all the numbers in vector
    for(int i = 0; i < v.getSize(); i++) {
        cout << v[i] << endl;
    }

    return 0;
}
