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
int Simi(string first, string second)
{

	int m = first.length();
	int n = second.length();

	int T[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
            T[i][j] = 0;
    }
	for (int i = 1; i <= m; i++) {
		T[i][0] = i;
	}

	for (int j = 1; j <= n; j++) {
		T[0][j] = j;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int weight = first[i - 1] == second[j - 1] ? 0: 1;
			T[i][j] = min(min(T[i-1][j] + 1, T[i][j-1] + 1), T[i-1][j-1] + weight);
		}
	}

	return T[m][n];
}
float findStringSimilarity(string first, string second) {
	float max_length = max(first.length(), second.length());
	if (max_length > 0) {
		return ((max_length - Simi(first, second)) / max_length)*100 ;
	}
	return 100.0;
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
            sum += findStringSimilarity(a.Chromo[i].DNA[0], b.Chromo[i].DNA[0]);
        }
        return sum / m;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            sum += findStringSimilarity(a.Chromo[i].DNA[0], b.Chromo[i].DNA[0]);
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
    Cell tmp = C[0];
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
        if (SimiDna(tmp, C[0]) >= 70.0)
        {
            NC = tmp;
            C.push_back(NC);
            cout << "Cell added !" << endl;
            break;
        }

    }
    return NC;
}
Animal Animal::operator+(Animal &A)
{
    Cell NC1 = AsexuaRep(A.C);
    Cell NC2 = AsexuaRep(C);
    Cell tmp= NC1;
    Cell NC;
    Animal t;
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
        if ((SimiDna(tmp, A.C[0]) + SimiDna(tmp, C[0])) / 2 > 70.0)
        {
            NC = tmp;
            t.C[0]= NC; 
            return t;  
        }
    }
    return t;
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
            Animal tmp = A + B;
            if(tmp.C[0].Chromo.size()!=0){
                cout << "new Animal created!!!"<<endl;
                for(int i =0;i<tmp.C[0].No_Chromo;i++)
                {
                    cout << tmp.C[0].Chromo[i].DNA[0] <<endl;
                    cout << tmp.C[0].Chromo[i].DNA[1] << endl;
                }
            }else{
                cout <<"mission failed !!!"<< endl;
            }
            
        }
    }
}
void Animal::CellDeath(Cell &C)
{
    for (int i = 0; i < C.No_Chromo; i++)
    {
        int cnt1 = 0, cnt2 = 0, cnt3 = 0,cnt4=0;
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
void Virus::SetRNA(string R)
{
    string d1 = "";
    string d2 = "";
    vir.SetGen(d2, d1, R);
}
vector<string> Virus::CheckChromo(Animal &A)
{
    int check = 0;
    vector<string> v;
    string str = A.C[0].Chromo[0].DNA[0];
    string substr = "";
    for (int len = 1; len <= str.length(); len++)
    {
        for (int i = 0; i <= str.length() - len; i++)
        {
            int j = i + len - 1;
            for (int k = i; k <= j; k++)
            {
                substr += str[k];
            }
            for (int i = 0; i < A.C[0].No_Chromo; i++)
            {
                if (kmpSearch(A.C[0].Chromo[i].DNA[0], substr) != 1000000000 || kmpSearch(A.C[0].Chromo[i].DNA[1], substr) != 1000000000)
                {
                    check++;
                }
            }
            if (check == A.C[0].No_Chromo)
            {
                v.push_back(substr);
            }
            check = 0;
            substr = "";
        }
    }
    return v;
}
string Change(string s){
    string tmp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A')
        {
            tmp += 'T';
        }
        else if (s[i] == 'T')
        {
            tmp += 'A';
        }
        else if (s[i] == 'G')
        {
            tmp += 'C';
        }
        else if (s[i] == 'C')
        {
            tmp += 'G';
        }
    }
    return tmp;

}
void Virus::CheckPathogenic(Animal &A)
{
    vector<string> total;

    string str = "";
    for (int i = 0; i < CheckChromo(A).size(); i++)
    {
        if (kmpSearch(vir.RNA, CheckChromo(A)[i])!= 1000000000 || kmpSearch(vir.RNA, Change(CheckChromo(A)[i])) != 1000000000){
            total.push_back(CheckChromo(A)[i]);
        }
    }
    for (int i = 0; i < total.size(); i++)
    {
        for (int j = 0; j < total.size() - i - 1; j++)
        {
            if (total[j].length() < total[j + 1].length())
            {
                str = total[j];
                total[j] = total[j + 1];
                total[j + 1] = str;
            }
        }
    }
    if (kmpSearch(vir.RNA, total[0])!= 1000000000 || kmpSearch(vir.RNA, Change(total[0])) != 1000000000)
    {
        cout << vir.RNA << endl;
        cout << "Longest Common Substring "<< endl;
        cout << total[0] << endl;
        cout << Change(total[0]) << endl;
        cout << "Pathogenic" << endl;
    }
    else
    {
        cout << "Non-Pathogenic" << endl;
    }
}
void Virus::JaheshS(char c, char h, int n){
    int cnt = 0;
    for (int i = 0; i < RNA.length(); i++)
    {
        if (RNA[i] == c && cnt <= n)
        {
            RNA[i] = h;
            cnt++;
        }
    }
    cout << RNA << endl;
}
void Virus::JaheshB(string s1,string s2){
    string temp = "";
    for (int i = 0; i < RNA.length() - s1.length(); i++)
    {
        for (int j = i; j < i + s1.length(); j++)
        {
            temp += RNA[j];
        }
        if (temp == s1)
        {
            string part1 = "", part3 = "";
            for (int k = 0; k < i; k++)
            {
                part1 += RNA[k];
            }
            for (int l = i + s1.length(); l < RNA.length(); l++)
            {
                part3 += RNA[l];
            }
            i = i + s1.length();
            RNA = part1 + s2 + part3;
        }
        temp = "";
    }
    cout << RNA << endl;
}
void Virus::JaheshR(string s1){
    string temp = "";
    string Ns1 = "";
    for (int i = 0; i < RNA.length() - s1.length(); i++)
    {
        for (int j = i; j < i + s1.length(); j++)
        {
            temp += RNA[j];
        }
        if (temp == s1)
        {
            string p1 = "", p3 = "";
            for (int k = 0; k < i; k++)
            {
                p1 += RNA[k];
            }
            for (int m = 0; m < s1.length(); m++)
            {
                Ns1 += s1[s1.length() - m - 1];
            }
            for (int l = i + s1.length(); l < RNA.length(); l++)
            {
                p3 += RNA[l];
            }
            i = i + s1.length();
            RNA = p1 + Ns1 + p3;
        }
        temp = "";
    }
    cout << RNA << endl;
}
void Virus::ProduceRNA()
{
    ProduceRNA();
}