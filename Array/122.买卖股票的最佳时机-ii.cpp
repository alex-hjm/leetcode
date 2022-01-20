/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include "Array.h"
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int today = 0, tomorrow = 1;
        int n = prices.size();
        int profit = 0;
        while (tomorrow < n) {
            if (prices[today] < prices[tomorrow])
                profit += prices[tomorrow] - prices[today];
            today++;
            tomorrow++;
        }
        return profit;
    }
};
// @lc code=end

//my pass
int maxProfit(vector<int>& prices) {
    int today = 0, tomorrow = 1;
    int n = prices.size();
    int profit = 0;
    while (tomorrow < n) {
        if (prices[today] < prices[tomorrow])
            profit += prices[tomorrow] - prices[today];
        today++;
        tomorrow++;
    }
    return profit;
}

//动态规划
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        //每天交易结束后手里有一支股票或者没有股票的状态
        int dp[n][2];
        //初始状态
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            //第 i 天交易完后手里没有股票的最大利润
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            //第 i 天交易完后手里持有一支股票的最大利润（i 从 0 开始）
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        //最后持有股票的收益一定低于不持有股票的收益  dp[n−1][0] > dp[n−1][1]
        return dp[n - 1][0];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp0 = 0, dp1 = -prices[0];
        for (int i = 1; i < n; ++i) {
            //每一天的状态只与前一天的状态有关
            int newDp0 = max(dp0, dp1 + prices[i]);
            int newDp1 = max(dp1, dp0 - prices[i]);
            //更新当天的状态
            dp0 = newDp0;
            dp1 = newDp1;
        }
        return dp0;
    }
};

//贪心 -只能用于计算最大利润，计算的过程并不是实际的交易过程。
class Solution {
public:
    int maxProfit(vector<int>& prices) {   
        int ans = 0;
        int n = prices.size();
        for (int i = 1; i < n; ++i) {
            //每次选择贡献大于 0 的区间
            ans += max(0, prices[i] - prices[i - 1]);
        }
        return ans;
    }
};