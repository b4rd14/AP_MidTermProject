#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Animal.h"
using namespace std;

Animal::Animal()
{
    C.push_back(cell);
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
    Cell temp = C[0];
    Cell tmp= C[0];
    temp.No_Chromo = 2 * x;
    
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
Cell Animal::operator+(Animal &A)
{
    Cell NC1 = AsexuaRep(A.C);
    Cell NC2 = AsexuaRep(C);
    Cell tmp;
    Cell NC;
    for (int j = 0; j < 2 * 1000000000; j++)
    {
        random_shuffle(NC1.Chromo.begin(), NC1.Chromo.end());
        random_shuffle(NC2.Chromo.begin(), NC2.Chromo.end());
        for (int i = 0; i < NC1.No_Chromo / 2; i++)
        {
            tmp.Chromo[i] = NC1.Chromo[i];
        }
        for (int i = NC2.No_Chromo / 2; i < NC2.No_Chromo; i++)
        {
            tmp.Chromo[i] = NC2.Chromo[i];
        }
        if ((SimiDna(tmp, A.C[0]) + SimiDna(tmp, C[0])) / 1.5 > 70.0)
        {
            NC = tmp;
            A.C.push_back(NC);
            cout << "Cell added " << endl;
            break;
        }
    }
    return NC;
}
void Animal::SexuaRep(Animal &A, Animal &B)
{
    if (A.C[0].No_Chromo != B.C[0].No_Chromo)
    {
        cout << "tedad chromo motefavet" << endl;
    }
    else
    {
        if (B.C[0].No_Chromo % 2 != 0 || A.C[0].No_Chromo % 2 != 0)
        {
            cout << "Num Chromo fard" << endl;
        }
        else
        {
        }
    }
}
void Animal::CellDeath(Cell &C)
{
    for (int i = 0; i < C.No_Chromo; i++)
    {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for (int j = 0; j < C.Chromo[i].DNA[0].length(); j++)
        {
            if (C.Chromo[i].DNA[0][j] == 'A' || C.Chromo[i].DNA[0][j] == 'T')
            {
                if (C.Chromo[i].DNA[0][j] != char(149 - C.Chromo[i].DNA[1][j]))
                {
                    cnt1++;
                }
                else
                {
                    cnt2++;
                }
            }
            else if (C.Chromo[i].DNA[0][j] == 'G' || C.Chromo[i].DNA[0][j] == 'C')
            {
                if (C.Chromo[i].DNA[0][j] != char(138 - C.Chromo[i].DNA[1][j]))
                {
                    cnt1++;
                }
                else
                {
                    cnt3++;
                }
            }
        }
        if (cnt1 > 5)
        {
            cout << "delete chromo" << endl;
            C.Chromo.erase(Chromo.begin() + i);
            C.No_Chromo--;
        }
        if (cnt2 - cnt3 > 2 * cnt3)
        {
            cout << "delete chromo" << endl;
            C.Chromo.erase(Chromo.begin() + i);
            C.No_Chromo--;
        }
    }
}