#include <iostream>
#include <string>
#include<string_view>
#include <charconv>
#include <memory>
//#include <format>



class SpreadsheetCell
{
public:
    SpreadsheetCell() {
        std::cout << "ctor" << std::endl;
    };
    explicit SpreadsheetCell(double initialValue);
    SpreadsheetCell(std::string_view initialValue);
    SpreadsheetCell(const SpreadsheetCell& src);
    SpreadsheetCell& operator=(const SpreadsheetCell& rhs);
    ~SpreadsheetCell() {
        std::cout << "dtor" << std::endl;
    }

public:
    void setValue(double value) {
        m_value = value;
    }
    double getValue() const {
        return m_value;
    }
public:
    void setString(std::string_view value);
    std::string getString() const;
private:
    std::string doubleToString(double value) const;
    double stringToDouble(std::string_view value) const;
private:
    double m_value{0};
};

SpreadsheetCell::SpreadsheetCell(double initialValue)
{
        std::cout << "double ctor" << std::endl;
    setValue(initialValue);
}

SpreadsheetCell::SpreadsheetCell(const SpreadsheetCell& src)
{
    std::cout << "copy ctor" << std::endl;
    m_value = src.m_value;
}

SpreadsheetCell& SpreadsheetCell::operator=(const SpreadsheetCell& rhs)
{
    if(this != &rhs)
    {
        m_value = rhs.m_value;
    }
    std::cout << "assignment operator" << std::endl;
    return *this;
}
/*SpreadsheetCell::SpreadsheetCell(std::string_view initialValue)
: SpreadsheetCell { stringToDouble(initialValue) }
{
    std::cout << "ahaha" << std::endl;
}*/
SpreadsheetCell::SpreadsheetCell(std::string_view initialValue)
{
    setString(initialValue);
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
    /*double number { 0 };
    std::from_chars(value.data(), value.data() + value.size(), number);
   */
    double number = std::stod(std::string(value));
    return number;
}


class Spreadsheet
{
public:
    Spreadsheet(size_t width, size_t height);
    Spreadsheet(const Spreadsheet& src);
    Spreadsheet& operator=(const Spreadsheet& rhs);
    void swap(Spreadsheet& other) noexcept;
    ~Spreadsheet();
public:
    void setCellAt(size_t x, size_t y, const SpreadsheetCell& cell);
    SpreadsheetCell& getCellAt(size_t x, size_t y);
    void verifyCoordinate(size_t x, size_t y) const;
private:
    bool inRange(size_t value, size_t upper) const;
    size_t m_width { 0 };
    size_t m_height { 0 };
    SpreadsheetCell** m_cells { nullptr };
};

Spreadsheet::Spreadsheet(size_t width, size_t height)
                        : m_width { width }, m_height { height }
{
    m_cells = new SpreadsheetCell*[m_width];
    for (size_t i { 0 }; i < m_width; i++) {
        m_cells[i] = new SpreadsheetCell[m_height];
    }
}

Spreadsheet::Spreadsheet(const Spreadsheet& src)
                        : Spreadsheet { src.m_width, src.m_height }
{
    for (size_t i { 0 }; i < m_width; i++) {
        for (size_t j { 0 }; j < m_height; j++) {
            m_cells[i][j] = src.m_cells[i][j];
        }
    }
}

void Spreadsheet::swap(Spreadsheet& other) noexcept
{
    std::swap(m_width, other.m_width);
    std::swap(m_height, other.m_height);
    std::swap(m_cells, other.m_cells);
}

Spreadsheet& Spreadsheet::operator=(const Spreadsheet& rhs)
{
   /* // Check for self-assignment
    if (this == &rhs) {
        return *this;
    }
    // Free the old memory
    for (size_t i { 0 }; i < m_width; i++) {
        delete[] m_cells[i];
    }
    delete[] m_cells;
    m_cells = nullptr;
    // Allocate new memory
    m_width = rhs.m_width;
    m_height = rhs.m_height;
    m_cells = new SpreadsheetCell*[m_width];
    for (size_t i { 0 }; i < m_width; i++) {
        m_cells[i] = new SpreadsheetCell[m_height];
    }
    // Copy the data
    for (size_t i { 0 }; i < m_width; i++) {
        for (size_t j { 0 }; j < m_height; j++) {
            m_cells[i][j] = rhs.m_cells[i][j];
        }
    }
    return *this;*/
    Spreadsheet temp { rhs }; // Do all the work in a temporary instance
    swap(temp);
    // Commit the work with only non-throwing operations
    return *this;
}


