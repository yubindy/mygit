#include <iostream>

class Date {
private:
    int year_ = 1;          // 年
    int month_ = 1;         // 月
    int day_ = 1;           // 日
    int totalDays_;         // 改日期是从公元元年1月1日开始的第几天

public:
    Date() = default;
    // 用年、月、日构造日期，默认为公元元年1月1日
    Date(int year, int month, int day);
    ~Date() { std::cout << "destructor called" << std::endl; }
    int getYear() const { return year_; }
    int getMonth() const { return month_; }
    int getDay() const { return day_; }
    int getMaxDay() const;          // 获得当月有多少天
    bool isLeapYear() const {
        return year_ % 4 == 0 && year_ % 100 != 0 || year_ % 400 == 0;
    }
    // 计算两个日期之间差多少天
    int operator-(const Date &date) const {
        return totalDays_ - date.totalDays_;
    }
    // 判断两个日期的前后顺序
    bool operator<(const Date &date) const {
        return totalDays_ < date.totalDays_;
    }
    // 拷贝构造函数
    Date(const Date &date);
    // 拷贝赋值运算符
    Date &operator=(const Date &date);
    // 移动构造函数
    Date(Date &&date) noexcept;
    // 移动赋值运算符
    Date &operator=(Date &&rhs) noexcept;
};

std::istream &operator>>(std::istream &in, Date &date);
std::ostream &operator<<(std::ostream &out, const Date &date);
namespace  {
    // 存储平年中某个月1日之前有多少天，为便于 getMaxDay 函数的实现，该数组多出一项
    const int DAYS_BEFORE_MONTH[] = {0, 31, 59, 90, 120, 151, 181, 212,
                                     243, 273, 304, 334, 365};
}
int year_ = 1;          // 年
    int month_ = 1;         // 月
    int day_ = 1;           // 日
    int totalDays_; 
Date::Date(const Date &date) : year_(date.year_),month_(date.month_),totalDays_(date.totalDays_)
{
    std::cout << "copy constructor" << std::endl;
}
int Date::getMaxDay() const {
    if (isLeapYear() && month_ == 2)
        return 29;
    else
        return DAYS_BEFORE_MONTH[month_] - DAYS_BEFORE_MONTH[month_ - 1];
}

