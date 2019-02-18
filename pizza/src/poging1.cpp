#include <poging1.h>
#include <iostream>

bool checkEnoughIngredients(Pizza& p, Position& pos1, Position& pos2)
{
    int tom = 0;
    int mush = 0;
    for (int i = pos1.x; i<pos2.x+1; i++) {
        for (int j = pos1.y; j<pos2.y+1; j++) {
            Ingredients in = p.ingredients[i][j];
            if (in==MUSHROOM)mush++;
            if (in==TOMATO)tom++;
        }
    }
    return tom>=p.minIngredients && mush>=p.minIngredients;
};

bool alreadyinSlice(vector<Slice> sl, Position& pos1)
{

}

vector<Slice> poging1Rijen(Pizza& p)
{
    vector<Slice> solution;
    unsigned int bx = 0;
    unsigned int by = 0;
    unsigned int cx = 0;
    unsigned int cy = 0;
    while (true) {
        cx++;
        if (cx>p.rowNum-1) {
            bx = 0;
            by++;
            cx = bx+1;
            cy = by;
        }
        Position p1 = Position(bx, by);
        Position p2 = Position(cx, cy);
        if (checkEnoughIngredients(p, p1, p2)) {
            if (bx-cx<=p.minIngredients) {
                auto pair = make_pair(p1, p2);
                solution.push_back(pair);
                bx = cx+1;
                by = cy;
            }
            else {
                bx++;
                cx--;
            }
        }
        if (by>p.colNum-1) {
            break;
        }
    }
    return solution;

}

vector<Slice> poging1kolommen(Pizza& p)
{

}

vector<Slice> poging1(Pizza& p)
{
    return poging1Rijen(p);
}

