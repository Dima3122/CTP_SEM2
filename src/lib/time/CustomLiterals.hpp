#include <ctime>
#include <ostream>
#include "Time.hpp"

namespace lab1::literals
{
    int operator"" _D(unsigned long long day) {
    int inSeconds;
    inSeconds = day * 24 * 60 * 60;
    return inSeconds;
}

int operator"" _H(unsigned long long hour) {
    int inSeconds;
    inSeconds = hour * 60 * 60;
    return inSeconds;
}

int operator"" _M(unsigned long long minute) {
    int inSeconds;
    inSeconds = minute * 60;
    return inSeconds;
}

int operator"" _S(unsigned long long second) { return second; }
}