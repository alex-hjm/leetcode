/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
#include "Array.h"
// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1;i >= 0;i--) {
            if (digits[i] != 9) {
                digits[i]++;
                for (int j = i + 1;j < n;j++) {
                    digits[j] = 0;
                }
                return digits;
            }
        }
        // digits 中所有的元素均为 9
        vector<int> ans(n + 1);
        ans[0] = 1;
        return ans;
    }
};
// @lc code=end

//my pass
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        //int ans = 0;
        vector<int> ans;
        for (int i = n - 1;i >= 0;i--) {
            int num;
            if (i == n - 1)
                num = digits[i] + 1;
            else
                num = digits[i] + carry;
            carry = num / 10;
            ans.push_back(num % 10);
        }
        if (carry > 0) ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

//找出最长的后缀 9
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1;i >= 0;i--) {
            if (digits[i] != 9) {
                digits[i]++;
                for (int j = i + 1;j < n;j++) {
                    digits[j] = 0;
                }
                return digits;
            }
        }
        // digits 中所有的元素均为 9
        vector<int> ans(n + 1);
        ans[0] = 1;
        return ans;
    }
};