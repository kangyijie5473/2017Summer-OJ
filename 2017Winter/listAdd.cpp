#include <stdio.h>
typedef struct Node
{
	struct Node *next;
	int val;
}node;
node *reverse(node *head)
{
	node dummy;
	dummy.next = NULL;
	node *p = &dummy;
	node *q = head;
	while(head){
		q = head->next;
		head->next = p->next;
		p->next = head;
		head = q;
	}
	head = p->next;
	return head;
}
node *func(node *head)
{
	node *slow,*fast;
	slow = fast = head;
	while(fast->next != NULL && fast->next->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	node *temp = fast->next;
	fast = slow->next;
	slow->next = NULL;
	head = reverse(head);
	node *p = head;
	if(temp == NULL)
		slow = head->next;
	while(slow){
		slow->val += fast->val;
		slow = slow->next;
		fast = fast->next;
	}
	return head;
}
int main()
{
	node h1,h2,h3,h4,h5;
	h1.val = 1;
	h1.next = &h2;
	h2.val = 2;
	h2.next = &h3;
	h3.val = 3;
	h3.next = &h4;
	h4.val = 4;
	h4.next = &h5;
	h5.val = 5;
	h5.next = NULL;
	node *p = func(&h1);
	while(p){
		printf("%d\n", p->val);
		p = p->next;
	}

}