#include <stdio.h>
#include <string.h>
int main(void)
{
	freopen("4-in", "r", stdin);
	int n;
	scanf("%d",&n);
	getchar();
	char buffer[1000] = {0};
	while(n--){
		fgets(buffer, 1000, stdin); // fgets will get '\n'
		int length = strlen(buffer);
		if(buffer[length - 1] == '\n')
			buffer[--length] = '\0';
		int space_count = 0 ;
		for (int i = 0; i < length; ++i)
		{
			if(buffer[i] == ' ')
				space_count++;
		}
		int index = space_count * 2 + length;

		if(index > 999)
			return  -1;

		for(int i = index, j = length; i >= 0; i--,j--){
			if(buffer[j] == ' '){
				buffer[i--] = '0'; 	
				buffer[i--] = '2';
				buffer[i] = '%';
			}else
				buffer[i] = buffer[j];
		}
		printf("%s\n", buffer);

	}
}