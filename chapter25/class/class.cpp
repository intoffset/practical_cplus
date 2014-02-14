/*************************************************
 * class_stuff -- handle student and grade infomation
 *************************************************/

#include <iostream>

#include <string>
#include <vector>
#include <map>
#include <list>

#include <algorithm>

const unsigned int MAX_STUDENTS = 5;

class class_stuff {
	public:
		typedef std::vector<int> grades;

		std::map<std::string, grades> roster;
		std::list<std::string> waiting_list;

	public:
		// use default constructor
		// use default destructor
		// use default copy-constructor
		// use default assignment operator

	public:
		void add_student(const std::string& name);
		void drop_student(const std::string& name);
		void record_grade(const std::string& name,
				const int grade,
				const unsigned int assignment_number
				);
		void print_grades();

	private:
		void new_student(const std::string& name) {
			grades no_grades;
			roster.insert(std::pair<std::string, grades>(name, no_grades));
		}
};

/*************************************************
 * class_stuff::add_student -- add student into class
 *************************************************/
void class_stuff::add_student(const std::string& name) {
	if (roster.find(name) != roster.end()) {
		return;
	}
	if (roster.size() < MAX_STUDENTS) {
		new_student(name);
	} else {
		waiting_list.push_back(name);
	}
}

/*************************************************
 * class_stuff::drop_student -- delete student from class
 *************************************************/
void class_stuff::drop_student(const std::string& name) {
	std::map<std::string, grades>::iterator the_student = roster.find(name);

	if (the_student == roster.end()) {
		return;
	}

	roster.erase(name);

	if (waiting_list.size() > 0) {
		std::string wait_name = waiting_list.front();
		waiting_list.pop_front();
		new_student(wait_name);
	}
}

/*************************************************
 * class_stuff::record_grade -- record grade of student
 *************************************************/
void class_stuff::record_grade(
		const std::string& name,
		const int grade,
		const unsigned int assignment_number
		) {
	std::map<std::string, grades>::iterator the_student = roster.find(name);

	if (the_student == roster.end()) {
		std::cerr << "ERROR: No such student " << name << '\n';
		return;
	}

	if (the_student->second.size() <= assignment_number) {
		the_student->second.resize(assignment_number + 1);
	}

	the_student->second[assignment_number] = grade;
}

/*************************************************
 * class_stuff::print_grades
 *   -- print student name and grades
 *************************************************/
void class_stuff::print_grades() {
	std::vector<std::string> sorted_names;

	std::map<std::string, grades>::iterator cur_student;

	for (cur_student = roster.begin(); cur_student != roster.end(); ++cur_student) {
		sorted_names.push_back(cur_student->first);
	}
	std::sort(sorted_names.begin(), sorted_names.end());

	std::vector<std::string>::const_iterator cur_print;

	for (cur_print = sorted_names.begin(); cur_print != sorted_names.end(); ++cur_print) {
		std::cout << *cur_print << '\t';

		grades::const_iterator cur_grade;
		for (cur_grade = roster[*cur_print].begin();
				cur_grade != roster[*cur_print].end();
				++cur_grade)
		{
			std::cout << *cur_grade << ' ';
		}
		std::cout << '\n';
	}
}

int main(void)
{
	class_stuff test_class;

	test_class.add_student("Able, Sam");
	test_class.add_student("Baker, Mary");
	test_class.add_student("Johnson, Robin");
	test_class.add_student("Smith, Joe");
	test_class.add_student("Mouse, Micky");

	test_class.add_student("Gadot, Waiting");
	test_class.add_student("Congreve, William");

	std::cout << "Before drop" << std::endl;
	test_class.print_grades();
	std::cout << '\n';

	test_class.drop_student("Johnson, Robin");

	std::cout << "After drop" << std::endl;
	test_class.print_grades();
	std::cout << '\n';

	int i;

	for (i = 0; i < 5; ++i) {
		test_class.record_grade("Able, Sam"     , i*10+50, i);
		test_class.record_grade("Baker, Mary"   , i*10+50, i);
		test_class.record_grade("Smith, Joe"    , i*10+50, i);
		test_class.record_grade("Mouse, Micky"  , i*10+50, i);
		test_class.record_grade("Gadot, Waiting", i*10+50, i);
	}
	std::cout << "Final" << std::endl;
	test_class.print_grades();
	std::cout << '\n';

	return 0;
}
