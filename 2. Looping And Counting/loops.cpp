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
	const int ypad = 2;
	const int xpad = 10;

	const int rows = ypad * 2 + 3;

	const string::size_type cols = greeting.size() + xpad * 2 + 2;

	//invariant: we have written r number of rows so far 
	for(int r = 0; r != rows; ++r){
		
		string::size_type c = 0;
		
		//invariant: we have written c characters so far 
		while (c != cols){
			if(r == ypad + 1 && c == xpad + 1){		//is it time to greet?
				cout << greeting;
				c += greeting.size();
			}
			else{
				if(r == 0 || r == rows - 1 || c == 0 || c == cols - 1) //are we on border?
					cout << "*";
				else 
					cout << " ";
				++c;
			}
		}

		cout << endl; 
	} 

	return 0;
}