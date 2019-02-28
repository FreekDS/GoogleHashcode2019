#include "PhotoParser.h"
#include <fstream>


vector<Photo> PhotoParser::parseInput(const std::string &in_file) {
    ifstream input(in_file);
    if(!input.is_open())
        throw runtime_error("Foute file he vriend");
    std::string line;
    getline(input, line);
    int amountOfPics = stoi(line);
    vector<Photo> result(amountOfPics);
    int index = 0;
    while(getline(input, line)){
        auto l = splitOnSpace(line);
        Photo photo;
        if(l[0] == "H")
            photo.dir = HORIZONTAL;
        else
            photo.dir = VERTICAL;
        // l[1] == # of tags, not needed
        for(int i = 2; i < l.size(); i++) {
            std::string tag = l[i];
            photo.tags.insert(l[i]);
        }
        result[index] = photo;
        index++;
    }
    input.close();
    return result;
}

vector<string> PhotoParser::splitOnSpace(string line) {
    vector<string> result;
    std::string current;
    for(char c : line){
        if(c == ' ' || c == '\n') {
            result.push_back(current);
            current.clear();
        }
        else{
            current += c;
        }
    }
    result.push_back(current);
    return result;
}



