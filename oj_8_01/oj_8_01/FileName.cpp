#include <stdio.h>
//
//����һ�������ͷ�ڵ� head ���ж��������Ƿ��л���
//
//�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����ע�⣺pos ����Ϊ�������д��� ��������Ϊ�˱�ʶ�����ʵ�������
//
//��������д��ڻ� ���򷵻� true �� ���򣬷��� false ��
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


//leedcoed 160. �ཻ����
//���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣����������������ཻ�ڵ㣬���� null ��
//
//ͼʾ���������ڽڵ� c1 ��ʼ�ཻ��

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


//����һ�����ͷָ�� ListNode* pHead����һ��ֵx����дһ�δ��뽫����С��x�Ľ������������֮ǰ��
//�Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣
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