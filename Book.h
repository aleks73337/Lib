#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
class Book
{
private:

	std::string name;
	std::string aut;
	std::string year;

public:
	Book(const std::string& name_, const std::string& aut_, const std::string& year_) : name(name_), aut(aut_), year(year_){};
	void setName(std::string& name_);
	void setAut(std::string& aut_);
	void setYear(std::string& year_);
	const std::string& getName();
	const std::string& getAut();
	const std::string& getYear();
};
#endif BOOK_H
