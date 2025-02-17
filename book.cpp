#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <limits>
#include "book.h"

using std::cout;
using std::cin;

void Book::feeddata()
{
	cout << "\n Enter Author Name: ";
	getline(cin, author);
	
	cout << "Enter Title Name: ";
	getline(cin, title);
	
	cout << "Enter Publisher Name: ";
	getline(cin, publisher);
	
	cout << "Enter Price: ";
	cin >> price;
	
	cout << "Enter Stock Position: ";
	cin >> stock;

	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
}

void Book::editdata()
{
	cout << "\n Enter Author Name: ";
	getline(cin, author);

	cout << "Enter Title Name: ";
	getline(cin, title);

	cout << "Enter Publisher Name: ";
	getline(cin, publisher);

	cout << "Enter Price: ";
	cin >> price;

	cout << "Enter Stock Position: ";
	cin >> stock;

	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
}

void Book::showdata() const 
{
 cout << "\nAuthor Name: " << author;
 cout << "\nTitle Name: " << title;
 cout << "\nPublisher Name: " << publisher;
 cout << "\nPrice: " << price;
 cout << "\nStock Position: " << stock << endl;   
}

bool Book::search(const string& t, const string& a) const  //search for a book by title and author
{
	return (title == t) && (author == a);
}

void Book::buybook()
{
	int count;
	cout << "\nEnter number of books to buy: ";				//request the number of books
	cin >> count;
	
	if (count <= stock)										//if the number of books less than in stock
	{
	 	stock -= count; 									//reduce the stock
		cout << "\nBooks bought sucessfully";				//message: Books bought sucessfully
		cout << "\nAmount: Rs. " << price * count << endl;	
	}
	else 
 		cout << "\nRequired copies not in stock" << endl;	//message about book shortage 
	
}


