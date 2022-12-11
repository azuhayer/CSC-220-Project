// C++ implementation of Insertion Sort
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;
 
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
 
int main()
{
    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;  
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000000;      
    }
 
    auto start = high_resolution_clock::now();
    insertionSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start); 
 
    cout << "Time taken by Insertion Sort function for the array is " << duration.count() << " nanoseconds" << endl;
    return 0;
}
