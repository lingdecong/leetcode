class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;
        for (int ii = 0; ii < nums.size(); ++ii)
        {
            if (mp.find(nums[ii]) == mp.end())
            {
                mp[nums[ii]] = ii;
            } else {
                if (ii - mp[nums[ii]] <= k)
                {
                    return true;
                } else {
                  mp[nums[ii]] = ii;
                }
            }
        }
        return false;
    }
};
