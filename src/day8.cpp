#include <vector>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>
#include <algorithm>
#include <iterator>
#include <unordered_set>

std::vector<std::vector<int>> readInput(std::string fileName);
void printTrees(std::vector<std::vector<int>> stacks);
int visible(std::vector<std::vector<int>> ts, int x, int y);
std::vector<int> getCol(std::vector<std::vector<int>> ts, int colIndex);

int main() {
    std::vector<std::vector<int>> trees = readInput("../../inputs/day8_input.txt");
    int score = 0;
    int hScore = 0;
    for (int i = 0; i < trees.size(); i++) {
        for (int j = 0; j < trees.at(i).size(); j++) {
            score = visible(trees, i, j);
            if (score > hScore) {
                hScore = visible(trees, i, j);
            }

        }
    }
    std::cout << hScore;
    return 1;
}

std::vector<std::vector<int>> readInput(std::string fileName) {
    std::ifstream file(fileName);
    std::string line;
    std::vector<std::vector<int>> lines;

    // Get rows
    while (getline(file, line)) {
        std::vector<int> row;
        for (int i = 0; i < line.size(); i++)
            row.push_back(line.at(i) - '0');
        lines.push_back(row);
    }
    return lines;
}

std::vector<int> getCol(std::vector<std::vector<int>> ts, int colIndex) {
    std::vector<int> col;
    for (std::vector<int> r : ts)
        col.push_back(r.at(colIndex));
    return col;
}

int visible(std::vector<std::vector<int>> ts, int x, int y) {
    std::vector<int> row = ts.at(x);
    std::vector<int> col = getCol(ts, y);
    int height = row.at(y);
    int scenic = 0;
    int s1, s2, s3, s4;

    // Look for higher tree to the left
    for (int i = y - 1; i >= 0; i--) {
        if (row.at(i) >= height) {
            scenic++;
            break;
        }
        if (row.at(i) < height) {
            scenic++;
        }
    }
    s1 = scenic;
    scenic = 0;

    // Right
    for (int i = y + 1; i < row.size(); i++) {
       if (row.at(i) >= height) {
            scenic++;
            break;
        }
        if (row.at(i) < height) {
            scenic++;
        }
    }
    s2 = scenic;
    scenic = 0;

    // Top
    for (int i = x - 1; i >= 0; i--) {
       if (col.at(i) >= height) {
            scenic++;
            break;
        }
        if (col.at(i) < height) {
            scenic++;
        }
    }
    s3 = scenic;
    scenic = 0;

    // Bottom
    for (int i = x + 1; i < col.size(); i++) {
       if (col.at(i) >= height) {
            scenic++;
            break;
        }
        if (col.at(i) < height) {
            scenic++;
        }
    }
    s4 = scenic;
    return s1 * s2 * s3 * s4;
}

void printTrees(std::vector<std::vector<int>> stacks) {
    int x = 0;
    for (std::vector stack : stacks) {
        for (int t : stack) {
            std::cout << t;
        }
        std::cout << "\n";

    }
}
