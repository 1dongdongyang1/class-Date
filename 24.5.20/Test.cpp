#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month)	//获取相关月份的天数
	{
		int MonthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//闰年
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
			return 29;
		return MonthDays[month];
	}

	Date(int year = 0, int month = 1, int day = 1)
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

	Date(const Date& d)	//拷贝构造函数
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//运算符重载
	bool operator<(const Date& d)	
	{
		if (_year < d._year)
			return true;
		else if (_year == d._year && _month < d._month)
			return true;
		else if (_year == d._year && _month == d._month && _day < d._day)
			return true;

		return false;
	}

	bool operator==(const Date& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	bool operator<=(const Date& d)
	{
		return *this < d || *this == d;
	}

	bool operator>(const Date& d)
	{
		return !(*this <= d);
	}

	bool operator>=(const Date& d)
	{
		return !(*this < d);
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	Date operator+(int day)
	{
		Date ret(*this);
		ret._day += day;

		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day -= GetMonthDay(ret._year, ret._month);
			ret._month++;

			if (ret._month == 13)
			{
				ret._year++;
				ret._month = 1;
			}
		}

		return ret;
	}

	Date& operator+=(int day)
	{
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

	void Print()
	{
		cout << _year << "." << _month << "." << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2020, 4, 11);
	
	Date d4 = d1 + 100;
	d4.Print();
	d1 += 10;
	d1.Print();
	return 0;
}
