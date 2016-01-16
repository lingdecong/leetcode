class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int count = 0;
		int max_length = 0;
		int begin = 0;
		int end = 0;
		map<char, int> m;
		for (int ii = 0; ii < s.length(); ++ii) {
			if (m.find(s[ii]) == m.end()) {
				++count;
				m[s[ii]] = ii;
			} else {
				if (count > max_length)
					max_length = count;
				end = m[s[ii]];
				for (int jj = begin; jj < end; ++jj) {
					m.erase(s[jj]);
				}
				begin = end + 1;
				count = ii - end;
				m[s[ii]] = ii;
			}
		}
		if (count > max_length)
			max_length = count;
		return max_length;
	}
};