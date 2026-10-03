#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = -1;

    int sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        int rem = sum % k;

        if (mp.count(rem)) {
            if (i - mp[rem] >= 2)
                return true;
        } else {
            mp[rem] = i;
        }
    }

    return false;
}

int main() {
    vector<int> nums = {23, 2, 4, 6, 7};
    int k = 6;

    cout << checkSubarraySum(nums, k) << endl;

    return 0;
}
