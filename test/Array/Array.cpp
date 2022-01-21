#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
using namespace std;

int removeElement(vector<int>& nums, int val) {
    int size = nums.size();
    for (int i = 0;i < size;i++) {
        if (nums[i] == val) {
            for (int j = i + 1;j < size;j++) {
                nums[j - 1] = nums[j];
            }
            i--;
            size--;
        }
    }
    return size;
}

int removeElement2(vector<int>& nums, int val) {
    int slow = 0;
    for (int fast = 0;fast < nums.size();fast++) {
        if (val != nums[fast]) {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}

int removeElement3(vector<int>& nums, int val) {
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

vector<int> sortedSquares(vector<int>& nums) {
    int left = 0, right = nums.size();
    vector<int> ans;
    ans.resize(nums.size());
    int index = right - 1;
    while (left < right) {
        int a = nums[left] * nums[left];
        int b = nums[right - 1] * nums[right - 1];
        if (a < b) {
            ans[index] = b;
            right--;
        } else {
            ans[index] = a;
            left++;
        }
        index--;
    }
    return ans;
}

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int sum = 0;
    int ans = INT_MAX;
    for (int left = 0, right = 0;right < n;) {
        if (left == right) {
            sum += nums[left];
            right++;
        } else {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
    }
    return ans == INT_MAX ? 0 : ans;
}

int minSubArrayLen2(int s, vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    }
    int ans = INT_MAX;
    vector<int> sums(n + 1, 0);
    // 为了方便计算，令 size = n + 1 
    // sums[0] = 0 意味着前 0 个元素的前缀和为 0
    // sums[1] = A[0] 前 1 个元素的前缀和为 A[0]
    // 以此类推
    for (int i = 1; i <= n; i++) {
        sums[i] = sums[i - 1] + nums[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        int target = s + sums[i - 1];
        auto bound = lower_bound(sums.begin(), sums.end(), target);//二分查找大于等于target的第一个位置
        if (bound != sums.end()) {
            ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
        }
    }
    return ans == INT_MAX ? 0 : ans;
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> ans;
    unordered_map<int, int> map;


    return ans;
}

int maxProfit(vector<int>& prices) {
    int today = 0, tomorrow = 1;
    int n = prices.size();
    int profit = 0;
    while (tomorrow < n) {
        if (prices[today] < prices[tomorrow])
            profit += prices[tomorrow] - prices[today];
        today++;
        tomorrow++;
    }
    return profit;
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    int count = __gcd(k, n);
    for (int start = 0; start < count; ++start) {
        int current = start;
        int prev = nums[start];
        do {
            int next = (current + k) % n;
            swap(nums[next], prev);
            current = next;
        } while (start != current);
    }
}

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    int carry = 0;
    //int ans = 0;
    vector<int> ans;
    for (int i = n - 1;i >= 0;i--) {
        int num;
        if (i == n - 1)
            num = digits[i] + 1;
        else
            num = digits[i] + carry;
        carry = num / 10;
        ans.push_back(num % 10);
        //ans += ans * 10 + num % 10;
    }
    if (carry > 0) ans.push_back(carry);
    reverse(ans.begin(), ans.end());
    return ans;
}

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

int findMiddleIndex(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    int left_sum = nums[left], right_sum = nums[right];
    while (left != right && left != right) {
        if (left_sum < right_sum) {
            left_sum += nums[left++];
        } else {
            right_sum += nums[right--];
        }

    }
    return left_sum;
}

int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + ((right - left) / 2);
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return left;
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.size() == 0)  return {};
    sort(intervals.begin(), intervals.end());
    vector<vector<int>>  merged;
    for (int i = 0; i < intervals.size(); ++i) {
        //区间的左端点和右端点
        int L = intervals[i][0], R = intervals[i][1];
        //将第一个区间加入merged，比较当前区间得左端点和merged最后一区间的右端点
        if (!merged.size() || merged.back()[1] < L) {
            merged.push_back({ L, R });//不会重合，直接将区间加入 merged 的末尾
        } else {
            merged.back()[1] = max(merged.back()[1], R);//重合，更新 merged 中最后一个区间的右端点
        }
    }
    return merged;
}

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2;i++) {
        for (int j = 0; j < n;j++) {
            swap(matrix[i][j], matrix[n - i - 1][j]);
        }
    }
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n;j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

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

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size();
    if (m < 0) return {};
    int n = mat.front().size();
    vector<int> ans;
    for (int i = 0;i < m;i++) {
        for (int j = 0; j < n; j++) {
            int sum = i + j;
            int x = i, y = j;
            if (sum % 2) { //奇数数
                while (x <= sum)
                    ans.push_back(mat[x++][sum - x]);
            } else {
                while (x >= 0)
                    ans.push_back(mat[x--][sum - x]);

            }
        }
    }
    return ans;
}

vector<int> findDiagonalOrder2(vector<vector<int>>& matrix) {
    vector<int> nums;
    int m = matrix.size();
    int n = matrix[0].size();

    int i = 0;	// i 是 x + y 的和
    while (i < m + n) {
        // 第 1 3 5 ... 趟
        int x1 = (i < m) ? i : m - 1;	// 确定 x y 的初始值
        int y1 = i - x1;
        while (x1 >= 0 && y1 < n) {
            nums.push_back(matrix[x1][y1]);
            x1--;
            y1++;
        }
        i++;

        if (i >= m + n) break;
        // 第 2 4 6 ... 趟
        int y2 = (i < n) ? i : n - 1;	// 确定 x y 的初始值
        int x2 = i - y2;
        while (y2 >= 0 && x2 < m) {
            nums.push_back(matrix[x2][y2]);
            x2++;
            y2--;
        }
        i++;
    }
    return nums;
}

void moveZeroes(vector<int>& nums) {
    int size = nums.size();
    int right = size - 1;
    for (int i = 0;i < right + 1;i++) {
        while (nums[i] == 0) {
            for (int j = i + 1;j < right + 1;j++) {
                nums[j - 1] = nums[j];
            }
            nums[right--] = 0;
        }
    }
}

int removeDuplicates(vector<int>& nums) {
    int size = nums.size();
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

int main() {
    //vector<int> nums = { 0,1,2,2,3,0,4,2 };
    //int size = removeElement3(nums, 2);

    //vector<int> nums = { -7,-3,2,3,11 };
    //vector<int> ans = sortedSquares(nums);

    //vector<int> prices = { 7,1,5,3,6,4 };
    //int profit = maxProfit(prices);

    // vector<int> nums = { 1,2,3,4,5,6 };
    // rotate(nums, 2);

    // vector<int> nums = { 8,9,9 };
    // vector<int> ans = plusOne(nums);

    // vector<int> nums1 = { 1,2,3 };
    // vector<int> nums2 = { 2,3,4 };
    // double val = findMedianSortedArrays(nums1, nums2);

    //vector<int> nums = { 1,3,5,6 };
    //searchInsert(nums, 2);

    // vector<vector<int>>intervals = { {1,2,3},{4,5,6},{7,8,9} };
    // vector<int> ans = findDiagonalOrder2(intervals);

    vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
    return removeDuplicates2(nums);

    // for (int i = 0;i < ans.size();i++) {
    //     cout << ans[i] << " ";
    // }
}