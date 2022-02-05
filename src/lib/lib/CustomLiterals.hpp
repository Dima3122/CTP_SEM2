#include <ctime>
#include <ostream>

namespace lab1::literals
{
    int operator"" _d(Time Time)
    {
        tm *ltm = localtime(&Time.now);
        return ltm->tm_mday;
    }
    int operator"" _h(Time Time)
    {
        tm *ltm = localtime(&Time.now);
        return ltm->tm_hour;
    }
    int operator"" _m(Time Time)
    {
        tm *ltm = localtime(&Time.now);
        return ltm->tm_min;
    }
    int operator"" _s(Time Time)
    {
        tm *ltm = localtime(&Time.now);
        return ltm->tm_sec;
    }
}