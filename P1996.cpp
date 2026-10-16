#include <iostream>
using namespace std;

struct listnode
{
    int data;
    listnode *next = nullptr;
    listnode(int a):data(a){}
    listnode(int a,listnode* ptr):data(a),next(ptr){}
    bool empty(){return this->next == this;}
};

int main(){
    int n,m;
    cin >>n>>m;
    listnode *head = new listnode(-2);
    head->next = head;
    for (int i = n; i > 0; i--)
    {
        listnode *tmp = new listnode(i);
        tmp->next = head->next;
        head->next = tmp;
    }
    listnode *p = head->next, *pre = head;
    int i = 1;
    while (!head->empty())
    {
        if (i % m == 0)
        {
            cout <<p->data<<' ';
            pre->next = p->next;
            delete p;
            p = pre->next;
            i++;
            if (p == head)
                {
                    p = p->next;
                    pre = pre->next;
                }
            continue;
        }
        p = p->next;
        pre = pre->next;
        if (p == head)
        {
            p = p->next;
            pre = pre->next;
        }            
        i++;
    }
    system("pause");
}