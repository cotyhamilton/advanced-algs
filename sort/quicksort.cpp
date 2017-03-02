/*
Coty Hamilton

|-- Note --|
- uncomment last line to print last array sorted

*/

#include <iostream>
#include <cstdlib>
#include "quicksort.h"

using namespace std;

int main()
{
    int count;
    int *pcount = &count;
    const int size = 5000;
    int list[size];
    int *rlist;

    for(int i = 0; i < 10; i++)
    {
        count = 0;
        
        rlist = fillRandomArray(list,size);

        rlist = quicksort(rlist, 0, size - 1, pcount);

        cout << "Quicksort for array [" << i + 1 << "] made " << count << " comparisons\n\n";

    }

    // print(rlist, size);

    return 0;
}