#include <vector>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <algorithm>
#include <iterator>

std::vector<int> readInput(std::string fileName);
int getMaxElement(std::vector<int> list);

int main() {
    std::cout << "Highest cal value: " << getMaxElement(readInput("../../inputs/day1_input.txt"));

    return 1;
}

std::vector<int> readInput(std::string fileName) {
    std::ifstream file(fileName);
    std::stringstream is;
    std::vector<int> values;
    std::string s;
    int val = 0;
    if (file) {
        is << file.rdbuf();    
        file.close();
 }

    while (getline(is, s)) {
        if (s.empty() || s == "\n") {
            values.push_back(val);
            val = 0;
            continue;
        } 
        val += stoi(s);
    }
    return values;
}

int getMaxElement(std::vector<int> list) {
    int highest = 0;
    std::sort(list.begin(), list.end());
    int n = list.size();
    return list.at(n - 1) + list.at(n - 2) + list.at(n - 3);
}