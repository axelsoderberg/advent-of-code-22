#include <vector>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <algorithm>
#include <iterator>

std::vector<std::string> readInput(std::string fileName);
char getPrioItem(std::string s);
char getGroupPrioItem(std::vector<std::string> s);
int getPrioVal(char p);
int getMaxElement(std::vector<int> list);

int main() {
    int sum = 0;
    std::vector<std::string> knapsacks = readInput("../../inputs/day3_input.txt");
    for (int i = 2; i <= knapsacks.size() - 1; i += 3) {
        std::vector<std::string> group;
        group.push_back(knapsacks.at(i));
        group.push_back(knapsacks.at(i - 1));
        group.push_back(knapsacks.at(i - 2));
        sum += getPrioVal(getGroupPrioItem(group));
    }
    std::cout << sum;
    return 1;
}

std::vector<std::string> readInput(std::string fileName) {
    std::ifstream file(fileName);
    std::stringstream is;
    std::vector<std::string> strs;
    std::string line;
    int val = 0;
    while (getline(file, line)) {
        std::stringstream s(line);
        s >> line;
        strs.push_back(line);
    }        
    return strs;
}

char getPrioItem(std::string s) {
    std::string comp1 = s.substr(0, s.length() / 2);
    std::string comp2 = s.substr(s.length() / 2);
    for (char c : comp1) {
        int pos = comp2.find(c);
        if (pos != -1) {
            return comp2.at(pos);
        }
    }
}

char getGroupPrioItem(std::vector<std::string> s) {
    std::string comp1 = s.at(0);
    std::string comp2 = s.at(1);
    std::string comp3 = s.at(2);

    for (char c : comp1) {
        int pos = comp2.find(c);
        if (pos != -1) {
            pos = comp3.find(c);
            if (pos != -1) {
                return comp3.at(pos);
            }
        }
    }
}

int getPrioVal(char p) {
    if (p >= 65 && p <= 90) {
        return p - 38;
    } else if (p >= 97 && p <= 122) {
        return p - 96;
    }
}