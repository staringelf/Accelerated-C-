#include <iostream>
#include <string>

using std::cin;  using std::cout;
using std::string;  using std::endl;

int main()
{
	cout << "Please enter your first name: ";

	//read the name
	string name;
	cin >> name;

	const string greeting = "Hello, " + name + "!";

	//the number of rows surrounding the greeting
	cout << "Please enter the padding you want: ";
	int pad;
	cin >> pad;

	const int rows = pad * 2 + 3;

	const string spaces(greeting.size() + pad * 2, ' ');
	const string stars(spaces.size()+2, '*');
	//invariant: we have written r number of rows so far 
	for(int r = 0; r != rows; ++r){
		
		if(r == 0 || r == rows - 1)
			cout << stars;

		else if(r == pad + 1){
			cout << "*";
			for(int i=0; i < pad; ++i)
				cout << " ";
			cout << greeting;
			for(int i=0; i < pad; ++i)
				cout << " ";
			cout << "*";
		}

		else{
			cout << '*';
			cout << spaces;
			cout << '*';
		}
		cout << endl;
	}

	return 0;
}