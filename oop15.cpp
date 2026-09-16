// Create a StudentResult class with private data members rollNo, name, and marks of three subjects. Use a parameterized constructor to initialize the object. Declare ResultAnalyzer as a friend class. The ResultAnalyzer class should calculate and display total marks, percentage, and pass/fail result. Also maintain a static data member totalStudents and a static function to display how many StudentResult objects have been created. Add a destructor that displays a message when an object is destroyed.

#include <iostream>
using namespace std;

class ResultAnalyzer;

class StudentResult
{
private:
  int rollNo;
  string name;
  float marks1, marks2, marks3;

  static int totalStudents;

public:
  StudentResult(int roll, string n, float m1, float m2, float m3)
  {
    rollNo = roll;
    name = n;
    marks1 = m1;
    marks2 = m2;
    marks3 = m3;

    totalStudents++;
  }

  ~StudentResult()
  {
    cout << "StudentResult object for " << name
         << " is destroyed." << endl;
  }

  friend class ResultAnalyzer;

  static void displayTotalStudents()
  {
    cout << "Total StudentResult objects created: "
         << totalStudents << endl;
  }
};

int StudentResult::totalStudents = 0;

class ResultAnalyzer
{
public:
  void calculateResult(const StudentResult &s)
  {
    float total = s.marks1 + s.marks2 + s.marks3;
    float percentage = total / 3;

    cout << "\nStudent Details:" << endl;
    cout << "Roll No: " << s.rollNo << endl;
    cout << "Name: " << s.name << endl;
    cout << "Total Marks: " << total << endl;
    cout << "Percentage: " << percentage << "%" << endl;

    if (s.marks1 >= 33 &&
        s.marks2 >= 33 &&
        s.marks3 >= 33)
    {
      cout << "Result: Pass" << endl;
    }
    else
    {
      cout << "Result: Fail" << endl;
    }
  }
};

int main()
{
  StudentResult s1(101, "Rahul", 80, 75, 90);
  StudentResult s2(102, "Aman", 65, 70, 55);

  ResultAnalyzer analyzer;

  analyzer.calculateResult(s1);
  analyzer.calculateResult(s2);

  StudentResult::displayTotalStudents();

  return 0;
}