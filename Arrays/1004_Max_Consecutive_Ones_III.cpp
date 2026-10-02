#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int left = 0;
    int zeros = 0;
    int ans = 0;

    for (int right = 0; right < nums.size(); right++) {
        if (nums[right] == 0)
            zeros++;

        while (zeros > k) {
            if (nums[left] == 0)
                zeros--;

            left++;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    cout << longestOnes(nums, k) << endl;

    return 0;
}
