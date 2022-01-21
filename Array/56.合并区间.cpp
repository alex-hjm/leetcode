/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include "Array.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)  return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>>  merged;
        for (int i = 0; i < intervals.size(); ++i) {
            //区间的左端点和右端点
            int L = intervals[i][0], R = intervals[i][1];
            //将第一个区间加入merged，比较当前区间得左端点和merged最后一区间的右端点
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({ L, R });//不会重合，直接将区间加入 merged 的末尾
            } else {
                merged.back()[1] = max(merged.back()[1], R);//重合，更新 merged 中最后一个区间的右端点
            }
        }
        return merged;
    }
};
// @lc code=end

