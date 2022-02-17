#include "TimeSpan.hpp"

namespace lab1
{
    TimeSpan::TimeSpan()
    {
        timeSpan = 0;
    }
    time_t TimeSpan::get_timeSpan() const
    {
        return timeSpan;
    }
    void TimeSpan::set_timeSpan(time_t time_span)
    {
        this->timeSpan = time_span;
    }
    TimeSpan TimeSpan::operator+(const TimeSpan &other)
    {
        TimeSpan timespan;
        timespan.set_timeSpan(this->get_timeSpan() + other.get_timeSpan());
        return timespan;
    }
    TimeSpan TimeSpan::operator-(const TimeSpan &other)
    {
        TimeSpan timespan;
        timespan.set_timeSpan(this->get_timeSpan() - other.get_timeSpan());
        return timespan;
    }
    std::ostream &operator<<(std::ostream &out, const TimeSpan &TimeSpan)
    {
        tm *ltm = localtime(&TimeSpan.timeSpan);
        out << "Month: " << 1 + ltm->tm_mon - 1 << std::endl;
        out << "Day: " << ltm->tm_mday - 1 << std::endl;
        out << "Time: " << ltm->tm_hour - 7 << ":" << ltm->tm_min << ":" << 1 + ltm->tm_sec;
        return out;
    }
}