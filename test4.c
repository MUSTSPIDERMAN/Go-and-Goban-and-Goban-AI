#include<stdio.h>
int main(){
	int month[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	int month2[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int num1,num2;
	scanf("%d %d",&num1,&num2);
	if(num1%4==0)
	{
		printf("%d\n",month[num2]);
	}
	else{
		printf("%d\n",month2[num2]);
	}
	return 0;
}

