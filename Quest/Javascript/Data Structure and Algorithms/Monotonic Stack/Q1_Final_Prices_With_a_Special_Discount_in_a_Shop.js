/*
    - Given an integer array prices
    - There is a discount. if you buy the ith item, then you will receive a discount equivalent 
      to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]
    - Return an array answer of price paid for each product
*/

// Method 1: Brute force [Time: O(N^2), Space: O(N)]
var finalPrices = function(prices) {
    const ans = [];
    for (let i = 0; i < prices.length; i++) {
        let price = prices[i];
        for (let j = i + 1; j < prices.length; j++) {
            if (prices[j] <= prices[i]) {
                price = prices[i] - prices[j];
                break;
            }
        }
        ans.push(price);
    }
    return ans;
};

// Method 1: Monotonic Stack [Time: O(N), Space: O(N)]
/*
    The solution is similar to find next smaller element
    Intuition:
        - loop through each element of prices
            - if current price is smaller than price of top of stack
                - pop stack and apply discount until price is larger than top of stack or stack is empty
            - push current index to stack
*/
var finalPrices = function(prices) {
    const ans = [...prices];
    const stack = [];
    for (let i = 0; i < prices.length; i++) {
        while (stack.length !== 0 && prices[i] <= prices[stack[stack.length - 1]]) {
            ans[stack.pop()] -= prices[i];
        }
        stack.push(i);
    }
    return ans;
};