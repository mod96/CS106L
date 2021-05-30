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
    cout << "Size of the vector : " << courses.size() << endl;
    remove_if(courses.begin(), courses.end(), isDep);
    // THINK IT'S NOT GOOD TO USE THIS.
    // rmv all cs courses (not actual rmv. can't change the size. it just moves stuffs to the backward)
    // and it can fail because it need to change "CS" to the elt comewhere in the back, which can be also "CS".
    
    cout << "Size of the vector : " << courses.size() << endl;
    copy(courses.begin(), courses.end(), ostream_iterator<Course>(cout,"\n"));
    return 0;
}

/*
HW problem: implement rmv
template <typename ForwardIt, typename Unipred>
ForwardIt remove_if(ForwardIt first, ForwardIt last, UniPred pred){
    //TODO
}
*/