#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sortHeights(string inputFile, string outputFile) {
    ifstream in(inputFile);
    vector<int> heights;
    int h;

    while (in >> h) {
        heights.push_back(h);
    }
    in.close();

    auto start = high_resolution_clock::now();
    quickSort(heights, 0, heights.size() - 1);
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Sorted " << heights.size() << " heights from "
         << inputFile << " in " << duration.count() << " ms" << endl;

    ofstream out(outputFile);
    for (int i = 0; i < heights.size(); i++) {
        out << heights[i] << endl;
    }
    out.close();
}

int main() {
    sortHeights("heights_1000.txt", "sorted_heights_1000.txt");
    sortHeights("heights_5000.txt", "sorted_heights_5000.txt");
    sortHeights("heights_10000.txt", "sorted_heights_10000.txt");
    sortHeights("heights_50000.txt", "sorted_heights_50000.txt");
    return 0;
}

