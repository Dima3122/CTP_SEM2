#include <iostream>
#include <unistd.h>
#include <smartptr/UniquePtr.cpp>
#include <smartptr/SharedPtr.cpp>
#include <time/Time.hpp>
#include <time/CustomLiterals.hpp>
#include <soundex/soundex.hpp>
#include <MyList/MyList.cpp>
#include <CourseWork/MyVector.cpp>

struct MyStruct
{
    std::string hash;
    std::string elems;
};

int main()
{
    // lab1
    lab1::Time time1;
    sleep(5);
    lab1::Time time2;
    lab1::TimeSpan spaner = time2 - time1;
    std::cout << time1 << std::endl;
    std::cout << std::endl;
    std::cout << time2 << std::endl;
    std::cout << std::endl;
    std::cout << spaner << std::endl;
    lab1::Time time3 = time2 + spaner;
    std::cout << std::endl;
    std::cout << time3 << std::endl;
    lab1::Time time4 = time2 - spaner;
    std::cout << std::endl;
    std::cout << time4 << std::endl;
    // lab2
    //  lab2::UniquePtr<int> pointer = new int(5);
    //  std::cout << pointer.get() << std::endl;
    //  lab2::SharedPtr<int> piont = new int(5);
    //  std::cout << piont.get() << std::endl;
    //  lab2::SharedPtr<double> p(new double(5.4));
    // lab3
    lab3::soundex sd;
    std::vector<MyStruct> res;
    auto sarr = sd.readData("names2020.csv", ";");
    MyStruct myStruct;
    for (auto var : sarr)
    {
        myStruct.elems = var;
        myStruct.hash = sd.soundex_hash(var);
        res.push_back(myStruct);
    }
    std::sort(res.begin(), res.end(), [](const MyStruct &st1, const MyStruct &st2)
              { return st1.hash < st2.hash; });
    std::cout << res[0].hash << std::endl;
    // lab4::MyList<int> list;
    // list.push_back(15);
    //  list.push_back(30);
    //  list.push_back(45);
    //  list.push_back(60);
    //  list.push_back(75);
    //  list.push_back(90);
    //  list.push_back(115);
    //  list.insert(60, 7, 4);
    //  std::cout << list.check() << std::endl;
    MyVector::MyVector<int> vec;
    vec.pushBack(521);
    return 0;
}