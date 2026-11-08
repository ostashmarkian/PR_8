#include <iostream>
#include <cstring>

using namespace std;

// чи є символ одним із '+', '-', '='
bool IsSign(char c)
{
    return c == '+' || c == '-' || c == '=';
}

// кількість символів '+', '-', '='
int Count(const char* str)
{
    int k = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (IsSign(str[i]))
            k++;
    return k;
}

// новий рядок, де кожен '+', '-', '=' замінено на "**"
char* Change(const char* str)
{
    char* tmp = new char[2 * strlen(str) + 1];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (IsSign(str[i]))
        {
            tmp[j++] = '*';
            tmp[j++] = '*';
        }
        else
            tmp[j++] = str[i];
    }
    tmp[j] = '\0';
    return tmp;
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " symbols '+', '-', '='" << endl;

    char* dest = Change(str);
    cout << "Modified string: " << dest << endl;

    delete[] dest;
    return 0;
}
