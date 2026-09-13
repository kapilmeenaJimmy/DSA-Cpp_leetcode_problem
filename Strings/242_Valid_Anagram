#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.length() != t.length()) {
            return false;
        }

        std::vector<int> count(26, 0);

        for (int i = 0; i < s.length(); ++i) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    Solution sol;
    std::string s = "anagram", t = "nagaram";
    std::cout << "Is Anagram: " << (sol.isAnagram(s, t) ? "true" : "false") << std::endl; // Expected: true

    return 0;
}
