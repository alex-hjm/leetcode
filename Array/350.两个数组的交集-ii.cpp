/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include "Array.h"
// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size(), n2 = nums2.size();
        int p1 = 0, p2 = 0;
        vector<int> ans;
        while (p1 < n1 && p2 < n2) {
            if (nums1[p1] < nums2[p2]) {
                p1++;
            } else if (nums1[p1] > nums2[p2]) {
                p2++;
            } else {
                ans.push_back(nums1[p1]);
                p1++;
                p2++;
            }
        }
        return ans;
    }
};
// @lc code=end

//哈希表 - 存储每个数字出现的次数
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);
        unordered_map<int, int> map;
        for (int i : nums1) {
            ++map[i];
        }
        vector<int> ans;
        for (int i : nums2) {
            if (map.count(i)) {
                ans.push_back(i);
                --map[i];
                if (map[i] == 0)
                    map.erase(i);
            }
        }
        return ans;
    }
};

//排序 + 双指针
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n1 = nums1.size(), n2 = nums2.size();
        int p1 = 0, p2 = 0;
        vector<int> ans;
        while (p1 < n1 && p2 < n2) {
            if (nums1[p1] < nums2[p2]) {
                p1++;
            } else if (nums1[p1] > nums2[p2]) {
                p2++;
            } else {
                ans.push_back(nums1[p1]);
                p1++;
                p2++;
            }
        }
        return ans;
    }
};