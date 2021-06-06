#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>

using std::cout;    using std::cin;
using std::endl;    using std::string;
using std::vector;

const string kPath = "Lecture9/";
vector<string> createFeatureVec() {
    return {"a", "about", "above", "after", "again", "against", "all",
            "am", "an", "and", "any", "are", "aren't", "as", "at", "be",
            "because", "been", "before", "being", "below", "between", "both",
            "but", "by", "can't", "cannot", "could", "couldn't", "did", "didn't",
            "do", "does", "doesn't", "doing", "don't", "down", "during", "each",
            "few", "for", "from", "further", "had", "hadn't", "has", "hasn't",
            "have", "haven't", "having", "he", "he'd", "he'll", "he's", "her",
            "here", "here's", "hers", "herself", "him", "himself", "his", "how",
            "how's", "i", "i'd", "i'll", "i'm", "i've", "if", "in", "into", "is",
            "isn't", "it", "it's", "its", "itself", "let's", "me", "more", "most",
            "mustn't", "my", "myself", "no", "nor", "not", "of", "off", "on", "once",
            "only", "or", "other", "ought", "our", "ours", "ourselves", "out", "over",
            "own", "same", "shan't", "she", "she'd", "she'll", "she's", "should", "shouldn't",
            "so", "some", "such", "than", "that", "that's", "the", "their", "theirs", "them",
            "themselves", "then", "there", "there's", "these", "they", "they'd", "they'll", "they're",
            "they've", "this", "those", "through", "to", "too", "under", "until", "up", "very", "was",
            "wasn't", "we", "we'd", "we'll", "we're", "we've", "were", "weren't", "what", "what's", "when",
            "when's", "where", "where's", "which", "while", "who", "who's", "whom", "why", "why's", "with",
            "won't", "would", "wouldn't", "you", "you'd", "you'll", "you're", "you've", "your", "yours",
            "yourself", "yourselves", "!", "\"", "#", "$", "%", "&", "'", "(", ")", "*", "+", ",", "-", ".",
            "/", ":", ";", "<", "=", ">", "?", "@", "[", "\\", "]", "^", "_", "`", "{", "|", "}", "~"};
}

template <typename T>
void printVector(const vector<T>& v) {
    cout << "{";
    if(!v.empty()) {
        for(size_t i = 0; i < v.size()-1; ++i) {
            cout << v[i] << ", ";

        }
        cout << v[v.size()-1];
    }
    cout << "}" << endl;
}

string fileToString(std::ifstream &inp){
    if (!inp.is_open()){
        cout << "file not found" << endl;
    }
    string res, line;
    while (std::getline(inp, line)){
        std::transform(line.begin(),line.end(),line.begin(),std::tolower);
        res += line + ' ';
    }
    // string res = string((std::istreambuf_iterator<char>(inp)), std::istreambuf_iterator<char>());
    // cout << res << endl;
    return res;
}

int count_occurences(const string &text, string featur){
    string feature = ' ' + featur + ' ';
    size_t found = text.find(feature);
    int res = 0;
    while (found != string::npos){
        res++;
        found = text.find(feature, found+1);
    }
    return res;
}

vector<int> createDocVec(const string &text, const vector<string> &featureVec){
    vector<int> res;
    for (auto elt : featureVec){
        res.push_back(count_occurences(text, elt));
    }
    return res;
}

int mag(const vector<int> &vec){
    return std::sqrt(std::inner_product(vec.begin(),vec.end(),vec.begin(),0));
}


double getSimilarity(const string &text1, const string &text2, const vector<string> &featureVec){
    vector<int> vec1 = createDocVec(text1, featureVec);
    vector<int> vec2 = createDocVec(text2, featureVec);
    int dot_prod = std::inner_product(vec1.begin(),vec1.end(),vec2.begin(),0);
    int mag1 = mag(vec1);
    int mag2 = mag(vec2);
    if (mag1 == 0 || mag2 == 0) return -1; 
    else return (double)dot_prod/(mag1*mag2);
}


int main() {
    // create vector of function words
    vector<string> featureVec = createFeatureVec();
    // get text of the files and store in strings,
    std::ifstream file1(kPath + "madison.txt");
    std::ifstream file2(kPath + "hamilton.txt");
    std::ifstream file3(kPath + "jj.txt");
    std::ifstream file4(kPath + "unknown.txt");
    string f_m = fileToString(file1);
    string f_h = fileToString(file2);
    string f_j = fileToString(file3);
    string f_u = fileToString(file4);
    // computeSimilarity
    cout << "Similarity - madison <-> unknown:  "   << getSimilarity(f_m, f_u, featureVec) << endl;
    cout << "Similarity - hamilton <-> unknown:  "  << getSimilarity(f_h, f_u, featureVec) << endl;
    cout << "Similarity - jj <-> unknown:  "        << getSimilarity(f_j, f_u, featureVec) << endl;

    return 0;
}