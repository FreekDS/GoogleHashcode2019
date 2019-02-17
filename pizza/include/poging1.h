//
// Created by thibaut on 17.02.19.
//

#ifndef PROJECT_POGING1_H
#define PROJECT_POGING1_H

#include "PizzaParser.h"
using namespace std;

bool checkEnoughIngredients(Pizza& p, Position& pos1,Position& pos2);

bool alreadyinSlice(vector<Slice> sl, Position& pos1);

vector<Slice> poging1Rijen(Pizza& p);

vector<Slice> poging1kolommen(Pizza& p);

vector<Slice> poging1(Pizza& p);
#endif //PROJECT_POGING1_H
