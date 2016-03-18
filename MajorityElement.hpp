
class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            if (nums.size() == 0)
                return 0;
            int me = nums[0];
            int count = 0;
            for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter) {
                if (me == *iter)
                    ++count;
                else {
                    --count;
                    if (count == 0) {
                        me = *iter;
                        count = 1;
                    }
                }
            }
            return me;
        }
};

