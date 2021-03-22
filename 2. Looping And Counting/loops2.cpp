#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int length, breadth;

	cout << "Please enter length and breadth: ";
	cin >> length >> breadth;

	for(int r = 0; r < breadth; ++r){
		for(int c = 0; c < length; ++c){
			if(r == 0 || r == breadth - 1 || c == 0 || c == length - 1)
				cout << "* ";
			else
				cout << "  ";
		}
		cout << endl;
	}

}