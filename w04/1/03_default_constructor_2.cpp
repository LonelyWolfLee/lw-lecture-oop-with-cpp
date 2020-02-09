
class Sample
{
private:
  int num;

public:
  Sample(int n) : num(n) {} // 이니셜라이저를 변수의 할당으로도 쓸 수 있음
};

int main(int argc, char const *argv[])
{
  Sample sample1; // 디폴드 생성자 사용 불가
  Sample sample2(10);
  return 0;
}
