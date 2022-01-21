/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include "Array.h"
// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int red = 0, white = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[red]);
                if (red < white)
                    swap(nums[i], nums[white]);
                red++;
                white++;
            } else if (nums[i] == 1) {
                swap(nums[i], nums[white++]);
            }
        }
    }
};
// @lc code=end

//my error
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int red = 0, blue = size - 1;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                int temp = nums[red];
                nums[red] = nums[i];
                nums[i] = temp;
                red++;
            } else if (nums[i] == 2) {
                int temp = nums[blue];
                nums[blue] = nums[i];
                nums[i] = temp;
                blue--;
            }
        }
    }
};

//单指针
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int head = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                // int temp = nums[head];
                // nums[head] = nums[i];
                // nums[i] = temp;
                swap(nums[i], nums[head]);
                head++;
            }
        }
        for (int i = head; i < size; i++) {
            if (nums[i] == 1) {
                // int temp = nums[head];
                // nums[head] = nums[i];
                // nums[i] = temp;
                swap(nums[i], nums[head]);
                head++;
            }
        }
    }
};

//双指针
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int size = nums.size();
        int red = 0, white = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                swap(nums[i], nums[red++]);
                if (red < white)
                    swap(nums[i], nums[white]);
                white++;
            } else if (nums[i] == 1) {
                swap(nums[i], nums[white++]);
            }
        }
    }
};