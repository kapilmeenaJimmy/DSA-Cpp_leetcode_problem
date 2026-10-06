#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1;
    int right = *max_element(piles.begin(), piles.end());

    while (left < right) {
        int mid = left + (right - left) / 2;

        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + mid - 1) / mid;
        }

        if (hours <= h)
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    cout << minEatingSpeed(piles, h) << endl;

    return 0;
}
