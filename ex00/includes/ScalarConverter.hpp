#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cerrno>
#include <iomanip>
#include <cmath>
class ScalarConverter
{
private:
    ScalarConverter();
    ~ScalarConverter();

public:
    static void convertToChar(const char *str);
    static void convertToInt(const char *str);
    static void convertToFloat(const char *str);
    static void convertToDouble(const char *str);
    static void convert(std::string str);
};
