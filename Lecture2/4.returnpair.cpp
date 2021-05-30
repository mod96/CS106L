#include <iostream>
using namespace std;

pair<int, int> findPriceRange(int dist){
    int min = static_cast<int>(dist * 0.08 + 100);
    int max = static_cast<int>(dist * 0.36 + 750);
    return make_pair(min, max);
}

int main(){
    int dist = 6452;
    pair<int, int> p = findPriceRange(dist);  // actually we can use & for referenced function value
    /*
    auto [min, max] = findPriceRange(dist);  // C++17 unpack seems doesn't work....
    cout << min << max << endl;
    */
    cout << "you can find prices between : " << p.first << " and " << p.second << endl;
    return 0;
}