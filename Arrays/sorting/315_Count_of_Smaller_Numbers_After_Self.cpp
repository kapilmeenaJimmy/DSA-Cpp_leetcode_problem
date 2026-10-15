#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();

        vector<int> indices(n);
        vector<int> counts(n, 0);

        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        mergeSort(nums, indices, counts, 0, n - 1);

        return counts;
    }

    void mergeSort(vector<int>& nums, vector<int>& indices,
                   vector<int>& counts, int left, int right) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;

        mergeSort(nums, indices, counts, left, mid);
        mergeSort(nums, indices, counts, mid + 1, right);

        vector<int> temp;

        int i = left;
        int j = mid + 1;

        while (i <= mid && j <= right) {
            if (nums[indices[i]] <= nums[indices[j]]) {
                counts[indices[i]] += j - (mid + 1);
                temp.push_back(indices[i]);
                i++;
            } else {
                temp.push_back(indices[j]);
                j++;
            }
        }

        while (i <= mid) {
            counts[indices[i]] += j - (mid + 1);
            temp.push_back(indices[i]);
            i++;
        }

        while (j <= right) {
            temp.push_back(indices[j]);
            j++;
        }

        for (int k = 0; k < temp.size(); k++) {
            indices[left + k] = temp[k];
        }
    }
};

int main() {
    Solution solution;

    vector<int> nums = {5, 2, 6, 1};
    vector<int> answer = solution.countSmaller(nums);

    cout << "[";

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];

        if (i + 1 < answer.size()) {
            cout << ", ";
        }
    }

    cout << "]\n";

    vector<int> nums2 = {-1};
    vector<int> answer2 = solution.countSmaller(nums2);

    cout << "[";

    for (int i = 0; i < answer2.size(); i++) {
        cout << answer2[i];

        if (i + 1 < answer2.size()) {
            cout << ", ";
        }
    }

    cout << "]\n";

    vector<int> nums3 = {2, 2, 1};
    vector<int> answer3 = solution.countSmaller(nums3);

    cout << "[";

    for (int i = 0; i < answer3.size(); i++) {
        cout << answer3[i];

        if (i + 1 < answer3.size()) {
            cout << ", ";
        }
    }

    cout << "]\n";

    return 0;
}
