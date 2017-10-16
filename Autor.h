#ifndef AUTOR_H
#define AUTOR_H
#include "Book.h"
#include <vector>


class Autor
{
protected:
	std::vector<Book> Books;
	std::string autName;
public:
	void Autor::setAutName(const std::string& name_);
	const std::string& Autor::getAutName();
	std::vector<Book>& Autor::getAutorBooks();
	void addBook(Book& book);
	void deleteBooks(std::string& name_);
};
#endif AUTOR_H
