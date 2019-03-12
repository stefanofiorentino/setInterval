#include <iostream>

#include "core/set_interval.hpp"

int main()
{
    setInterval([]()
                {
                    std::cout << "print" << std::endl;
                }, std::chrono::seconds(3));
    std::cout << "Hello, World!" << std::endl;
    return 0;
}