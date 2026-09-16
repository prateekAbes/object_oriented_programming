// Create a Product class with productId, name, and price as data members.Use a parameterized constructor to initialize the object.Write a function comparePrice() that takes another Product object as a const reference parameter and returns the Product object with the higher price.Display the details of the returned object.

#include <iostream>
using namespace std;

class Product
{
public:
  int productId;
  string name;
  int price;

  Product(int id, string name, int price)
  {

    this->productId = id;
    this->name = name;
    this->price = price;
  }

  Product comparePrice(const Product &p2)
  {
    if (this->price > p2.price)
      return *this;
    else
      return p2;
  }
};

int main()
{
  Product p1(12, "Dark Chocolate", 100);
  Product p2(13, "Milk Chocolate", 80);
  Product p = p1.comparePrice(p2);

  cout << p.name << ": " << p.price;

  return 0;
}
