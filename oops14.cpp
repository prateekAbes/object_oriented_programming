// Create an Employee class with employeeId, name, and salary. Implement a default constructor, parameterized constructor, and copy constructor. Make display() a const member function. In main(), create a const Employee object and display its details. Also create another Employee object using the copy constructor. Add a salary update function and show, as a commented statement, that it cannot be called using the const object.

#include <iostream>
using namespace std;

class Employee
{
private:
  int employeeId;
  string name;
  double salary;

public:
  Employee()
  {
    employeeId = 0;
    name = "Unknown";
    salary = 0;
  }

  Employee(int id, string n, double s)
  {
    employeeId = id;
    name = n;
    salary = s;
  }

  Employee(const Employee &e)
  {
    employeeId = e.employeeId;
    name = e.name;
    salary = e.salary;
  }

  void display() const
  {
    cout << "Employee ID: " << employeeId << endl;
    cout << "Name: " << name << endl;
    cout << "Salary: " << salary << endl;
  }

  void updateSalary(double newSalary)
  {
    salary = newSalary;
  }
};

int main()
{
  const Employee e1(101, "Rahul", 50000);

  cout << "Const Employee:" << endl;
  e1.display();

  Employee e2(e1);

  cout << "\nCopied Employee:" << endl;
  e2.display();

  e2.updateSalary(60000);

  cout << "\nAfter Salary Update:" << endl;
  e2.display();

  return 0;
}