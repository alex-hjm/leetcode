/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include "Array.h"
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,right = numbers.size() - 1;
        while(left<=right) {
            int sum=numbers[left]+numbers[right];
            if(sum>target)
                right--;
            else if(sum<target)
                left++;
            else
                return {left+1,right+1}; 
        }
        return {};
    }
};
// @lc code=end

//my pass
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> map;
        vector<int> ans;
        for (int i = 0;i < numbers.size();i++) {
            auto result = map.find(target - numbers[i]);
            if (result != map.end()) {
                ans = { i + 1,result->second };
                sort(ans.begin(), ans.end());
                return ans;
            } else
                map[numbers[i]] = i + 1;
        }
        return {};
    }
};

//error
vector<int> twoSum(vector<int>& numbers, int target) {
    for (int i = 0;i < numbers.size();i++) {
        for (int j = i + 1;j < numbers.size();j++) {
            if (numbers[i] + numbers[j] == target)
                return { i + 1,j + 1 };
        }
    }
    return {};
}

//二分查找
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int right = numbers.size() - 1;
        for (int i = 0;i < numbers.size();i++) {
            int val = target - numbers[i];
            int left = i + 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] > val)
                    right = mid - 1;
                else if (numbers[mid] < val)
                    left = mid + 1;
                else
                    return { i + 1,mid + 1 };
            }
        }
        return {};
    }
};

//双指针
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0,right = numbers.size() - 1;
        while(left<=right) {
            int sum=numbers[left]+numbers[right];
            if(sum>target)
                right--;
            else if(sum<target)
                left++;
            else
                return {left+1,right+1}; 
        }
        return {};
    }
};