
struct TradeResult
{
  int numOfProduct;
  int change;
};

class Seller
{
private:
  // 물건값은 변하지 않는데 const로 하면 안되나?
  const int priceOfProduct;
  int numOfProduct;
  int balance;

public:
  Seller(int price, int products)
  {
    // 생성자가 호출 된 시점에 멤버변수가 선언되어 수정 불가!
    priceOfProduct = price;
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
  // 좌표 값을 받아서 Point를 초기화 하고 싶은데 대체 어떻게 해야 하지?
  // Point(ulx, uly) 와 같이 호출해야 하는데..
  Rectangle(int ulx, int uly, int lrx, int lry);
};

int main(int argc, char const *argv[])
{
  Ractangle(1, 2, 3, 4);
  return 0;
}
