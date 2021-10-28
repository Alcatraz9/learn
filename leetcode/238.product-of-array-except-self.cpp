/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> res(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
        {
            res[i] = nums[i - 1] * res[i - 1];
        }

        int p = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            p *= nums[i + 1];
            res[i] *= p;
        }

        return res;
    }
};
// @lc code=end
