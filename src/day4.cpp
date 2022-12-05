#include <vector>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <algorithm>
#include <iterator>

int readInput(std::string fileName);

int main() {
    std::cout << readInput("../../inputs/day4_input.txt");
}

int readInput(std::string fileName) {
    std::ifstream file(fileName);
    std::string line;
    int val = 0;
    int r1start, r1end, r2start, r2end;
    while (getline(file, line)) {
        std::stringstream s(line);
        s >> line;
        r1start = stoi(line.substr(0, line.find('-')));
        r1end = stoi(line.substr((line.find('-') + 1), (line.find(',') - line.find('-') - 1)));
        line = line.substr(line.find(',') + 1);
        r2start = stoi(line.substr(0, line.find('-')));
        r2end = stoi(line.substr((line.find('-') + 1), (line.find(',') - line.find('-') - 1)));

        //std::cout << r1start << ' ' << r1end << '\n';
        //std::cout << r2start << ' ' << r2end << '\n';

        if ((r1start <= r2start && r1end >= r2end) || (r1start >= r2start && r1end <= r2end)) {
            val++;
        } else if ((r1start <= r2start && r2start <= r1end) || (r1start <= r2end && r2end <= r1end)) {
            val++;
        }
    }        
    return val;
}