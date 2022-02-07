#include <ctime>
#include <ostream>
#include "Time.hpp"

namespace lab1::literals
{
    int operator"" _D(long double n)
    {
        time_t time = (time_t)n;
        tm *ltm = localtime(&time);
        return ltm->tm_mday;
    }
    int operator""_H(long double n)
    {
        time_t time = (time_t)n;
        tm *ltm = localtime(&time);
        return ltm->tm_hour;
    }
    int operator"" _M(long double n)
    {
        time_t time = (time_t)n;
        tm *ltm = localtime(&time);
        return ltm->tm_min;
    }
    int operator"" _S(long double n)
    {
        time_t time = (time_t)n;
        tm *ltm = localtime(&time);
        return ltm->tm_sec;
    }
}