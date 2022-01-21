/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
#include "Array.h"
// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
    }
};
// @lc code=end

//my pass
void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.size() == 0) return;
    vector<vector<int>> zeros;
    int m = matrix.size();
    int n = matrix.back().size();
    for (int i = 0; i < m;i++) {
        for (int j = 0;j < n;j++) {
            if (matrix[i][j] == 0)
                zeros.push_back({ i,j });
        }
    }

    for (int i = 0; i < zeros.size();i++) {
        for (int j = 0; j < m;j++) {
            matrix[j][zeros[i][1]] = 0;
        }
        for (int k = 0; k < n;k++) {
            matrix[zeros[i][0]][k] = 0;
        }
    }
}

//使用标记数组
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        //分别记录每一行和每一列是否有零出现
        vector<int> row(m), col(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!matrix[i][j]) {
                    row[i] = col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

//使用两个标记变量 - 用矩阵的第一行和第一列代替方法一中的两个标记数组
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // 分别记录第一行和第一列是否原本包含 0
        int flag_col0 = false, flag_row0 = false;
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                flag_col0 = true;
            }
        }
        for (int j = 0; j < n; j++) {
            if (!matrix[0][j]) {
                flag_row0 = true;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    // 更新第一行和第一列为 0
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                //使用第一行与第一列去更新其他行与列
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        //使用两个标记变量更新第一行与第一列
        if (flag_col0) {
            for (int i = 0; i < m; i++) {
                matrix[i][0] = 0;
            }
        }
        if (flag_row0) {
            for (int j = 0; j < n; j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

//使用一个标记变量 - 只使用一个标记变量记录第一列是否原本存在 0
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag_col0 = false;
        for (int i = 0; i < m; i++) {
            if (!matrix[i][0]) {
                flag_col0 = true;
            }
            for (int j = 1; j < n; j++) {
                if (!matrix[i][j]) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        //为了防止每一列的第一个元素被提前更新，需要倒序地处理
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 1; j < n; j++) {
                if (!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
            if (flag_col0) {
                matrix[i][0] = 0;
            }
        }
    }
};
