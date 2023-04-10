#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <vector>
#include "cell.h"

using namespace std;
class Animal : public Cell
{
public:
    Cell cell;
    vector<Cell> C;
    Animal();
    float SimiDna( Cell& a, Cell& b);
    float Simi(string s1, string s2);
    float operator==( Animal &A);
    Cell AsexuaRep( vector<Cell> &C);
    Cell operator+( Animal &A);
    void SexuaRep(Animal &A,Animal &B);
    void CellDeath(Cell &C);
};
#endif