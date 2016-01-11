class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        const char *str = s.c_str();
        int ii;
        map<char, int> cm;
        cm.insert(make_pair('(', 1));
        cm.insert(make_pair('[', 2));
        cm.insert(make_pair('{', 3));
        cm.insert(make_pair(')', -1));
        cm.insert(make_pair(']', -2));
        cm.insert(make_pair('}', -3));

        vector<char> vec;
        char temp, pop;
        for (ii = 0; ii < len; ++ii) {
            temp = s.at(ii);
            if (temp== '(' || temp == '[' || temp == '{') {
                vec.push_back(s.at(ii));
                continue;
            }

            if (temp == ')' || temp == ']' || temp == '}') {
                if (vec.size() == 0)
                    return false;
                pop = vec[vec.size() -1];
                if (cm[pop] + cm[temp] == 0) {
                    vec.pop_back();
                    continue;
                }
                else
                    return false;
            }
        }
        if (vec.size() != 0)
            return false;
        return true;
    }
};
