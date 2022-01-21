/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int  left = 0, right = 0;
        while (right < size) {
            if (nums[left] != nums[right]) {
                ++left;
                nums[left] = nums[right];
            }
            right++;
        }
        return left + 1;
    }
};
// @lc code=end

//my pass
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int  left = 0, right = 0;
        while (right < size) {
            if (nums[left] != nums[right]) {
                ++left;
                nums[left] = nums[right];
            }
            right++;
        }
        return left + 1;
    }
};

//双指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int fast = 1, slow = 1;
        while (fast < n) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};