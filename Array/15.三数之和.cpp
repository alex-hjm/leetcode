/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include "Array.h"
// @lc code=start
class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int start, int end, int target, int value) {
        vector<vector<int>> ans;
        while (start < end) { //双指针法
            int sum = nums[start] + nums[end];
            if (sum == target) {
                ans.push_back({ value,nums[start],nums[end] });
                while (start < end && nums[start] == nums[start + 1]) { //跳过重复值
                    start++;
                }
                start++;
                while (start < end && nums[end] == nums[end - 1]) {
                    end--;
                }
                end--;
            } else if (sum < target) { //两数之和太小，左指针右移
                start++;
            } else {//两数之和太大，右指针左移
                end--;
            }
        }
        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) { //跳过重复值
                continue;
            }
            auto res = twoSum(nums, i + 1, size - 1, -nums[i], nums[i]);
            ans.insert(ans.end(), res.begin(), res.end());
        }
        return ans;
    }
};
// @lc code=end

//排序 + 双指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({ nums[first], nums[second], nums[third] });
                }
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        if (size < 3)   return {};          // 特判
        vector<vector<int> >res;            // 保存结果（所有不重复的三元组）
        sort(nums.begin(), nums.end());     // 排序（默认递增）
        for (int i = 0; i < size; i++)      // 固定第一个数，转化为求两数之和
        {
            if (nums[i] > 0)    return res; // 第一个数大于 0，后面都是递增正数，不可能相加为零了
            // 去重：如果此数已经选取过，跳过
            if (i > 0 && nums[i] == nums[i - 1])  continue;
            // 双指针在nums[i]后面的区间中寻找和为0-nums[i]的另外两个数
            int left = i + 1;
            int right = size - 1;
            while (left < right) {
                if (nums[left] + nums[right] > -nums[i])
                    right--;    // 两数之和太大，右指针左移
                else if (nums[left] + nums[right] < -nums[i])
                    left++;     // 两数之和太小，左指针右移
                else {
                    // 找到一个和为零的三元组，添加到结果中，左右指针内缩，继续寻找
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    // 去重：第二个数和第三个数也不重复选取
                    // 例如：[-4,1,1,1,2,3,3,3], i=0, left=1, right=5
                    while (left < right && nums[left] == nums[left - 1])  left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
        return res;
    }
};