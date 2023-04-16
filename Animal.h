#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <vector>
#include "cell.h"

using namespace std;
class Virus;
class Animal : public Cell 
{
public:
    Cell cell;
    vector<Cell> C;
    Animal();
    float SimiDna(Cell &a, Cell &b);
    float operator==(Animal &A);
    Cell AsexuaRep(vector<Cell> &C);
    Animal operator+(Animal &A);
    void SexuaRep(Animal &A, Animal &B);
    void CellDeath(Cell &C);
};

class Virus : public Genome
{
protected:
    Genome vir;

public:
    void SetRNA(string R);
    vector<string> CheckChromo(Animal &A);
    void CheckPathogenic(Animal &A);
    void JaheshS(char c, char h, int n);
    void JaheshB(string s1, string s2);
    void JaheshR(string s1);
    void ProduceRNA();
};
#endif