#include <PizzaParser.h>
#include <fstream>
#include <sstream>

Pizza PizzaParser::parseFile(const std::string& file_name)
{
    std::ifstream in(file_name);
    std::string line;
    std::getline(in, line);

    // First line contains information about pizza
    auto properties = splitOn(line, ' ');
    int rowNum = properties[0];
    int colNum = properties[1];
    int minIngredients = properties[2];
    int maxIngredients = properties[3];

    Pizza pizza;
    pizza.rowNum = rowNum;
    pizza.colNum = colNum;
    pizza.minIngredients = minIngredients;
    pizza.sliceSize = maxIngredients;

    while (std::getline(in, line)) {
        if (line.empty() || line=="\n")
            continue;

        std::vector<Ingredients> row;

        for (const char& c : line) {
            if (c=='M') {
                row.push_back(MUSHROOM);
            }
            else if (c=='T')
                row.push_back(TOMATO);
            else if (c=='\n') {
                continue;
            }
            else
                throw std::runtime_error("Invalid type: "+std::to_string(c));
        }
        pizza.ingredients.push_back(row);
    }
    if (pizza.ingredients.size()>colNum)
        throw std::runtime_error("Invalid file format");
    in.close();
    return pizza;
}

void PizzaParser::generateOutput(const std::vector<Slice>& slices, const std::string& file_name)
{

}

std::array<int, 4> PizzaParser::splitOn(const std::string& input, char ch = ' ')
{
    std::stringstream sstr(input);
    std::string segment;
    std::array<int, 4> result{};
    int i = 0;
    while (std::getline(sstr, segment, ch)) {
        if (i>=4)
            throw std::runtime_error("Invalid first line of file");
        result[i] = std::stoi(segment);
        i++;
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Pizza& pizza)
{
    os << "--Pizza----------------------------------------" << std::endl;
    os << "#Rows: " << pizza.rowNum << '\t' << "#Columns: " << pizza.colNum << std::endl <<"Minimum ingredients per slice: "
       << pizza.minIngredients << "\tMaximum slice size: " << pizza.sliceSize << std::endl << std::endl;
    for (const auto& row : pizza.ingredients) {
        for (const Ingredients& ingredient : row) {
            if (ingredient==MUSHROOM)
                os << "M";
            if (ingredient==TOMATO)
                os << "T";

        }
        os << std::endl;
    }
    os << "-----------------------------------------------" << std::endl;
    return os;
}
