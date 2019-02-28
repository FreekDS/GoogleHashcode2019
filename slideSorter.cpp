

#include "slideSorter.h"

std::vector<Slide> slideSorter::sort(std::vector<Slide>& slides) {

    std::vector<Slide > order;

    std::vector<std::pair<Slide, int> > slidesTags;

    for(auto slide: slides){
        int tags = countTags(slide);
        std::pair<Slide, int> slideTag = std::make_pair(slide, tags);
        slidesTags.emplace_back(slideTag);
    }

    std::map<int, std::set<Slide> > setsOfSlidesMap = sortIntoSets(slidesTags);


    int counter = 1;
    std::set<Slide > trash;


    while(setsOfSlidesMap.find(counter) != setsOfSlidesMap.end()) {
       std::set<Slide > setsOfSlides = setsOfSlidesMap.at(counter);

       Slide firstSlide; //todo assign firstSlide


       if(counter == 1){
           firstSlide = *setsOfSlides.begin();
       }else{
           std::vector<Slide > lastFirst = getFirstInSet(trash, setsOfSlides);


           firstSlide = lastFirst.at(1);
       }


       setsOfSlides.erase(firstSlide);
       std::vector<Slide> insideOrder = sortInsideSet(firstSlide, setsOfSlides);

       trash = setsOfSlides;

       for(auto slide: insideOrder){
           order.emplace_back(slide);
       }

       counter++;
    }
}

int slideSorter::countTags(Slide slide) {
    int nrTags = slide.photos.at(0).tags.size();


    if(slide.photos.size() == 1){
        nrTags += slide.photos.at(0).tags.size();
    }

    return nrTags;
}

std::vector<Slide>  slideSorter::sortInsideSet(Slide begin, std::set<Slide>& slidesInSet) {
    std::vector<Slide> order;
    order.emplace_back(begin);

    int amountOfTags = begin.photos.at(0).tags.size();

    if(begin.photos.size() == 1){
        amountOfTags += begin.photos.at(1).tags.size();
    }

    int scenario = std::floor((amountOfTags / 2));

    Slide current = begin;
    while(true)  {

        std::set<Slide> stringOfSlides;

        for (auto slide:slidesInSet) {
            if(scenario == compareTags(current, slide)) {
                stringOfSlides.insert(slide);
                slidesInSet.erase(slide);
            }
        }

        if(stringOfSlides.empty()){
            break;
        }

        for(auto slide: stringOfSlides){
            order.emplace_back(slide);
        }

        current = *slidesInSet.begin();
        slidesInSet.erase(slidesInSet.begin());
    }



}