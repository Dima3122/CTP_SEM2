#include <Time.hpp>
#include <gtest/gtest.h>

TEST(test_Time, operator_subtraction)
{
	lab1::Time time1;
    sleep(5);
    lab1::Time time2;
    lab1::TimeSpan spaner = time1 - time2;
	time_t time = time2.get_now() - time1.get_now();
	ASSERT_EQ(time, spaner.get_timeSpan());
}

TEST(test_Time, operator_sum)
{
	lab1::Time time1;
    sleep(5);
    lab1::Time time2;
	lab1::TimeSpan spaner = time1 - time2;
    lab1::Time time3 = time2 + spaner;
	time_t time = time2.get_now() + spaner.get_timeSpan();
	ASSERT_EQ(time, time3.get_now());
}

TEST(test_Time, operator_subtraction_other)
{
	lab1::Time time1;
    sleep(5);
    lab1::Time time2;
	lab1::TimeSpan spaner = time1 - time2;
    lab1::Time time3 = time2 - spaner;
	time_t time = time2.get_now() - spaner.get_timeSpan();
	ASSERT_EQ(time, time3.get_now());
}