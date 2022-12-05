#include <vector>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <algorithm>
#include <iterator>

int readInput(std::string fileName);
int calcRound(char a, char b);
int calcRoundFromOutcome(char a, char outcome);

int main() {
    std::cout << readInput("../../inputs/day2_input.txt");
    return 1;
}

int readInput(std::string fileName) {
    std::ifstream file(fileName);
    std::vector<int> rounds;
    int sum = 0;
    std::string s;
    int val = 0;
    char a;
    char b;
    while (getline(file, s)) {
        std::stringstream round(s);
        round >> a;
        round >> b;
        sum += calcRoundFromOutcome(a, b);
        std::cout << sum << "\n";
        
    }
    return sum;
}

int calcRound(char a, char b) {
    int shapeScore = 0;
    std::cout << a << " " << b << "\n";
    switch (b) {
        case 'X':
            shapeScore = 1;
            break;
        case 'Y':
            shapeScore = 2; 
            break;
        case 'Z':
            shapeScore = 3;
    }
    if ((a == 'A' && b == 'Y') || (a == 'B' && b == 'Z') || (a == 'C' && b == 'X'))
        return 6 + shapeScore;
    else if ((a == 'A' && b == 'Z') || (a == 'B' && b == 'X') || (a == 'C' && b == 'Y'))
        return 0 + shapeScore;
    else
        return 3 + shapeScore;
    return -1;
}

int calcRoundFromOutcome(char a, char outcome) {
    int roundScore = 0;
    char b;
    switch (outcome) {
        case 'X':
            roundScore = 0;
            break;
        case 'Y':
            roundScore = 3; 
            break;
        case 'Z':
            roundScore = 6;
    }

    if (roundScore == 0) {
        switch (a) {
            case 'A':
                return 3;
            case 'B':
                return 1;
            case 'C':
                return 2;
        }
    } else if (roundScore == 6) {
        switch (a) {
            case 'A':
                return roundScore + 2;
            case 'B':
                return roundScore + 3;
            case 'C':
                return roundScore + 1;
        }
    } else if (roundScore == 3) {
        switch (a) {
            case 'A':
                return roundScore + 1;
            case 'B':
                return roundScore + 2;
            case 'C':
                return roundScore + 3;
        }
    }
    return -1;
}