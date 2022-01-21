/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for (auto num : nums)
            if (len < 2 || nums[len - 2] != num)
                nums[len++] = num;
        return len;
    }
};
// @lc code=end

//双指针
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int slow = 2, fast = 2;
        while (fast < n) {
            if (nums[slow - 2] != nums[fast]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};

//通用解法
class Solution {
public:
    int work(vector<int>& nums, int k) {
        int len = 0;
        for (auto num : nums)
            if (len < k || nums[len - k] != num)
                nums[len++] = num;
        return len;
    }

    int removeDuplicates2(vector<int>& nums) {
        return work(nums, 2);
    }
}