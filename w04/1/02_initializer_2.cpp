
struct TradeResult
{
  int numOfProduct;
  int change;
};

class Seller
{
private:
  const int priceOfProduct;
  int numOfProduct;
  int balance;

public:
  // good
  Seller(int price, int products) : priceOfProduct(price)
  {
    numOfProduct = products;
  }
  TradeResult Sell(int money);
  void ShowState();
};

class Point
{
private:
  int x;
  int y;

public:
  Point(int xpos, int ypos);
};

class Rectangle
{
private:
  Point upLeft;
  Point lowRight;

public:
  Rectangle(int ulx, int uly, int lrx, int lry);
};

// 이니셜라이저는 선언이 아니라 정의에 있어야 한다.
Rectangle::Rectangle(int ulx, int uly, int lrx, int lry)
    : upLeft(ulx, uly), lowRight(lrx, lry)
{
}

int main(int argc, char const *argv[])
{
  Ractangle(1, 2, 3, 4);
  return 0;
}
