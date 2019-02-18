#include <iostream>
#include "poging1.h"

/**
 * Run the program
 * @param argc Argument count
 * @param argv Array of arguments, this program requires one: the input file path
 * @return EXIT_SUCCESS if the program terminated correctly
 */
int main(int argc, char* argv[])
{
    if(argc < 2)
        return EXIT_FAILURE;
    std::string file = argv[1];
    std::cout << "Hello Pizza lovers!" << std::endl << std::endl;
    Pizza p = PizzaParser::parse(file);
    auto sol=poging1(p);
    p.slices = sol;
    std::cout << "Score: " << p.calculateScore() << std::endl;
    PizzaParser::generateOutput(p, "c_medium");
    return EXIT_SUCCESS;
}
