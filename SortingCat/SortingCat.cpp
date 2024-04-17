#include <iostream>
#include <vector>
#include <chrono>
#include "sorting.h"

using namespace std;
using namespace std::chrono;

// Function to measure the time taken by a sorting algorithm { im bad at CPP , see if you can fix this stupid code}
double measureSortingTime(void (*sortingFunction)(vector<int>&), vector<int>& arr) {
    auto start = high_resolution_clock::now();
    sortingFunction(arr);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}

double measuremergeTime(void (*sortingFunction)(std::vector<int>&, int, int), std::vector<int>& arr, int left, int right) {
    auto start = high_resolution_clock::now();
    sortingFunction(arr, left, right);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    return duration.count();
}


void printCat() {
    cout << R"(
                                                    ??????
                                           \`-._           __
                                            \\  `-..____,.'  `.
                                             :`.         /    \`.
                  SORTING CAT ON WORK        :  )       :      : \
                                              ;'        '   ;  |  :
                                              )..      .. .:.`.;  :
                                             /::...  .:::...   ` ;
                                             ; _ '    __        /:\
                                             `:o>   /\o_>      ;:. `.
                                            `-`.__ ;   __..--- /:.   \
                                            === \_/   ;=====_.':.     ;
                                             ,/'`--'...`--....        ;
                                                  ;                    ;
                                                .'                      ;
                                              .'                        ;
                                            .'     ..     ,      .       ;
                                           :       ::..  /      ;::.     |
                                          /      `.;::.  |       ;:..    ;
                                         :         |:.   :       ;:.    ;
                                         :         ::     ;:..   |.    ;
                                          :       :;      :::....|     |
                                          /\     ,/ \      ;:::::;     ;
                                        .:. \:..|    :     ; '.--|     ;
                                       ::.  :''  `-.,,;     ;'   ;     ;
                                    .-'. _.'\      / `;      \,__:      \
                                    `---'    `----'   ;      /    \,.,,,/
                                                       `----`              HE CANT EVEN DO BASIC MATHS
    )" << endl;
}



int main() {


    printCat();


    char choice;
    do {
        int option;
        cout << "Choose an option:\n";
        cout << "1. Sorting\n";
        cout << "2. Searching\n";
        cout << "3. Exit\n";
        cin >> option;

        switch (option) {
        case 1: {
            int sortChoice;
            cout << "Choose a sorting algorithm:\n";
            cout << "1. Bubble Sort\n";
            cout << "2. Insertion Sort\n";
            cout << "3. Selection Sort\n";
            cout << "4. Quick sort\n";
            cout << "5. Merge sort\n";
            cin >> sortChoice;

            if (sortChoice < 1 || sortChoice > 5) {
                cout << "Invalid choice!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            int n;
            cout << "Enter the number of elements: ";
            cin >> n;

            if (n <= 0) {
                cout << "Invalid number of elements!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            vector<int> arr(n);
            cout << "Enter the elements:\n";
            for (int i = 0; i < n; ++i) {
                cin >> arr[i];
                if (!cin) {
                    cout << "Invalid input!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
            }

            if (!cin) {
                continue;
            }

            cout << "Initial array: ";
            printArray(arr);

            double timeTaken;
            if (sortChoice == 1) {
                cout << "\nPerforming Bubble Sort:\n";
                timeTaken = measureSortingTime(bubbleSort, arr);
            }
            else if (sortChoice == 2) {
                cout << "\nPerforming Insertion Sort:\n";
                timeTaken = measureSortingTime(insertionSort, arr);
            }
            else if (sortChoice == 3) {
                cout << "\nPerforming Selection Sort:\n";
                timeTaken = measureSortingTime(selectionSort, arr);
            }
            else if (sortChoice == 4) {
                cout << "\nPerforming Quick Sort:\n";
                timeTaken = measureSortingTime(quickSort, arr);
            }
            else if (sortChoice == 5) {
                cout << "\nPerforming Merge Sort:\n";
                int left = 0;
                int right = arr.size() - 1;
                timeTaken = measuremergeTime(mergeSort, arr, left, right);
            }

            cout << "\nSorted array: ";
            printArray(arr);

            cout << "\nTime taken: " << timeTaken << " milliseconds\n";
            break;
        }
        case 2: {
        
            cout << "Searching functionality not implemented yet." << endl;
            break;
        }
        case 3: {
        
            return 0;
        }
        default: {
            cout << "Invalid option! Please choose again." << endl;
            break;
        }
        }

        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get(choice);
    } while (choice == '\n');

    return 0;
}
