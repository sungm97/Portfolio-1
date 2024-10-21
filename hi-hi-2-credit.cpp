#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int strcmp_case_insensitive(const string& str1, const string& str2, bool skip_spaces = false, int max_chars = -1)
{
    string string1;
    string string2;

    int counter1 = 0;
    int counter2 = 0;

    
    for (size_t i = 0; i < str1.length(); i++)
    {
        if (skip_spaces && str1[i] == ' ')
            continue;

        if (max_chars >= 0 && counter1 >= max_chars)
            break;

        string1 += toupper(str1[i]);
        counter1++;
    }

    for (size_t i = 0; i < str2.length(); i++)
    {
        if (skip_spaces && str2[i] == ' ')
            continue;

        if (max_chars >= 0 && counter2 >= max_chars)
            break;

        string2 += toupper(str2[i]);
        counter2++;
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
    struct test_case_max_chars
    {
        string string1;
        string string2;
        int max_chars;
    };

    test_case_max_chars test[] = 
    {
        {"string one", "string one", 6},
        {"string two", "string five", 10},
        {"abcde", "abcfgh", 4},    
        {"abcdef", "abc", 10},     
        {"abc", "abcdef", 10},     
        {"abc", "ABC", 0},          
        {"abc", "ABC", -2},          
    };

    for (int i = 0; i < 7; i++)
    {
        int result = strcmp_case_insensitive(test[i].string1, test[i].string2, false, test[i].max_chars);
        cout << "Comparing \"" << test[i].string1 << "\" and \"" << test[i].string2 << "\" with max_chars=" << test[i].max_chars << " returns " << result << endl;
    }
}

int main()
{
    driver();
    return 0;
}
