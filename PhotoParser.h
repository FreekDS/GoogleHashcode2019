#ifndef HASHCODE_PHOTOPARSER_H
#define HASHCODE_PHOTOPARSER_H

#include <set>
#include <string>
#include <vector>

using namespace std;

struct Photo {
    std::set<std::string> tags;
};

int calculatescore(const vector<Photo>& photos);

class PhotoParser {
public:
    vector<Photo> parseInput(const std::string& in_file);
};


#endif //HASHCODE_PHOTOPARSER_H
