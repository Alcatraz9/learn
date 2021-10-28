/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int res = -INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            sum = max(nums[i], sum + nums[i]);
            res = max(sum, res);
        }
        return res;
    }
};
// @lc code=end
