#include <vector>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <algorithm>
#include <iterator>

constexpr int NBR_OF_STACKS = 9;

struct instr {
    int crates;
    int from;
    int to;
};

std::vector<std::vector<char>> readStacksInput(std::string fileName);
std::vector<instr> readInstrInput(std::string fileName);
void doInstruction(int crates, std::vector<char> &from, std::vector<char> &to);
void printStacks(std::vector<std::vector<char>> stacks);
void printTopLayer(std::vector<std::vector<char>> stacks);


int main() {
    std::vector<std::vector<char>> stacks = readStacksInput("../../inputs/day5_input.txt");
    std::vector<instr> instructions = readInstrInput("../../inputs/day5_input.txt");
    for (instr i : instructions) {
        doInstruction(i.crates, stacks.at(i.from - 1), stacks.at(i.to - 1));
    }
    printTopLayer(stacks);
    return 1;
}

std::vector<std::vector<char>> readStacksInput(std::string fileName) {
    std::vector<std::vector<char>> stacks;
    for (int sIndex = 1; sIndex <= NBR_OF_STACKS * 4; sIndex += 4) {
        std::ifstream file(fileName);
        std::string line;
        std::vector<char> stack;
        while (getline(file, line)) {
            char c = line.at(sIndex);
            if (isdigit(c)) {
                break;
            }
            if (!isspace(c)) {
                stack.push_back(c);
            }
        }
        file.close();
        std::reverse(stack.begin(), stack.end());
        stacks.push_back(stack);
    }
    // printStacks(stacks);
    return stacks;
}

std::vector<instr> readInstrInput(std::string fileName) {
    std::ifstream file(fileName);
    std::string line;
    std::vector<instr> instructions;
    int ignore;
    while (getline(file, line)) {
        instr i;
        if (!line.rfind("move", 0) == 0)
            continue;
        else {
            std::stringstream l(line);
            l >> line;
            l >> line;
            i.crates = stoi(line);
            l >> line;
            l >> line;
            i.from = stoi(line);
            l >> line;
            l >> line;
            i.to = stoi(line);
            std::cout << "C: " << i.crates << " From :" << i.from << " To: " << i.to << "\n";
            instructions.push_back(i);
        }

    }
    file.close();
    return instructions;
}

void printStacks(std::vector<std::vector<char>> stacks) {
    for (std::vector stack : stacks) {
        for (char c : stack) {
            std::cout << c << " ";
        }
        std::cout << "\n";
    }
}

void printTopLayer(std::vector<std::vector<char>> stacks) {
    for (std::vector stack : stacks) {
        std::cout << stack.back();
    }
    std::cout << "\n";
}

void doInstruction(int crates, std::vector<char> &from, std::vector<char> &to) {
    std::vector<char> moves;
    for (int c = 0; c < crates; c++) {
        char move = from.back();
        from.pop_back();
        moves.push_back(move);
    }
    for (int c = 0; c < crates; c++) {
        char move = moves.back();
        moves.pop_back();
        to.push_back(move);
    }
}
