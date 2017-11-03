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
};

std::ostream& operator << (std::ostream &os, const Fraction &frac)
{
	os << frac.devisor << "/" << frac.denominator;
	return(os);
}

Fraction Fraction::operator ~ ()
{
	int c = this->devisor;
	this->devisor = this->denominator;
	this->denominator = c;
	return(*this);
};

Fraction Fraction::operator=(Fraction& frac)
{
	devisor = frac.devisor;
	denominator = frac.denominator;
	return(*this);
};

Fraction Fraction::operator*(Fraction& frac)
{
	Fraction c;
	c.devisor = this->devisor*frac.devisor;
	c.denominator = this->denominator*frac.denominator;
	return(c);
}

Fraction Fraction::operator/(Fraction frac)
{
	Fraction c;
	~frac;
	c = (*this)*frac;
	return(c);
};

bool Fraction::operator==(Fraction& frac)
{
	if (this->devisor == frac.devisor && this->denominator == frac.denominator) 
		return(true);
	else
		return(false);

}

void main()
{
	Fraction frac(10, 20);
	std::cout << frac<<std::endl;
	Fraction frac2;
	frac2 = frac;
	~frac2;
	std::cout << frac2 << std::endl;
	if (frac == frac2)
		std::cout << "TRUE"<<std::endl;
	else
		std::cout << "FALSE"<<std::endl;
	Fraction frac3=frac / frac2;
	std::cout << frac3<<std::endl;
	frac3 = frac*frac2;
	std::cout << frac3 << std::endl;
	std::cin.get();}