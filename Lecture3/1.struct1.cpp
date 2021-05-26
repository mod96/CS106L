#include <iostream>
using namespace std;

struct PriceRange{
    int min; 
    int max;
};

PriceRange findPriceRange(int dist){
    int min = static_cast<int>(dist * 0.08 + 100);
    int max = static_cast<int>(dist * 0.36 + 750);
    return PriceRange{min, max};
}

int main(){
    int dist = 6452;
    auto p = findPriceRange(dist);  // actually we can use & for referenced function value
    /*
    auto [min, max] = findPriceRange(dist);
    cout << min << max << endl;
    */
    cout << "you can find prices between : " << p.min << " and " << p.max << endl;
    return 0;
}