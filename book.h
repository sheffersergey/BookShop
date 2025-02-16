
#include <iostream>
#include <string.h>
#include <stdlib.h>

class Book{
	private:
		char *author, *title, *publisher;	//�����, ��������, ��������
		float *price;								//����
		int *stock;									//�����
		
	public:
		Book()		//constructor of book class
		{
			//������ �������� ����� ������������������ ��� ������
			//��������� �� �������� ���� char ���� ����� ������������������ ��� ������
			//��� ������ �� �������� �������� ��������� ���������� ����� ���������� ������
			author = new char[20]; 
			title = new char[20];
			publisher = new char[20];
			price = new float;
			stock = new int;
		}
		
		void feeddata();					//������ ������ � �����
		void editdata();					//������������� ������ � �����
		void showdata();					//�������� ������ � �����
		int searsh(char[], char[]);	//����� �����
		void buybook();					//������ �����
	
};
