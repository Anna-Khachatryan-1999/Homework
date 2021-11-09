#include <iostream>
#include <string>
#include <string_view>

//export module spreadsheet_cell;

class SpreadsheetCell
{
public:
    SpreadsheetCell();
    SpreadsheetCell(double initialValue);
    SpreadsheetCell(std::string_view initialValue);
    SpreadsheetCell(const SpreadsheetCell& src);
    ~SpreadsheetCell();

public:
    SpreadsheetCell& operator=(const SpreadsheetCell& rhs);

public:
    void setValue(double value);
    double getValue() const;

    void setString(std::string_view value);
    std::string getString() const;
    void printCell(const SpreadsheetCell& cell);

private:
    std::string doubleToString(double value) const;
    double stringToDouble(std::string_view value) const;
    double m_value{0};
};
