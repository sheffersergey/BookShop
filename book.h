
#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class Book{
	private:
		string author, title, publisher;	//�����, ��������, ��������
		float price = 0;					//����
		int stock = 0;						//�����
		
	public:
		void feeddata();										//������ ������ � �����
		void editdata();										//������������� ������ � �����
		void showdata() const;									//�������� ������ � �����
		bool search(const string& t, const string& a) const;	//����� �����
		void buybook();											//������ �����
};
