#include <iostream>

class Book {
public:
	void setTitle(std::string title);
	void setAuthor(std::string author);
	void setISBN(std::string ISBN);

	std::string getTitle();
	std::string getAuthor();
	std::string getISBN();

private:
	std::string m_title;
	std::string m_author;
	std::string m_ISBN;
};

int main()
{
	std::string info;

	Book book;
	std::cout << "Enter the book title: ";
	std::getline(std::cin, info);
	book.setTitle(info);
	
	std::cout << "Enter the book author: ";
	std::getline(std::cin, info);
	book.setAuthor(info);
	
	std::cout << "Enter the book ISBN: ";
	std::cin >> info;
	book.setISBN(info);

	std::cout << "Your book information.\n" 
			  << "Title: " << book.getTitle() << "\n"
			  << "Author: " << book.getAuthor() << "\n"
			  << "ISBN: " << book.getISBN() << std::endl;
	return 0;
}

void Book::setTitle(std::string title)
{
	this->m_title = title;
}

void Book::setAuthor(std::string author)
{
	this->m_author = author;
}

void Book::setISBN(std::string ISBN)
{
	this->m_ISBN = ISBN;
}

std::string Book::getTitle()
{
	return this->m_title;
}

std::string Book::getAuthor()
{
	return this->m_author;
}

std::string Book::getISBN()
{
	return this->m_ISBN;
}



