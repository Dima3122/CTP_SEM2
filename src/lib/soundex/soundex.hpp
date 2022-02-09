#pragma once
#include <cstdint>
#include <string_view>
#include <iostream>
#include <algorithm>
#include <vector>

namespace lab3
{
    struct MyStruct
    {
    	std::string hash;
    	std::string elems;
    };

    class soundex
    {
    private:
    	void removeCharsFromString(std::string& str, const char* charsToRemove);
    	void replaceCharsFromString(std::string& str, const char* charsToReplace, const char number);
    	void splitString(const std::string& fullstr, std::vector<std::string>& elements, const std::string& delimiter);
    public:
    	soundex() = default;
    	~soundex() = default;
    	std::vector<std::string> readData(const std::string& filename, const std::string& csvdelimiter);
    	std::string soundex_hash(std::string_view str);
    };
}