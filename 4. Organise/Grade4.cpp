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
using std::max; 

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
bool compare(Student_info& x, Student_info& y);

int main(void)
{
	
	Student_info record;

	vector<Student_info> students;

	string::size_type maxlen = 0;

	while(read(cin, record)){
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);	          //filling the vector students
	}

	sort(students.begin(), students.end(), compare);

	for(vector<double>::size_type i = 0; i != students.size(); ++i){
		cout << students[i].name;
		cout << string(maxlen - students[i].name.size() + 1, ' ');

		try{
			double final_grade = grade(students[i]);
			streamsize prec = cout.precision();

			cout << setprecision(3) << final_grade 
				 << setprecision(prec);
		}
		catch (domain_error e){
			cout << e.what();
		}
		cout << endl;
	}
	
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

	vec_sz mid = size / 2 + 1;

	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid]; 
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

bool compare(Student_info& x, Student_info& y)
{
	return x.name < y.name;
}