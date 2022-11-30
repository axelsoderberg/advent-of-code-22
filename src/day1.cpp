#include <vector>
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>



int main() {
    
    return 1;
}

// return what we need
std::vector<std::string> readInput(std::string fileName) {
    std::ifstream file(fileName);
    std::string line;
    //std::vector<std::string> 

    while (getline(file, line))
    {
        std::istringstream atom(line); 
        // Handle line    
        // append to something
    }

    file.close(); 
    //return input;
}