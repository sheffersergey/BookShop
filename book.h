
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class Book{
	private:
		string author, title, publisher;	//автор, название, издатель
		float price = 0;					//цена
		int stock = 0;						//запас
		
	public:
		void feeddata();										//внести данные о книге
		void editdata();										//редактировать данные о книге
		void showdata() const;									//показать данные о книге
		bool search(const string& t, const string& a) const;	//найти книгу
		void buybook();											//купить книгу
};
