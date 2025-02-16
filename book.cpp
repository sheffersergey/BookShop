#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "book.h"

using namespace std;

void Book::feeddata()
{
	cin.ignore();
	cout << "\n Enter Author Name: ";
	cin.getline(author, 20);
	
	cout << "Enter Title Name: ";
	cin.getline(title, 20);
	
	cout << "Enter Publisher Name: ";
	cin.getline(publisher, 20);
	
	cout << "Enter Price: ";
	cin >> *price;
	
	cout << "Enter Stock Position: ";
	cin >> *stock;
}

void Book::editdata()
{
	cout << "\nEnter Author Name: ";      
	cin.getline(author, 20);
	
   cout << "Enter Title Name: ";       
	cin.getline(title, 20);
	
   cout << "Enter Publisher Name: ";   
	cin.getline(publisher, 20);
	
   cout << "Enter Price: ";            
	cin >> *price;
	
   cout << "Enter Stock Position: ";   
	cin >> *stock;   
}

void Book::showdata()   
{
 	cout << "\nAuthor Name: " << author;
   cout << "\nTitle Name: " << title;
   cout << "\nPublisher Name: " << publisher;
   cout << "\nPrice: " << *price;
   cout << "\nStock Position: " << *stock;   
}

int Book::searsh(char tbuy[20], char abuy[20])  //поиск книги по названию и автору
{
   if(strcmp(tbuy, title) == 0 && strcmp(abuy, author) == 0)	
   	return 1;	//если название и автор совпадают
   else 
	 	return 0;	//если название и автор НЕ совпадают
                
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


