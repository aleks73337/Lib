#include "Autor.h"

void Autor::setAutName(const std::string& name_)
{
	autName = name_;
}

std::vector<Book>& Autor::getAutorBooks()
{
	return (Books);
}

const std::string& Autor::getAutName()
{
	return autName;
}

void Autor::addBook(Book& book)
{
	Books.push_back(book);
}
