#include <iostream>

using namespace std;

int main()
{
    int list[] = {41, 17, 3, 74, 60, 4, 56, 40, 79, 70, 73, 76, 94, 37, 31, 79, 5, 96, 22, 40, 64, 51, 68, 14, 52, 87, 11, 18, 39, 68, 27, 98, 87, 12, 10, 10, 94, 72, 39, 24, 78, 32, 46, 39, 1, 53, 40, 96, 2, 66};

    int temp;

    for(int i = 1; i < 50; i++)
    {
        int j = i;

        while(j > 0 && list[j] < list[j-1])
        {
            temp = list[j];
            list[j] = list[j -1];
            list[j-1] = temp;
            j--;
        }
    }



    for(int i = 0; i < 50; i++)
    {
        cout << list[i] << " ";
    }

    return 0;
}