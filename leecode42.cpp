//最经典的接雨水题
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int count_ = 0;
        for (int i = 0;i < height.size();i++)
        {
            while (!st.empty() && height[i] > height[st.top()]){
                int middle = st.top();
                st.pop();
                if (st.empty()) break;
                int left = st.top();
                int max_height = min(height[i],height[left]);
                count_ += (max_height-height[middle]) * (i-left-1);
            }
            st.push(i);
        }
        return count_;
    }
};

int main(){
    vector<int> h = {5,2,1,2,1,5};
    Solution s;
    cout << s.trap(h);
    system("pause");
}