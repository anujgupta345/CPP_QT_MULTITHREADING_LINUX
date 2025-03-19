#include <iostream>

template <typename... Args>
void printVariadic(Args... args) {
    ((std::cout << args << " "), ...);
}
//Unary Left Fold
//(expr op ...)
//Applies the operator from left to right.
// Equivalent to:
// ((a op b) op c) op d
// simple words when operation is applied to 2
//the operation is applied to output and 3rd and so on

//Unary Right Fold
// Applies the operator from right to left.
//(...op expr )
// Equivalent to:
// a op (b op (c op d))
//same as left but operation starts from right


// Binary Left Fold

// (expr op ... op init)
// Similar to a unary left fold but with an initial value on the right.
// Equivalent to:
// (((a op b) op c) op d) op init

// Binary Right Fold

// (init op ... op expr)
// Similar to a unary right fold but with an initial value on the left.
// Equivalent to:
// init op (a op (b op c))


template <typename ...T>
int printVal(T...args)
{
    return (args+ ...);
}

template <typename ...T>
int printValRight(T...args)
{
    return (...+args);
}

template <typename ...T>
int printValInit(T...args)
{
    return (args+ ...+100);
}

template <typename ...T>
int printValInitBegDefaultValue(T...args)
{
    return (120+ ...+args);
}

// Variadic function template with perfect forwarding
template <typename... Args>
void forwardToPrint(Args&&... args) {
    print(std::forward<Args>(args)...);  // Forward all arguments
}

template <typename... Args>
void printCout(Args... args) {
    ((std::cout << args), ...);  // when we use , ... we say that we evaluate each argument separately
    //in the left part each argument will go and evaluate then second and so on
    //while in folded expressions value is accumulated and used with next argument either sum or multiple etc
    //another way to expand it is (std::cout << ... << args);  // ✅ Right fold expression only not left fold

}

int main()
{
    std::cout << printVal(1,2,3,4)<<"\n";
    std::cout << printValInit(1,2,3,4) << "\n";
    std::cout << printValInitBegDefaultValue(1,2,3,4) << "\n";
    std::cout << printValRight(1,2,3,10) << "\n";
    printCout(100, 200, 300, 400); std::cout << "\n";
}