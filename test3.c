#include<stdio.h>

int main(){
	int num1,num2;
	int count,sum=0;
	scanf("%d %d",&num1, &num2);
	if(num1<num2){
		count=num1;
		while(count<=num2)
		{
			sum=sum+count;
			count++;
		}
		printf("%d",sum);
		return 0;
	}
	else if (num1>num2){
		count=num2;
		while(count<=num1)
		{
			sum=sum+count;
			count++;
		}
		printf("%d",sum);
		return 0;
	
	}
	else if(num1=num2){
		printf("%d",sum=num1+num2);
		return 0;
	}
	
}
