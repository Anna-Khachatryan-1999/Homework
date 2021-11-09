#include "spreadsheet.h"
#include <charconv>

SpreadsheetCell::SpreadsheetCell()
{
    m_value = 0;
}

SpreadsheetCell::SpreadsheetCell(double initialValue) : m_value { initialValue } {}

SpreadsheetCell::SpreadsheetCell(std::string_view initialValue)
{
    setString(initialValue);
}

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src)
    : m_value { src.m_value } {}

SpreadsheetCell::~SpreadsheetCell()
{
    std::cout << "Destructor called." << std::endl;
}

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
    if (this != &rhs) {
        m_value = rhs.m_value;
    }
    return *this;
}

void SpreadsheetCell::setValue(double value)
{
    m_value = value;
}

double SpreadsheetCell::getValue() const
{
    return m_value;
}

void SpreadsheetCell::setString(std::string_view value)
{
    m_value = stringToDouble(value);
}

std::string SpreadsheetCell::getString() const
{
    return doubleToString(m_value);
}

std::string SpreadsheetCell::doubleToString(double value) const
{
    return std::to_string(value);
}

double SpreadsheetCell::stringToDouble(std::string_view value) const
{
    return std::stod(std::string(value));;
}

void SpreadsheetCell::printCell(const SpreadsheetCell& cell)
{
    std::cout << cell.getString() << std::endl;
}
