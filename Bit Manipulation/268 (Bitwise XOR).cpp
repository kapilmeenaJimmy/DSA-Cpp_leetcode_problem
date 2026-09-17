#include <iostream>
#include <vector>
#include <numeric>

// Solution class
class Solution {
public:
    // Bitwise XOR: Time O(N), Space O(1)
    int missingNumberXOR(const std::vector<int>& nums) {
        int n = nums.size();
        int missing = n;
        for (int i = 0; i < n; ++i) {
            missing ^= i ^ nums[i];
        }
        return missing;
    }

    // Mathematical Sum: Time O(N), Space O(1)
    int missingNumberSum(const std::vector<int>& nums) {
        int n = nums.size();
        long long expectedSum = (static_cast<long long>(n) * (n + 1)) / 2;
        long long actualSum = 0;
        for (int num : nums) {
            actualSum += num;
        }
        return static_cast<int>(expectedSum - actualSum);
    }
};

int main() {
    Solution solver;

    // Test Case 1: [3, 0, 1] -> Expected: 2
    std::vector<int> test1 = {3, 0, 1};
    std::cout << "Test 1 Result (XOR): " << solver.missingNumberXOR(test1) << " | Expected: 2\n";

    // Test Case 2: [0, 1] -> Expected: 2
    std::vector<int> test2 = {0, 1};
    std::cout << "Test 2 Result (Sum): " << solver.missingNumberSum(test2) << " | Expected: 2\n";

    // Test Case 3: [9,6,4,2,3,5,7,0,1] -> Expected: 8
    std::vector<int> test3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    std::cout << "Test 3 Result (XOR): " << solver.missingNumberXOR(test3) << " | Expected: 8\n";

    return 0;
}
