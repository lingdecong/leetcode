class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> s1, s2;
        int l1 = 0, l2 = 0;
        l1 = version1.length();
        l2 = version2.length();
        string::size_type pos1, pos2, ii = 0;
        
        while(ii < l1)
        {
            pos1 = version1.find(".", ii);
            if (pos1 != string::npos)
            {
                s1.push_back(atoi(version1.substr(ii, pos1 - ii).c_str()));
                ii = pos1 + 1;
                continue;
            }
            s1.push_back(atoi(version1.substr(ii, l1 - ii).c_str()));
            break;
        }
        
        ii = 0;
        while(ii < l2)
        {
            pos1 = version2.find(".", ii);
            if (pos1 != string::npos)
            {
                s2.push_back(atoi(version2.substr(ii, pos1 - ii).c_str()));
                ii = pos1 + 1;
                continue;
            }
            s2.push_back(atoi(version2.substr(ii, l2 - ii).c_str()));
            break;
        }
        
        int ret;
        for(ii = 0; ii < s1.size() && ii < s2.size(); ii++)
        {
            if (s1[ii] > s2[ii])
            {
                return 1;
            }
            else if (s1[ii] < s2[ii])
            {
                return -1;
            }
            else
            {
                continue;
            }
        }
        
        if ((s1.size() > s2.size()))
        {
            while (ii < s1.size())
            {
                if (s1[ii] > 0)
                {
                    return 1;
                    break;
                }
                ii++;
            }
        }    
        else if (s1.size() < s2.size())
        {
            while (ii < s2.size())
            {
                if (s2[ii] > 0)
                {
                    return -1;
                    break;
                }
                ii++;
            }
        }
        return 0;
        
    }
};
