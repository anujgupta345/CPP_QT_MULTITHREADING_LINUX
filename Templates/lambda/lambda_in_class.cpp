#include <iostream>
#include <functional>
class LambdaTester
{
    public:
    std::function<int(void)> testLambda();
    LambdaTester();
    private: int someVar1;
};
int main()
{
    LambdaTester tester;
   // std::cout << tester.testLambda();
    return 0;
}

std::function<int(void)> LambdaTester::testLambda()
{
    return [this](){
        return someVar1;
    };
}
/*
* [] => this wont pass
* [this] => this wont pass
* [] => this wont pass
*/
LambdaTester::LambdaTester():someVar1(1)
{
}
