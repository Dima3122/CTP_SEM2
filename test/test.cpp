#include <time/Time.hpp>
#include <gtest/gtest.h>
#include <smartptr/UniquePtr.cpp>
#include <smartptr/SharedPtr.cpp>
#include <soundex/soundex.hpp>
#include <MyList/MyList.cpp>
#include <CourseWork/MyVector.cpp>
#include <vector>
#include <string>

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

TEST(test_soundex, readData)
{
	lab3::soundex sd;
	std::string str = sd.soundex_hash("hfasdsahjtq");
	ASSERT_EQ(str, "h232");
}

TEST(test_MyList, test_list)
{
	lab4::MyList<int> list;
	list.push_back(15);
	list.push_back(30);
	list.push_back(45);
	list.push_back(60);
	list.push_back(75);
	list.push_back(90);
	list.push_back(115);
	list.insert(60, 7, 4);
	ASSERT_EQ(list.check(), true);
}

TEST(test_MyVector, test_MyVector_pushBack)
{
	MyVector::MyVector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.pushBack(i);
	}
	ASSERT_EQ(vec.size(), 10);
}

TEST(test_MyVector, test_MyVector_remove)
{
	MyVector::MyVector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.pushBack(i);
	}
	for (int i = 0; i < 5; i++)
	{
		vec.remove(0);
	}
	
	ASSERT_EQ(vec.size(), 5);
}

TEST(test_MyVector, test_MyVector_popBack)
{
	MyVector::MyVector<int> vec;
	for (int i = 0; i < 10; i++)
	{
		vec.pushBack(i);
	}
	for (int i = 0; i < 5; i++)
	{
		vec.pop_back();
	}
	
	ASSERT_EQ(vec.size(), 5);
}