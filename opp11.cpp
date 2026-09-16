// Create a BankAccount class with private data members accountNumber, customerName, and balance. Initialize the values using a constructor. Write a friend function compareBalance() that accepts two BankAccount objects and displays the account holder with the higher balance. The function should not modify either object.

#include <iostream>
using namespace std;

class BankAccount
{
private:
  int accountNumber;
  string customerName;
  double balance;

public:
  BankAccount(int accNo, string name, double bal)
  {
    accountNumber = accNo;
    customerName = name;
    balance = bal;
  }

  friend void compareBalance(const BankAccount &a1, const BankAccount &a2);
};

void compareBalance(const BankAccount &a1, const BankAccount &a2)
{
  if (a1.balance > a2.balance)
  {
    cout << "Account holder with higher balance: "
         << a1.customerName << endl;
    cout << "Balance: " << a1.balance << endl;
  }
  else if (a2.balance > a1.balance)
  {
    cout << "Account holder with higher balance: "
         << a2.customerName << endl;
    cout << "Balance: " << a2.balance << endl;
  }
  else
  {
    cout << "Both accounts have the same balance." << endl;
  }
}

int main()
{
  BankAccount a1(101, "Rahul", 50000);
  BankAccount a2(102, "Aman", 75000);

  compareBalance(a1, a2);

  return 0;
}