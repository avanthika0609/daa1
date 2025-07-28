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

void selectionSort(vector<Employee>& employees) {
    int n = employees.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (employees[j].id < employees[minIdx].id) {
                minIdx = j;
            }
        }
        swap(employees[i], employees[minIdx]);
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
    selectionSort(employees);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << filename << " took " << duration.count() << " ms" << endl;

    ofstream outfile("sorted_" + filename);
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
