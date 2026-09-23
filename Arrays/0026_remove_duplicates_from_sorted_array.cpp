#include <iostream>
#include <vector>
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }


        int insertIndex = 1;

        // Traverse using a fast pointer starting at index 1
        for (size_t i = 1; i < nums.size(); ++i) {
            // Check if current element is distinct from previous element
            if (nums[i] != nums[i - 1]) {
                nums[insertIndex] = nums[i]; // Write unique element in-place
                ++insertIndex;               // Advance write boundary
            }
        }

        return insertIndex;
    }
};

// Driver code for local VS Code testing
int main() {
    Solution solution;
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    int k = solution.removeDuplicates(nums);

    std::cout << "Count of unique elements: " << k << "\n";
    std::cout << "Array after removing duplicates: [ ";
    for (int i = 0; i < k; ++i) {
        std::cout << nums[i] << " ";
    }
    std::cout << "]\n";

    return 0;
}
