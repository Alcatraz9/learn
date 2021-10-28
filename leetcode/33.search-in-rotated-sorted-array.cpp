/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l, r;
        l = 0, r = nums.size() - 1;
        int p = 0;
        // find smallest element
        while (l < r)
        {
            int mid = (l + r) / 2;

            if (nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        // cout << p << " ";
        // searching in array
        p = l;
        l = 0, r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int realmid = (mid + p) % nums.size();

            if (nums[realmid] == target)
            {
                return realmid;
            }
            else if (nums[realmid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        return -1;
    }
};
// @lc code=end
