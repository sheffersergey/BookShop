
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

class Book{
	private:
		string author, title, publisher;	
		float price = 0;					
		int stock = 0;						
		
	public:
		json to_json() const //save to json file
		{
			return
			{
				{"author", author},
				{"title", title},
				{"publisher", publisher},
				{"price", price},
				{"stock", stock}
			};
		}

		void from_json(const json& j) //load from json file
		{
			author = j["author"];
			title = j["title"];
			publisher = j["publisher"];
			price = j["price"];
			stock = j["stock"];
		}

		void feeddata(); //enter book details
		void editdata(); //edit book details
		void showdata() const; //show book details
		bool search(const string& t, const string& a) const; //find book
		void buybook();	//buy book
};


class FileManager{

	public:
		static void saveToFile(const vector <Book>& books, const string& filename) 
		{
			json j;
			for (const auto& book : books) 
			{
				j.push_back(book.to_json());
			}
			ofstream file(filename);
			file << j.dump(4);
		}
		
		static vector <Book> loadFromFile(const string& filename)
		{
			vector <Book> books;
			ifstream file(filename);

			if (!file) return books;

			try
			{
				json j;
				file >> j;
				for (const auto& item : j) {
					Book b;
					b.from_json(item);
					books.push_back(b);
				}
			}
			catch (...)
				{
					cerr << "Error reading file!" << endl;
				}
				return books;
		}


};