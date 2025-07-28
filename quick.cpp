#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <chrono>
using namespace std;
using namespace chrono;

struct Employee
{
    int id;
    string name;
    string department;
    float salary;
};

int partition(vector<Employee>&employees,int low,int high)
{
    int pivot=employees[high].id;
    int i=low-1;

    for(int j=low;j<high;j++)
    {
        if(employees[j].id<pivot)
        {
            i++;
            swap(employees[i],employees[j]);
        }
    }
    swap(employees[i+1],employees[high]);
    return i+1;
}

void quickSort(vector<Employee>&employees,int low,int high)
{
    if(low<high)
    {
        int pi=partition(employees,low,high);
        quickSort(employees,low,pi-1);
        quickSort(employees,pi+1,high);
    }
}

void sortFile(const string&filename)
{
    vector<Employee>employees;
    ifstream infile(filename);

    Employee emp;
    while(infile>>emp.id>>emp.name>>emp.department>>emp.salary)
    {
        employees.push_back(emp);
    }
    infile.close();

    auto start=high_resolution_clock::now();
    quickSort(employees,0,employees.size()-1);
    auto end=high_resolution_clock::now();
    auto duration=duration_cast<milliseconds>(end-start);
    cout<<filename<<" took "<<duration.count()<<" ms"<<endl;

    string outputFile="quick_sorted_"+filename;
    ofstream outfile(outputFile);
    for(const auto&e:employees)
    {
        outfile<<e.id<<" "<<e.name<<" "<<e.department<<" "<<e.salary<<"\n";
    }
    outfile.close();
}

int main()
{
    vector<string>files={
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

    for(const auto&file:files)
    {
        sortFile(file);
    }

    return 0;
}
