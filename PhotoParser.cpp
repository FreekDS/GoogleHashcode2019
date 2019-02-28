#include "PhotoParser.h"
#include <fstream>


vector<Photo> PhotoParser::parseInput(const std::string &in_file) {
    ifstream input(in_file);
    std::string line;
    getline(input, line);
    int amountOfPics = stoi(line);
    vector<Photo> result(amountOfPics);
    while(getline(input, line)){

    }
    return vector<Photo>();
}
