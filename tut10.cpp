#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::string fileName;
    std::cout << "Enter the file name: ";
    std::cin >> fileName;

    // Open the file
    std::ifstream inputFile(fileName.c_str());

    // Check if the file is opened successfully
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }

    std::string line;
    int wordCount = 0;

    // Read the file line by line
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string word;

        // Count words in each line using stringstream
        while (ss >> word) {
            wordCount++;
        }
    }

    // Close the file
    inputFile.close();

    std::cout << "Total word count: " << wordCount << std::endl;

    return 0;
}

