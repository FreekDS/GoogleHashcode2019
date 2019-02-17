#include <iostream>
#include "poging1.h"

int main(int argc, char* argv[])
{
    std::cout << "Hello Pizza lovers!" << std::endl << std::endl;

    Pizza p = PizzaParser::parse("input/a_example.in");
    auto sol=poging1(p);
    std::cout << p << std::endl;


    Slice slice;
    slice.first.x = 5;
    slice.first.y = 6;
    slice.second.x = 1;
    slice.second.y = 3;

    std::cout << Pizza::countCells(slice) << std::endl;

    return EXIT_SUCCESS;
}
