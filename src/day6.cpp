#include <vector>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <algorithm>
#include <iterator>
#include <unordered_set>

int readInput(std::string fileName);
int readInputForMessage(std::string fileName);

int main() {
    std::cout << readInputForMessage("../../inputs/day6_input.txt");
    return 1;
}

int readInput(std::string fileName) {
    std::ifstream file(fileName);
    std::string line;
    while (getline(file, line)) {
        for (int i = 3; i < line.size() - 1; i++) {
            char c = line.at(i);
            std::unordered_set<char> cs = {c, line.at(i - 1), line.at(i - 2), line.at(i - 3)};
            if (cs.size() == 4) {
                return i + 1;
            }
        }
    }
    return 0;
}

int readInputForMessage(std::string fileName) {
    std::ifstream file(fileName);
    std::string line;
    while (getline(file, line)) {
        for (int i = 14; i < line.size() - 1; i++) {
            char c = line.at(i);
            std::unordered_set<char> cs;
            for (int j = 0; j < 14; j++) {
                cs.insert(line.at(i - j));
            }
            if (cs.size() == 14) {
                return i + 1;
            }
        }
    }
    return 0;
}