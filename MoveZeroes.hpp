class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	if (nums.size() == 0) {
		return;
	}
	int j = 0;
	while (nums[j]) {
		++j;
	}   
	int len = nums.size();
	for (int i = j + 1; i < len; ++i) {
		if (nums[i] != 0 && i > j) {
			swap(nums[i],nums[j++]);
			while(nums[j] != 0 && j < len)
				++j;
		} else {
			continue;
		}
	}
    }
};

