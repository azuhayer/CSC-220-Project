// C++ implementation of Heap Sort
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;
  
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 
  
    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;
  
    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;
  
    // If largest is not root
    if (largest != i) 
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) 
    {
        // Move current root to end
        swap(arr[0], arr[i]);
  
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
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
   heapSort(arr, n);
   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<nanoseconds>(stop - start);
 
   cout << "Time taken by Heap Sort function for the array is " << duration.count() << " nanoseconds" << endl;
   return 0; 
   
}
