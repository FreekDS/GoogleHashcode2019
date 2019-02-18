#include <PizzaParser.h>
#include <fstream>
#include <sstream>

Pizza PizzaParser::parse(const std::string& file_name)
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

void PizzaParser::generateOutput(const Pizza& pizza, const std::string& file_name)
{
    std::string file = "out/" + file_name;
    std::ofstream outFile(file);
    if(!outFile.is_open())
        throw std::runtime_error("Cannot create file " + file);

    outFile << pizza.slices.size() << std::endl;
    for(const Slice& slice : pizza.slices)
        outFile << slice.first.x << " " << slice.second.x << " " << slice.first.y << " " << slice.second.y << std::endl;

    outFile.close();
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


int Pizza::countCells(const Slice& slice)
{
    const Position& start = slice.first;
    const Position& end = slice.second;
    int tempX = abs(static_cast<int>(end.x - start.x)) + 1;
    int tempY = abs(static_cast<int>(end.y - start.y)) + 1;
    return tempX * tempY;
}

int Pizza::calculateScore()
{
    int sum = 0;
    for(const auto& slice : slices)
        sum += Pizza::countCells(slice);
    return sum;
}
