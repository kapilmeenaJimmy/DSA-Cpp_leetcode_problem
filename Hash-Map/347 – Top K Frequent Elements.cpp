#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }

        // Step 2: Store pairs as (frequency, element)
        vector<pair<int, int>> freqList;
        for (auto& entry : countMap) {
            freqList.push_back({entry.second, entry.first});
        }

        // Step 3: Sort descending by frequency
        sort(freqList.rbegin(), freqList.rend());

        // Step 4: Extract top k numbers
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(freqList[i].second);
        }

        return result;
    }
};

int main() {
    Solution solver;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    vector<int> ans = solver.topKFrequent(nums, k);

    // Print output to verify in VS Code terminal
    cout << "Top " << k << " frequent: ";
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
