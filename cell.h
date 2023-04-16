#ifndef CELL_H
#define CELL_H
#include <string>
#include <vector>
using namespace std;

class Cell;
class Genome
{
protected:
    string RNA;
    string DNA[2];

public:
    friend class Cell;
    friend class Animal;
    friend class Virus;
    void SetGen(string D2, string D1, string R);
    void ProduceRNA();
    void JaheshS(char c, char h, int n);
    vector<int> prefixFunction(const string &pattern);
    int kmpSearch(const string &text, const string &pattern);
    void JaheshB(string s1, string s2);
    void JaheshR(string s1);
};
class Cell : public Genome
{
protected:
    int No_Chromo=0;

public:
    friend class Animal;
    friend class Virus;
    vector<Genome> Chromo;
    void SetChromo(int n);
    int Get_No_Chromo();
    void CellDeath(Cell &C);
    void JaheshS(char c, char h, int n, int m);
    void JaheshB(string s1, int n, string s2, int m);
    void JaheshR(string s1, int n);
    void palin(int n);
};
#endif