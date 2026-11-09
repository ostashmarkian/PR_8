#include<iostream>
#include<cstring>

using namespace std;
bool IsSign(char c)
{
    return c == '+' || c == '-' || c == '=';
}

int Count(const char* str, int k, int i) {
    if (str[i] == '\0') {
        return k;
    }
    if (IsSign(str[i]))
        return Count(str, k + 1, i + 1);
    return Count(str, k, i + 1);

}
char* Change(const char* str, char* tmp, int i, int j)
{
    if (str[i] == '\0')
    {
        tmp[j] = '\0';
        return tmp;
    }

    if (IsSign(str[i]))
    {
        tmp[j] = '*';
        tmp[j + 1] = '*';
        return Change(str, tmp, i + 1, j + 2);
    }

    tmp[j] = str[i];
    return Change(str, tmp, i + 1, j + 1);
}
int main() {
    char str[101];
    int k;
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    k = Count(str, 0, 0);
    cout << "String contained " << k << " symbols '+', '-', '='" << endl;
    char* tmp = new char[2 * strlen(str) + 1];
    Change(str, tmp, 0, 0);
    cout << "Modified string: " << tmp << endl;
    delete[] tmp;
    return 0;
}