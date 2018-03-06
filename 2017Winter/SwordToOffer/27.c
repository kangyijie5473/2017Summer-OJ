#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node *key;
typedef struct Node{
    char data;
    struct Node *leftChild;
    struct Node *rightChild;
}node;
node *mykey;

typedef struct  StackNode{
	node treeNode;
	struct  StackNode *next;
}stackNode;

char *ch;
int count;
stackNode *top;
stackNode head;

int judgeEmpty(void){
	if(top == NULL){
		return -1;
	}else {
		return 1;
	}
}
void push(node *p)
{
    stackNode *q;
    q = (stackNode *)malloc(sizeof(stackNode));
    memcpy(&(q->treeNode), p, sizeof(node));
    head.next = q;
    q->next = top;
    top = head.next;
    
}

node* pop(void)
{
    node *t;
    t = (node *)malloc(sizeof(top->treeNode));
    node *temp = &(top->treeNode);
    memcpy(t, temp, sizeof(top->treeNode));
    top = top->next;
    head.next = top;
    return t;
    
}

void funMidPrint(node *root)
{
    node *p = root;
    top = NULL;
    int i;
    while(p != NULL || (i = judgeEmpty()) != -1){
        while(p != NULL){
            push(p);
            p = p->leftChild;
        }
        if((i = judgeEmpty()) != -1){
            p = pop();
            printf("%c",p->data);
            p = p->rightChild;
        }
    }
}

void prePrint(node *root)
{
	if(root == NULL)
		return;
	printf("%c", root->data);
	prePrint(root->leftChild);
	prePrint(root->rightChild);
}
void freeTree(node *root)
{
    if(root == NULL)
        return;
    printf("%c\n", root->data);
    freeTree(root->leftChild);
    freeTree(root->rightChild);
    if(root == mykey)
        return ;
    free(root);
    printf("free ok\n");
}
void midPrint(node *root)
{
	if(root == NULL)
		return;
	midPrint(root->leftChild);
	printf("%c", root->data);
	midPrint(root->rightChild);
}

void lastPrint(node *root)
{
	if(root == NULL)
		return;
	lastPrint(root->leftChild);
	lastPrint(root->rightChild);
	printf("%c", root->data);
}

node *createTree(node *root)
{
    if(*ch == '#'){
        ch++;
        root = NULL;
        return root;
    }else{
    	if(count++){
        	root = (node *)malloc(sizeof(node));
    	}
        root->data = *(ch++);
        root->leftChild = createTree(root->leftChild);
        root->rightChild = createTree(root->rightChild);
        return root;
        
    }
}

void printTree(node *root,int h)
{
	int i ;
    if(root == NULL){
        return ;
    }
    printTree(root->rightChild, h+1);
    for(i = 1; i <= h; i++){
        printf("   ");
    }
    printf("%c\n",root->data);
    printTree(root->leftChild,h+1);
}
node *anotherCreatTree(node *root, char a[], char b[], int len)
{
    if(len <= 0){
        return root = NULL;
    }else{
        char *temp = NULL;
        int k = 0;
        root = (node *)malloc(sizeof(node));
        root->data = *a;
        for(temp = b; *temp != *a; temp++){
            k++;
        }
        root->leftChild = anotherCreatTree(root->leftChild, a+1, b, k);
        root->rightChild = anotherCreatTree(root->rightChild, a+1+k, temp+1, len-1-k);
        return root;
    }

}
int countEdgeZero;
int countEdgeOne;
int countEdgeTwo;
int T;
char outChar[100];

void countEdge(node *root)
{
    if(root == NULL)
        return;
    //printf("%c", root->data);
    if(root->leftChild && root->rightChild)
        countEdgeTwo++;
    else if(root->leftChild == NULL && root->rightChild == NULL)
        countEdgeZero++,outChar[T++] = root->data;
    else
        countEdgeOne++;
    countEdge(root->leftChild);
    countEdge(root->rightChild);
}
void changeChildren(node *root)
{
    if(root == NULL)
        return;
    changeChildren(root->leftChild);
    changeChildren(root->rightChild);
    if(root->rightChild && root->leftChild){
        node * temp = root->leftChild;
        root->leftChild = root->rightChild;
        root->rightChild = temp;
        return;
    }else if(root->rightChild == NULL && root->leftChild == NULL)
        return;
    if(root->leftChild)
        root->rightChild = root->leftChild,root->leftChild = NULL;
    else
        root->leftChild = root->rightChild,root->rightChild  = NULL;
}



void convert(node *root, node **last_node)
{
	if(!root)
		return ;
	convert(root->leftChild, last_node);
	root->leftChild = *last_node;
	if(*last_node)
		(*last_node)->rightChild = root;
	*last_node = root;
	convert(root->rightChild, last_node);
}
node *changeToList(node *root)
{
	node *last_node = NULL;
	convert(root, &last_node);
	while(root && root->leftChild)
		root = root->leftChild;
	return root;
}
int main(void)
{
    node root;
    node *Root;
    
    char a[20];
    scanf("%s",a); // put in pre list
    ch = &a[0];

    mykey = &root;
    createTree(&root); // creat tree

    midPrint(&root); // mid traversal print
    printf("\n");
    node *list_head = changeToList(&root);
    while(list_head){
    	printf("%c \n", list_head->data);
    	list_head = list_head->rightChild;
    }
  
}