#include <iostream>
#include <stdio.h>
#include <vector>
#define  MaxSize 100005
#define MaxTime 86400
using namespace std;

struct ship
{
    int t;
    vector<int> countries;
};

struct quene_
{
    ship data[MaxSize];
    int f = 0,r = 0;
    void push_back(ship tmp){data[r] = tmp;r++;}
    void pop_front(){
        data[f].t = -1;
        f++;
    }
};


int main(){
    int n;
    quene_ v;
    scanf("%d",&n);
    int x[MaxSize] = {0},count_ = 0;
    for (int i = 0; i < n; i++)
    {
        int k,t;
        ship tmp;
        scanf("%d %d",&t,&k);
        tmp.t = t;
        for (int j = 0; j < k; j++)
        {
            int a;
            scanf("%d",&a);
            tmp.countries.push_back(a);
            if (x[a] == 0)
            {
                count_++;
            }
            x[a]++;
        }
        v.push_back(std::move(tmp));
        while (v.data[v.r-1].t - v.data[v.f].t >= MaxTime)
        {
            for (int j = 0; j < v.data[v.f].countries.size(); j++)
            {
                int b = v.data[v.f].countries[j];
                x[b]--;
                if (x[b] == 0)
                {
                    count_--;
                }
                
            }            
            v.pop_front();
        }
        cout <<count_<<endl;
    }
    
}