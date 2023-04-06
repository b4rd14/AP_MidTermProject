#include <iostream>
#include <string>
#include <vector>
#include "cell.h"
using namespace std;
void Genome::SetGen(string D1, string D2, string R = "")
{
    RNA = R;
    DNA[0] = D1;
    DNA[1] = D2;
}
void Genome::ProduceRNA()
{
    string NewDNA = "";
    for (int i = 0; i < RNA.length(); i++)
    {
        if (RNA[i] == 'A' || RNA[i] == 'T')
        {
            NewDNA += char(149 - RNA[i]);
        }
        else
        {
            NewDNA += char(138 - RNA[i]);
        }
    }
    cout << RNA << endl;
    cout << NewDNA << endl;
}
vector<int> Genome::prefixFunction(const string &pattern)
{
    int m = pattern.size();
    vector<int> pi(m);
    pi[0] = 0;
    int k = 0;
    for (int i = 1; i < m; i++)
    {
        while (k > 0 && pattern[k] != pattern[i])
        {
            k = pi[k - 1];
        }
        if (pattern[k] == pattern[i])
        {
            k++;
        }
        pi[i] = k;
    }
    return pi;
}
int Genome::kmpSearch(const string &text, const string &pattern)
{
    int index = 100000000;
    int n = text.size();
    int m = pattern.size();
    vector<int> pi = Genome::prefixFunction(pattern);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        while (k > 0 && pattern[k] != text[i])
        {
            k = pi[k - 1];
        }
        if (pattern[k] == text[i])
        {
            k++;
        }
        if (k == m)
        {
            index = i - m + 1;
            break;
        }
    }
    return index;
}
void Genome::JaheshS(char c, char h, int n)
{
    int cnt = 0;
    for (int i = 0; i < RNA.length(); i++)
    {
        if (RNA[i] == c && cnt <= n)
        {
            RNA[i] = h;
            cnt++;
        }
    }
    cnt = 0;
    for (int i = 0; i < DNA[0].length(); i++)
    {
        if (cnt < n)
        {
            if (DNA[0][i] == c)
            {
                DNA[0][i] = h;
                if (h == 'A' || h == 'T')
                {
                    DNA[1][i] = char(149 - DNA[0][i]);
                }
                else
                {
                    DNA[1][i] = char(138 - DNA[0][i]);
                }

                cnt++;
            }
            else if (DNA[1][i] == c)
            {
                DNA[1][i] = h;
                if (h == 'A' || h == 'T')
                {
                    DNA[0][i] = char(149 - DNA[1][i]);
                }
                else
                {
                    DNA[0][i] = char(138 - DNA[1][i]);
                }
                cnt++;
            }
        }
    }
}
void Genome::JaheshB(string s1, string s2)

{
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
    if (Genome::kmpSearch(DNA[0], s1) < Genome::kmpSearch(DNA[1], s1))
    {
        string part11 = "", part13 = "";
        string part01 = "", part03 = "";
        string s22 = "";
        for (int k = 0; k < Genome::kmpSearch(DNA[0], s1); k++)
        {
            part01 += DNA[0][k];
            part11 += DNA[1][k];
        }
        for (int m = 0; m < s2.length(); m++)
        {
            if (s2[m] == 'A' || s2[m] == 'T')
            {
                s22 += char(149 - s2[m]);
            }
            else
            {
                s22 += char(138 - s2[m]);
            }
        }
        for (int l = Genome::kmpSearch(DNA[0], s1) + s1.length(); l < DNA[0].length(); l++)
        {
            part03 += DNA[0][l];
            part13 += DNA[1][l];
        }

        DNA[0] = part01 + s2 + part03;
        DNA[1] = part11 + s22 + part13;
    }
    else
    {
        string part11 = "", part13 = "";
        string part01 = "", part03 = "";
        string s22 = "";
        for (int k = 0; k < Genome::kmpSearch(DNA[1], s1); k++)
        {
            part01 += DNA[0][k];
            part11 += DNA[1][k];
        }
        for (int m = 0; m < s2.length(); m++)
        {
            if (s2[m] == 'A' || s2[m] == 'T')
            {
                s22 += char(149 - s2[m]);
            }
            else
            {
                s22 += char(138 - s2[m]);
            }
        }
        for (int l = Genome::kmpSearch(DNA[1], s1) + s1.length(); l < DNA[0].length(); l++)
        {
            part03 += DNA[0][l];
            part13 += DNA[1][l];
        }
        DNA[0] = part01 + s22 + part03;
        DNA[1] = part11 + s2 + part13;
    }
}
void Genome::JaheshR(string s1)
{
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
    string temp0 = "";
    string temp1 = "";
    string Ns01 = "";
    string RNs01 = "";
    string Ns11 = "";
    string RNs11 = "";
    if (Genome::kmpSearch(DNA[0], s1) < Genome::kmpSearch(DNA[1], s1))
    {
        string p11 = "", p13 = "";
        string p01 = "", p03 = "";
        string s22 = "";
        for (int k = 0; k < Genome::kmpSearch(DNA[0], s1); k++)
        {
            p01 += DNA[0][k];
            p11 += DNA[1][k];
        }
        for (int m = 0; m < s1.length(); m++)
        {
            if (s1[m] == 'A' || s1[m] == 'T')
            {
                Ns01 += s1[s1.length() - m - 1];
                RNs01 = char(149 - s1[m]) + RNs01;
            }
            else
            {
                Ns01 += s1[s1.length() - m - 1];
                RNs01 = char(138 - s1[m]) + RNs01;
            }
        }
        for (int l = Genome::kmpSearch(DNA[0], s1) + s1.length(); l < DNA[0].length(); l++)
        {
            p03 += DNA[0][l];
            p13 += DNA[1][l];
        }
        DNA[0] = p01 + Ns01 + p03;
        DNA[1] = p11 + RNs01 + p13;
    }
    else
    {
        string p11 = "", p13 = "";
        string p01 = "", p03 = "";
        string s22 = "";
        for (int k = 0; k < Genome::kmpSearch(DNA[1], s1); k++)
        {
            p01 += DNA[0][k];
            p11 += DNA[1][k];
        }
        for (int m = 0; m < s1.length(); m++)
        {
            if (s1[m] == 'A' || s1[m] == 'T')
            {
                Ns11 += s1[s1.length() - m - 1];
                RNs11 = char(149 - s1[m]) + RNs11;
            }
            else
            {
                Ns11 += s1[s1.length() - m - 1];
                RNs11 = char(138 - s1[m]) + RNs11;
            }
        }
        for (int l = Genome::kmpSearch(DNA[1], s1) + s1.length(); l < DNA[0].length(); l++)
        {
            p03 += DNA[0][l];
            p13 += DNA[1][l];
        }
        DNA[0] = p01 + RNs11 + p03;
        DNA[1] = p11 + Ns11 + p13;
    }
}

