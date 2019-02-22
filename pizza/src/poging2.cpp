//
// Created by thibaut on 22.02.19.
//

#include "../include/poging2.h"
#include <iostream>

vector<Slice> poging2Rijen(Pizza& p)
{
    vector<Slice> solution;
    unsigned int bx = 0;
    unsigned int by = 0;
    unsigned int cx = 0;
    unsigned int cy = 0;
    while (true) {
        if(p.rowNum<bx+p.sliceSize){
            cx=p.rowNum-1;
        }else{
            cx=bx+p.sliceSize-1;
        }
        Position p1 = Position(bx, by);
        Position p2 = Position(cx, cy);
        if(PizzaParser::checkEnoughIngredients(p,p1,p2)){
            auto pair = make_pair(p1, p2);
            solution.emplace_back(pair);
            bx=cx+1;
        }else{
            bx++;
        }
        if(bx>p.rowNum-1){
            bx=0;
            by++;
            cx=0;
            cy=by;
            if(by>p.colNum-1){
                break;
            }
        }


    }
    return solution;

}

vector<Slice> poging2kolommen(Pizza& p)
{
    vector<Slice> solution;
    unsigned int bx = 0;
    unsigned int by = 0;
    unsigned int cx = 0;
    unsigned int cy = 0;
    while (true) {
        if(p.colNum<by+p.sliceSize){
            cy=p.colNum-1;
        }else{
            cy=by+p.sliceSize-1;
        }
        Position p1 = Position(bx, by);
        Position p2 = Position(cx, cy);
        if(PizzaParser::checkEnoughIngredients(p,p1,p2)){
            auto pair = make_pair(p1, p2);
            solution.emplace_back(pair);
            by=cy+1;
        }else{
            by++;
        }
        if(by>p.colNum-1){
            by=0;
            bx++;
            cy=0;
            cx=bx;
            if(bx>p.rowNum-1){
                break;
            }
        }
    }
    return solution;
}

vector<Slice> poging2(Pizza& p)
{

    auto p2r=poging2Rijen(p);
    auto p2k=poging2kolommen(p);
    p.slices=p2r;
    int sp1r=p.calculateScore();
    p.slices=p2k;
    int sp1k=p.calculateScore();
    return (sp1r>sp1k)? p2r:p2k;
}