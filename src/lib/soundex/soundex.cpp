#include "soundex.hpp"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <cstring>

namespace lab3
{
    void soundex::removeCharsFromString(std::string& str, const char* charsToRemove)
    {
    	for (unsigned int i = 0; i < strlen(charsToRemove); ++i) 
    	{
    		str.erase(std::remove(str.begin(), str.end(), charsToRemove[i]), str.end());
    	}
    }

    void soundex::replaceCharsFromString(std::string& str, const char* charsToReplace, const char number)
    {
    	for (unsigned int i = 0; i < strlen(charsToReplace); ++i)
    	{
    		std::replace(str.begin(),str.end(), charsToReplace[i], number);
    	}
    }

    void soundex::splitString(const std::string& fullstr, std::vector<std::string>& elements, const std::string& delimiter)
    {
    	std::string::size_type lastpos = fullstr.find_first_not_of(delimiter, 0);
    	std::string::size_type pos = fullstr.find_first_of(delimiter, lastpos);
    	while ((std::string::npos != pos) || (std::string::npos != lastpos)) 
    	{
    		elements.push_back(fullstr.substr(lastpos, pos - lastpos));
    		lastpos = fullstr.find_first_not_of(delimiter, pos);
    		pos = fullstr.find_first_of(delimiter, lastpos);
    	}
    }

    std::vector<std::string> soundex::readData(const std::string& filename, const std::string& csvdelimiter)
    {
    	std::vector<std::string> sarr;
    	std::ifstream fin(filename.c_str());
    	std::string s;
    	std::vector<std::string> selements;
    	while (!fin.eof()) 
    	{
    		std::getline(fin, s);
    		if (!s.empty()) 
    		{
    			splitString(s, selements, csvdelimiter);
    			for (size_t i = 0; i < selements.size(); i++) 
    			{
    				removeCharsFromString(selements[i], ",");
    				sarr.push_back(selements[i]);
    			}
    			selements.clear();
    		}
    	}
    	fin.close();
    	return sarr;
    }

    std::string soundex::soundex_hash(std::string string)
    {
    	std::string res;
    	if (string.empty())
    	{
            std::cout << "Строка пустая" << std::endl;
        }
        else
        {
    		char fisrt = string[0];
    		removeCharsFromString(string, "hwaeiouy");
    		replaceCharsFromString(string, "bfpv", '1');
    		replaceCharsFromString(string, "cgjkqsxz", '2');
    		replaceCharsFromString(string, "dt", '3');
    		replaceCharsFromString(string, "bfpv", '4');
    		replaceCharsFromString(string, "bfpv", '5');
    		replaceCharsFromString(string, "bfpv", '6');
    		string.erase(std::unique(string.begin(), string.end()), string.end());
    		res.push_back(fisrt);
    		for (size_t i = 1; i < 4; i++)
    		{
    			if (string.size() > i)
    			{
    				res.push_back(string[i]);
    			}
    			else
    			{
    				res.push_back('0');	
    			}
    		}
        }
    	return res;
    }
}