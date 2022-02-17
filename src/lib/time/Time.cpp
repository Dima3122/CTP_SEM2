#include "Time.hpp"

namespace lab1
{
    Time::Time()
    {
        //получаем время сейчас
        now = time(NULL);
    }

    time_t Time::get_now()
    {
        return now;
    }

    TimeSpan Time::operator-(const Time &other)
    {
        TimeSpan span;
        span.set_timeSpan(other.now - this->now);
        return span;
    }

    void Time::set_now(time_t now)
    {
        this->now = now;
    }

    Time Time::operator-(const TimeSpan &other)
    {
        Time time;
        time.set_now(this->get_now() - other.get_timeSpan());
        return time;
    }

    Time Time::operator+(const TimeSpan &other)
    {
        Time time;
        time.set_now(this->get_now() + other.get_timeSpan());
        return time;
    }
    
    std::ostream &operator<<(std::ostream &out, const Time &Time)
    {
        tm *ltm = localtime(&Time.now);
        out << "Month: " << 1 + ltm->tm_mon << std::endl;
        out << "Day: " << ltm->tm_mday << std::endl;
        out << "Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << 1 + ltm->tm_sec;
        return out;
    }
}