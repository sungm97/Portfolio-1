#include <iostream>
#include <cctype>

using namespace std;

int find(const string &str, const char &c, bool caseSensitive = true)
{
    for (int i = 0; i < str.size(); i++)
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

int find(const string &str, const string &search, bool caseSensitive = true)
{
    int searchSize = search.size();
    if (searchSize == 0)
    {
        return 0; 
    }

    for (int i = 0; i <= (str.size() - searchSize); i++)
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
    cout << find("String", 'z') << endl;                        
    cout << find("String", "ing") << endl;                      
    cout << find("The quick brown fox", 'e') << endl;           
    cout << find("The quick brown fox", "e") << endl;           
    cout << find("The quick brown fox", ' ') << endl;           
    cout << find("The quick brown fox", "quiet") << endl;      
    cout << find("The quick brown fox", "quick") << endl;       
    cout << find("The quick brown fox", "") << endl;            
    
    cout << "\nCase-insensitive searches:" << endl;
    cout << find("String", 'Z', false) << endl;   
    cout << find("String", 's', false) << endl;   
    cout << find("String", "ING", false) << endl;               
    cout << find("The quick brown fox", 'E', false) << endl;   
    cout << find("The quick brown fox", "E", false) << endl;    
    cout << find("The quick brown fox", ' ', false) << endl;    
    cout << find("The quick brown fox", "QUIET", false) << endl;
    cout << find("The quick brown fox", "QUICK", false) << endl;
    cout << find("The quick brown fox", "", false) << endl;     

    return 0;
}
