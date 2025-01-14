#include <iostream>
using namespace std;

class Book {
	public:
		string book_name;
		string author_name;
		int price;
		
		void getData()
		{
			cout << "Book Name: ";
			getline(cin, book_name);
			cout << "Author Name: ";
			getline(cin, author_name);
			cout << "Price: ";
			cin >> price;
		}
		
		void display()
		{
			cout << "Book Name: " << book_name << endl;
			cout << "Author Name: " << author_name << endl;
			cout << "Price: " << price << endl;
		}
};

int main ()
{
	Book *b1 = new Book();

	cout << "Enter data for book 1" << endl;
	b1->getData();
	
	cout << endl << "Book 1 -" << endl;
	b1->display();
	return 0;
}
