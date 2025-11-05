#include <iostream>
#include <vector>
using namespace std;

/*
    - Return the maximum profit you can achieve from this transaction.
        - If you cannot achieve any profit, return 0.

    Time: O(N), Space: O(1)
*/

/*
    Intuition:
    - this uses Kadane's Algorithm
        - if prices at that day is smaller than the best buy time -> set that to the best buy time
            - this ensure that every future sell would produce a larger profit than keeping the old buy time [a - 1 > a - 2 no matter value of a]
        - update maxProfit each day
*/

int maxProfit(vector<int>& prices) {
    int bestBuy = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++) {
        // try selling on this day, if profit is negative => buy on this day
        if (prices[i] - bestBuy < 0) {
            bestBuy = prices[i];
        } else {
            // see how much profit would be made and update maxProfit
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        }
    }

    return maxProfit;
}