class Solution {
public:
    /**
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode * partition(ListNode * head, int x) {
        // write your code here
        if(head == NULL)
            return head;
        ListNode d1, d2;
        d1.next = NULL;
        d2.next = NULL;
        ListNode *p = &d1, *q = &d2, *t;
        while(head){
            t = head->next;

            if(head->val < x){
                head->next = p->next;
                p->next = head;
                head = t;
                p = p->next;
            }else{
                head->next = q->next;
                q->next = head;
                head = t;
                q = q->next;
            }
                
        }
        p->next = d2.next;
        return d1.next;
  
    }
};