#include "pch.h"
#include "Datarow.h"


Datarow::Datarow(CString _id, CString _bookname, CString _author, CString _price, CString _other)
	:id(_id), bookname(_bookname), author(_author), price( _price), other(_other)
{

}

Datarow::~Datarow()
{
	
}


CString Datarow::getID() const
{
	return id;
}

void Datarow::setID(const CString& id)
{
	this->id = id;
}

CString Datarow::getBookname() const
{
	return bookname;
}

void Datarow::setBookname(const CString& bookname)
{
	this->bookname = bookname;
}

CString Datarow::getAuthor() const
{
	return author;
}

void Datarow::setAuthor(const CString& author)
{
	this->author = author;
}

CString Datarow::getPrice() const
{
	return price;
}

void Datarow::setPrice(const CString& price)
{
	this->price = price;
}

CString Datarow::getOther() const
{
	return other;
}

void Datarow::setOther(const CString& other)
{
	this->other = other;
}