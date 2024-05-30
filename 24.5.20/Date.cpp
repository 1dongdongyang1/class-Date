#include"Date.h"

//��ȡ����·ݵ�����
int Date::GetMonthDay(int year, int month)
{
	int MonthDays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	//����
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
		return 29;
	return MonthDays[month];
}

//���캯��
Date::Date(int year , int month , int day)	//����ʱ����дȱʡ����
{
	//�ж������Ƿ�Ϸ�
	if (year >= 0
		&& month >= 1 && month <= 12
		&& day >= 1 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
		cout << "�Ƿ�����" << endl;
}

//�������캯��
Date::Date(const Date& d)	
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

//���������
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

//	++d ǰ��++
Date& Date::operator++()
{
	*this += 1;
	return *this;	//���ؼ�֮���ֵ
}

//	d++ ����++
Date Date::operator++(int)	//Ϊ�˹��ɺ�������
{
	Date tmp(*this);
	*this += 1;
	return tmp;		//���ؼ�֮ǰ��ֵ
}

//	--d ǰ��--
Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

//	d-- ����--
Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

//��ֵ���������
Date& Date::operator=(const Date& d)
{
	if (this != &d)		//����Լ����Լ���ֵ���жϼ��
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	return *this;
}

//���� - ����
int Date::operator-(const Date& d) const
{
	int flag = 1;
	Date max = *this;	//��������
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