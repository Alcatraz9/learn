/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l, r;
        l = 0;
        r = nums.size() - 1;
        if (r == 0)
            return nums[r];

        // no rotation
        if (nums[l] < nums[r])
            return nums[l];

        while (l < r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }

        return nums[l];
    }
};
// @lc code=end
