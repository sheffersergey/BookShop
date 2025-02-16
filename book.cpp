#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <string>
#include <limits>
#include "book.h"

using namespace std;

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

bool Book::search(const string& t, const string& a) const  //поиск книги по названию и автору
{
	return (title == t) && (author == a);
}

void Book::buybook()
{
	int count;
	cout << "\nEnter number of books to buy: "; //запрос количества книг
	cin >> count;
	
	if (count <= *stock) //если количество книг меньше, чем есть в запасе
	{
	 	*stock = *stock - count; 								//уменьшаем количество запаса
		 cout << "\nBooks bought sucessfully";				//сообщение: книги куплены успешно
		 cout << "\nAmount: Rs. " << (*price) * count;	
	}
	else 
 		cout << "\nRequired copies not in stock";			//буемого количества копий нет в запасе
	
}


