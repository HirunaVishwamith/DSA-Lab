#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root) {
    int largest = root;
    int left_child = 2 * root + 1;
    int right_child = 2 * root + 2;

    // If left child is larger than root
    if (left_child < n && arr[left_child] > arr[largest])
        largest = left_child;

    // If right child is larger than largest so far
    if (right_child < n && arr[right_child] > arr[largest])
        largest = right_child;

    // If largest is not root
    if (largest != root) {
        // Swap root and largest
        int temp = arr[root];
        arr[root] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}



// Function to perform heap sort
void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}



/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i = 0; i < n; ++i)
      cout << arr[i] << " ";
   cout << "\n";
}

// main program
int main()
{
   int heap_arr[] = {9,6,2,4,55,3,4,1,0,5,7,8,10,11,12,13,14,15,16,17,18,19,20};
   int n = sizeof(heap_arr) / sizeof(heap_arr[0]);
   cout << "Input array" << endl;
   displayArray(heap_arr, n);

   heapSort(heap_arr, n);

   cout << "Sorted array" << endl;
   displayArray(heap_arr, n);
}