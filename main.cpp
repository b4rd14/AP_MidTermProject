#include <iostream>
#include <ctype.h>
#include <vector>
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
        cout << "1.Create animal\n2.Jahesh kochak\n3.Jahesh bozorg\n4.Jahesh maakos\n5.Palindrom\n6.Check SimilaryDNA\n7.Asexual reproduction\n8.sexual reproduction";
        try
        {
            int n;
            cin >> n;
            if (n == 1)
            {
                string name;
                cout << "Set a name for your animal : ";
                cin >> name;
                Animal *animal = new Animal;
                animals.push_back(*animal);
                names.push_back(name);
            }
            else if (n == 2 && animals.size() > 0)
            {
                cout << "There are " << animals.size() << "animals" << endl;
                cout << "Which one?(just a numaber between 1 to " << animals.size() << ")" << endl;
                for (int i = 0; i < names.size(); i++)
                {
                    cout << i + 1 << "." << names[i] << endl;
                }
            hell1:
                try
                {
                    int n;
                    cout << "Enter the number : ";
                    cin >> n;
                    cout << "Which Chromo?(just a numaber between 1 to " << animals[n - 1].C[0].Get_No_Chromo() << ")" << endl;
                hell:
                    try
                    {

                        int m, k;
                        char c, h;
                        cout << "Enter the number : ";
                        cin >> m;
                        cout << "First Character : ";
                        cin >> c;
                        cout << "Second Character : ";
                        cin >> h;
                        cout << "How many : ";
                        cin >> k;
                        if (c == 'A' || c == 'T' || c == 'G' || c == 'C')
                        {
                            if (h == 'A' || h == 'T' || h == 'G' || h == 'C')
                            {
                                animals[n - 1].C[0].JaheshS(c, h, k, m);
                            }
                            else
                            {
                                goto hell;
                            }
                        }
                        else
                        {
                            goto hell;
                        }
                    }
                    catch (const out_of_range)
                    {
                        cerr << "just a numaber between 1 to " << animals[n - 1].C[0].Get_No_Chromo() << ")" << endl;
                        goto hell;
                    }
                    catch (const exception)
                    {
                        cerr << "just a number!" << '\n';
                        goto hell;
                    }
                }
                catch (const out_of_range)
                {
                    cerr << "just a numaber between 1 to " << animals.size() << endl;
                    goto hell1;
                }
                catch (const exception)
                {
                    cerr << "just a number!" << '\n';
                    goto hell1;
                }
            }
            else if (n == 3 && animals.size() > 0)
            {
                cout << "There are " << animals.size() << "animals" << endl;
                cout << "Which one?(just a numaber between 1 to " << animals.size() << ")" << endl;
                for (int i = 0; i < names.size(); i++)
                {
                    cout << i + 1 << "." << names[i] << endl;
                }
            hell3:
                try
                {
                    int n;
                    cout << "Enter the number : ";
                    cin >> n;
                    cout << "Which Chromo?(just a numaber between 1 to " << animals[n - 1].C[0].Get_No_Chromo() << ")" << endl;
                hell2:
                    try
                    {

                        int m, k;
                        string s1, s2;
                        cout << "First number : ";
                        cin >> m;
                        cout << "Second number : ";
                        cin >> k;
                        cout << "First String : ";
                        cin >> s1;
                        cout << "Second String : ";
                        cin >> s2;

                        animals[n - 1].JaheshB(s1, m, s2, k);
                    }
                    catch (const out_of_range)
                    {
                        cerr << "just a numaber between 1 to " << animals[n - 1].C[0].Get_No_Chromo() << ")" << endl;
                        goto hell2;
                    }
                    catch (const exception)
                    {
                        cerr << "just a number!" << '\n';
                        goto hell2;
                    }
                }
                catch (const out_of_range)
                {
                    cerr << "just a numaber between 1 to " << animals.size() << endl;
                    goto hell3;
                }
                catch (const exception)
                {
                    cerr << "just a number!" << '\n';
                    goto hell3;
                }
            }
            else if (n == 4 && animals.size() > 0)
            {
                cout << "There are " << animals.size() << "animals" << endl;
                cout << "Which one?(just a numaber between 1 to " << animals.size() << ")" << endl;
                for (int i = 0; i < names.size(); i++)
                {
                    cout << i + 1 << "." << names[i] << endl;
                }
            hell5:
                try
                {
                    int n;
                    cout << "Enter the number : ";
                    cin >> n;
                    cout << "Which Chromo?(just a numaber between 1 to " << animals[n - 1].C[0].Get_No_Chromo() << ")" << endl;
                hell4:
                    try
                    {

                        int m;
                        string s1;
                        cout << "First number : ";
                        cin >> m;
                        cout << "First String : ";
                        cin >> s1;

                        animals[n - 1].JaheshR(s1, m);
                    }
                    catch (const out_of_range)
                    {
                        cerr << "just a numaber between 1 to " << animals[n - 1].C[0].Get_No_Chromo() << ")" << endl;
                        goto hell4;
                    }
                    catch (const exception)
                    {
                        cerr << "just a number!" << '\n';
                        goto hell4;
                    }
                }
                catch (const out_of_range)
                {
                    cerr << "just a numaber between 1 to " << animals.size() << endl;
                    goto hell5;
                }
                catch (const exception)
                {
                    cerr << "just a number!" << '\n';
                    goto hell5;
                }
            }
            else if (n == 5 && animals.size() > 0)
            {
                cout << "There are " << animals.size() << "animals" << endl;
                cout << "Which one?(just a numaber between 1 to " << animals.size() << ")" << endl;
                for (int i = 0; i < names.size(); i++)
                {
                    cout << i + 1 << "." << names[i] << endl;
                }
            hell7:
                try
                {
                    int n;
                    cout << "Enter the number : ";
                    cin >> n;
                    cout << "Which Chromo?(just a numaber between 1 to " << animals[n - 1].C[0].Get_No_Chromo() << ")" << endl;
                hell6:
                    try
                    {

                        int m;
                        cout << "First number : ";
                        cin >> m;

                        animals[n - 1].palin(m);
                    }
                    catch (const out_of_range)
                    {
                        cerr << "just a numaber between 1 to " << animals[n - 1].C[0].Get_No_Chromo() << ")" << endl;
                        goto hell6;
                    }
                    catch (const exception)
                    {
                        cerr << "just a number!" << '\n';
                        goto hell6;
                    }
                }
                catch (const out_of_range)
                {
                    cerr << "just a numaber between 1 to " << animals.size() << endl;
                    goto hell7;
                }
                catch (const exception)
                {
                    cerr << "just a number!" << '\n';
                    goto hell7;
                }
            }
            else if (n == 6 && animals.size() > 1)
            {
                cout << "There are " << animals.size() << "animals" << endl;
                cout << "Which one?(just a numaber between 1 to " << animals.size() << ")" << endl;
                for (int i = 0; i < names.size(); i++)
                {
                    cout << i + 1 << "." << names[i] << endl;
                }
            hell9:
                try
                {
                    int n, m;
                    cout << "First number : ";
                    cin >> n;
                    cout << "Second number : ";
                    cin >> m;

                hell8:
                    try
                    {
                        if (animals[n - 1] == animals[m - 1])
                        {
                            cout << "Same" << endl;
                        }
                        else
                        {
                            cout << "Not Same" << endl;
                        }
                    }
                    catch (const out_of_range)
                    {
                        cerr << "just a numaber between 1 to " << animals.size() << ")" << endl;
                        goto hell8;
                    }
                    catch (const exception)
                    {
                        cerr << "just a number!" << '\n';
                        goto hell8;
                    }
                }
                catch (const exception)
                {
                    cerr << "just a number!" << '\n';
                    goto hell9;
                }
            }
            else if (n == 7 && animals.size() > 0)
            {
                cout << "There are " << animals.size() << "animals" << endl;
                cout << "Which one?(just a numaber between 1 to " << animals.size() << ")" << endl;
                for (int i = 0; i < names.size(); i++)
                {
                    cout << i + 1 << "." << names[i] << endl;
                }
            hell11:
                try
                {
                    int n;
                    cout << "First number : ";
                    cin >> n;
                hell10:
                    try
                    {
                        sample.AsexuaRep(animals[n - 1].C);
                    }
                    catch (const out_of_range)
                    {
                        cerr << "just a numaber between 1 to " << animals.size() << ")" << endl;
                        goto hell10;
                    }
                    catch (const exception)
                    {
                        cerr << "just a number!" << '\n';
                        goto hell10;
                    }
                }
                catch (const exception)
                {
                    cerr << "just a number!" << '\n';
                    goto hell11;
                }
            }
            else if (n == 8 && animals.size() > 1)
            {
                cout << "There are " << animals.size() << "animals" << endl;
                cout << "Which one?(just a numaber between 1 to " << animals.size() << ")" << endl;
                for (int i = 0; i < names.size(); i++)
                {
                    cout << i + 1 << "." << names[i] << endl;
                }
            hell13:
                try
                {
                    int n, m;
                    cout << "First number : ";
                    cin >> n;
                    cout << "Second number : ";
                    cin >> m;

                hell12:
                    try
                    {
                        if (animals[n - 1] == animals[m - 1])
                        {
                            cout << "Same" << endl;
                        }
                        else
                        {
                            cout << "Not Same" << endl;
                        }
                    }
                    catch (const out_of_range)
                    {
                        cerr << "just a numaber between 1 to " << animals.size() << ")" << endl;
                        goto hell12;
                    }
                    catch (const exception)
                    {
                        cerr << "just a number!" << '\n';
                        goto hell12;
                    }
                }
                catch (const exception)
                {
                    cerr << "just a number!" << '\n';
                    goto hell13;
                }
            }
        }
        catch (const exception)
        {
            cerr << "just number!" << '\n';
        }
    }

    return 0;
}