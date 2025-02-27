#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "book.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	using std::cout;
	using std::cin;

	const std::string filename = "books_database.json";

	vector <Book> books = FileManager::loadFromFile(filename);
	int choice;

	while (true)
	{
		cout << "\n\n\tMENU"
			<< "\n1. Entry of new book"
			<< "\n2. Buy book"
			<< "\n3. Searsh for book"
			<< "\n4. Edit details of book"
			<< "\n5. Exit"
			<< "\n\nEnter your choice: ";

		cin >> choice;
		cin.ignore();

		if (choice == 5) break;		//exit from program

		string titlebuy, authorbuy;

		switch (choice)
		{
		case 1:
		{
			Book b;				//creating an object of class Book 
			b.feeddata();		//entering new data
			books.push_back(b);	//adding new item to the end of a list 
			break;
		}

		case 2:
		{
			cout << "\nEnter title of book: ";
			getline(cin, titlebuy);
			cout << "\nEnter author of book: ";
			getline(cin, authorbuy);

			bool found = false;

			for (auto& book : books)	//iterating elemnts in "for each" style
			{
				if (book.search(titlebuy, authorbuy))	//if book found
				{
					book.buybook();
					found = true;
					break;
				}
			}

			if (!found) cout << "\nBook not found";	//if book not found
			break;
		}

		case 3:
		{
			cout << "\nEnter title of book: ";
			getline(cin, titlebuy);
			cout << "\nEnter author of book: ";
			getline(cin, authorbuy);

			bool found = false;

			for (const auto& book : books)	//iterating elemnts in "for each" style
			{
				if (book.search(titlebuy, authorbuy))	//if book found
				{
					book.showdata();
					found = true;
					break;
				}
			}
			if (!found) cout << "\nBook not found";	//if book not found
			break;
		}

		case 4:
		{
			cout << "\nEnter title of book: ";
			getline(cin, titlebuy);
			cout << "\nEnter author of book: ";
			getline(cin, authorbuy);

			bool found = false;

			for (auto& book : books) //iterating elemnts in "for each" style
			{
				if (book.search(titlebuy, authorbuy)) //if book found
				{
					book.editdata();
					found = true;
					break;
				}
			}
			if (!found) cout << "\nBook not found";	//if book not found
			break;
		}

		default: cout << "\nInvalid choice entered" << endl;
		}
	}
	FileManager::saveToFile(books, filename);
	return 0;
}
