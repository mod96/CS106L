#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
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

vector<double> readNumbers(){
    vector<double> numbers;
    generate_n(back_inserter(numbers), 500, rand);
    return numbers;
}

int main(){
    auto courses = readCourses();
    auto numbers = readNumbers();
    // LOOK AT THIS!
    auto compareRating = [](const Course& c1, const Course& c2){
        return c1.rating < c2.rating;
    };
    sort(numbers.begin(), numbers.end());
    sort(courses.begin(), courses.end(), compareRating);


    copy(courses.begin(), courses.end(), ostream_iterator<Course>(cout,"\n"));
    return 0;
}