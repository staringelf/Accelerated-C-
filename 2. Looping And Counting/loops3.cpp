#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int length, breadth;

	cout << "Please enter length: ";
	cin >> length; 

	for(int r = 0; r < length; ++r){
		cout << "\t";
		for(int c = 0; c < length; ++c){
			if(r == 0 || r == length - 1 || c == 0 || c == length - 1)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << endl;
	}

}