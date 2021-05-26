#include <iostream>
#include <vector>

void MergeSort(std::vector<int> &arr);
void printArray(std::vector<int> arr);

int main(){
    std::vector<int> arr = {12, 11, 13, 14, 9, 7, 5, 4, 3, 2, 1};
    printArray(arr);
    MergeSort(arr);
    printArray(arr);
    return 0;
}

/*
vector<int> v; create an empty vector
vector<int> v(n); vreate a vector with n copies of zero = vector<int> v(n, 0);
v.push_back(k); Add k to the end of the vector
v.clear(); Clear vector
v.empty; check if the vector is empty
v.at(n) vs v[at]  <- this related to memory?
*/

void MergeSort(std::vector<int> &arr){
    if (arr.size() > 1){
        int temp = arr.size();
        const int size_left = arr.size() / 2;
        const int size_right = arr.size() - size_left;
        std::vector<int> left(size_left), right(size_right);

        //Copy left, right and sort each
        for (int i=0; i<size_left;i++){
            left[i] = arr[i];
        }
        for (int i=0; i<size_right;i++){
            right[i] = arr[i+size_left];
        }
        MergeSort(left);
        MergeSort(right);

        //Merge
        int cnt = 0, i = 0, j = 0;
        while (i < size_left && j < size_right){
            if (left[i] < right[j]){
                arr[cnt] = left[i];
                i++; cnt++;
            }
            else{
                arr[cnt] = right[j];
                j++; cnt++;
            }
        }
        while (i < size_left){
            arr[cnt] = left[i];
            i++; cnt++;
        }
        while (j < size_right){
            arr[cnt] = right[j];
            j++; cnt++;
        }
    }
}

void printArray(std::vector<int> arr){
    std::cout << "The Array is : ";
    for (int i = 0; i < arr.size(); i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}