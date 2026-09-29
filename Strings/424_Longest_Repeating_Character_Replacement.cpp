#include <bits/stdc++.h>
using namespace std;

int characterReplacement(string s, int k) {

    vector<int> freq(26, 0);

    int left = 0;
    int maxFreq = 0;
    int answer = 0;

    for (int right = 0; right < s.length(); right++) {

        // Add current character
        freq[s[right] - 'A']++;

        // Maximum frequency inside window
        maxFreq = max(maxFreq, freq[s[right] - 'A']);

        // If replacements required > k
        while ((right - left + 1) - maxFreq > k) {

            freq[s[left] - 'A']--;
            left++;
        }

        // Update answer
        answer = max(answer, right - left + 1);
    }

    return answer;
}

int main() {

    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter k: ";
    cin >> k;

    int result = characterReplacement(s, k);

    cout << "Longest length = " << result << endl;

    return 0;
}
