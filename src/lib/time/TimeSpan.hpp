#pragma once
#include <ctime>
#include <ostream>

namespace lab1
{
    class TimeSpan
    {
    private:
        time_t timeSpan;

    public:
        TimeSpan();
        // TimeSpan(Time Start, Time The_End);
        ~TimeSpan() = default;

        time_t get_timeSpan() const;
        void set_timeSpan(time_t time_span);

        TimeSpan operator+(const TimeSpan &other);
        TimeSpan operator-(const TimeSpan &other);

        friend std::ostream &operator<<(std::ostream &out, const TimeSpan &Time);
    };
    std::ostream &operator<<(std::ostream &out, const TimeSpan &Time);
}