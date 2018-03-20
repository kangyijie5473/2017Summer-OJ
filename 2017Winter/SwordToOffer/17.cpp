#include <iostream>
#include <set>
#include <vector>
using namespace std;

struct Node
{
	Node(int v):val(v),next(NULL){}
	struct Node *next;
	int val;
};
Node *mergeList(Node *head1, Node *head2)
{
	Node *p = head1->val <= head2->val ? head1 : head2;
	Node *q = head1->val > head2->val ? head1 : head2;
	Node *result = p;
	while(p && p->next && q){
		if(p->val < q->val && p->next->val > q->val){
			Node *temp = q->next;
			q->next = p->next;
			p->next = q;
			p = p->next;
			q = temp;
		}else{
			p = p->next;
		}
	}
	if(!p->next)
		p->next = q;
	return result;

}
int main()
{
	Node n1[] = {3, 6};
	Node n2[] = {1, 4, 5}; 

	for(int i = 0; i < 1; i++){
		n1[i].next = &n1[i+1];
	}
	for(int i = 0; i < 2; i++){
		n2[i].next = &n2[i+1];
	}
	Node *m;

    m = mergeList(n1, n2);
	while(m){
		cout << m->val << " " << endl;;
		m = m->next;
	}
}