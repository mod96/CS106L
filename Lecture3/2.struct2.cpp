#include <string>
#include <vector>
using namespace std;

struct Time{int hour; int minute;};
struct Course{
    string code;
    Time startTime; Time endTime;
    vector<string> instructors;
};

int main(){
    vector<int> vec{3, 1, 4, 1, 5, 9};
    Course now {"CS106L", {15, 30}, {16, 30}, {"Wang", "Zeng"}};

    return 0;
}
