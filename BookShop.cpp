#include <iostream>
#include <stdlib.h>
#include "book.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {

	using namespace std;

	Book* book[20];
	int i = 0, t, choice;
	char titlebuy[20], authorbuy[20];

	while (1)
	{
		cout << "\n\n\tMENU"
			<< "\n1. Entry of new book"
			<< "\n2. Buy book"
			<< "\n3. Searsh for book"
			<< "\n4. Edit details of book"
			<< "\n5. Exit"
			<< "\n\nEnter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			book[i] = new Book;
			book[i]->feeddata();
			i++;
			break;

		case 2:
			cin.ignore();
			cout << "\nEnter title of book: "; 	//запрашиваем название книги
			cin.getline(titlebuy, 20);
			cout << "\nEnter author of book: ";	//запрашиваем автора книги
			cin.getline(authorbuy, 20);

			for (t = 0; t < i; t++)
			{
				if (book[i]->searsh(titlebuy, authorbuy) == 1)		//если книга найдена
				{
					book[t]->buybook();	//покупаем
					break;
				}
			}

			if (t == i)
			{
				cout << "\nThis book is not in stock";  //сообщение, что книги нет в запасе
			}
			break;

		case 3:
			cin.ignore();
			cout << "\nEnter title of book: ";
			cin.getline(titlebuy, 20);
			cout << "\nEnter author of book: ";
			cin.getline(authorbuy, 20);

			for (t = 0; t < i; t++)
			{
				if (book[t]->searsh(titlebuy, authorbuy))
				{
					cout << "\nBook found successfully";
					book[t]->showdata();
					break;
				}
			}
			if (t == i)
			{
				cout << "\nBook found successfully";
			}
			break;

		case 4:
			cin.ignore();
			cout << "\nEnter title of book: ";
			cin.getline(titlebuy, 20);
			cout << "Enter author of book: ";
			cin.getline(authorbuy, 20);

			for (t = 0; t < i; t++)
			{
				if (book[t]->searsh(titlebuy, authorbuy))
				{
					cout << "\nBook found successfully";
					book[t]->editdata();
					break;
				}
			}
			if (t == i)
			{
				cout << "\nThis book is not in stock";
			}
			break;

		case 5:
			exit(0);
		default: cout << "\nInvalid choice entered";
		}
	}

	return 0;
}
