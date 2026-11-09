#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// кількість символів '+', '-', '='
int Count(const char* str)
{
    int k = 0;
    const char* p = str;
    while ((p = strpbrk(p, "+-=")) != NULL)
    {
        k++;
        p++;
    }
    return k;
}

// новий рядок, де кожен '+', '-', '=' замінено на "**"
char* Change(const char* str)
{
    char* tmp = new char[2 * strlen(str) + 1];
    tmp[0] = '\0';

    const char* p;
    while ((p = strpbrk(str, "+-=")) != NULL)
    {
        strncat(tmp, str, p - str);   // частина до символу
        strcat(tmp, "**");
        str = p + 1;
    }
    strcat(tmp, str);                 // залишок рядка
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