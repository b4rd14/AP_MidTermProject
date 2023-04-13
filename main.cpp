#include <iostream>
#include <ctype.h>
#include <vector>
#include <regex>
#include "cell.cpp"
#include "Animal.cpp"
using namespace std;

int main()
{

    char t;
    vector<Animal> animals;
    Animal sample;
    vector<string> names;
    cout << "Welcome to Project " << endl;
    while (tolower(t) != 'n')
    {

        cout << "what do you wnat to do?(just send the number)" << endl;
        cout << "1.Create animal\n2.Jahesh kochak\n3.Jahesh bozorg\n4.Jahesh maakos\n5.Palindrom\n6.Check SimilaryDNA\n7.Asexual reproduction\n8.sexual reproduction\n";
        try
        {
            int n;
            cout << "Enter the number : ";
            cin >> n;
            if (n == 1)
            {
                string name;
                int chromo;
                cout << "Set a name for your animal : ";
                cin >> name;
                cout << "Number of chromo : ";  
                cin >> chromo;              
                Animal *animal = new Animal;
                animal->C[0].SetChromo(chromo);
                animals.push_back(*animal);
                names.push_back(name);

            }
            else if (n == 2 && animals.size() > 0)
            {
                string n;
                cout << "There are " << animals.size() << "animals" << endl;
                cout << "Which one?(just a numaber between 1 to " << animals.size() << ")" << endl;
                for (int i = 0; i < names.size(); i++)
                {
                    cout << i + 1 << "." << names[i] << endl;
                }
            hell:
                cout << "Enter the number : ";
                cin >> n;
                if (regex_match(n, regex("\\d+")))
                {
                    if (stoi(n) > 0 && stoi(n) <= animals.size())
                    {
                    hell1:
                        cout << "Which Chromo?(just a numaber between 1 to " << animals[stoi(n)-1].C[0].Get_No_Chromo() << ")" << endl;
                        string m, k;
                        cout << "Enter the number : ";
                        cin >> m;
                        if (stoi(m) > 0 && stoi(m) <= animals[stoi(n) - 1].C[0].Get_No_Chromo())
                        {
                            cout << "How many : ";
                            cin >> k;
                            string c, h;
                        hell2:
                            cout << "First Character : ";
                            cin >> c;
                            cout << "Second Character : ";
                            cin >> h;
                            if (regex_match(c, regex("[ATCG]")) && regex_match(h, regex("[ATCG]")))
                            {
                                animals[stoi(n) - 1].C[0].JaheshS(c.c_str()[0], h.c_str()[0], stoi(k), stoi(m));
                            }
                            else
                            {
                                cout << "Wrong Character" << endl;
                                goto hell2;
                            }
                        }
                        else
                        {
                            cout << "just a number between 1 to " << animals[stoi(n) - 1].C[0].Get_No_Chromo() << endl;
                            goto hell1;
                        }
                    }
                    else
                    {
                        cout << "just a number between 1 to " << animals.size() << endl;
                        goto hell;
                    }
                }
                else
                {
                    cout << "just a number" <<endl;
                    goto hell;
                }
            }
            else if (n == 3 && animals.size() > 0)
            {
                string n;
                cout << "There are " << animals.size() << "animals" << endl;
                cout << "Which one?(just a numaber between 1 to " << animals.size() << ")" << endl;
                for (int i = 0; i < names.size(); i++)
                {
                    cout << i + 1 << "." << names[i] << endl;
                }
            hell3:
                cout << "Enter the number : ";
                cin >> n;
                if (regex_match(n, regex("\\d+")))
                {
                    if (stoi(n) > 0 && stoi(n) <= animals.size())
                    {
                    hell4:
                        cout << "Which Chromo?(just a numaber between 1 to " << animals[stoi(n) - 1].C[0].Get_No_Chromo() << ")" << endl;
                        string m, k;
                        cout << "Enter First number : ";
                        cin >> m;
                        cout << "Enter Second number : ";
                        cin >> k;
                        if (stoi(m) > 0 && stoi(m) <= animals[stoi(n) - 1].C[0].Get_No_Chromo() && stoi(k) > 0 && stoi(k) <= animals[stoi(n) - 1].C[0].Get_No_Chromo())
                        {
                            string s1, s2;
                            cout << "First string : ";
                            cin >> s1;
                            cout << "Second string : ";
                            cin >> s2;
                            animals[stoi(n) - 1].C[0].JaheshB(s1, stoi(m), s2, stoi(k));
                        }
                        else
                        {
                            cout << "just a numaber between 1 to " << animals[stoi(n) - 1].C[0].Get_No_Chromo() << endl;
                            goto hell4;
                        }
                    }
                    else
                    {
                        cout << "just a numaber between 1 to " << animals.size() << endl;
                        goto hell3;
                    }
                }
                else
                {
                    cout << "just a numaber between 1 to " << animals.size() << endl;
                    goto hell3;
                }
            }
            else if (n == 4 && animals.size() > 0)
            {
                string n;
                cout << "There are " << animals.size() << "animals" << endl;
                cout << "Which one?(just a numaber between 1 to " << animals.size() << ")" << endl;
                for (int i = 0; i < names.size(); i++)
                {
                    cout << i + 1 << "." << names[i] << endl;
                }
            hell6:
                cout << "Enter the number : ";
                cin >> n;
                if (regex_match(n, regex("\\d+")))
                {
                    if (stoi(n) > 0 && stoi(n) <= animals.size())
                    {
                    hell7:
                        cout << "Which Chromo?(just a numaber between 1 to " << animals[stoi(n) - 1].C[0].Get_No_Chromo() << ")" << endl;
                        string m;
                        cout << "Enter the number : ";
                        cin >> m;
                        if (stoi(m) > 0 && stoi(m) <= animals[stoi(n) - 1].C[0].Get_No_Chromo())
                        {
                            string s1;
                            cout << "First string : ";
                            cin >> s1;
                            animals[stoi(n) - 1].C[0].JaheshR(s1, stoi(m));
                        }
                        else
                        {
                            cout << "just a numaber between 1 to " << animals[stoi(n) - 1].C[0].Get_No_Chromo() << endl;
                            goto hell7;
                        }
                    }
                    else
                    {
                        cout << "just a numaber between 1 to " << animals.size() << endl;
                        goto hell6;
                    }
                }
                else
                {
                    cout << "just a numaber between 1 to " << animals.size() << endl;
                    goto hell6;
                }
            }
            else if (n == 5 && animals.size() > 0)
            {
                string n;
                cout << "There are " << animals.size() << "animals" << endl;
                cout << "Which one?(just a numaber between 1 to " << animals.size() << ")" << endl;
                for (int i = 0; i < names.size(); i++)
                {
                    cout << i + 1 << "." << names[i] << endl;
                }
            hell8:
                cout << "Enter the number : ";
                cin >> n;
                if (regex_match(n, regex("\\d+")))
                {
                    if (stoi(n) > 0 && stoi(n) <= animals.size())
                    {
                    hell9:
                        cout << "Which Chromo?(just a numaber between 1 to " << animals[stoi(n) - 1].C[0].Get_No_Chromo() << ")" << endl;
                        string m;
                        cout << "Enter the number : ";
                        cin >> m;
                        if (stoi(m) > 0 && stoi(m) <= animals[stoi(n) - 1].C[0].Get_No_Chromo())
                        {
                            animals[stoi(n) - 1].palin(stoi(m));
                        }
                        else
                        {
                            cout << "just a numaber between 1 to " << animals[stoi(n) - 1].C[0].Get_No_Chromo() << endl;
                            goto hell9;
                        }
                    }
                    else
                    {
                        cout << "just a numaber between 1 to " << animals.size() << endl;
                        goto hell8;
                    }
                }
                else
                {
                    cout << "just a numaber between 1 to " << animals.size() << endl;
                    goto hell8;
                }
            }
            else if (n == 6 && animals.size() > 1)
            {
                string n;
                cout << "There are " << animals.size() << "animals" << endl;
                cout << "Which one?(just a numaber between 1 to " << animals.size() << ")" << endl;
                for (int i = 0; i < names.size(); i++)
                {
                    cout << i + 1 << "." << names[i] << endl;
                }
            hell10:
                cout << "Enter the number : ";
                cin >> n;
                if (regex_match(n, regex("\\d+")))
                {
                    if (stoi(n) > 0 && stoi(n) <= animals.size())
                    {
                    hell11:
                        cout << "Which Chromo?(just a numaber between 1 to " << animals[stoi(n) - 1].C[0].Get_No_Chromo() << ")" << endl;
                        string m, k;
                        cout << "Enter First number : ";
                        cin >> m;
                        cout << "Enter Second number : ";
                        cin >> k;
                        if (stoi(m) > 0 && stoi(m) <= animals[stoi(n) - 1].C[0].Get_No_Chromo() && stoi(k) > 0 && stoi(k) <= animals[stoi(n) - 1].C[0].Get_No_Chromo())
                        {
                            if (animals[stoi(m) - 1] == animals[stoi(k) - 1])
                            {
                                cout << names[stoi(m) - 1] << " Same " << names[stoi(k) - 1] << endl;
                            }
                            else
                            {
                                cout << names[stoi(m) - 1] << " Not Same " << names[stoi(k) - 1] << endl;
                            }
                        }
                        else
                        {
                            cout << "just a numaber between 1 to " << animals[stoi(n) - 1].C[0].Get_No_Chromo() << endl;
                            goto hell11;
                        }
                    }
                    else
                    {
                        cout << "just a numaber between 1 to " << animals.size() << endl;
                        goto hell10;
                    }
                }
                else
                {
                    cout << "just a numaber between 1 to " << animals.size() << endl;
                    goto hell10;
                }
            }
            else if (n == 7 && animals.size() > 0)
            {
                string n;
                cout << "There are " << animals.size() << "animals" << endl;
                cout << "Which one?(just a numaber between 1 to " << animals.size() << ")" << endl;
                for (int i = 0; i < names.size(); i++)
                {
                    cout << i + 1 << "." << names[i] << endl;
                }
            hell12:
                cout << "Enter the number : ";
                cin >> n;
                if (regex_match(n, regex("\\d+")))
                {
                    if (stoi(n) > 0 && stoi(n) <= animals.size())
                    {
                    hell13:
                        if (stoi(n) > 0 && stoi(n) <= animals[stoi(n) - 1].C[0].Get_No_Chromo())
                        {
                            animals[stoi(n) - 1].AsexuaRep(animals[stoi(n) - 1].C);
                        }
                        else
                        {
                            cout << "just a numaber between 1 to " << animals[stoi(n) - 1].C[0].Get_No_Chromo() << endl;
                            goto hell13;
                        }
                    }
                    else
                    {
                        cout << "just a numaber between 1 to " << animals.size() << endl;
                        goto hell12;
                    }
                }
                else
                {
                    cout << "just a numaber between 1 to " << animals.size() << endl;
                    goto hell12;
                }
            }
            else if (n == 8 && animals.size() > 1)
            {
                string n;
                cout << "There are " << animals.size() << "animals" << endl;
                cout << "Which one?(just a numaber between 1 to " << animals.size() << ")" << endl;
                for (int i = 0; i < names.size(); i++)
                {
                    cout << i + 1 << "." << names[i] << endl;
                }
            hell14:
                string m, k;
                cout << "Enter First number : ";
                cin >> m;
                cout << "Enter Second number : ";
                cin >> k;
                if (regex_match(m ,regex("\\d+")) && regex_match(k ,regex("\\d+")) )
                {
                    if (stoi(n) > 0 && stoi(n) <= animals.size())
                    {
                    hell15:
                        if (stoi(m) > 0 && stoi(m) <= animals[stoi(n) - 1].C[0].Get_No_Chromo() && stoi(k) > 0 && stoi(k) <= animals[stoi(n) - 1].C[0].Get_No_Chromo())
                        {
                            sample.SexuaRep(animals[stoi(m) - 1], animals[stoi(k) - 1]);
                        }
                        else
                        {
                            cout << "just a numaber between 1 to " << animals[stoi(n) - 1].C[0].Get_No_Chromo() << endl;
                            goto hell15;
                        }
                    }
                    else
                    {
                        cout << "just a numaber between 1 to " << animals.size() << endl;
                        goto hell14;
                    }
                }
                else
                {
                    cout << "just a numaber between 1 to " << animals.size() << endl;
                    goto hell14;
                }
            }
            else
            {
                cout << "The number of animals is not enough\n" << endl;
            }
        }
        catch (const exception)
        {
            cerr << "just number!" << '\n';
        }
    }
    return 0;
}