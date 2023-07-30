#include <stdio.h>
//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//
//测试样例：
//1->2->2->1
//返回：true
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        ListNode* slow = A, * fast = A;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* n1 = NULL, * n2 = slow, * n3 = slow->next;
        while (n2)
        {
            n2->next = n1;

            n1 = n2;
            n2 = n3;
            if (n3)
                n3 = n3->next;
        }
        ListNode* cur = A;
        while (n1 && cur)
        {
            if (cur->val != n1->val)
            {
                return false;
            }
            cur = cur->next;
            n1 = n1->next;
        }
        return true;
    }
};

//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//
//输入：l1 = [1, 2, 4], l2 = [1, 3, 4]
//输出：[1, 1, 2, 3, 4, 4]

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* newhead = NULL, * tail = NULL;
    if (list1 == NULL)
        return newhead = list2;
    if (list2 == NULL)
        return newhead = list1;

    while (list1 && list2)
    {
        if (list1->val < list2->val)
        {
            if (newhead == NULL)
            {
                newhead = tail = list1;
            }
            else
            {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;
        }
        else
        {
            if (newhead == NULL)
            {
                newhead = tail = list2;
            }
            else
            {
                tail->next = list2;
                tail = tail->next;
            }
            list2 = list2->next;
        }
    }

    if (list1)
        tail->next = list1;
    if (list2)
        tail->next = list2;

    return newhead;
}

//输入一个链表，输出该链表中倒数第k个结点。
//输入：
//1, { 1,2,3,4,5 }
//返回值：
//{ 5 }

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    struct ListNode* Fast = pListHead, * Slow = pListHead;

    while (Fast)
    {
        Fast = Fast->next;
        if (k)
        {
            k--;
        }
        else
        {
            Slow = Slow->next;
        }
    }
    if (k == 0)
        return Slow;
    else
        return NULL;
}

//给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
    {
        return NULL;
    }
    else if (head->next == NULL)
    {
        return head;
    }
    else
    {
        struct ListNode* n1 = NULL;
        struct ListNode* n2 = head;
        struct ListNode* n3 = head->next;
        while (n3)
        {
            n2->next = n1;

            n1 = n2;
            n2 = n3;
            n3 = n3->next;
        }
        n2->next = n1;
        return n2;
    }

}
