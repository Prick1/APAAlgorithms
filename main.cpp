#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <chrono>
#include "algorithms.h"

typedef std::chrono::steady_clock Clock;

using namespace std;

void PrintArray(int ar[], int size){
    for(int i = 0; i < size; i++)
        cout << ar[i] << "\t";
    cout << endl;
}

void Measure(int ar[], int size, int sort){
    std::chrono::steady_clock::time_point t1 = Clock::now();
    switch(sort){

        case 0:
            InsertionSort(ar, size);
            break;

        case 1:
            SelectionSort(ar, size);
            break;

        case 2:
            MergeSort(ar, 0, size - 1);
            break;

        case 3:
            QuickSort(ar, 0, size - 1);
            break;

        case 4:
            HeapSort(ar, size);
            break;

        case 5:
            CountSort(ar, size);
            break;

        case 6:
            RadixSort(ar, size);
            break;
    }
    std::chrono::steady_clock::time_point t2 = Clock::now();
    switch(sort){

        case 0:
            cout << "Insertion Sort Time: ";
            break;

        case 1:
            cout << "Selection Sort Time: ";
            break;

        case 2:
            cout << "Merge Sort Time: ";
            break;

        case 3:
            cout << "Quick Sort Time: ";
            break;

        case 4:
            cout << "Heap Sort Time: ";
            break;

        case 5:
            cout << "Count Sort Time: ";
            break;

        case 6:
            cout << "Radix Sort Time: ";
            break;
    }
    cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << " microseconds" << endl;

}

int main(int argc, char *argv[]){
    vector<int> instance;
    string line;
    ifstream file(argv[1]);
    if(file.is_open()){
        while(  getline(file, line) ){
            instance.push_back(stoi(line));
        }
        int ar[instance.size()];
        for(int i = 0; i < 7; i++){
            copy(instance.begin(), instance.end(), ar);
            Measure(ar, instance.size(), i);
        }
    }
    return 0;


}

