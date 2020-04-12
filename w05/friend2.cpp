#include <iostream>

using namespace std;

class Data;

class DataHandler
{
public:
  void Add(Data &d);
  void Sub(Data &d);
};

class Data
{
private:
  int num;
  friend void DataHandler::Add(Data &d);

public:
  Data(int n) : num(n) {}
  friend void ShowInfo(const Data &d);
};

void DataHandler::Add(Data &d)
{
  // DataHandler 의 함수 Add 는 Data friend 이므로
  // private 정보에 접근이 가능하다.
  cout << "Num = " << d.num << endl;
  d.num++;
}

void DataHandler::Sub(Data &d)
{
  // DataHandler 의 함수 Sub 는 Data friend 가 아니므로
  // private 정보에 접근이 불가능하다.
  // cout << "Num = " << d.num << endl;
  // d.num--;
}

void ShowInfo(const Data &d)
{
  cout << "Num = " << d.num << endl;
}

int main(int argc, char const *argv[])
{
  Data d(100);
  DataHandler handler;
  handler.Add(d);
  ShowInfo(d);
  return 0;
}
