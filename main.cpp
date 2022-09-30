#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

bool digital(string& s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < '0' && s[i] > '9') {
            return false;
        }
    }
    return true;
}

int convert_number(string& s) {
    int number = 0;
    for (int i = 0; i < s.size(); i++) {
        number *= 10;
        number += (s[i] - '0');
    }
    return number;
}

bool number(string& s) {
    if (s.size() > 3 || s.size() == 0) {
        return false;
    }
    if (s.size() == 2) {
        if (convert_number(s) < 10) {
            return false;
        }
    }
    if (s.size() == 3) {
        if (convert_number(s) < 100 || convert_number(s) > 255) {
            return false;
        }
    }
    return true;
}

bool check(string& s) {
    if (digital(s) == false) {
        return false;
    }
    if (number(s) == false) {
        return false;
    }
    return true;
}

int main() {
    string s, s1;
    getline(cin, s);
    s1 = "";
    int k = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '.') {
            ++k;
        }
        if (s[i] != '.') {
            s1 += s[i];
            if (i == s.size() - 1) {
                if (check(s1) == false) {
                    cout << "NO";
                    return 0;
                }
            }
        } else {
            if (check(s1) == false) {
                cout << "NO";
                return 0;
            }
            s1 = "";
        }
    }
    if (k == 3 && s[s.size() - 1] != '.') {
        cout << "YES";
    } else {
        cout << "NO";
    }
  return 0;
}
