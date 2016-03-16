class Solution {
public:
    bool isAnagram(string s, string t) {
    	if (s.size() != t.size())
		return false;
	vector<int> char_count(26, 0);
	for (int i = 0; i < s.size(); ++i) {
		++char_count[s[i] - 'a'];
		--char_count[t[i] - 'a'];
	}
	
	for (int i = 0; i < 26; ++i) {
		if (char_count[i] != 0)
			return false; 
	}
	return true;
    }
};
