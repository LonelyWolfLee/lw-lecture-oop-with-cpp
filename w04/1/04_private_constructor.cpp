class Sample
{
private:
  int num;
  Sample() : num(0) {}

public:
  Sample(int n) : num(n) {}
};

int main(int argc, char const *argv[])
{
  // Sample sample1; // 기본 생성자를 명시적으로 막음
  Sample sample2(10);
  return 0;
}
