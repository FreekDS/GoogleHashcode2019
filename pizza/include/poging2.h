//the functions depicted in this file are all an attempt at the google hashcode pizza problem
//these function are a largest slice first by row and by collumns
//slices always have a width or height of 1

#ifndef PIZZAPROBLEM_POGING2_H
#define PIZZAPROBLEM_POGING2_H

using namespace std;
#include "PizzaParser.h"


vector<Slice> poging2Rijen(Pizza& p);

vector<Slice> poging2kolommen(Pizza& p);

vector<Slice> poging2(Pizza& p);



#endif //PIZZAPROBLEM_POGING2_H
