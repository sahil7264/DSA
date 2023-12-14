// for any random larger input
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for srand()

#include <set>

using namespace std;

void printArray(int arr[], int left, int right)
{
    for (int i = left; i <= right; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(int arr[], int left, int mid, int right)
{
    int size1 = mid - left + 1;
    int size2 = right - mid;
    int arr1[size1];
    int arr2[size2];
    for (int i = 0; i < size1; i++)
    {
        arr1[i] = arr[left + i];
    }
    for (int i = 0; i < size2; i++)
    {
        arr2[i] = arr[mid + i + 1];
    }

    int i = 0, j = 0;
    int k = left;
    while ((i < size1) && (j < size2))
    {
        if (arr1[i] <= arr2[j])
        {
            arr[k] = arr1[i];
            i++;
        }
        else
        {
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }
    while (i < size1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while (j < size2)
    {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
    else{
        return;
    }
}

int main()
{
    const int size = 1000;
    // int array[size];
    int array[size];
    set<int> usedNumbers;
    srand(static_cast<unsigned>(time(0)));

    /*srand(static_cast<unsigned>(time(0)));


    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 1000;
    }*/
    for (int i = 0; i < size; i++)
    {
        int randomNumber;
        do
        {
            randomNumber = rand() % 1000 + 1;          // Generate a random positive number between 1 and 1000
        } while (usedNumbers.count(randomNumber) > 0); // Ensure uniqueness

        array[i] = randomNumber;
        usedNumbers.insert(randomNumber);
    }

    cout << "Original array:" << endl;
    printArray(array, 0, size - 1);

    mergeSort(array, 0, size - 1);

    cout << "Sorted array:" << endl;
    printArray(array, 0, size - 1);

    return 0;
}