Spreadsheet::~Spreadsheet()
{
    for (size_t i { 0 }; i < m_width; i++) {
        delete [] m_cells[i];
    }
    delete [] m_cells;
    m_cells = nullptr;
}
/*void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
    if (!inRange(x, m_width)) {
        //throw std::out_of_range { std::format("{} must be less than {}.", x, m_width) };
    }
    if (!inRange(y, m_height)) {
        //throw std::out_of_range { std::format("{} must be less than {}.", y, m_height) };
    }
    m_cells[x][y] = cell;
}

SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
    if (!inRange(x, m_width)) {
        //throw std::out_of_range { std::format("{} must be less than {}.", x, m_width) };
    }
    if (!inRange(y, m_height)) {
        //throw std::out_of_range { std::format("{} must be less than {}.", y, m_height) };
    }
    return m_cells[x][y];
}
*/
void Spreadsheet::verifyCoordinate(size_t x, size_t y) const
{
    if (x >= m_width) {
        //throw std::out_of_range { std::format("{} must be less than {}.", x, m_width) };
    }
    if (y >= m_height) {
        //throw std::out_of_range { std::format("{} must be less than {}.", y, m_height) };
    }
}
void Spreadsheet::setCellAt(size_t x, size_t y, const SpreadsheetCell& cell)
{
    verifyCoordinate(x, y);
    m_cells[x][y] = cell;
}

SpreadsheetCell& Spreadsheet::getCellAt(size_t x, size_t y)
{
    verifyCoordinate(x, y);
    return m_cells[x][y];
}


int main()
{
   /* SpreadsheetCell myCell, anotherCell;
    myCell.setValue(6);
    anotherCell.setString("3.2");
    std::cout << "cell 1: " << myCell.getValue() << std::endl;
    std::cout << "cell 2: " << anotherCell.getValue() << std::endl;
    SpreadsheetCell* myCellp { new SpreadsheetCell { } };
    myCellp->setValue(3.7);
    std::cout << "cell 1: " << myCellp->getValue() << " " << myCellp->getString() << std::endl;
    delete myCellp;
    myCellp = nullptr;
    auto myCellp1 { std::make_unique<SpreadsheetCell>() };
    // Equivalent to:
    // unique_ptr<SpreadsheetCell> myCellp { new SpreadsheetCell { } };
    myCellp1->setValue(3.7);
    std::cout << "cell 1: " << myCellp1->getValue() << " " << myCellp1->getString() << std::endl;
    SpreadsheetCell myCell2 { 5 }, anotherCell2 { 4 };
    auto smartCellp1 { std::make_unique<SpreadsheetCell>(4) };
    // ... do something with the cell, no need to delete the smart pointer
    // Or with raw pointers, without smart pointers (not recommended)
    SpreadsheetCell* myCellp2 { new SpreadsheetCell { 5 } };
    // Or
    // SpreadsheetCell* myCellp{ new SpreadsheetCell(5) };
    SpreadsheetCell* anotherCellp1 { nullptr };
    anotherCellp1 = new SpreadsheetCell { 4 };
    // ... do something with the cells
    delete myCellp2;
    myCellp2 = nullptr;
    delete anotherCellp1;
    anotherCellp1 = nullptr;
    SpreadsheetCell cells3[3]; // FAILS compilation without default constructor
    SpreadsheetCell* myCellp7 { new SpreadsheetCell[10] }; // Also FAILS
    //SpreadsheetCell myCell();
    //myCell.setValue(6);
    SpreadsheetCell myCell11 { }; // Calls the default constructor.
    myCell11.setValue(6);
    std::string_view s ={"12"};
    SpreadsheetCell m(s);
    std::cout << m.getValue() << std::endl;
    SpreadsheetCell* cellPtr1 { new SpreadsheetCell { 5 } };
    SpreadsheetCell* cellPtr2 { new SpreadsheetCell { 6 } };
    std::cout << "cellPtr1: " << cellPtr1->getValue() << std::endl;
    delete cellPtr1; // Destroys cellPtr1
    cellPtr1 = nullptr;
    // cellPtr2 is NOT destroyed because delete was not called on it.
    myCell = myCell2;
    myCell = myCell;*/
    SpreadsheetCell news;
    news.getString();

}
