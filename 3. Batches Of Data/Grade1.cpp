#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;	using std::setprecision;
using std::cin;		using std::string;	
using std::endl;	using std::streamsize;
using std::vector;

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


	vector<double> homework;   //A place to hold values
	//variable to read values in
	double x;

	//invariant: we have read count grades so far
	while(cin >> x)
		homework.push_back(x);

	typedef vector<double>::size_type vec_sz;

	vec_sz size = homework.size();

	if(!size){
		cout << endl <<"You must enter your grades."
						"Please try again" << endl;
		return 1;
	}

	sort(homework.begin(), homework.end());

	double  median;

	vec_sz mid = size / 2; 

	median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid]; 

	//write the result
	streamsize prec = cout.precision();
	cout << "Your final grade is " << setprecision(3) 
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) << endl;

	if(cin >> x)
	cout << endl << x;
	return 0;

}
