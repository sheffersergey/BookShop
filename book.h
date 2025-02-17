
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class Book{
	private:
		string author, title, publisher;	
		float price = 0;					
		int stock = 0;						
		
	public:
		void feeddata();										//enter book details
		void editdata();										//edit book details
		void showdata() const;									//show book details
		bool search(const string& t, const string& a) const;	//find book
		void buybook();											//buy book
};
