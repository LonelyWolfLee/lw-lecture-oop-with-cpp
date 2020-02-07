#include <iostream>

class Seller
{
private:
  int price;
  int numOfProduct;
  int balance;

public:
  void InitMembers(int price, int products, int balance);
  int Sell(int numOfProduct);
  void ShowState();
};

class Buyer
{
private:
  int numOfProduct;
  int balance;

public:
  void InitMembers(int price, int products, int balance);
  bool Buy(Seller &seller, int numOfBuyingProduct);
  void ShowState();
};

using namespace std;