
#ifndef HASHCODE_SLIDESORTER_H
#define HASHCODE_SLIDESORTER_H

#include <map>
#include <algorithm>
#include <limits>
#include <cmath>

#include "PhotoParser.h"

class slideSorter {

    std::vector<Slide > sortInsideSet(Slide begin, std::set<Slide>& slidesInSet);

    int countTags(Slide slide);

    std::vector<Slide> sort(std::vector<Slide>& slides);
};


#endif //HASHCODE_SLIDESORTER_H
