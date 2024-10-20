#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int strcmp_case_insensitive(const string& str1, const string& str2, bool skip) 
{
    string string1;
    string string2;
    for (char c : str1) 
    {
        if (skip && c == ' ')
        {
            continue;
        }
        string1 += toupper(c);
    }
    for (char c : str2) 
    {
        if (skip && c == ' ') {
            continue;
        }
        string2 += toupper(c);
    }
    
    if (string1 < string2)
    {
        return -1;
    }
    else if (string1 > string2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void driver()
{
    struct test_case
    {
        string string1;
        string string2;
    };
    test_case test1[] = 
    {
        {"string one", "string one"},
        {"string one", "stringone"},        
        {"string two", "string one"},
        {"STRING ONE", "string one"},
        {"abcd", "a b c d"},
        {"test","testerino"},
        {"","a"},
        {"",""},
        {"0", "1"},
        {"0","-1"},
        {"NULL", ""},
    };
    for (int i = 0; i < 11; i++)
    {
        int result = strcmp_case_insensitive(test1[i].string1, test1[i].string2, true);
        cout << "The comparison of " << test1[i].string1 << " and " << test1[i].string2 << " returns " << result << endl;
    }
}

int main()
{
    driver();
    return 0;
}
