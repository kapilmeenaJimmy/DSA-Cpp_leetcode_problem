#include <iostream>
#include <string>
#include <cctype>

class Solution {
public:
    bool isPalindrome(const std::string& s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[left]))) {
                left++;
            }
            while (left < right && !std::isalnum(static_cast<unsigned char>(s[right]))) {
                right--;
            }

            if (std::tolower(static_cast<unsigned char>(s[left])) != 
                std::tolower(static_cast<unsigned char>(s[right]))) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {
    Solution solver;

    std::string s1 = "A man, a plan, a canal: Panama";
    std::string s2 = "race a car";
    std::string s3 = " ";

    std::cout << std::boolalpha;
    std::cout << "Example 1 Output: " << solver.isPalindrome(s1) << " (Expected: true)\n";
    std::cout << "Example 2 Output: " << solver.isPalindrome(s2) << " (Expected: false)\n";
    std::cout << "Example 3 Output: " << solver.isPalindrome(s3) << " (Expected: true)\n";

    return 0;
}
