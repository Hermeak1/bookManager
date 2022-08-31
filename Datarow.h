#pragma once
class Datarow
{
private:
	CString id;
	CString bookname;
	CString author;
	CString price;
	CString other;
public:
	Datarow(CString _id, CString _bookname, CString _author, CString _price, CString _other);
	~Datarow();
	CString getID() const;
	void setID(const CString& id);
	CString getBookname() const;
	void setBookname(const CString& bookname);
	CString getAuthor() const;
	void setAuthor(const CString& author);
	CString getPrice() const;
	void setPrice(const CString& price);
	CString getOther() const;
	void setOther(const CString& other);
};

