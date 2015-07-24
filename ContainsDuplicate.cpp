class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
         map<int, int> mp;
            for (int ii = 0; ii < nums.size(); ++ii)
            {
                if (mp.find(nums[ii]) == mp.end())
                {
                    mp[nums[ii]] = ii;
                } else {
                    return true;
                }
            }
            return false;
    }
};
