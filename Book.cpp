#include "Book.h"


void Book::setName(std::string& name_)
{
	name = name_;
}

void Book::setAut(std::string& aut_)
{
	aut = aut_;
}

void Book::setYear(std::string& year_)
{
	year = year_;
}

const std::string& Book::getName()
{
	return name;
}

const std::string& Book::getAut()
{
	return aut;
}

const std::string& Book::getYear()
{
	return year;
}
