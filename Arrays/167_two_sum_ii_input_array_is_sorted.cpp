#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int current_sum = numbers[left] + numbers[right];
            if (current_sum == target) {
                return {left + 1, right + 1}; // 1-indexed
            } else if (current_sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};

int main() {
    Solution solver;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solver.twoSum(numbers, target);

    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl; // Output: [1, 2]
    return 0;
}
