#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	struct node *next;
	int element;
}Node;
const int node_size = sizeof(Node);
void printList(Node *head)
{
	while(head){
		printf("%d\n", head->element);
		head = head->next;
	}
}
void freeList(Node *head){
	Node *temp;
	while(head){
		temp = head;
		head = head->next;
		free(temp);
	}
}
int deleteNode(Node **curr, int key)
{
	while(*curr){
		Node *entry = *curr;
		if(entry->element == key){
			*curr = entry->next;
			free(entry);
		}else
			curr = &entry->next;
	}
}
int main(void)
{
	Node *head = (Node *)calloc(1, node_size);
	Node *new;
	int n;
	scanf("%d",&n);
	while(n--){
		new = (Node *)calloc(1, node_size);
		scanf("%d",&new->element);
		new->next = head->next;
		head->next = new;
	}
	//printList(head);
	deleteNode(&head->next,3); // just for simulate No-head-node list
	printList(head);
	freeList(head);
}