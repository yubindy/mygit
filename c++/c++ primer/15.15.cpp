#include <iostream>
#include <memory>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <fstream>
#include <alloca.h>
#include <sstream>
#include <algorithm>
using namespace std;
class Quote
{
private:
    string bookNo;

public:
    Quote() = default;
    Quote(const string &book, double sales_price)
        : bookNo(book), price(sales_price) {}
    string isbn() const { return bookNo; }
    virtual ~Quote() = default;
    virtual double net_price(size_t n) const { return n * price; }

protected:
    double price = 0;
};
class Disc_quote : public Quote
{
public:
    Disc_quote();
    Disc_quote(const std::string &book, double price,
               std::size_t qty, double disc) : Quote(book, price), nums(qty), cnt(disc) {}
    double net_price(std::size_t) const = 0;

protected:
    size_t nums = 0;
    double cnt = 0.0;
};
class Bulk_Quote : public Disc_quote
{
public:
    Bulk_Quote() = default;
    Bulk_Quote(const string &book, double sales_price, size_t number, double zc) : Disc_quote(book,sales_price,number,zc) {}
    virtual double net_price(size_t n) const override;
};
double Bulk_Quote::net_price(size_t n) const
{
    if (n >= nums)
        return n * (1 - cnt) * price;
    else
        return n * price;
};
//虚函数和抽象基类 