#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();

        int low = 0, high = m;

        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;

            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int right1 = cut1 == m ? INT_MAX : nums1[cut1];

            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int right2 = cut2 == n ? INT_MAX : nums2[cut2];

            if (left1 <= right2 && left2 <= right1) {
                if ((m + n) % 2 == 0) {
                    return (max(left1, left2) +
                            (long long)min(right1, right2)) / 2.0;
                }

                return max(left1, left2);
            }

            if (left1 > right2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};

int main() {
    Solution solution;

    vector<int> a1 = {1, 3};
    vector<int> b1 = {2};
    cout << solution.findMedianSortedArrays(a1, b1) << '\n';

    vector<int> a2 = {1, 2};
    vector<int> b2 = {3, 4};
    cout << solution.findMedianSortedArrays(a2, b2) << '\n';

    vector<int> a3 = {};
    vector<int> b3 = {1};
    cout << solution.findMedianSortedArrays(a3, b3) << '\n';

    vector<int> a4 = {0, 0};
    vector<int> b4 = {0, 0};
    cout << solution.findMedianSortedArrays(a4, b4) << '\n';

    return 0;
}
