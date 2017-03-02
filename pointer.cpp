#include <iostream>
#include <cstdlib>

using namespace std;

void incr(int *&counter)
{
    *counter += 1;
}

int main()
{
    int count = 0;
    int *ptr;

    ptr = &count;

    cout << *ptr;

    for (int i = 0; i < 99; i++)
    {
        incr(ptr);
        cout << count << endl;
    }



    return 0;
}