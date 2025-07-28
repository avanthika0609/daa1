#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;
using namespace chrono;

struct Employee {
    int id;
    string name;
    string department;
    float salary;
};

void merge(vector<Employee>& employees, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Employee> L(n1);
    vector<Employee> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = employees[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = employees[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].id <= R[j].id) {
            employees[k] = L[i];
            i++;
        } else {
            employees[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        employees[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        employees[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<Employee>& employees, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(employees, left, mid);
        mergeSort(employees, mid + 1, right);
        merge(employees, left, mid, right);
    }
}

void sortFile(const string& filename) {
    vector<Employee> employees;
    ifstream infile(filename);

    Employee emp;
    while (infile >> emp.id >> emp.name >> emp.department >> emp.salary) {
        employees.push_back(emp);
    }
    infile.close();

    auto start = high_resolution_clock::now();
    mergeSort(employees, 0, employees.size() - 1);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << filename << " took " << duration.count() << " ms" << endl;

    string outputFile = "merge_sorted_" + filename;
    ofstream outfile(outputFile);
    for (const auto& e : employees) {
        outfile << e.id << " " << e.name << " " << e.department << " " << e.salary << "\n";
    }
    outfile.close();
}

int main() {
    vector<string> files = {
        "ascending_employees_5000.txt",
        "ascending_employees_10000.txt",
        "ascending_employees_20000.txt",
        "descending_employees_5000.txt",
        "descending_employees_10000.txt",
        "descending_employees_20000.txt",
        "random_employees_5000.txt",
        "random_employees_10000.txt",
        "random_employees_20000.txt"
    };

    for (const auto& file : files) {
        sortFile(file);
    }

    return 0;
}

