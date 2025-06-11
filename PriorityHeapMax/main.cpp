#include <iostream>
#include"MPHeap.h"
#include"Employee.h"
#include<iomanip>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct PriorityData 
{
    int priority; // Priority value for ordering
    int data;     // Data value
    PriorityData(int p = 0, int d = 0) 
    {
    	this->priority=p;
    	this->data=d;
	}
};
int main(int argc, char** argv)
{
	MPHeap<PriorityData> dataHeap(5);
    cout << "Testing MPHeap with PriorityData:" << endl;
    dataHeap.insert(PriorityData(10.5, 42)); // Priority 10.5, data 42
    dataHeap.insert(PriorityData(5.2, 15));  // Priority 5.2, data 15
    dataHeap.insert(PriorityData(8.7, 99));  // Priority 8.7, data 99
    
    cout << "Removing elements: ";
    while (!dataHeap.isEmpty()) {
        PriorityData item = dataHeap.remove();
        cout << "(" << fixed << setprecision(1) << item.priority << ", " << item.data << ") ";
    }
    cout << endl << endl;

    // Test with Employee
    MPHeap<Employee> employeeHeap(5);
    cout << "Testing MPHeap with Employee:" << endl;
    employeeHeap.insert(Employee(1, "Alice", "HR", 5.5)); // Priority 5.5 (from exp)
    employeeHeap.insert(Employee(2, "Bob", "IT", 3.2));   // Priority 3.2 (from exp)
    employeeHeap.insert(Employee(3, "Charlie", "Finance", 7.8)); // Priority 7.8 (from exp)
   
    cout << "Removing employees: ";
    while (!employeeHeap.isEmpty()) {
        Employee e = employeeHeap.remove();
        e.display();
        cout << endl;
    }
   

	return 0;
}