//the functions depicted in this file are all an attempt at the google hashcode pizza problem
//these function are a smallest slice first by row and by collumns
//slices always have a width or height of 1

#ifndef PROJECT_POGING1_H
#define PROJECT_POGING1_H

#include "PizzaParser.h"
using namespace std;


vector<Slice> poging1Rijen(Pizza& p);

vector<Slice> poging1kolommen(Pizza& p);

vector<Slice> poging1(Pizza& p);
#endif //PROJECT_POGING1_H
