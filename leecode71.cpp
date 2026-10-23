#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string simplifyPath(string path) {
        istringstream ss(path);
        vector<string> names;
        string s;
        while (getline(ss,s,'/'))
        {
            if (!s.empty())
                names.push_back(s);
        }
        deque<string> dq;
        for (int i = 0;i < names.size();i++)
        {
            if (names[i] == "..")
            {
                if (dq.empty()) continue;
                dq.pop_back();
            }
            else if (names[i] == ".") continue;
            else dq.push_back(names[i]);
        }
        auto it = dq.begin();
        string result;
        while (it != dq.end())
        {
            result += "/"+(*it);
            it ++;
        }
        if (dq.empty()) result += "/";
        return result;
    }
};