#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <exception>

class ScalarConverter {
public:
    static void convert(const std::string &literal);
    class ConversionException;
    class NonDisplayableException;

private:

    ScalarConverter(); // Hacemos el constructor privado para prevenir la instanciación.
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
	~ScalarConverter();
    static void convertToChar(double value);
    static void convertToInt(double value);
    static void convertToFloat(double value);
    static void convertToDouble(double value);
};

#endif // SCALARCONVERTER_HPP
