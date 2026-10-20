#include <vector>
#include <stack>
#include <iostream>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int count_ = 0, maxstr = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(') st.push(i);
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                count_ = i - st.top();
                maxstr = maxstr < count_? count_:maxstr;
            }
        }
        maxstr = maxstr < count_? count_:maxstr;
        return maxstr;
    }
};

int main(){
    string s;
    cin>>s;
    Solution a;
    cout <<a.longestValidParentheses(s);
    system("pause");
}