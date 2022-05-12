#pragma once

#include "Pair.h"

class MoneyC : private Pair
{
public:
	MoneyC(const long x = 0, const unsigned long y = 0);
	MoneyC(const MoneyC& r);
	MoneyC(double z);
	~MoneyC(void);

	using Pair::GetHrn;
	using Pair::GetKop;
	using Pair::SetHrn;
	using Pair::SetKop;

	friend MoneyC operator -(const MoneyC&, const MoneyC&);
	friend MoneyC operator *(const MoneyC&, const double);
	friend MoneyC operator *(const double, const MoneyC&);

	bool operator ==(const MoneyC&);
	bool operator !=(const MoneyC&);
	bool operator >(const MoneyC&);
	bool operator <(const MoneyC&);
	bool operator >=(const MoneyC&);
	bool operator <=(const MoneyC&);

	operator string() const;
	friend ostream& operator << (ostream&, const MoneyC&);
	friend istream& operator >> (istream&, MoneyC&);

	MoneyC& operator ++();
	MoneyC& operator --();
	MoneyC operator ++(int);
	MoneyC operator --(int);
};