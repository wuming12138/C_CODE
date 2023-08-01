#include <stdio.h>
//
//给你一个链表的头节点 head ，判断链表中是否有环。
//
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
//
//如果链表中存在环 ，则返回 true 。 否则，返回 false 。
struct ListNode {
    int val;
    struct ListNode* next;
    
};

bool hasCycle(struct ListNode* head) {
    struct ListNode* slow = head, * fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
    return false;
}


//leedcoed 160. 相交链表
//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
//
//图示两个链表在节点 c1 开始相交：

struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* curA = headA, * curB = headB;
    int cntA = 1, cntB = 1;
    while (curA->next)
    {
        curA = curA->next;
        cntA++;
    }
    while (curB->next)
    {
        curB = curB->next;
        cntB++;
    }
    if (curA != curB)
        return NULL;
    int div = abs(cntA - cntB);
    struct ListNode* longhead = headA, * shorthead = headB;
    if (cntA < cntB)
    {
        longhead = headB;
        shorthead = headA;
    }
    while (div--)
    {
        longhead = longhead->next;
    }
    while (longhead != shorthead)
    {
        longhead = longhead->next;
        shorthead = shorthead->next;
    }
    return longhead;
}


//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余结点之前，
//且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        // write code here
        ListNode* lList = (ListNode*)malloc(sizeof(ListNode));
        ListNode* gList = (ListNode*)malloc(sizeof(ListNode));
        ListNode* cur = pHead;
        ListNode* ltail = lList, * gtail = gList;
        while (cur)
        {
            if (cur->val < x)
            {
                ltail->next = cur;
                ltail = ltail->next;
            }
            else
            {
                gtail->next = cur;
                gtail = gtail->next;
            }
            cur = cur->next;
        }
        gtail->next = NULL;
        ltail->next = gList->next;
        pHead = lList->next;

        free(lList);
        free(gList);
        return pHead;
    }
};