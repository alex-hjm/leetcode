#include <vector>
#include <unordered_map>
using namespace std;
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

//note: 哈希表

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash_map;
        for(int i=0;i<nums.size();++i)
        {
            auto result=hash_map.find(target-nums[i]);
            if(result!=hash_map.end())
                return {i,result->second};
            hash_map[nums[i]]=i; 
        }
        return {};
    }
};
// @lc code=end

//my 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++)
        {
            vector<int>::const_iterator result=find(nums.begin(),nums.end(),(target-nums[i]));
            if((result!=(nums.begin()+i))&&(result!=nums.end()))
                return {i,(int)(result-nums.begin())};
        }
        return vector<int>();
    }
};

//方法一：暴力枚举
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};

//方法二：哈希表
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash_map;
        for(int i=0;i<nums.size();++i)
        {
            auto result=hash_map.find(target-nums[i]);
            if(result!=hash_map.end())
                return {i,result->second};
            hash_map[nums[i]]=i; 
        }
        return {};
    }
};