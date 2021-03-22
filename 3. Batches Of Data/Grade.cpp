#include <iomanip>
#include <ios>
#include <iostream>
#include <string>

using std::cout;	using std::setprecision;
using std::cin;		using std::string;	
using std::endl;	using std::streamsize;

int main()
{
	// Introduction
	cout <<"Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello, " << name << "!";

	cout << endl;
	//ask for and read midterm and final exam grades
	cout << "Please enter midterm and final exam grades: ";
	double midterm, final;
	cin >> midterm >> final;

	//ask for homework grades
	cout << "Enter all your homework grades " <<
		"followed by end-of-file indicator: ";

	//the number and sum of grades read so far
	int count = 0;
	double sum = 0;

	//variable to read values in
	double x;

	//invariant: we have read count grades so far
	while(cin >> x){
		++count;
		sum += x;
	}

	//write the result
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3) 
		<< 0.2 * midterm + 0.4 * final + 0.4 * sum / count 
		<< setprecision(prec) << endl;

	if(cin >> x)
	cout << endl << x;
	return 0;

}
