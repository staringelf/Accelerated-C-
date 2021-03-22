#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::cout;	using std::setprecision;
using std::cin;		using std::string;	
using std::endl;	using std::streamsize;
using std::vector;  using std::domain_error;
using std::sort;    using std::istream; 


double grade(double midterm, double final, double homework);
double median(vector<double> vec);
double grade(double midterm, double final, const vector<double>& hw);
istream& read_hw(istream& in, vector<double>& hw);


int main(void)
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

	cout << endl;

	cout << "Enter your homework grades followed by an end-of-file indicator: " ;
	vector<double> homework;
	
	read_hw(cin, homework);

	try{
		double final_grade = grade(midterm, final, homework);
		streamsize prec = cout.precision();
		cout << "Your final grade is " << setprecision(3)
		<< final_grade << setprecision(prec) << endl;
	}	catch(domain_error){
		cout << endl << "You must enter grades" "Please try agian" << endl;
	}

	string a;
	cin >> a;
	cout << a;

	return 0;
}



double grade(double midterm, double final, double homework)
{
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double median(vector <double> vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if(!size)
		throw domain_error("Median of an empty vector");

	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid - 2]) / 2 : vec[mid]; 
}


double grade(double midterm, double final, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("Student has no homework");
	return grade(midterm, final, median(hw));
}

istream& read_hw(istream& in, vector<double>& hw)
{
	if (in){
		hw.clear();  //get rid of previous content

		double x;		
		while(in >> x)			//read homework grades
			hw.push_back(x);

		in.clear();
	}
}

