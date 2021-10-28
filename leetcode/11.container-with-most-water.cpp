/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxA = 0;

        int l, r;

        l = 0;
        r = height.size() - 1;

        while (l < r)
        {
            int ar;

            if (height[l] <= height[r])
            {
                ar = height[l] * (r - l);
                l++;
            }
            else
            {
                ar = height[r] * (r - l);
                r--;
            }

            maxA = max(maxA, ar);
        }

        return maxA;
    }
};
// @lc code=end
