#include <iostream>
#include <limits>
#include <string>
#include <sstream>

using namespace std;

int validation(
    int lower = numeric_limits<int>::min(),
    int upper = numeric_limits<int>::max(),
    const string& prompt = "Please enter a value: ",
    const string& error = "Your value is invalid",
    bool hasDefault = false,
    int defaultValue = 0)
{
    int input;
    bool check = false;
    while (!check)
    {
        cout << prompt;
        if (hasDefault)
        {
            cout << "\nHit ENTER to use default value of " << defaultValue << endl;
        }
        cout << endl;

        string line;
        getline(cin, line);

        if (line.empty() && hasDefault)
        {
            input = defaultValue;
            check = true;
        }
        else
        {
            stringstream parseInt(line);
            if (parseInt >> input && parseInt.eof())
            {
                if (input < lower || input > upper)
                {
                    cout << error << endl;
                }
                else
                {
                    check = true;
                }
            }
            else
            {
                cout << error << endl;
            }
        }
    }
    return input;
}

int main()
{
    int test;

    test = validation();
    cout << "You entered: " << test << endl;

    test = validation(0, 100, "Please enter a value between 0 and 100", "Your value is invalid", true, 50);
    cout << "You entered: " << test << endl;

    test = validation(0, numeric_limits<int>::max(), "Please enter a value greater or equal to 0", "Your value is invalid", true, 10);
    cout << "You entered: " << test << endl;

    test = validation(numeric_limits<int>::min(), 100, "Please enter a value less or equal to 100");
    cout << "You entered: " << test << endl;

    return 0;
}
