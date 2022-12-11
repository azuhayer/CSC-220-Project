// C++ implementation of Radix Sort
#include <iostream>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace chrono;

void radix_sort(int arr[], int n)
{
 
    // Step 1: Find the maxumum element
    int maximum = arr[0];
 
    for(int i = 1; i < n; i++)
    {
        maximum = max(maximum, arr[i]);
    }
 
    // Step 2: Count the number of digits of the maximum number
    int digits = 0;
 
    while(maximum > 0)
    {
        digits++;
        maximum /= 10;
    }
 
    // Step 3, 4, 5: Arrange the numbers on the basis of digits
    for(int i = 0; i < digits; i++) 
    {
 
        // Units/Tens/Hundreds - used to determine which digit
        int power = pow(10, i);
 
        // Holds the updated array 
        int new_array[n];
 
        // Counting Sort Array - required for arranging digits [0-9]
        int count[10];
 
        // Initializing Count Array
        memset(count, 0, sizeof(count));
 
        // Calculating frequency of digits
        for(int j = 0; j < n; j++)
        {
 
            // The digit under consideration in this iteration
            int num = (arr[j] / power) % 10;
 
            count[num]++;
        }
 
        // Cumulative frequency of count array
        for(int j = 1; j < 10; j++)
        {
            count[j] += count[j - 1];
        }
 
        // Designating new positions in the updated array
        for(int j = n - 1; j >= 0; j--) 
        {
 
            // The digit under consideration in this iteration
            int num = (arr[j] / power) % 10;
 
            new_array[count[num]-1] = arr[j];
            count[num]--;
        }
 
        // Updating the original array using New Array
        for(int j = 0; j < n; j++)
        {
            arr[j] = new_array[j];
        }
     
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
    radix_sort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
 
    cout << "Time taken by Radix Sort function for the array is " << duration.count() << " nanoseconds" << endl;
    return 0;
}
