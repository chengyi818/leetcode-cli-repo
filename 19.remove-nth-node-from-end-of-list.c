/*
 * [19] Remove Nth Node From End of List
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (28.17%)
 * Total Accepted:    3.3K
 * Total Submissions: 11.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, remove the n-th node from the end of list and return
 * its head.
 *
 * Example:
 *
 *
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, the linked list becomes
 * 1->2->3->5.
 *
 *
 * Note:
 *
 * Given n will always be valid.
 *
 * Follow up:
 *
 * Could you do this in one pass?
 *
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    typedef struct ListNode* Node;
    Node tmp = head;
    Node removeNode;
    int i = 0;

    // 申请循环数组,将指针循环保存到数组中
    Node* store = (Node*)malloc(sizeof(Node) * (n+1));
    memset(store, 0, sizeof(Node) * (n+1));
    printf("malloc store finished ");
    while(tmp) {
        store[i%(n+1)] = tmp;
        printf(" %d: %p   ", i, tmp);
        tmp = tmp->next;
        i++;
    }

    printf("save store finished ");

    tmp = store[i%(n+1)];
    printf("tmp: %p", tmp);
    if(tmp) {
        // 不是删头节点
        if(tmp->next) {
            // 不是删尾节点
            tmp->next = tmp->next->next;
            free(store[(i+1)%(n+1)]);
            return head;
        } else {
            // 删尾节点
            free(store[(i+1)%(n+1)]);
            tmp->next = NULL;
            return head;
        }
    } else {
        // 删头节点
        tmp = head;
        head = head->next;
        free(tmp);
        return head;
    }
}
