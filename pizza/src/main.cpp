#include <iostream>
//#include "poging1.h"
#include "poging2.h"

/**
 * Run the program
 * @param argc Argument count
 * @param argv Array of arguments, this program requires one: the input file path
 * @return EXIT_SUCCESS if the program terminated correctly
 */
int main(int argc, char* argv[])
{
    if(argc < 2) {
        std::cout << "no input path given" << std::endl;
        return EXIT_FAILURE;
    }
    std::string file = argv[1];
    std::cout << "Hello Pizza lovers!" << std::endl << std::endl;
    Pizza p = PizzaParser::parse(file);
    auto sol=poging2(p);
    p.slices = sol;
    std::cout << "Score: " << p.calculateScore() << std::endl;
    PizzaParser::generateOutput(p, "a_example");


    return EXIT_SUCCESS;
}
