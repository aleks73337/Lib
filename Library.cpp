#include "Library.h"

void Library::addBook(Book& book_)
{
	for (Autor& autor : autors)
	{
		if (autor.getAutName() == book_.getAut())
		{
			autor.addBook(book_);
		}
	}
}

void Library::addAutor(const std::string& name)
{
	Autor autor;
	autor.setAutName(name);
	autors.push_back(autor);
}

Autor& Library::searchAutor(const std::string& n)
{
	for (Autor& autor : autors)
	{
		if (autor.getAutName() == n)
		{
			return(autor);
		}
	}
}

std::vector<Book> Library::searchBookByYear(const std::string& year_)
{
	std::vector<Book> books;
	for (Autor& autor : autors)
	{
		for (Book book : autor.getAutorBooks())
		{
			if (book.getYear() == year_)
			{
				books.push_back(book);
			}
		}
	}
	return(books);
}

void Library::deleteAutor(const std::string& n)
{
	std::vector<Autor> del_aut;
	for (Autor& autor : autors)
	{
		if (autor.getAutName() != n)
		{
			del_aut.push_back(autor);
		}
	}
	autors.clear();
	for (Autor& autor : del_aut)
	{
		autors.push_back(autor);
	}
	del_aut.clear();
}

Book Library::searchBookByName(const std::string& name)
{
	for (Autor& autor : autors)
	{
		for (Book book : autor.getAutorBooks())
		{
			if (book.getName() == name)
			{
				return(book);
			}
		}
	}
}

void Library::deleteBook(const std::string& name_)
{
	for (Autor autor : autors)
	{
		std::vector<Book> book1;
		for (Book book : autor.getAutorBooks())
		{
			if (book.getName() != name_)
			{
				book1.push_back(book);
			}
		}
		autor.getAutorBooks().clear();
		for (Book book : book1)
		{
			autor.getAutorBooks().push_back(book);
		}
		book1.clear();
	}
}
