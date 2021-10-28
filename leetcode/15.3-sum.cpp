/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        vector<vector<int>> res;

        if (nums.size() < 3)
            return res;

        sort(nums.begin(), nums.end());

        int l, r;

        for (int i = 0; i < nums.size() - 2; i++)
        {
            vector<int> triplet;
            l = i + 1;
            r = nums.size() - 1;
            while (l < r)
            {
                if (nums[i] + nums[l] + nums[r] == 0)
                {
                    triplet = {nums[i], nums[l], nums[r]};
                    res.push_back(triplet);

                    while (l < r && nums[l] == triplet[1])
                        l++;

                    while (l < r && nums[r] == triplet[2])
                        r--;
                }
                else if (nums[i] + nums[l] + nums[r] < 0)
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }

            while (i < nums.size() - 2 && nums[i] == nums[i + 1])
                i++;
        }

        return res;
    }
};
// @lc code=end
