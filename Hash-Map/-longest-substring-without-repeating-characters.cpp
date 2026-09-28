#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::vector<int> lastSeen(256, -1);
        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];

            if (lastSeen[currentChar] >= left) {
                left = lastSeen[currentChar] + 1;
            }

            lastSeen[currentChar] = right;
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    std::string s1 = "abcabcbb";
    std::cout << "Test 1 Output: " << sol.lengthOfLongestSubstring(s1) << " (Expected: 3)" << std::endl;

    // Test Case 2
    std::string s2 = "bbbbb";
    std::cout << "Test 2 Output: " << sol.lengthOfLongestSubstring(s2) << " (Expected: 1)" << std::endl;

    // Test Case 3
    std::string s3 = "pwwkew";
    std::cout << "Test 3 Output: " << sol.lengthOfLongestSubstring(s3) << " (Expected: 3)" << std::endl;

    return 0;
}
