#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    mp[0] = 1;

    int sum = 0;
    int ans = 0;

    for (int num : nums) {
        sum += num;

        if (mp.count(sum - k))
            ans += mp[sum - k];

        mp[sum]++;
    }

    return ans;
}

int main() {
    vector<int> nums = {1, 1, 1};
    int k = 2;

    cout << subarraySum(nums, k) << endl;

    return 0;
}
