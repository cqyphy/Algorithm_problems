#include <vector>
#include <iostream>
using namespace std;
struct stack_handmake{
    vector<char> data;
    void push(char &e){data.push_back(e);}
    void pop(){
        if (!data.empty()) data.pop_back();
    }
    bool gettop(char &e){
        if (!data.empty()){
            e = data[data.size()-1];
            return true;
        }
        else return false;
    }
    bool empty(){return data.empty();}
};
class Solution {
public:
    bool isValid(string s) {
        stack_handmake v;
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                v.push(s[i]);
            }
            else
            {
                char tmp;
                if (!v.gettop(tmp)) return false;
                if (tmp != s[i]-1 && tmp != s[i]-2)
                {
                    return false;
                }
                v.pop();
            }
        }
        if (!v.empty()) return false;
        return true;
    }
};

int main(){
    string s;
    cin>>s;
    Solution a;
    if (a.isValid(s))
    {
        cout <<"true";
    }
    else cout <<"false";
}