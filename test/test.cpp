#include <time/Time.hpp>
#include <gtest/gtest.h>
#include <smartptr/UniquePtr.cpp>
#include <smartptr/SharedPtr.cpp>

TEST(test_Time, operator_subtraction)
{
	lab1::Time time1;
    sleep(1);
    lab1::Time time2;
    lab1::TimeSpan spaner = time1 - time2;
	time_t time = time2.get_now() - time1.get_now();
	ASSERT_EQ(time, spaner.get_timeSpan());
}

TEST(test_Time, operator_sum)
{
	lab1::Time time1;
    sleep(1);
    lab1::Time time2;
	lab1::TimeSpan spaner = time1 - time2;
    lab1::Time time3 = time2 + spaner;
	time_t time = time2.get_now() + spaner.get_timeSpan();
	ASSERT_EQ(time, time3.get_now());
}

TEST(test_Time, operator_subtraction_other)
{
	lab1::Time time1;
    sleep(1);
    lab1::Time time2;
	lab1::TimeSpan spaner = time1 - time2;
    lab1::Time time3 = time2 - spaner;
	time_t time = time2.get_now() - spaner.get_timeSpan();
	ASSERT_EQ(time, time3.get_now());
}

TEST(test_UniquePtr, pointer_get)
{
	lab2::UniquePtr<int> pointer = new int(5);
	ASSERT_EQ(pointer.get(), 5);
}

TEST(test_UniquePtr, point_pointer)
{
	lab2::UniquePtr<int> pointer = new int(5);
	ASSERT_EQ(*pointer, 5);
}

TEST(test_SharedPtr, pointer_get)
{
	lab2::SharedPtr<int> pointer = new int(5);
	ASSERT_EQ(pointer.get(), 5);
}

TEST(test_SharedPtr, point_pointer)
{
	lab2::SharedPtr<int> pointer = new int(5);
	ASSERT_EQ(*pointer, 5);
}