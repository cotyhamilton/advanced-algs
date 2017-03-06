/*
Coty Hamilton
*/

#ifndef quicksort_h
#define quicksort_h

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
        std::cout << arr[i] << std::endl;
    }
}

int partition(int arr[], int p, int r, int *&counter)
{
    int temp;
    int k = rand() % (r - p) + p;
    
    temp = arr[r];
    arr[r] = arr[k];
    arr[k] = temp;

    int i = p - 1;
    int x = arr[r];
    int j = p;

    while (++(*counter) && j <= r - 1)
    {
        if (++(*counter) && arr[j] <= x)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j++;
    }
    temp = arr[i+1];
    arr[i+1] = arr[r];
    arr[r] = temp;
    return i + 1;
}

int *quicksort(int arr[], int p, int r, int *&counter)
{
    if (++(*counter) && p < r)
    {
        int q = partition(arr, p, r, counter);
        quicksort(arr, p, q - 1, counter);
        quicksort(arr, q + 1, r, counter);
    }
    return arr;
}

#endif
