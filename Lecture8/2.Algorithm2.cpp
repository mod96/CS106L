#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
#include <iterator>
using namespace std;

struct Course{
    string name;
    double rating;
};

/*
This function allows you to print a Course struct to any  ostream.
Usage:  std::cout << c << std::endl;
*/
ostream& operator << (ostream& os, const Course& c){
    os << setw(15) << setfill(' ') << c.name << "   " << c.rating;
    return os;
}

vector<Course> readCourses(){
    vector<Course> v = {{"CS 106A", 4.4337}, {"CS 106B", 4.4025}, {"CS 107", 4.6912}, {"CS 103", 4.0532},
    {"CS 109", 4.6062}, {"CS 110", 4.343}, {"Math 53", 4.3111}, {"Econ 1", 4.2552}, {"CS 251", 4.24}};
    return v;
}

int main(){
    auto courses = readCourses();
    // LOOK AT THIS!
    string department = "CS";
    auto isDep = [department](auto elt){
        return elt.name.size() > 2 && elt.name.substr(0,2) == department;
    };
    vector<Course> csCourses;
    copy_if(courses.begin(), courses.end(), back_inserter(csCourses), isDep);  
    // output iterator must be expandable. csCourses.begin() does not work.
    // Like This, below copy works. elt in csCourses goes to ostream_iterator(cout)

    copy(csCourses.begin(), csCourses.end(), ostream_iterator<Course>(cout,"\n"));
    return 0;
}