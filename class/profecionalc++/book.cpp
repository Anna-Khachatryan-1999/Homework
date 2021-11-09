#include <iostream>

class Book
{
public:
    virtual ~Book() = default;
    virtual std::string getDescription() const { return "Book"; }
    virtual int getHeight() const { return 120; }
};

class Paperback : public Book
{
public:
    std::string getDescription() const override {
        return "Paperback " + Book::getDescription();
    }
};

class Romance : public Paperback
{
public:
    std::string getDescription() const override {
        return "Romance " + Paperback::getDescription();
    }
    int getHeight() const override {
        return Paperback::getHeight() / 2;
    }
};

class Technical : public Book
{
public:
    std::string getDescription() const override {
        return "Technical " + Book::getDescription();
    }
};

int main()
{
    Romance novel;
    Book book;
    std::cout << novel.getDescription() << std::endl;
    std::cout << book.getDescription() << std::endl;
    std::cout << novel.getHeight() << std::endl;
    std::cout << book.getHeight() << std::endl;
}
