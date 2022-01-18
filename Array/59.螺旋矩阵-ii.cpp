/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include "Array.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        int left = 0, right = n - 1, top = 0, bottom = n - 1;

        vector<vector<int>> ans(n, vector<int>(n));
        while (num <= n * n) {
            //left to right
            for (int i = left; i <= right; i++) ans[top][i] = num++;
            top++;

            //top to bottom
            for (int i = top; i <= bottom; i++) ans[i][right] = num++;
            right--;

            //right to left
            for (int i = right; i >= left; i--) ans[bottom][i] = num++;
            bottom--;

            //bottom to top
            for (int i = bottom; i >= top; i--) ans[i][left] = num++;
            left++;
        }
        return ans;
    }
};
// @lc code=end


//模拟
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int num = 1;
        int left = 0, right = n - 1, top = 0, bottom = n - 1;

        vector<vector<int>> ans(n, vector<int>(n));
        while (num <= n * n) {
            //left to right
            for (int i = left; i <= right; i++) ans[top][i] = num++;
            top++;

            //top to bottom
            for (int i = top; i <= bottom; i++) ans[i][right] = num++;
            right--;

            //right to left
            for (int i = right; i >= left; i--) ans[bottom][i] = num++;
            bottom--;

            //bottom to top
            for (int i = bottom; i >= top; i--) ans[i][left] = num++;
            left++;
        }
        return ans;
    }
}