#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s1.length() > s2.length())
        return false;
    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);
    for (char c : s1) {
        freq1[c - 'a']++;
    }
    for (int i = 0; i < s1.length(); i++) {
        freq2[s2[i] - 'a']++;
    }
    if (freq1 == freq2)
        return true;
    for (int right = s1.length(); right < s2.length(); right++) {
        freq2[s2[right] - 'a']++;
        int left = right - s1.length();

        freq2[s2[left] - 'a']--;
        if (freq1 == freq2)
            return true;
    }

    return false;
}

int main() {

    string s1, s2;

    cout << "Enter s1: ";
    cin >> s1;

    cout << "Enter s2: ";
    cin >> s2;

    bool result = checkInclusion(s1, s2);

    if (result)
        cout << "True - permutation exists" << endl;
    else
        cout << "False - permutation does not exist" << endl;

    return 0;
}
