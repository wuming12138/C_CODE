#include <stdio.h>
#include <stdlib.h>
struct Node {
    int val;
    struct Node* next;
    struct Node* random;  
};
struct Node* ListBuyNode(int x)
{
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    if (newnode == NULL)
    {
        perror("malloc error");
        exit(-1);
    }
    newnode->val = x;
    newnode->next = NULL;
    newnode->random = NULL;
    return newnode;
}

struct Node* copyRandomList(struct Node* head) {
    struct Node* cur = head;
    struct Node* newhead = NULL, * newcur = NULL;

    while (cur)
    {
        struct Node* newnode = ListBuyNode(cur->val);

        if (newhead == NULL)
        {
            newhead = newcur = newnode;
        }
        else
        {
            newcur->next = newnode;
            newcur = newcur->next;
        }

        cur = cur->next;
    }
    cur = head;
    newcur = newhead;
    while (cur)
    {
        struct Node* tail = head;
        struct Node* newtail = newhead;
        int cnt = 0;
        while (tail != cur->random)
        {
            cnt++;
            tail = tail->next;
        }

        while (cnt--)
        {
            newtail = newtail->next;
        }
        newcur->random = newtail;

        newcur = newcur->next;
        cur = cur->next;
    }
    return newhead;
}


int main()
{
    struct Node* n1 = ListBuyNode(1);
    struct Node* n2 = ListBuyNode(2);
    struct Node* n3 = ListBuyNode(3);
    struct Node* n4 = ListBuyNode(4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;

    n1->random = n3;
    n2->random = n1;
    n3->random = NULL;
    n4->random = n2;
    
    struct Node* newhead = copyRandomList(n1);



}