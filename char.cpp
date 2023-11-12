//! кінцевий результат
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int Count(char *s) {
    int k = 0,
        pos = 0;

    char *t;

    while (t = strstr(s + pos, "no")) {
        pos = t - s + 1;
        k++;
    }

    pos = 0;

    while (t = strstr(s + pos, "on")) {
        pos = t - s + 1;
        k++;
    }

    return k;
}

char *Change(char *s) {
    char *t = new char[strlen(s)];
    char *p;
    int pos1 = 0,
        pos2 = 0;
    *t = 0;
    while (p = strstr(s + pos1, "no")) {
        pos2 = p - s + 2;
        strncat(t, s + pos1, pos2 - pos1 - 2);
        strcat(t, "***");
        pos1 = pos2;
    }
    strcat(t, s + pos1);
    strcpy(s, t);
    return t;
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str) << " groups of 'no' or 'on'" << endl;
    char *dest = new char[151];
    dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    return 0;
}