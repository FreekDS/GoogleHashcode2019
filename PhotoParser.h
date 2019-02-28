#ifndef HASHCODE_PHOTOPARSER_H
#define HASHCODE_PHOTOPARSER_H

#include <set>
#include <string>
#include <vector>

using namespace std;

enum Direction{
    HORIZONTAL,
    VERTICAL
};

struct Photo {
    std::set<std::string> tags;
    Direction dir;
};

int calculatescore(const vector<Photo>& photos);

class PhotoParser {
public:
    vector<Photo> parseInput(const std::string& in_file);
};


#endif //HASHCODE_PHOTOPARSER_H
