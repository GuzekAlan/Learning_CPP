#include <iostream>
#include <string>
#include <vector>


void print()
{
    std::cout << std::endl;
}

template<typename T>
void print_literal(T el)
{
    std::cout << el << std::endl;
    //std::cout << sizeof(T) << std::endl;
}

template<typename P1, typename... Param>
void print(P1 first, Param... parameters)
{
    print_literal(first);
    print(parameters...);

}

int main(){

    int a{7};
    print("asdasd", 312,"asdasd",32121, 0.4f);
    
    

    return 0;
}