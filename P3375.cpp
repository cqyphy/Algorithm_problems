#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s1,s2;
void getnext(string str,vector<int> &next){
    int j = 0,k = -1;
    next.push_back(-1);
    while (j < str.size())
    {
        if (k == -1 || str[j] == str[k])
        {
            j++;
            k++;
            next.push_back(k);
        }
        else k = next[k];
    }
    
}

void KMPindex(string s,string t,vector<int> &next,vector<int> &location){
    int i = 0, j = 0;
    getnext(t,next);
    while (i < s.size())
    {
        if (j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else j = next[j];
        if (j >= t.size() && j > 0)
        {
            location.push_back(i-j+1);
            j = next[j];
            continue;
        }
    }
    
}

int main(){
    cin >>s1>>s2;
    vector<int> next,location;
    KMPindex(s1,s2,next,location);
    if (!location.empty())
    {
        for (size_t i = 0; i < location.size(); i++)
        {
            cout << location[i] <<endl;
        }
    }
    for (size_t i = 1; i < next.size(); i++)
    {
        cout << next[i] <<' ';
    }
    system("pause");
}