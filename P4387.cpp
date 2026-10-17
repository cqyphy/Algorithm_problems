#include <stdio.h>
#include <vector>
using namespace std;
#define Maxsize 100002
struct stack
{
    //int data[Maxsize];
    vector<int> data;
    int i = 0;
    void push(int &e){
        if (i < Maxsize)
        {
            data.push_back(e);
            i++;
        }
    }
    void pop(){
        if (i > 0)
        {
            data.pop_back();
            i--;
        }
        
    }
    bool gettop(int &e){
        if (i == 0)
        {
            return false;
        }
        e = data[i-1];
        return true;
    }
};

bool judge(vector<int> &in,vector<int> &out){
    stack s;
    auto in_it = in.begin(),out_it = out.begin();
    while (out_it != out.end())
    {
        int top;
        if (s.gettop(top))
        {
            if (top == *out_it) {
                s.pop();
                out_it++;
                continue;
            }
            if (in_it == in.end()) return false;
            s.push(*in_it);
            in_it++;
        }
        else {
            s.push(*in_it);
            in_it++;
        }
    }
    return true;
}

int main(){
    int q;
    scanf("%d",&q);
    for (int i = 0; i < q; i++)
    {
        int n;
        scanf("%d",&n);
        vector<int> in,out;
        for (int j = 0; j < n; j++)
        {
            int tmp;
            scanf("%d",&tmp);
            in.push_back(tmp);
        }
        for (int j = 0; j < n; j++)
        {
            int tmp;
             scanf("%d",&tmp);
            out.push_back(tmp);
        }
        if (judge(in,out))
        {
            printf("Yes\n");
        }
        else printf("No\n");
    }
}