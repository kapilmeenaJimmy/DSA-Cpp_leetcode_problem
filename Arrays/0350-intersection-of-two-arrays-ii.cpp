#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> frequency;
        vector<int> result;

for (int num : nums1) {
            frequency[num]++;
        }

for (int num : nums2) {
            if (frequency[num] > 0) {
                result.push_back(num);
                frequency[num]--;
            }
        }

return result;
    }
};
