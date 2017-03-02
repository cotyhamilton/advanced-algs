#include <iostream>
#include <cstdlib>

using namespace std;

int *fillRandomArray(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = rand() % 20000 - 10000;
    }
    return arr;
}

void print(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << endl;
    }
}

int partition(int arr[], int p, int r)
{
    int x = arr[rand() % (r - p) + p];
    int i = p;
    int j = r;
    int temp;
    while (i <= j)
    {
        while(arr[i] < x)
        {
            i++;
        }
        while(arr[j] > x)
        {
            j--;
        }
        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    return i;
}

int *quicksort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q, r);
    }
    return arr;
}

int main()
{
    int count = 0;
    const int size = 20;
    int list[size];

    for(int i = 0; i < 5; i++)
    {
        int *rlist = fillRandomArray(list,size);

        rlist = quicksort(rlist, 0, size-1);

        print(rlist, size);

        cout << endl << endl;
    }

    return 0;
}