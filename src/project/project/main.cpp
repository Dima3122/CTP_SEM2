#include <iostream>
#include <time/Time.hpp>
#include <smartptr/UniquePtr.cpp>
#include <unistd.h>

int main()
{
    // lab1::Time time1;
    // sleep(5);
    // lab1::Time time2;
    // lab1::TimeSpan spaner = time2 - time1;
    // std::cout << time1 << std::endl;
    // std::cout << std::endl;
    // std::cout << time2 << std::endl;
    // std::cout << std::endl;
    // std::cout << spaner << std::endl;
    // lab1::Time time3 = time2 + spaner;
    // std::cout << std::endl;
    // std::cout << time3 << std::endl;
    // lab1::Time time4 = time2 - spaner;
    // std::cout << std::endl;
    // std::cout << time4 << std::endl;
    // std::cout << std::endl;
    // std::cout << time4 << std::endl;
    lab2::UniquePtr<int> pointer = new int(5);
    std::cout << pointer.get() << std::endl;
    return 0;
}