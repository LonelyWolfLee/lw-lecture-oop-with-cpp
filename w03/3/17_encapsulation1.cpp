#include <iostream>
using namespace std;

class SnivelCap // 콧물 처치용 캡슐
{
public:
  void Take() const { cout << "콧물이 싹~ 납니다." << endl; }
};

class SnuffleCap // 코막힘 처치용 캡슐
{
public:
  void Take() const { cout << "코가 뻥 뚫립니다." << endl; }
};

class SneezeCap // 재채기 처치용 캡슐
{
public:
  void Take() const { cout << "재채기가 멎습니다." << endl; }
};

class ColdPatient
{
public:
  void TakeSnivelCap(const SnivelCap &cap) const { cap.Take(); }
  void TakeSnuffleCap(const SnuffleCap &cap) const { cap.Take(); }
  void TakeSneezeCap(const SneezeCap &cap) const { cap.Take(); }
};

int main(void)
{
  SnivelCap vcap;
  SnuffleCap fcap;
  SneezeCap zcap;

  ColdPatient sufferer;
  sufferer.TakeSnivelCap(vcap);
  sufferer.TakeSnuffleCap(fcap);
  sufferer.TakeSneezeCap(zcap);
  return 0;
}