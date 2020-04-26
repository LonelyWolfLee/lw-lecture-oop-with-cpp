#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "a_comp.cpp"
#include "b_comp.cpp"

using namespace std;
using namespace AComp;
// using namespace BComp;

namespace MyNameSpace
{
int age = 20;
}

namespace BCar = BComp::Car;

int main(int argc, char const *argv[])
{
    bool isOk = true;

    // 특정 범위(scope)에 속한 변수를 만들고 사용 할 수 있다.
    std::cout << "Hi " << MyNameSpace::age << std::endl;

    // 여러 의존성 간의 충돌을 방지 할 수 있다. (namespace + 범위 연산자(::) + 사용 함수/변수)

    // Nested(중첩) 선언이 가능하다.
    BComp::People::GetImportantNum();

    // 별칭을 생성 할 수 있다.
    namespace BCar = BComp::Car;

    // using을 사용해서 namespace 기술을 생략 할 수 있다 (꼭 필요한 경우만 사용 할 것)
    using namespace std;
    using namespace AComp;
    cout << "Very important number is " << GetImportantNum() << endl;

    return 0;
}
