#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

int main(){
    vector<map<int,long>> v;
    int n,q,j,k;
    scanf("%d %d",&n,&q);
    v.resize(n+1);
    for (size_t i = 0; i < q; i++)
    {
        int f;
        scanf("%d",&f);
        switch (f)
        {
        case 1:
        {   
            long val;
            scanf("%d %d %ld",&j,&k,&val);
            v[j][k] = val;
            break;
        }
        case 2:
        {
            scanf("%d %d",&j,&k);
            long tmp = v[j][k];
            printf("%ld\n",tmp);
            break;
        }
        default:
            break;
        }
    }
    
}