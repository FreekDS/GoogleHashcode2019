#ifndef PIZZAPROBLEM_PIZZAPARSER_H
#define PIZZAPROBLEM_PIZZAPARSER_H

#include <vector>
#include <array>
#include <string>
#include <ostream>

enum Ingredients {
    MUSHROOM,
    TOMATO
};

struct Pizza {
    std::vector<std::vector<Ingredients>> ingredients;
    int minIngredients;
    int sliceSize;
    int rowNum;
    int colNum;
    friend std::ostream& operator<<(std::ostream& os, const Pizza& pizza);
};

using Slice = std::pair<std::pair<unsigned int, unsigned int>, std::pair<unsigned int, unsigned int>>;

class PizzaParser {
private:
    static std::array<int, 4> splitOn(const std::string& input, char ch);

public:
    static Pizza parseFile(const std::string& file_name);

    static void generateOutput(const std::vector<Slice>& slices, const std::string& file_name);
};

#endif //PIZZAPROBLEM_PIZZAPARSER_H
