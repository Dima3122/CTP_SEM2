#pragma once
#include <ctime>
#include <ostream>
#include "TimeSpan.hpp"

namespace lab1
{
    class Time
    {
    private:
        time_t now;//in seconds    
    public:
        Time();
        ~Time() = default;

        time_t get_now();
        void set_now(time_t now);

        friend std::ostream& operator <<(std::ostream& out, const Time& Time);
        
        Time operator +(const TimeSpan& other);
        Time operator -(const TimeSpan& other);
        TimeSpan operator -(const Time& other);

    };
    std::ostream& operator <<(std::ostream& out, const Time& Time);
}