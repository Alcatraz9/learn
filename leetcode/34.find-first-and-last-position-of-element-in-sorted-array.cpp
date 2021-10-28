/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> res;
        int res1, res2;
        res1 = res2 = -1;
        int l = 0, r = nums.size() - 1;

        //      last
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
            {
                if (mid + 1 < nums.size() && nums[mid + 1] == target)
                {
                    l = mid + 1;
                }
                else
                {
                    res2 = mid;
                    break;
                }
            }

            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        //      first
        l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target)
            {
                if (mid - 1 >= 0 && nums[mid - 1] == target)
                {
                    r = mid - 1;
                }
                else
                {
                    res1 = mid;
                    break;
                }
            }

            else if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        res.push_back(res1);
        res.push_back(res2);
        return res;
    }
};
// @lc code=end
