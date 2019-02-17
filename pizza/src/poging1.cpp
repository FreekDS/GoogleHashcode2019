//
// Created by thibaut on 17.02.19.
//

#include "../include/poging1.h"



bool checkEnoughIngredients(Pizza& p, Position& pos1,Position& pos2){
    int tom=0;
    int mush=0;
    for(int i=pos1.x;i<pos2.x+1;i++){
        for(int j=pos1.y;j<pos2.y+1;j++){
            Ingredients in=p.ingredients[i][j];
            if(in==MUSHROOM)mush++;
            if(in==TOMATO)tom++;
        }
    }
    if(tom>=p.minIngredients&&mush>=p.minIngredients)return true;
    return false;
};

bool alreadyinSlice(vector<Slice> sl, Position& pos1){

}

vector<Slice> poging1Rijen(Pizza& p){
    vector<Slice> solution;
    int bx=0;
    int by=0;
    int cx=0;
    int cy=0;
    while(true){
        cx++;
        if(cx>p.rowNum-1){
            bx=0;
            by++;
            cx=bx+1;
            cy=by;
        }
        Position p1=Position(bx,by);
        Position p2=Position(cx,cy);
        if(checkEnoughIngredients(p,p1,p2)){
            if(bx-cx<=p.minIngredients) {
                solution.emplace_back(make_pair(p1, p2));
                bx = cx+1;
                by = cy;
            }else{
                bx++;
                cx--;
            }
        }
        if(by>p.colNum-1){
            break;
        }
    }
    return solution;

}

vector<Slice> poging1kolommen(Pizza& p){

}

vector<Slice> poging1(Pizza& p){
    return poging1Rijen(p);
}

