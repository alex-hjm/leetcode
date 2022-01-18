/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */
#include "Array.h"
// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) / 2);
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
            else return mid;
        }
        return -1;
    }
};
// @lc code=end

//my
int search(vector<int>& nums, int target) {
    for (int i = 0;i < nums.size();i++) {
        if (nums[i] == target)
            return i;
    }
    return -1;
}

//二分查找
//版本一：左闭右闭区间
int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;// 定义target在左闭右闭的区间里，[left, right]
    while (left <= right) {
        int mid = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
        if (nums[mid] < target)
            left = mid + 1;// target 在右区间，所以[middle + 1, right]
        else if (nums[mid] > target)
            right = mid - 1;// target 在左区间，所以[left, mid - 1]
        else return mid;// nums[middle] == target
    }
    return -1;
}
//版本二：左闭右开区间
int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();// 定义target在左闭右开的区间里，即：[left, right)
    while (left < right) { //因为left == right的时候，在[left, right)是无效的空间，所以使用 <
        int mid = left + ((right - left) >> 1);
        if (nums[mid] < target)
            left = mid + 1;// target 在右区间，在[middle + 1, right)中
        else if (nums[mid] > target)
            right = mid ;// target 在左区间，在[left, middle)中
        else return mid;// nums[middle] == target
    }
    return -1;
}