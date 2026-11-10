#include <iostream>
#include <string>

using namespace std;

// кількість символів '+', '-', '='
int Count(const string& s)
{
    int k = 0;
    size_t pos = s.find_first_of("+-=");
    while (pos != string::npos)
    {
        k++;
        pos = s.find_first_of("+-=", pos + 1);
    }
    return k;
}

// копія рядка, де кожен '+', '-', '=' замінено на "**"
string Change(string s)
{
    size_t pos = 0;
    while ((pos = s.find_first_of("+-=", pos)) != string::npos)
    {
        s.replace(pos, 1, "**");
        pos += 2;
    }
    return s;
}

int main()
{
    string str;

    cout << "Enter string:" << endl;
    getline(cin, str);

    cout << "String contained " << Count(str) << " symbols '+', '-', '='" << endl;

    string dest = Change(str);
    cout << "Modified string: " << dest << endl;

    return 0;
}