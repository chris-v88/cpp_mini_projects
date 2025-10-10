#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// get all divisors of the number
vector<int> getDivisors(int num)
{
    vector<int> divisors;

    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            cout << num << " / " << i << " = " << (num / i) << endl;
            divisors.push_back(i);
        }
    };

    cout << "The divisors of " << num << " are: ";
    for (int d : divisors)
    {
        cout << d << " ";
    }

    return divisors;
}

// sum of the proper divisors
int sumOfDivisors(vector<int> divisors)
{
    int result = 0;
    cout << "\nSum: ";
    for (int i = 0; i < divisors.size(); i++)
    {
        if (i != (divisors.size() - 1))
            cout << divisors[i] << " + ";
        else
            cout << divisors[i] << " = ";
        result += divisors[i];
    }
    cout << result << endl;
    return result;
}

bool isPerfectNumber(int num)
{
    vector<int> divisors = getDivisors(num);
    int sum = sumOfDivisors(divisors);

    return sum == num;
}

int main()
{
    cout << "Check if the number is perfect." << endl;
    cout << "Enter a number: ";

    int num;
    cin >> num;

    bool result = isPerfectNumber(num);
    if (result)
    {
        cout << "\nThe number " << num << " is a perfect number!" << endl;
    }
    else
    {
        cout << "\nThe number " << num << " is NOT a perfect number!" << endl;
    }

    return 0;
}