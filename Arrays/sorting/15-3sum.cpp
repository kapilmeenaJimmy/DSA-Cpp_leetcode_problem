#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> triplets;
        const int n = static_cast<int>(nums.size());

        // Step 1: Sort array to use the two-pointer technique and prune duplicates
        std::sort(nums.begin(), nums.end());

        // Step 2: Fix the first element
        for (int i = 0; i < n - 2; ++i) {
            // Early break: since array is sorted, values > 0 cannot sum to 0
            if (nums[i] > 0) {
                break;
            }

            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Step 3: Two-pointer scan on the remainder of the array
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                const int currentSum = nums[i] + nums[left] + nums[right];

                if (currentSum == 0) {
                    triplets.push_back({nums[i], nums[left], nums[right]});


                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }

                    ++left;
                    --right;
                } else if (currentSum < 0) {
                    ++left; // Increase sum
                } else {
                    --right; // Decrease sum
                }
            }
        }

        return triplets;
    }
};
int main() {
    Solution solution;
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};

    std::vector<std::vector<int>> result = solution.threeSum(nums);

    std::cout << "Unique Triplets summing to 0:\n";
    for (const auto& triplet : result) {
        std::cout << "[ ";
        for (int num : triplet) {
            std::cout << num << " ";
        }
        std::cout << "]\n";
    }

    return 0;
}
