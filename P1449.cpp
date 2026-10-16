#include <iostream>
#include <string>
#include <sstream>
using namespace std;
#define Maxsize 60

struct stack
{
    long data[Maxsize];
    int i = 0;
    void push(long &e){
        if (i < Maxsize)
        {
            data[i] = e;
            i++;            
        }        
    }
    void pop(long &e){
        if (i >= 1){
            e = data[i-1];
            i--;
        }
    }
    void gettop(long &e){
        e = data[i-1];
    }
};

int main(){
    stack v;
    string s;
    cin >>s;
    int i = 0;
    for (i; s[i] != '@'; i++)
    {
        string subs;
        while (s[i] >= 48 && s[i] <= 57)
        {
            subs += s[i++];
        }
        if (s[i] == '.')
        {
            long tmp = stol(subs);
            v.push(tmp);
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            long a,b,sum;
            v.pop(a);
            v.pop(b);
            switch (s[i])
            {
            case '+':
                sum = b+a;
                break;
            case '-':
                sum = b-a;
                break;
            case '*':
                sum = b*a;
                break;
            case '/':
                sum = b/a;
                break;
            default:
                break;
            }
            v.push(sum);
        }
        
    }
    if (s[i] == '@')
    {
        long tmp;
        v.gettop(tmp);
        cout << tmp;
    }
    
}