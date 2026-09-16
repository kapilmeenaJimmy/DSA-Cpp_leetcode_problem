#include <iostream>
#include <vector>

class Solution {
public:
    // Optimal Reverse Three-Pointer: O(m + n) Time, O(1) Space
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t idx = 0; idx < vec.size(); ++idx) {
        std::cout << vec[idx] << (idx + 1 < vec.size() ? ", " : "");
    }
    std::cout << "]\n";
}

int main() {
    Solution solver;

    // Test Case 1: Standard merge
    std::vector<int> nums1_1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2_1 = {2, 5, 6};
    solver.merge(nums1_1, 3, nums2_1, 3);
    std::cout << "Test 1 Output: ";
    printVector(nums1_1); // Expected: [1, 2, 2, 3, 5, 6]

    // Test Case 2: nums2 empty
    std::vector<int> nums1_2 = {1};
    std::vector<int> nums2_2 = {};
    solver.merge(nums1_2, 1, nums2_2, 0);
    std::cout << "Test 2 Output: ";
    printVector(nums1_2); // Expected: [1]

    // Test Case 3: nums1 empty valid elements (m = 0)
    std::vector<int> nums1_3 = {0};
    std::vector<int> nums2_3 = {1};
    solver.merge(nums1_3, 0, nums2_3, 1);
    std::cout << "Test 3 Output: ";
    printVector(nums1_3); // Expected: [1]

    return 0;
}
