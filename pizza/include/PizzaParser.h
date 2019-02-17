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

struct Position{
    unsigned int x;
    unsigned int y;
    Position(unsigned int posx,unsigned int posy):x(posx),y(posy){}
};

using Slice = std::pair<Position, Position>;

struct Pizza {
    std::vector<std::vector<Ingredients>> ingredients;
    int minIngredients;
    int sliceSize;
    int rowNum;
    int colNum;
    friend std::ostream& operator<<(std::ostream& os, const Pizza& pizza);
    std::vector<Slice> slices;
};


class PizzaParser {
private:
    static std::array<int, 4> splitOn(const std::string& input, char ch);

public:
    static Pizza parse(const std::string& file_name);

    static void generateOutput(const Pizza& pizza, const std::string& file_name = "output.out");
};

#endif //PIZZAPROBLEM_PIZZAPARSER_H
