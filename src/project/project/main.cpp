#include <iostream>
#include <time/Time.hpp>
#include <smartptr/UniquePtr.cpp>
#include <unistd.h>
#include <time/CustomLiterals.hpp>
#include <soundex/soundex.hpp>
#include <MyList/MyList.cpp>

int main()
{
    //lab1
    // lab1::Time time1;
    // sleep(5);
    // lab1::Time time2;
    // lab1::TimeSpan spaner = time2 - time1;
    // std::cout << time1 << std::endl;
    // std::cout << std::endl;
    // std::cout << time2 << std::endl;
    // std::cout << std::endl;
    // std::cout << spaner << std::endl;
    // lab1::Time time3 = time2 + spaner;
    // std::cout << std::endl;
    // std::cout << time3 << std::endl;
    // lab1::Time time4 = time2 - spaner;
    // std::cout << std::endl;
    // std::cout << time4 << std::endl;
    //lab2
    // lab2::UniquePtr<int> pointer = new int(5);
    // std::cout << pointer.get() << std::endl;
    //lab3
    lab3::soundex sd;
	std::vector<lab3::MyStruct> res;
	auto sarr = sd.readData("names2020.csv",";");
	lab3::MyStruct myStruct;
	for (auto var : sarr)
	{
		myStruct.elems = var;
		myStruct.hash = sd.soundex_hash(var);
		res.push_back(myStruct);
	}
	std::sort(res.begin(), res.end(), [](const lab3::MyStruct& st1, const lab3::MyStruct& st2)
	{
		return st1.hash < st2.hash;
	});
	std::cout << res[0].hash << std::endl;
    MyList<int> list;
	list.push_back(15);
	list.push_back(30);
	list.push_back(45);
	list.push_back(60);
	list.push_back(75);
	list.push_back(90);
	list.push_back(115);
	list.insert(60, 7, 4);
	std::cout << list.check() << std::endl;
    return 0;
}