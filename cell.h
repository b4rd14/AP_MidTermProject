#ifndef CELL_H
#define CELL_H
#include <string>
#include <vector>
using namespace std;

class Cell;
// Genome Class
class Genome
{
protected:
    string RNA;
    string DNA[2];

public:
    friend class Cell;
    friend class Animal;
    void SetGen(string D2, string D1, string R);
    void ProduceRNA();
    void JaheshS(char c, char h, int n);
    vector<int> prefixFunction(const string &pattern);
    int kmpSearch(const string &text, const string &pattern);
    void JaheshB(string s1, string s2);
    void JaheshR(string s1);
};

#endif