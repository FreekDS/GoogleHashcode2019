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
    int id;
};

struct Slide{
    std::vector<Photo> photos;
};

int calculatescore(const vector<Slide>& slides);

const Photo& getOtherPhoto(const Photo& first, const vector<Photo>& others);

int getDifferentInts(vector<pair<Slide,int>> slides);

vector <pair<set<Slide>, int>> sortIntoSets(vector<pair<Slide, int>> slides);

class PhotoParser {
private:
    static vector<string> splitOnSpace(string line);
public:
    static vector<Photo> parseInput(const std::string& in_file);
    static void generateOutput(const std::string& out_file, const vector<Slide>& slides);

};


#endif //HASHCODE_PHOTOPARSER_H
