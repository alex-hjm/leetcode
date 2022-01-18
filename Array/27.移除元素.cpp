/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include "Array.h"
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for (int fast = 0;fast < nums.size();fast++) {
            if (val != nums[fast]) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};
// @lc code=end

//暴力解法
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        for (int i = 0;i < size;i++) {
            if (nums[i] == val) {// 发现需要移除的元素，就将数组集体向前移动一位
                for (int j = i + 1;j < size;j++) {
                    nums[j - 1] = nums[j];
                }
                i--;// 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
                size--;// 此时数组的大小-1
            }
        }
        return size;
    }
}

//双指针
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left  = 0;
        for (int right  = 0;right  < nums.size();right ++) {
            if (val != nums[right ]) {
                nums[left++] = nums[right ];
            }
        }
        return left;
    }
}

//双指针优化
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = nums.size();
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                right--;
            } else {
                left++;
            }
        }
        return left;
    }
};