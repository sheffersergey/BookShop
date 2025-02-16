
#include <iostream>
#include <string.h>
#include <stdlib.h>

class Book{
	private:
		char *author, *title, *publisher;	//автор, название, издатель
		float *price;								//цена
		int *stock;									//запас
		
	public:
		Book()		//constructor of book class
		{
			//массив символов может интерпретироваться как строка
			//указатель на значения типа char тоже может интерпретироваться как строка
			//при выводе на констоль значения указателя фактически будет выводиться строка
			author = new char[20]; 
			title = new char[20];
			publisher = new char[20];
			price = new float;
			stock = new int;
		}
		
		void feeddata();					//внести данные о книге
		void editdata();					//редактировать данные о книге
		void showdata();					//показать данные о книге
		int searsh(char[], char[]);	//найти книгу
		void buybook();					//купить книгу
	
};
