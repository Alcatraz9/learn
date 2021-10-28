/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int res = nums[0];

        for (int i = 1, maxP = res, minP = res; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                swap(maxP, minP);

            maxP = max(nums[i], maxP * nums[i]);
            minP = min(nums[i], minP * nums[i]);

            res = max(maxP, res);
        }

        return res;
    }
};
// @lc code=end
