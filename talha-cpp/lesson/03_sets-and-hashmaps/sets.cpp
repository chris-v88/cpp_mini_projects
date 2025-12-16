#include <iostream>
#include <set>
using namespace std;

int main()
{
    // Set just tell if the element is present or not

    set<int> mySet; // we can initallize it like `set<int> mySet = { 1, 2, 3, 4}`
    mySet = {10, 20, 30, 40, 50};
    mySet.insert(60);
    mySet.insert(4);
    mySet.erase(30);

    /*
    set<int>::iterator itr;

    for(itr = mySet.begin(); itr != mySet.end(); itr++)
    {
        // cout << itr << endl; // we can't do this

        // variable pointer to store the address (int*)
        // (*itr) is extract the address
        const int* ptr = &(*itr);

        cout << ptr << endl; // print address
        cout << *itr << endl;
    }
        */
    for (auto itr = mySet.begin(); itr != mySet.end(); ++itr)
    {
        const int *ptr = &(*itr);
        cout << ptr << endl; // print address
        cout << *itr << endl;
    }

    cout << "--- --- ---" << endl;
    if (mySet.find(4) != mySet.end()) // will find in te
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    cout << "--- --- ---" << endl;
    string sen1 = "My name is Chris, and I live in USA. USA is a country";
    string sen2 = "My name is Talha, and I live in Pakistan. Pakistan is a country";

    set<char> charSet1;
    for (int i = 0; i < sen1.length(); i++)
    {
        charSet1.insert(sen1[i]);
    }

    // for(auto itr = charSet1.begin(); itr != charSet1.end(); itr++) {
    //     cout << *itr << endl;
    // }

    set<char> charSet2;
    for (int i = 0; i < sen2.length(); i++)
    {
        charSet2.insert(sen2[i]);
    }

    cout << "Unique common characters: " << endl;
    for (char c : charSet1)
    {
        if (charSet2.find(c) != charSet2.end())
        {
            cout << c << endl;
        }
    }

    cout << "--- --- ---" << endl;
    set<int> numSet1 = {1, 2, 3, 4, 6, 5, 44, 55, 7, 8, 7, 6, 99};
    set<int> numSet2 = {1, 2, 3, 4, 6, 9, 34, 55, 7, 8, 7, 10, 21};

    for (int i : numSet1)
    {
        if (numSet2.find(i) != numSet2.end())
        {
            cout << i << endl;
        }
    }
}

int *ptr;
