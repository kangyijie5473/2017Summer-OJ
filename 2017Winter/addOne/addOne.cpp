#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
struct Node
{
	Node(int num, char *new_num):num_(num), new_num_(new_num){}
	char *new_num_;
	int num_;
};
char *itoa(int num){
	char *result = new char [50];
	int k = 0;
	while(num){
		int t = num % 10;
		num /= 10;
		result[k++] = t + '0';
	}
	result[k] = '\0';
	for(int i = 0, j = strlen(result) - 1; i != j && i < j; i++,j--){
		char temp = result[i];
		result[i] = result[j];
		result[j] = temp;
	}
	return result;
}
int main(void)
{
	freopen("in-addOne", "r", stdin);
	char str[50] = {0};
	char old_num[50] = {0};
	std::vector<Node> v;
	while(scanf("%s",str) != EOF){
		int i = 0;
		char *p = &str[1];
		while(*p != ']'){
			if(*p != ','){
				old_num[i++] = *p;
			}
			p++;
		}
		old_num[i] = '\0';
		int num = atoi(old_num);
		num++;
		char *t = itoa(num);
		v.push_back(Node(num, t));

	}

	std::sort(v.begin(),v.end(), [](const Node &a, const Node &b){return a.num_ > b.num_;});

	for(std::vector<Node>::iterator i = v.begin(); i != v.end(); i++){
		int length = strlen(i->new_num_);
		for(int j = 0; j < length; j++){
			if(j == 0)
				putchar('[');
			putchar(i->new_num_[j]);
			if(j == length - 1)
				putchar(']');
			else
				putchar(',');
		}
		putchar('\n');
	}
	
	for(std::vector<Node>::iterator i = v.begin(); i != v.end(); i++){
		delete i->new_num_;
	}
}