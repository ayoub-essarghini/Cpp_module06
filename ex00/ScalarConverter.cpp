#include "includes/ScalarConverter.hpp"

void ScalarConverter::convert(std::string str)
{
    const char *str2 = str.c_str();
    while (*str2 && std::isspace(*str2))
        str2++;
    convertToChar(str2);
    convertToInt(str2);
    convertToFloat(str2);
    convertToDouble(str2);
}

ScalarConverter::ScalarConverter(){}
ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convertToChar(const char *str)
{
    std::stringstream ss(str);
    int val;

    if (ss >> val)
    {
        if (val >= 32 && val <= 126)
            std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
        else
            std::cerr << "char: Non displayable" << std::endl;
    }
    else
        std::cerr << "char: impossible" << std::endl;
}

void ScalarConverter::convertToInt(const char *str)
{

    char *endPtr;
    errno = 0;
    long val = std::strtol(str, &endPtr, 10);
    if (errno == ERANGE || endPtr == str || val > INT_MAX || val < INT_MIN)
        std::cerr << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(val) << std::endl;
}

void ScalarConverter::convertToFloat(const char *str)
{
    char *endPtr;
    errno = 0;
    float val = std::strtof(str, &endPtr);

    if (endPtr == str || errno == ERANGE)
    {
        std::cerr << "float: impossible" << std::endl;
        return;
    }
    if (std::isnan(val))
    {
        std::cerr << "float: nanf" << std::endl;
        return;
    }
    std::cout << "float: " << std::fixed << std::setprecision(1) << val << "f" << std::endl;

}

void ScalarConverter::convertToDouble(const char *str)
{
    char *endPtr;
    errno = 0;  
    double val = std::strtod(str, &endPtr);

    if (endPtr == str || errno == ERANGE) {
        std::cerr << "double: impossible" << std::endl;
        return;
    }
    if (std::isnan(val)) {
        std::cerr << "double: nan" << std::endl;
        return;
    }
    std::cout << "double: " << val << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}
