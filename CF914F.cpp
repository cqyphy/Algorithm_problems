#include <iostream>
#include <vector>
#include <string>
using namespace std;

void getnext(string t,vector<int> &next){
    int j = 0,k = -1;
    next.push_back(-1);
    while (j < t.size())
    {
        if (k == -1 || t[j] == t[k])
        {
            j++;
            k++;
            next.push_back(k);
        }
        else k = next[k];
    }
    
}

int KMPIndex(string s,string t){
    int i = 0,j = 0,count_ = 0;
    vector<int> next;
    getnext(t,next);
    while (i < s.size())
    {
        if (j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else j = next[j];
        if (j > 0 && j >= t.size())
        {
            count_ ++;
            j = next[j];
        }
        
    }
    return count_;
}

int main(){
    string target;
    int times;
    cin >> target>>times;
    for (int i = 0; i < times; i++)
    {
        int search_mode;
        cin >>search_mode;
        switch (search_mode)
        {
        case 1:
        {
            int i;
            char c;
            cin >>i>>c;
            target[i-1] = c;
            break;
        }   
        case 2:
        {
            int l,r;
            string y;
            cin >>l>>r>>y;
            string s = target.substr(l-1,r-l+1);
            cout << KMPIndex(s,y)<<endl;
            break;
        }    
        default:
            break;
        }
    }
    system("pause");
}