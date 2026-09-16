// Create a Patient class with patientId and patientName. Use a static data member activePatients to store the number of currently active Patient objects. Increase the count in the constructor and decrease it in the destructor. Add a static member function showActivePatients() to display the current count. Use a local block in main() to show how the count changes when an object is destroyed.

#include <iostream>
using namespace std;

class Patient
{
private:
  int patientId;
  string patientName;

  static int activePatients;

public:
  Patient(int id, string name)
  {
    patientId = id;
    patientName = name;
    activePatients++;
  }

  ~Patient()
  {
    activePatients--;
  }

  static void showActivePatients()
  {
    cout << "Active Patients: " << activePatients << endl;
  }
};

// Definition of static data member
int Patient::activePatients = 0;

int main()
{
  Patient p1(101, "Rahul");
  Patient p2(102, "Aman");

  Patient::showActivePatients();

  {
    Patient p3(103, "Rohan");

    Patient::showActivePatients();
  } // p3 is destroyed here

  Patient::showActivePatients();

  return 0;
}