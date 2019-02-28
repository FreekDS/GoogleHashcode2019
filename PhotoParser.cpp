#include "PhotoParser.h"
#include <fstream>
#include <algorithm>


void PhotoParser::generateOutput(const std::string &out_file, const vector<Slide> &slides) {
    ofstream out(out_file);
    if(!out.is_open())
        throw runtime_error("foute out file he vriend");
    out << slides.size() << endl;
    for(const auto& slide : slides) {
        string line;
        for(const auto& ph : slide.photos){
            line += to_string(ph.id);
            line += ' ';
        }
        line.pop_back();
        out << line.substr() << endl;
    }
    out.close();
}

int compareTags(Slide slide1, Slide slide2) {
    int count = 0;
    for(auto& photo1 : slide1.photos){
        for(auto& tag1 : photo1.tags){
            for(auto& photo2 : slide2.photos){
                for(auto& tag2 : photo2.tags) {
                    if(tag1 == tag2)
                        count++;
                }
            }
        }
    }
    return count;
}

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

int calculatescore(const vector<Slide> &slides) {
    if(slides.size()<2)return 0;
    int total=0;
    for (int i = 0; i < slides.size(); ++i) {

        int score1=0;
        int score2=0;
        int score3=0;
        Slide s1=slides[i];
        Slide s2=slides[i+1];
        std::set<string> tags1;
        for(auto i:s1.photos){
            for(auto j:i.tags) tags1.insert(j);
        }
        std::set<string> tags2;
        for(auto i:s2.photos){
            for(auto j:i.tags) tags2.insert(j);
        }

        for(auto i:tags1){
            bool search=false;
            for(auto j:tags2){
                if(j==i) search=true;
            }
            if(search){
                score1++;
            }else{
                score2++;
            }

        }
        for(auto i:tags2) {
            bool search = false;
            for (auto j:tags1) {
                if (j == i) search = true;
            }
            if (!search) {
                score3++;
            }
        }
        total+=std::min(score1,std::min(score2,score3));

    }
    return total;
}

const Photo getOtherPhoto(const Photo& first, const vector<Photo>& others,int minSize,std::vector<std::string> containing) {
    int check = 999999999;
    int tagsInCommon = 0;
    Photo toretrun =Photo();
    std::vector<int> todelete;
    for (int i = 0; i < containing.size(); ++i) {
        for(auto j:first.tags){
            if(j==containing[i]){
                todelete.emplace_back(i);
            }
        }
    }
    int throwback=0;
    for(auto i:todelete){
        containing.erase(containing.begin()+(i-throwback));
        throwback++;
    }
    for(const Photo& other : others) {
        if(other.dir == HORIZONTAL)
            continue;
        int newtags=0;
        for(auto i :other.tags){
            for(auto j:first.tags){
                if(i==j)newtags++;
            }
        }
        if(first.tags.size()+newtags<minSize)continue;
        std::set<string> hasthem;
        for(auto i:other.tags){
            for(auto j:containing){
                if(i==j)hasthem.insert(i);
            }
        }
        if(hasthem.size()!=containing.size())continue;
        for(const auto& tagFirst : first.tags)
            for(const auto& tagOther : other.tags){
                if(tagFirst == tagOther)
                    tagsInCommon++;
            }
        if(tagsInCommon <= check) {
            toretrun=other;
            check=other.tags.size();
            tagsInCommon=0;
        }
    }
    // none found, take the first one:
//    for(const auto& ph : others)
//        if(ph.dir == VERTICAL)
//            return ph;

    return toretrun; // !!! als geen gevonden return dezelfde foto
}

map<int, set<pair<Slide, int>>> sortIntoSets(vector<pair<Slide, int>> slides) {
    vector<pair<set<Slide>, int>> result;
    map<int, set<pair<Slide, int>>> mapje;
    for(auto vroem : slides ){
        mapje[vroem.second].insert(vroem);
    }
    return mapje;
}

int getDifferentInts(vector<pair<Slide, int>> slides) {
    set<int> ints;
    for(auto sl : slides){
        ints.insert(sl.second);
    }
    return ints.size();
}

std::vector<Slide> getFirstInSet(set<Slide> einde,set<Slide> slideset){
    int matchneeded=0;
    Slide i =*einde.begin();
    if(i.photos.size()==1){
        matchneeded=i.photos[0].tags.size()/2;
    }else{
        std::set<std::string> tags;
        for(auto j:i.photos){
            for(auto h:j.tags){
                tags.insert(h);
            }
        }
        matchneeded=tags.size()/2;
    }

    for(auto i:einde){
        for(auto j:slideset){
            if(compareTags(i,j)==matchneeded){
                einde.erase(i);
                return {i,j};
            }
        }
    }

    matchneeded--;
    if(matchneeded<0){
        return {};
    }
}

bool Slide::operator<(const Slide &rhs) const {
    return photos < rhs.photos;
}

bool Slide::operator>(const Slide &rhs) const {
    return rhs < *this;
}

bool Slide::operator<=(const Slide &rhs) const {
    return !(rhs < *this);
}

bool Slide::operator>=(const Slide &rhs) const {
    return !(*this < rhs);
}

bool Photo::operator<(const Photo &rhs) const {
    return id < rhs.id;
}

bool Photo::operator>(const Photo &rhs) const {
    return rhs < *this;
}

bool Photo::operator<=(const Photo &rhs) const {
    return !(rhs < *this);
}

bool Photo::operator>=(const Photo &rhs) const {
    return !(*this < rhs);
}
