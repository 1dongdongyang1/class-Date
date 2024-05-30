#include"Date.h"

//获取相关月份的天数
int Date::GetMonthDay(int year, int month)
{
	int MonthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//闰年
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return 29;
	return MonthDays[month];
}

//构造函数
Date::Date(int year , int month , int day)	//定义时不再写缺省参数
{
	//判断日期是否合法
	if (year >= 0
		&& month >= 1 && month <= 12
		&& day >= 1 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
		cout << "非法日期" << endl;
}

//拷贝构造函数
Date::Date(const Date& d)	
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

//运算符重载
bool Date::operator<(const Date& d) const
{
	if (_year < d._year)
		return true;
	else if (_year == d._year && _month < d._month)
		return true;
	else if (_year == d._year && _month == d._month && _day < d._day)
		return true;

	return false;
}

bool Date::operator==(const Date& d) const
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator<=(const Date& d) const
{
	return *this < d || *this == d;
}

bool Date::operator>(const Date& d) const
{
	return !(*this <= d);
}

bool Date::operator>=(const Date& d) const
{
	return !(*this < d);
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

Date Date::operator+(int day) const
{
	Date ret(*this);
	ret += day;
	return ret;
}

Date& Date::operator+=(int day)
{
	if (day < 0)
		return *this -= -day;

	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}

	return *this;
}

Date Date::operator-(int day) const
{
	Date ret(*this);
	ret -= day;
	return ret;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
		return *this += -day;

	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_year--;
			_month = 12;
		}
		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

//	++d 前置++
Date& Date::operator++()
{
	*this += 1;
	return *this;	//返回加之后的值
}

//	d++ 后置++
Date Date::operator++(int)	//为了构成函数重载
{
	Date tmp(*this);
	*this += 1;
	return tmp;		//返回加之前的值
}

//	--d 前置--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

//	d-- 后置--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

//赋值运算符重载
Date& Date::operator=(const Date& d)
{
	if (this != &d)		//针对自己给自己赋值的判断检查
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	return *this;
}

//日期 - 日期
int Date::operator-(const Date& d) const
{
	int flag = 1;
	Date max = *this;	//拷贝构造
	Date min = d;
	if (*this < d)
	{
		max = d;		//operator=
		min = *this;
		flag = -1;
	}

	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}

	return n * flag;
}

void Date::Print() const
{
	cout << _year << "." << _month << "." << _day << endl;
}