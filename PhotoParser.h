#ifndef HASHCODE_PHOTOPARSER_H
#define HASHCODE_PHOTOPARSER_H

#include <set>
#include <string>
#include <vector>
#include <map>

using namespace std;

enum Direction{
    HORIZONTAL,
    VERTICAL
};

struct Photo {
    std::set<std::string> tags;
    Direction dir;
    int id;

    bool operator<(const Photo &rhs) const;

    bool operator>(const Photo &rhs) const;

    bool operator<=(const Photo &rhs) const;

    bool operator>=(const Photo &rhs) const;
};

struct Slide{
    std::vector<Photo> photos;

    bool operator<(const Slide &rhs) const;

    bool operator>(const Slide &rhs) const;

    bool operator<=(const Slide &rhs) const;

    bool operator>=(const Slide &rhs) const;
};

int calculatescore(const vector<Slide>& slides);

const Photo getOtherPhoto(const Photo& first, const vector<Photo>& others,int minSize,std::vector<std::string> containing);

int getDifferentInts(vector<pair<Slide,int>> slides);

map<int, set<pair<Slide, int>>> sortIntoSets(vector<pair<Slide, int>> slides);

std::vector<Slide> getFirstInSet(set<Slide> einde,set<Slide> slideset);

int compareTags(Slide s1,Slide s2);

class PhotoParser {
private:
    static vector<string> splitOnSpace(string line);
public:
    static vector<Photo> parseInput(const std::string& in_file);
    static void generateOutput(const std::string& out_file, const vector<Slide>& slides);

};


#endif //HASHCODE_PHOTOPARSER_H
