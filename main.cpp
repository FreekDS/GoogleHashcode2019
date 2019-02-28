#include <iostream>
#include "PhotoParser.h"


using namespace std;

int main(int argc, char* argv[])
{
    auto photos = PhotoParser::parseInput("in/a_example.txt");

    return 0;
}
//vector van pair (slides en ints(hoeveel tags in de slide))

//sort tags
