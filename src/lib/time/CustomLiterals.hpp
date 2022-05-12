#include <ctime>
#include <ostream>
#include "Time.hpp"

namespace lab1::literals
{
    TimeSpan operator"" _D(unsigned long long day)
    {
        TimeSpan span;
        span.set_timeSpan(day * 24 * 60 * 60);
        return span;
    }

    TimeSpan operator"" _H(unsigned long long hour)
    {
        TimeSpan span;
        span.set_timeSpan(hour * 60 * 60);
        return span;
    }

    TimeSpan operator"" _M(unsigned long long minute)
    {
        TimeSpan span;
        span.set_timeSpan(minute * 60);
        return span;
    }

    TimeSpan operator"" _S(unsigned long long second) 
    { 
        TimeSpan span;
        span.set_timeSpan(second);
        return span; 
    }
}