class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        map<int, int> mp;
       for (int i = 0; i < numbers.size(); i++) {
           mp[numbers[i]] = i;
       }

       int idx1, idx2;
       for (int i = 0; i < numbers.size(); i++) {
            auto idx = mp.find(target - numbers[i]);
            if (idx != mp.end() && idx->second != i) {
                idx1 = min(i, idx->second);
                idx2 = max(i, idx->second);
                break;
            }
       }
       return vector<int>({idx1 + 1, idx2 + 1});
    }
};
