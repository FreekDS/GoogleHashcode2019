#include <iostream>
#include "poging1.h"

int main(int argc, char* argv[])
{
    std::cout << "Hello Pizza lovers!" << std::endl << std::endl;

    Pizza p = PizzaParser::parse("input/b_small.in");
    auto sol=poging1(p);
    p.slices = sol;
    std::cout << "Score: " << p.calculateScore() << std::endl;
    return EXIT_SUCCESS;
}
