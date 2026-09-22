#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        for (size_t i = 1; i < prices.size(); ++i) {
            if (prices[i] > prices[i - 1]) {
                max_profit += prices[i] - prices[i - 1];
            }
        }
        return max_profit;
    }
};

int main() {
    Solution solver;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << solver.maxProfit(prices) << endl; // Output: 7
    return 0;
}
