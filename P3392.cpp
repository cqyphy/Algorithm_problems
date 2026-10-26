#include <bits/stdc++.h>
using namespace std;

struct counts
{
    int r = 0,w = 0,b = 0;
    char maxcolor(int &recive_num){
        recive_num =  max(max(r,b),w);
        if (recive_num == r) return 'R';
        else if (recive_num == b) return 'B';
        else return 'W';
    }
};


int main(){
    int n,m;
    cin >>n>>m;
    vector<counts> v;
    for (int i = 0; i < n; i++)
    {
        counts tmp;
        char ch_tmp;
        for (int j = 0; j < m; j++)
        {
            cin>>ch_tmp;
            switch (ch_tmp)
            {
            case 'R':
                tmp.r ++;
                break;
            case 'W':
                tmp.w ++;
                break;
            case 'B':
                tmp.b ++;
                break;
            default:
                break;
            }
        }
        v.push_back(tmp);
    }
    char printmod = 'w';
    int result = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (i == 0) {result += m - v[i].w;continue;}
        if (i == v.size()-1) {result += m-v[i].r;continue;}
        switch (printmod)
        {
        case 'w':
        {
            int choosecolor = max(v[i].w,v[i].b);
            if (choosecolor == v[i].b && v[i].w != v[i].b){
                result += m-v[i].b;
                printmod = 'b';
            }
            else result += m - v[i].w;
            break;
        }
        case 'b':
        {
            int choosecolor = max(v[i].b,v[i].r);
            if (choosecolor == v[i].r && v[i].b != v[i].r){
                result += m-v[i].r;
                printmod = 'r';
            }
            else result += m - v[i].b;
            break;
        }
        case 'r':
            result += m-v[i].r;
            break;;
        default:
            break;
        }
    }
    cout << result;
}