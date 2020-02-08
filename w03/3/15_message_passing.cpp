#include <iostream>

struct TradeResult
{
  int numOfProduct;
  int change;
};

class Seller
{
private:
  int priceOfProduct;
  int numOfProduct;
  int balance;

public:
  void InitMembers(int price, int products);
  TradeResult Sell(int money);
  void ShowState();
};

class Buyer
{
private:
  int numOfProduct;
  int balance;

public:
  void InitMembers(int money);
  void Buy(Seller &seller, int money);
  void ShowState();
};

using namespace std;

void Seller::InitMembers(int price, int products)
{
  priceOfProduct = price;
  numOfProduct = products;
}

TradeResult Seller::Sell(int money)
{
  int numOfSelling = money / priceOfProduct;
  if (numOfSelling > numOfProduct)
    numOfSelling = numOfProduct;

  int totalPrice = numOfSelling * priceOfProduct;
  balance += totalPrice;
  numOfProduct -= numOfSelling;

  return {numOfSelling, money - totalPrice};
}

void Seller::ShowState()
{
  cout << "총 매출액 : " << balance << endl;
  cout << "남은 재고 : " << numOfProduct << endl;
}

void Buyer::InitMembers(int money)
{
  numOfProduct = 0;
  balance = money;
}
void Buyer::Buy(Seller &seller, int money)
{
  if (money > balance)
  {
    cout << "구매 실패 : 잔액 부족" << endl;
    return;
  }
  TradeResult result = seller.Sell(money);
  numOfProduct += result.numOfProduct;
  balance -= money - result.change;
  if (result.numOfProduct <= 0)
  {
    cout << "구매 실패" << endl;
    return;
  }
  cout << "구매 성공" << endl;
}
void Buyer::ShowState()
{
  cout << "남은 잔고 : " << balance << endl;
  cout << "총 구매수 : " << numOfProduct << endl;
}

int main(int argc, char const *argv[])
{
  Seller seller;
  seller.InitMembers(100, 20);
  Buyer buyer;
  buyer.InitMembers(500);

  seller.ShowState();
  buyer.ShowState();

  buyer.Buy(seller, 600);
  buyer.Buy(seller, 450);

  seller.ShowState();
  buyer.ShowState();

  return 0;
}
