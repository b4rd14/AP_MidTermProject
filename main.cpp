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
    vector<Virus> viruses;    
    Animal sample;
    vector<string> Anames;
    vector<string> Vnames;
    cout << "Welcome to Project " << endl;
    while (tolower(t) != 'n')
    {
        cout << "what do you wnat to do?(just send the number)" << endl;
        cout << "1.Create animal\n2.Jahesh kochak\n3.Jahesh bozorg\n4.Jahesh maakos\n5.Palindrom\n6.Check SimilaryDNA\n7.Asexual reproduction\n8.sexual reproduction\n9.Create Virus\n10.CheckPathogenic\n";
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
            Anames.push_back(name);

        }
        else if (n == 2 && animals.size() > 0)
        {
            string n;
            cout << "There are " << animals.size() << "animals" << endl;
            cout << "Which one?(just a numaber between 1 to " << animals.size() << ")" << endl;
            for (int i = 0; i < Anames.size(); i++)
            {
                cout << i + 1 << "." << Anames[i] << endl;
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
            for (int i = 0; i < Anames.size(); i++)
            {
                cout << i + 1 << "." << Anames[i] << endl;
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
            for (int i = 0; i < Anames.size(); i++)
            {
                cout << i + 1 << "." << Anames[i] << endl;
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
            for (int i = 0; i < Anames.size(); i++)
            {
                cout << i + 1 << "." << Anames[i] << endl;
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
            for (int i = 0; i < Anames.size(); i++)
            {
                cout << i + 1 << "." << Anames[i] << endl;
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
                            cout << Anames[stoi(m) - 1] << " Same " << Anames[stoi(k) - 1] << endl;
                        }
                        else
                        {
                            cout << Anames[stoi(m) - 1] << " Not Same " << Anames[stoi(k) - 1] << endl;
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
            for (int i = 0; i < Anames.size(); i++)
            {
                cout << i + 1 << "." << Anames[i] << endl;
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
            for (int i = 0; i < Anames.size(); i++)
            {
                cout << i + 1 << "." << Anames[i] << endl;
            }
        hell14:
            string m, k;
            cout << "Enter First number : ";
            cin >> m;
            cout << "Enter Second number : ";
            cin >> k;
            if (regex_match(m ,regex("\\d+")) && regex_match(k ,regex("\\d+")) )
            {

            hell15:
                if (stoi(m) > 0 && stoi(m) <= animals[stoi(m) - 1].C[0].Get_No_Chromo() && stoi(k) > 0 && stoi(k) <= animals[stoi(k) - 1].C[0].Get_No_Chromo())
                {
                    animals[stoi(m) - 1].SexuaRep(animals[stoi(m) - 1], animals[stoi(k) - 1]);
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
        else if(n==9)
        {
            string name;
            string RNA;
            cout << "Set a name for your Virus : ";
            cin >> name;            
            Virus *virus = new Virus;
            cout<<"Set RNA for your Virus : ";
            cin>>RNA;
            virus->SetRNA(RNA);
            viruses.push_back(*virus);
            Vnames.push_back(name);
            cout << "\n";

        }
        else if(n==10 && viruses.size()>0 && animals.size()>0)
        {
            string n;
            cout << "There are " << viruses.size() << " viruses" << endl;
            cout << "Which one?(just a numaber between 1 to " << viruses.size() << ")" << endl;
            for (int i = 0; i < Vnames.size(); i++)
            {
                cout << i + 1 << "." << Vnames[i] << endl;
            }
            cout << "There are " << animals.size() << " animals" << endl;
            cout << "Which one?(just a numaber between 1 to " << animals.size() << ")" << endl;
            for (int i = 0; i < Anames.size(); i++)
            {
                cout << i + 1 << "." << Anames[i] << endl;
            }
        hell16:
            string m;
            cout << "Enter Virus number : ";
            cin >> n;
            cout << "Enter Animal number : ";
            cin >> m;
            if (regex_match(n ,regex("\\d+")) && regex_match(m ,regex("\\d+")) )
            {
                if (stoi(n) > 0 && stoi(n) <= viruses.size())
                {
                hell17:
                    if (stoi(m) > 0 && stoi(m) <= animals.size())
                    {
                        viruses[stoi(n) - 1].CheckPathogenic(animals[stoi(m) - 1]);
                    }
                    else
                    {
                        cout << "just a numaber between 1 to " << animals.size() << endl;
                        goto hell17;
                    }
                }
                else
                {
                    cout << "just a numaber between 1 to " << viruses.size() << endl;
                    goto hell16;
                }
            }
            else
            {
                cout << "just a numaber between 1 to " << viruses.size() << endl;
                goto hell16;
            }
        }
        else
        {
            cout << "The number of animals or viruses is not enough \n" << endl;
        }
        
    
    }
    return 0;
}