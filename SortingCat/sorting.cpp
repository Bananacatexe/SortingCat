#include <vector>
#include <algorithm>
#include "sorting.h"
#include <iostream>
using namespace std;



//you can add more sorting but make sure you declare the funtion on sorting.h header file 
//merge and quick is not well codded , ill prolly fix it later , see if you can optimise them 

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}
// Function to implement Bubble Sort
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
           
            cout << "Step " << i + 1 << ", Pass " << j + 1 << ": ";
            printArray(arr);
        }
    }
}

// Function to implement Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
       
        cout << "Step " << i << ": ";
        printArray(arr);
    }
}

// Function to implement Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
        
        cout << "Step " << i + 1 << ": ";
        printArray(arr);
    }
}

// Function to implement Quick Sort and The current state is so fucking goofy, idk help me fix this part of quick sort , dont mess this up
void printPartitionStep(const vector<int>& arr, int low, int high, int pivot) {
    cout << "Array after partitioning with pivot " << pivot << ": ";
    for (int i = low; i <= high; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSortHelper(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        printPartitionStep(arr, low, high, arr[pi]);

        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(vector<int>& arr) {
    quickSortHelper(arr, 0, arr.size() - 1);
    cout << endl;
}

// Merge sort merging the clown aura into me ,lamaooa funny right  ??

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        }
        else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);

        
        /*cout << "After merging: ";
        for (int i = left; i <= right; ++i) {
            cout << arr[i] << " ";
        }*/
        cout << endl;
    }
}
