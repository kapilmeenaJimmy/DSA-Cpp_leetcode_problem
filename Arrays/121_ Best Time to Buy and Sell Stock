#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int maxProfit(const std::vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;

        for (int price : prices) {
            min_price = std::min(min_price, price);
            max_profit = std::max(max_profit, price - min_price);
        }

        return max_profit;
    }
};

int main() {
    Solution solver;

    std::vector<int> test1 = {7, 1, 5, 3, 6, 4};
    std::cout << "Example 1 Output: " << solver.maxProfit(test1) << " (Expected: 5)\n";

    std::vector<int> test2 = {7, 6, 4, 3, 1};
    std::cout << "Example 2 Output: " << solver.maxProfit(test2) << " (Expected: 0)\n";

    return 0;
}
