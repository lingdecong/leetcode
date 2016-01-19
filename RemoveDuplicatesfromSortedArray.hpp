class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int len = nums.size();
		if (len <= 1)
			return len;
		int current = nums[0];
		int count = 1;
		int pos = 0;
		for (int i = 1; i < len; ++i) {
			if (current != nums[i]) {
				current = nums[i];
				swap(nums[++pos], nums[i]);
				++count;
			}
		}
		return count;
	}
};