#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Animal.h"
using namespace std;

Animal::Animal()
{
    C.push_back(c);
}
float Animal::Simi(string s1, string s2)
{

    int n = s1.length();
    int m = s2.length();
    int cnt = 0;
    if (n > m)
    {
        for (int i = 0; i < m; i++)
        {
            if (s1[i] != s2[i])
            {
                cnt++;
            }
        }
        return (m - cnt) * 100 / n;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
            {
                cnt++;
            }
        }
        return (n - cnt) * 100 / m;
    }
}
float Animal::SimiDna(Cell &a, Cell &b)
{
    int n = a.No_Chromo;
    int m = b.No_Chromo;
    float sum = 0;
    if (n > m)
    {
        for (int i = 0; i < m; i++)
        {
            sum += Simi(a.Chromo[i].DNA[0], b.Chromo[i].DNA[0]);
        }
        return sum / m;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            sum += Simi(a.Chromo[i].DNA[0], b.Chromo[i].DNA[0]);
        }
        return sum / n;
    }
}
float Animal::operator==(Animal &A)
{
    if (C[0].No_Chromo != A.C[0].No_Chromo)
    {
        return false;
    }
    float simidna = SimiDna(C[0], A.C[0]);
    if (simidna > 70.0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
Cell Animal::AsexuaRep(vector<Cell> &C)
{
    int x = C[0].No_Chromo;
    C[0].No_Chromo = 2 * x;
    Cell temp = C[0];
    for (int i = x; i < 2 * x; i++)
    {
        Genome chromo;
        temp.Chromo.push_back(chromo);
    }
    for (int i = x; i < 2 * x; i++)
    {
        temp.Chromo[i] = temp.Chromo[i - x];
    }
    Cell NC;
    while (true)
    {
        Cell tmp;
        random_shuffle(temp.Chromo.begin(), temp.Chromo.end());
        for (int i = 0; i < x; i++)
        {
            tmp.Chromo[i] = temp.Chromo[i];
        }
        if (SimiDna(tmp, C[0]) > 70.0)
        {
            NC = tmp;
            C.push_back(NC);
            cout << "Cell added " << endl;
            break;
        }
    }
    return NC;
}

