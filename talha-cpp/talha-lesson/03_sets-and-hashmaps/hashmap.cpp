#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> myMap;

    // 2 ways to insert into map
    // first:
    // ["key"] = value
    myMap["Chris"] = 25;
    myMap["Talha"] = 29;
    myMap["Abdullah"] = 29;
    myMap["Anusha"] = 31;

    // second:
    myMap.insert({"Ali", 18});
    myMap.insert({"Aurangseb", 23});

    // but insert can only add once
    myMap.insert({{"Salah", 25}, {"Abid", 20}});

    myMap.erase("Abullah");

    if (myMap.find("Chris") != myMap.end())
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not found" << endl;
    }

    for (auto pair : myMap)
    {
        cout << pair.first << " " << pair.second << endl;
    }
}