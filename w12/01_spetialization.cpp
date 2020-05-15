#include <iostream>

using namespace std;

template <typename T>
class Sample 
{
    T value;
    void increase ()
    {
        value += 1;
    }

public : 
    void increaseAndPrint()
    {
        increase();
        cout << value << endl;
    }
};

template <>
class Sample<int>
{
    int value;
    void increase()
    {
        value += 2;
    }

public:
    void increaseAndPrint()
    {
        increase();
        cout << value << endl;
    }
};

template<>
void Sample<float>::increase() 
{
    value += 3;
}

int main(int argc, char const *argv[])
{
    Sample<double> d;
    d.increaseAndPrint();
    
    Sample<int> i;
    i.increaseAndPrint();

    Sample<float> f;
    f.increaseAndPrint();
    return 0;
}
