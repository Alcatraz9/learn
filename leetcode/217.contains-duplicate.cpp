/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> store;
        for (auto num : nums)
        {
            if (store.find(num) != store.end())
            {
                return true;
            }
            else
            {
                store.insert(num);
            }
        }
        return false;
    }
};
// @lc code=end
