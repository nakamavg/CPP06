#include "ScalarConverter.hpp"

class ScalarConverter::ConversionException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "impossible";
        }
    };
class ScalarConverter::NonDisplayableException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Non displayable";
        }
    };

ScalarConverter::ScalarConverter() {
}

ScalarConverter::~ScalarConverter() {
}

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string &literal) {
    double value;
    try {
        value = std::stod(literal);
    } catch (const std::invalid_argument &) {
        std::cerr << "char: impossible" << std::endl;
        std::cerr << "int: impossible" << std::endl;
        std::cerr << "float: impossible" << std::endl;
        std::cerr << "double: impossible" << std::endl;
        return;
    } catch (const std::out_of_range &) {
        std::cerr << "char: impossible" << std::endl;
        std::cerr << "int: impossible" << std::endl;
        std::cerr << "float: impossible" << std::endl;
        std::cerr << "double: impossible" << std::endl;
        return;
    }

    try {
        convertToChar(value);
    } catch (const std::exception &e) {
        std::cerr << "char: " << e.what() << std::endl;
    }

    try {
        convertToInt(value);
    } catch (const std::exception &e) {
        std::cerr << "int: " << e.what() << std::endl;
    }

    try {
        convertToFloat(value);
    } catch (const std::exception &e) {
        std::cerr << "float: " << e.what() << std::endl;
    }

    try {
        convertToDouble(value);
    } catch (const std::exception &e) {
        std::cerr << "double: " << e.what() << std::endl;
    }
}

void ScalarConverter::convertToChar(double value) {
    if (std::isnan(value) || value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max()) {
        throw ConversionException();
    }
    char c = static_cast<char>(value);
    if (!std::isprint(c)) {
        throw NonDisplayableException();
    }
    std::cout << "char: '" << c << "'" << std::endl;
}

void ScalarConverter::convertToInt(double value) {
    if (std::isnan(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        throw ConversionException();
    }
    std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::convertToFloat(double value) {
    if (std::isnan(value)) {
        std::cout << "float: nanf" << std::endl;
    } else if (value == std::numeric_limits<double>::infinity()) {
        std::cout << "float: +inff" << std::endl;
    } else if (value == -std::numeric_limits<double>::infinity()) {
        std::cout << "float: -inff" << std::endl;
    } else if (value < -std::numeric_limits<float>::max() || value > std::numeric_limits<float>::max()) {
        throw ConversionException();
    } else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    }
}

void ScalarConverter::convertToDouble(double value) {
    if (std::isnan(value)) {
        std::cout << "double: nan" << std::endl;
    } else if (value == std::numeric_limits<double>::infinity()) {
        std::cout << "double: +inf" << std::endl;
    } else if (value == -std::numeric_limits<double>::infinity()) {
        std::cout << "double: -inf" << std::endl;
    } else if (value < -std::numeric_limits<double>::max() || value > std::numeric_limits<double>::max()) {
        throw ConversionException();
    } else {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << value << std::endl;
    }
}
