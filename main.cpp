#include <iostream>
#include "PhotoParser.h"


using namespace std;

int main(int argc, char* argv[])
{
    auto photos = PhotoParser::parseInput("in/a_example.txt");
//    return 0;

    Photo p1=Photo();
    Photo p2=Photo();
    p1.dir=VERTICAL;
    p2.dir=VERTICAL;
    p1.tags={"sun","beach"};
    p2.tags={"sun","bier"};

    auto i=getOtherPhoto(p1,{p2},3,{"sun","beach","bier"});
    return 0;

}
//vector van pair (slides en ints(hoeveel tags in de slide))

//sort tags
