#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

// Merge two sorted subarrays
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Read file, sort, and write output
void sortPages(string inputFile, string outputFile) {
    ifstream in(inputFile);
    vector<int> pages;
    int val;

    while (in >> val) {
        pages.push_back(val);
    }
    in.close();

    auto start = high_resolution_clock::now();
    mergeSort(pages, 0, pages.size() - 1);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Sorted " << pages.size() << " documents from "
         << inputFile << " in " << duration.count() << " ms" << endl;

    ofstream out(outputFile);
    for (int i = 0; i < pages.size(); i++) {
        out << pages[i] << endl;
    }
    out.close();
}

// Main
int main() {
    sortPages("pages_1000.txt", "sorted_pages_1000.txt");
    sortPages("pages_5000.txt", "sorted_pages_5000.txt");
    sortPages("pages_10000.txt", "sorted_pages_10000.txt");
    sortPages("pages_50000.txt", "sorted_pages_50000.txt");
    return 0;
}

