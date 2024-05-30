#define  _CRT_SECURE_NO_WARNINGS
#pragma once

#include<iostream>
using namespace std;

class Date
{
public:
	int GetMonthDay(int year, int month) const;
	Date(int year = 0, int month = 1, int day = 1);
	Date(const Date& d);
	bool operator<(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator!=(const Date& d) const;
	Date operator+(int day) const;
	Date& operator+=(int day);
	Date operator-(int day) const;
	Date& operator-=(int day);
	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);
	Date& operator=(const Date& d);
	int operator-(const Date& d) const;
	void Print() const;
private:
	int _year;
	int _month;
	int _day;
};
