#include "MoneyC.h"
#include <string>
#include <sstream>

using namespace std;

MoneyC::MoneyC(const long x, const unsigned long y)
{
	if (x < 0 || y < 0)
	{
		throw invalid_argument("Numbers must be bigger than 0!");
	}
	else
	{
		long a = x;
		unsigned int b = y;

		while (b > 99)
		{
			b -= 100;
			a++;
		}

		SetHrn(a);
		SetKop(b);
	}
}

MoneyC::MoneyC(double z)
{
	if (z < 0)
	{
		throw invalid_argument("Numbers must be bigger than 0!");
	}
	else
	{
		long a = (long)z;
		z -= a;
		z *= 100;
		unsigned long b = (unsigned long)z;

		while (b > 99)
		{
			b -= 100;
			a++;
		}

		SetHrn(a);
		SetKop(b);
	}
}

MoneyC::MoneyC(const MoneyC& r)
{
	int a = r.GetHrn();
	int b = r.GetKop();

	while (b > 99)
	{
		b -= 100;
		a++;
	}
	while (b < -99)
	{
		b += 100;
		a--;
	}

	SetHrn(a);
	SetKop(b);
}

MoneyC::~MoneyC(void)
{ }

MoneyC operator -(const MoneyC& l, const MoneyC& r)
{
	MoneyC t;

	long a = l.GetHrn() - r.GetHrn();
	unsigned long b = l.GetKop() - r.GetKop();

	t.SetHrn(a);
	t.SetKop(b);

	return t;
}

MoneyC operator *(const MoneyC& l, const double k)
{
	MoneyC t;

	long a = (l.GetHrn() * k);
	unsigned long b = (l.GetKop() * k);

	while (b > 99)
	{
		b -= 100;
		a++;
	}

	t.SetHrn(a);
	t.SetKop(b);

	return t;
}

MoneyC operator *(const double k, const MoneyC& r)
{
	MoneyC t;

	long a = r.GetHrn() * k;
	unsigned long b = r.GetKop() * k;

	while (b > 99)
	{
		b -= 100;
		a++;
	}

	t.SetHrn(a);
	t.SetKop(b);

	return t;
}

string format(unsigned long b)
{
	stringstream ss;

	if (b < 10)
	{
		ss << "0";
	}

	ss << b;

	return ss.str();
}

MoneyC::operator string() const
{
	stringstream ss;

	ss << endl;
	ss << GetHrn() << "," << format(GetKop()) << " hrn.";

	return ss.str();
}

ostream& operator << (ostream& out, const MoneyC& r)
{
	out << string(r);

	return out;
}

istream& operator >> (istream& in, MoneyC& r)
{
	long a;
	unsigned long b;

	cout << endl;
	cout << "hrn = "; in >> a;
	cout << "kop = "; in >> b;
	cout << endl;

	r.SetHrn(a);
	r.SetKop(b);

	return in;
}

bool MoneyC::operator ==(const MoneyC& x)
{
	return this->GetHrn() == x.GetHrn() && this->GetKop() == x.GetKop();
}

bool MoneyC::operator !=(const MoneyC& x)
{
	return !(this->GetHrn() == x.GetHrn() && this->GetKop() == x.GetKop());
}

bool MoneyC::operator >(const MoneyC& x)
{
	if (this->GetHrn() > x.GetHrn())
	{
		return true;
	}

	if (this->GetHrn() == x.GetHrn())
	{
		if (this->GetKop() > x.GetKop())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	if (this->GetHrn() < x.GetHrn())
	{
		return false;
	}
}

bool MoneyC::operator <(const MoneyC& x)
{
	if (this->GetHrn() < x.GetHrn())
	{
		return true;
	}

	if (this->GetHrn() == x.GetHrn())
	{
		if (this->GetKop() < x.GetKop())
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	if (this->GetHrn() > x.GetHrn())
	{
		return false;
	}
}

bool MoneyC::operator >=(const MoneyC& x)
{
	if (this->GetHrn() > x.GetHrn())
	{
		return true;
	}

	if (this->GetHrn() == x.GetHrn())
	{
		if (this->GetKop() > x.GetKop())
		{
			return true;
		}

		if (this->GetKop() == x.GetKop())
		{
			return true;
		}

		if (this->GetKop() < x.GetKop())
		{
			return false;
		}
	}

	if (this->GetHrn() < x.GetHrn())
	{
		return false;
	}
}

bool MoneyC::operator <=(const MoneyC& x)
{
	if (this->GetHrn() < x.GetHrn())
	{
		return true;
	}

	if (this->GetHrn() == x.GetHrn())
	{
		if (this->GetKop() < x.GetKop())
		{
			return true;
		}

		if (this->GetKop() == x.GetKop())
		{
			return true;
		}

		if (this->GetKop() > x.GetKop())
		{
			return false;
		}
	}

	if (this->GetHrn() > x.GetHrn())
	{
		return false;
	}
}

MoneyC& MoneyC::operator ++()
{
	int a = this->GetHrn();
	int b = this->GetKop();
	a++;
	b++;

	this->SetHrn(a);
	this->SetKop(b);

	return *this;
}

MoneyC& MoneyC::operator --()
{
	int a = this->GetHrn();
	int b = this->GetKop();
	a--;
	b--;

	this->SetHrn(a);
	this->SetKop(b);

	return *this;
}

MoneyC MoneyC::operator ++(int)
{
	MoneyC t(*this);

	int a = this->GetHrn();
	int b = this->GetKop();
	a++;
	b++;

	this->SetHrn(a);
	this->SetKop(b);

	return t;
}

MoneyC MoneyC::operator --(int)
{
	MoneyC t(*this);

	int a = this->GetHrn();
	int b = this->GetKop();
	a--;
	b--;

	this->SetHrn(a);
	this->SetKop(b);

	return t;
}