#include <iostream>
#include <cctype>

using namespace std;

int find(const string &str, const char &c, bool caseSensitive = true, int start = 0)
{
    if (start < 0 || start >= str.size())
    {
        return -1; 
    }

    for (int i = start; i < str.size(); i++)
    {
        if (caseSensitive)
        {
            if (str[i] == c)
            {
                return i;
            }
        }
        else
        {
            if (tolower(str[i]) == tolower(c))
            {
                return i;
            }
        }
    }
    return -1;
}

int find(const string &str, const string &search, bool caseSensitive = true, int start = 0)
{
    int searchSize = search.size();
    int strSize = str.size();

    if (start < 0 || start > strSize)
    {
        return -1;
    }

    if (searchSize == 0)
    {
        return 0;
    }

    for (int i = start; i <= (strSize - searchSize); i++)
    {
        int index = 0;
        while (index < searchSize)
        {
            char strChar;
            char searchChar;
            if (caseSensitive)
            {
                strChar = str[i + index];
                searchChar = search[index];
            }
            else
            {
                strChar= tolower(str[i + index]);
                searchChar = tolower(search[index]);
            }
            if (strChar != searchChar)
            {
                break;
            }
            index++;
        }
        if (index == searchSize)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    cout << "Case-sensitive searches:" << endl;
    cout << find("SpaceX is cool", 'c') << endl;
    cout << find("SpaceX is cool", 'c', true, 2) << endl;
    cout << find("SpaceX is cool", 'c', true, 5) << endl;
    cout << "Case-insensitive searches:" << endl;
    cout << find("SpaceX is cool", 'c') << endl;
    cout << find("SpaceX is cool", 'c', false, 2) << endl;
    cout << find("SpaceX is cool", 'c', false, 5) << endl;

}