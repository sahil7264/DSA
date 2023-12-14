#include <iostream>
#include <cstdlib> 
#include <ctime>  
#include <set>

using namespace std;

//int size;
const int size = 1000;

void PrintArray(int arr[], int low, int high)
{
    for (int i = low; i <= high; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int Partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int k = high;
    for (int i = high; i > low; i--)
    {
        if (pivot < arr[i])
        {
            swap(arr[i], arr[k--]);
        }
    }
    swap(arr[low], arr[k]);

    return k;
}

void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int index = Partition(arr, low, high);
        cout<<"pivot : "<<index<<" "<<endl;
        QuickSort(arr, low, index - 1);
       
         PrintArray(arr, low, index - 1);
        QuickSort(arr, index + 1, high);
        
        PrintArray(arr, index + 1, high);
        
    }
}

int main()
{
   // const int size = 1000;
    int array[size];
    set<int> usedNumbers;
    srand(static_cast<unsigned>(time(0)));

   
  /*  for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 1000; 
    }*/
  /*for (int i = 0; i < size; i++) {
        do {
            array[i] = rand() % 1000 + 1; // Generate a random positive number between 1 and 1000
        } while (i > 0 && array[i] == array[i - 1]); // Ensure uniqueness
    }*/
    for (int i = 0; i < size; i++) {
        int randomNumber;
        do {
            randomNumber = rand() % 1000 + 1; // Generate a random positive number between 1 and 1000
        } while (usedNumbers.count(randomNumber) > 0); // Ensure uniqueness

        array[i] = randomNumber;
        usedNumbers.insert(randomNumber);
    }

 

    cout << "Original array:" << endl;
    PrintArray(array, 0, size - 1);

    QuickSort(array, 0, size - 1);

    cout << "Sorted array:" << endl;
    PrintArray(array, 0, size - 1);

    return 0;
}