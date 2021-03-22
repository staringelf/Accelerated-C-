/* If input is:-  A 100 100 100 100 100 
				  B 95 95 95 95 95
   Output will be 100 as istream expected a double as it is filling homework,
   and we are providing it with B, a char. The istream will fail 
   and will remain infailure state till it is restored using istream.clear() */ 



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

struct Student_info {
	string name;
	double midterm, final;
	vector<double> homework;
};


double grade(double midterm, double final, double homework);
double median(vector<double> vec);
double grade(double midterm, double final, const vector<double>& hw);
istream& read_hw(istream& in, vector<double>& hw);
istream& read(istream& is, Student_info& s);
double grade(const Student_info& s);

int main(void)
{
	
	Student_info record;
	
	read (cin, record);

	try{
		double final_grade = grade(record);
		streamsize prec = cout.precision();
		cout << "Your final grade is " << setprecision(3)
		<< final_grade << setprecision(prec) << endl;
	}	
	catch(domain_error e){
		cout << e.what();			
	}
	cout << endl;
	
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

istream& read(istream& is, Student_info& s)
{
	is >> s.name >> s.midterm >> s.final;

	read_hw(is, s.homework);

	return is;
}

double grade(const Student_info& s)
{
	return grade(s.midterm, s.final, s.homework);
}