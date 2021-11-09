#include "spreadsheet.h"
#include <memory>

int main()
{
    SpreadsheetCell myCell, anotherCell;
    myCell.setValue(6);
    anotherCell.setString("3.2");
    std::cout << "cell 1: " << myCell.getValue() << std::endl;
    std::cout << "cell 2: " << anotherCell.getValue() << std::endl;
    SpreadsheetCell* myCellp { new SpreadsheetCell { } };
    myCellp->setValue(3.7);
    std::cout << "cell 3: " << myCellp->getValue() << " " << myCellp->getString() << std::endl;
    delete myCellp;
    myCellp = nullptr;
    SpreadsheetCell myCell1(5), anotherCell1(4);
    std::cout << "cell 4: " << myCell1.getValue() << std::endl;
    std::cout << "cell 5: " << anotherCell1.getValue() << std::endl;
    SpreadsheetCell aFourthCell { 4.4 };
    auto aFifthCellp {std::make_unique<SpreadsheetCell>("5.5") };
    std::cout << "aFourthCell: " << aFourthCell.getValue() << std::endl;
    std::cout << "aFifthCellp: " << aFifthCellp->getValue() << std::endl;
    SpreadsheetCell cells[3] { SpreadsheetCell { 0 }, SpreadsheetCell { 23 }, SpreadsheetCell { 41 } };
    SpreadsheetCell myCell2 { 4 };
    SpreadsheetCell myCell3 { myCell1 };
    SpreadsheetCell* cellPtr1 { new SpreadsheetCell { 5 } };
    SpreadsheetCell* cellPtr2 { new SpreadsheetCell { 6 } };
    std::cout << "cellPtr1: " << cellPtr1->getValue() << std::endl;
    delete cellPtr1;
    cellPtr1 = nullptr;
    SpreadsheetCell myCell4{ 5 }, anotherCell2;
    anotherCell2 = myCell4;
    SpreadsheetCell myCell5 { 5 };
    std::string s1 = myCell5.getString();
}
