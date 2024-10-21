#include <iostream>
#include <limits>
#include <string>

using namespace std;

int validateInt(int lower = numeric_limits<int>::min(), int upper = numeric_limits<int>::max(), const string& prompt = "Please enter a value: ", const string& error = "Your value is invalid")
{
    int input;
    bool check = false;
    while (!check)
    {
        cout << prompt << endl;
        cin >> input;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer value." << endl;
            continue;
        }

        if (input < lower || input > upper)
        {
            cout << error << endl;
        }
        else
        {
            check = true;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return input;
}

string validateString(const string& prompt = "Please enter a string: ", const string& error = "You entered an empty string. Try again!")
{
    string input;
    bool check = false;
    while (!check)
    {
        cout << prompt << endl;
        getline(cin, input);

        if (input.empty())
        {
            cout << error << endl;
        }
        else
        {
            check = true;
        }
    }
    return input;
}

int main()
{
    string testStr;
    int testInt;

    testStr = validateString("Please enter a non-empty string:");
    cout << "You entered string: " << testStr << endl;

    testInt = validateInt();
    cout << "You entered integer: " << testInt << endl;

    testInt = validateInt(0, 100, "Please enter a value between 0 and 100");
    cout << "You entered integer: " << testInt << endl;

    testInt = validateInt(0, numeric_limits<int>::max(), "Please enter a value greater or equal to 0");
    cout << "You entered integer: " << testInt << endl;

    testInt = validateInt(numeric_limits<int>::min(), 100, "Please enter a value less or equal to 100");
    cout << "You entered integer: " << testInt << endl;

  
    return 0;
}
