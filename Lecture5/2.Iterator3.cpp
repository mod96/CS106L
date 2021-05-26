#include <iostream>
#include <map>
using namespace std;

int main(){
    map<int, int> m;
    pair<int, int> temp;
    temp.first = 0; temp.second = 1;
    m.insert(temp);
    m.insert({1, 2});
    m.insert(make_pair(2,3));
    map<int, int>::iterator i = m.begin();
    map<int, int>::iterator end = m.end();
    while (i != end){
        cout << "key : " << (*i).first << "  val : " << (*i).second << endl;
        i++;
    }
}