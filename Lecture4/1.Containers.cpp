/*
1. Sequence Containers
    - array
    - vector
    - deque
    - forward_list
    - list
2. Container adaptors
    - stack
    - queue
    - priority_queue
3. Associative containers : based on ordering property of keys (keys need to be comparable)
    - set
    - multiset
    - map
    - multimap
4. Unordered associative containers : based on hash function. (keys need to be hashed)
    - unordered_set
    - unordered_multiset
    - unordered_map
    - unordered_multimap
*/

#include <iostream>
#include <sstream>
#include <map>

std::string GetLine(){
    std::string response;
    std::getline(std::cin, response);
    return response;
}

int main(){
    std::map<std::string, int> frequencyMap;

    std::cout << "Enter words. None to go to next step." << std::endl;
    while (true){
        std::cout << ">";
        std::string response = GetLine();
        if (response.empty()) break;
        std::istringstream stream(response);
        std::string word;
        while (stream >> word){
            ++frequencyMap[word];
        }
    }

    std::cout << "Enter words to look up. None to stop" << std::endl;
    while (true){
        std::cout << ">";
        std::string response = GetLine();
        if (response.empty()) break;

        if (frequencyMap.count(response)){
            std::cout << frequencyMap[response] << "entries found." << std::endl;
        } else {
            std::cout << "None." << std::endl;
        }
    }

    return 0;
}