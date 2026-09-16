#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        auto isPalindrome = [&](int l, int r) {
            while (l < r) {
                if (s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        };

        for (int i = 0; i < n; i++) {
            dp[i + 1] = max(dp[i + 1], dp[i]);

            // Checking minimal odd-length valid palindromic window
            if (i + k <= n && isPalindrome(i, i + k - 1)) {
                dp[i + k] = max(dp[i + k], dp[i] + 1);
            }

            // Checking minimal even-length valid palindromic window
            if (i + k + 1 <= n && isPalindrome(i, i + k)) {
                dp[i + k + 1] = max(dp[i + k + 1], dp[i] + 1);
            }
        }

        return dp[n];
    }
};

int main() {
    Solution sol;

    string s1 = "abaccdbbd";
    int k1 = 3;
    cout << "Example 1 Output: " << sol.maxPalindromes(s1, k1) << " (Expected: 2)" << endl;

    string s2 = "adbcda";
    int k2 = 2;
    cout << "Example 2 Output: " << sol.maxPalindromes(s2, k2) << " (Expected: 0)" << endl;

    return 0;
}
