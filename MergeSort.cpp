// C++ implementation of Merge Sort
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) 
{
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
  {
    L[i] = arr[p + i];
  }
  
  for (int j = 0; j < n2; j++)
  {
    M[j] = arr[q + 1 + j];
  }

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  while (i < n1 && j < n2) 
  {
    if (L[i] <= M[j]) 
    {
      arr[k] = L[i];
      i++;
    } 
    else 
    {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) 
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) 
  {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) 
{
  if (l < r) 
  {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
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
   mergeSort(arr, 0, n - 1);
   auto stop = high_resolution_clock::now();
   auto duration = duration_cast<nanoseconds>(stop - start);
 
   cout << "Time taken by Merge Sort function for the array is " << duration.count() << " nanoseconds" << endl;
   return 0;
}
