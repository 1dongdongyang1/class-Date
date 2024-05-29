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

	/*Date operator+(int day)
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
	}*/

	Date operator+(int day)		//复用
	{
		Date ret(*this);
		ret += day;
		return ret;
	}

	Date& operator+=(int day)
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

	/*Date operator-(int day)
	{
		Date ret(*this);
		ret._day -= day;

		while (ret._day <= 0)
		{
			ret._month--;
			if (ret._month == 0)
			{
				ret._year--;
				ret._month = 12;
			}
			ret._day += GetMonthDay(ret._year, ret._month);
		}

		return ret;
	}*/

	Date operator-(int day)
	{
		Date ret(*this);
		ret -= day;
		return ret;
	}

	Date& operator-=(int day)
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
	Date& operator++()
	{
		*this += 1;
		return *this;	//返回加之后的值
	}

	//	d++ 后置++
	Date operator++(int)	//为了构成函数重载
	{
		Date tmp(*this);
		*this += 1;
		return tmp;		//返回加之前的值
	}

	//	--d 前置--
	Date& operator--()
	{
		*this -= 1;
		return *this;
	}

	//	d-- 后置--
	Date operator--(int)
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}

	//赋值运算符重载
	//运算符重载是为了让自定义类型可以像内置类型一样去使用运算符
	//自定义类型在传参数和返回值时，在可以的情况下，尽量使用引用，减少拷贝
	Date& operator=(const Date& d)
	{
		if (this != &d)		//针对自己给自己赋值的判断检查
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		
		return *this;
	}

	int operator-(const Date& d)
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

		return n*flag;
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
	Date d2;
	Date d3;

	d2 = d1 + -10;
	d2.Print();

	d3 = d1 - 10;
	d3.Print();
	return 0;
}
