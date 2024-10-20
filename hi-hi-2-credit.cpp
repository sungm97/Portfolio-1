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

    // Process str2
    for (size_t i = 0; i < str2.length(); i++)
    {
        if (skip_spaces && str2[i] == ' ')
            continue;

        if (max_chars >= 0 && counter2 >= max_chars)
            break;

        string2 += toupper(str2[i]);
        counter2++;
    }

    // Compare the two processed strings
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
        {"string one", "string two"},
        {"string one", "string one"},        
        {"string two", "string one"},
        {"STRING ONE", "string one"},
        {"test","testerino"},
        {"","a"},
        {"",""},
        {"0", "1"},
        {"0","-1"},
        {"NULL", ""},
    };

    cout << "Original comparisons without specifying max_chars:\n";
    for (int i = 0; i < 10; i++)
    {
        int result = strcmp_case_insensitive(test1[i].string1, test1[i].string2);
        cout << "The comparison of \"" << test1[i].string1 << "\" and \"" << test1[i].string2 << "\" returns " << result << endl;
    }

    // Comparisons with max_chars specified
    cout << "\nComparisons with max_chars specified:\n";

    // Test cases for max_chars
    struct test_case_max_chars
    {
        string string1;
        string string2;
        int max_chars;
    };

    test_case_max_chars test2[] = 
    {
        {"abcdef", "abcxyz", 3},    // Should compare "ABC" vs "ABC", expect 0
        {"abcdef", "abcxyz", 4},    // Compare "ABCD" vs "ABCX", expect -1
        {"abcdef", "abc", 10},      // Compare "ABCDEF" vs "ABC", expect 1
        {"abc", "abcdef", 10},      // Compare "ABC" vs "ABCDEF", expect -1
        {"abc", "ABC", 0},          // Compare zero characters, expect 0
        {"abc", "def", -5},         // Negative max_chars, compare entire strings, expect -1
        {"abc", "def", 2},          // Compare "AB" vs "DE", expect -1
        {"abcdef", "abcxyz", 6},    // Compare "ABCDEF" vs "ABCXYZ", expect -1
        {"abcdef", "ABCDEF", 6},    // Compare "ABCDEF" vs "ABCDEF", expect 0
        {"abc", "abcdef", 3},       // Compare "ABC" vs "ABC", expect 0
        {"abc", "abcdef", 4},       // Compare "ABC" vs "ABCD", expect -1
    };

    for (int i = 0; i < 11; i++)
    {
        int result = strcmp_case_insensitive(test2[i].string1, test2[i].string2, false, test2[i].max_chars);
        cout << "Comparing \"" << test2[i].string1 << "\" and \"" << test2[i].string2 << "\" with max_chars=" << test2[i].max_chars << " returns " << result << endl;
    }

    // Edge cases
    cout << "\nEdge cases:\n";

    // max_chars is zero
    cout << "Comparing \"abc\" and \"def\" with max_chars=0 returns "
         << strcmp_case_insensitive("abc", "def", false, 0) << endl;

    // max_chars is negative
    cout << "Comparing \"abc\" and \"abc\" with max_chars=-1 returns "
         << strcmp_case_insensitive("abc", "abc", false, -1) << endl;

    // max_chars greater than string length
    cout << "Comparing \"abc\" and \"abc\" with max_chars=10 returns "
         << strcmp_case_insensitive("abc", "abc", false, 10) << endl;
}

int main()
{
    driver();
    return 0;
}
