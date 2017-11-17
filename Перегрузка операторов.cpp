#include <iostream>
#include <string>
class Fraction
{
public:
	int devisor;
	int denominator;
	Fraction(int dev, int den) : devisor(dev), denominator(den){};
	Fraction(): devisor(0),denominator(0){};
	Fraction operator=( Fraction &);
	Fraction operator~();
	Fraction operator*(Fraction &);
	Fraction operator/(Fraction );
	bool operator==(Fraction &);
	bool operator > (Fraction &);
	bool operator < (Fraction &);
};

std::ostream& operator << (std::ostream &os, const Fraction &fraction)
{
	os << fraction.devisor << "/" << fraction.denominator;
	return(os);
}

Fraction Fraction::operator ~ ()
{
	int c = this->devisor;
	this->devisor = this->denominator;
	this->denominator = c;
	return(*this);
};

Fraction Fraction::operator=(Fraction& fraction)
{
	if (&fraction == this)
	{
		return(*this);
	}
	devisor = fraction.devisor;
	denominator = fraction.denominator;
	return(*this);
};

Fraction Fraction::operator*(Fraction& fraction)
{
	fraction c;
	c.devisor = this->devisor*fraction.devisor;
	c.denominator = this->denominator*fraction.denominator;
	return(c);
}

Fraction Fraction::operator/(Fraction fraction)
{
	fraction c;
	~fraction;
	c = (*this)*fraction;
	return(c);
};

bool Fraction::operator==(Fraction& fraction)
{
	if (&fraction == this)
	{
		return(true);
	}
	if (this->devisor == fraction.devisor && this->denominator == fraction.denominator) 
		return(true);
	else
		return(false);

}

bool Fraction::operator> (Fraction& fraction)
{
	if (&fraction == this)
	{
		return(false);
	}
	if (this->devisor / this->denominator > fraction.devisor / fraction.denominator)
		return(true);
	else
		return(false);
}

bool Fraction::operator<(Fraction& fraction)
{
	if (&fraction == this)
	{
		return(false);
	}
	if (this->devisor / this->denominator < fraction.devisor / fraction.denominator)
		return(true);
	else
	return (false);
}
void main()
{
	Fraction fraction(10, 20);
	std::cout << fraction<<std::endl;
	Fraction fraction2;
	fraction2 = fraction;
	~fraction2;
	std::cout << fraction2 << std::endl;
	if (fraction == fraction2)
		std::cout << "TRUE"<<std::endl;
	else
		std::cout << "FALSE"<<std::endl;
	Fraction fraction3 = fraction / fraction2;
	std::cout << fraction3<<std::endl;
	fraction3 = fraction*fraction2;
	std::cout << fraction3 << std::endl;
	std::cin.get();}