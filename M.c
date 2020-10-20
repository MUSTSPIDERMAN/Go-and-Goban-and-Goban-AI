#include<stdio.h>
#include<math.h>
int check_num(int * array,int length){
	int i,number=0;
	int k=0;
	for(i=0;i<=10000;i++){
		for(k=1;k<=length;k++){
			if(array[k]==i)
			{
				number++;
				break; 
			}
		}
	} 
	return number;
}
int main(){
	int number[100000];
	int sum[100000];
	int num1,num2;int i;
	int sum_position=1,number_position=1;
	while(1){
		scanf("%d",&num1);
		if(num1==-1)
			break;
		number[number_position]=num1;
		scanf("%d",&num2);
		if(num2==-1)
			break;
		number_position++;
		number[number_position]=num2;
		sum[sum_position]=num1+num2;
		sum_position++;
		number_position++;
	}
	sum_position--;
	number_position--;
	int x=1,y=1;
	int number2[100000];
	int sum2[100000];
	while(y<=sum_position){
		num1=number[x];
		num2=number[x+1];
		number2[x]=num1;
		number2[x+1]=num2;
		sum2[y]=num1+num2;
		if(check_num(number2,x+1)==check_num(sum2,y))
		{
			printf("%d\n", sum_position-y);
			break;
		}
		x=x+2;
		y++;
		
	}
	
	
	//	if(check_num(number,number_position)==check_num(sum,sum_position))
	//	{
	//		printf("%d\n", );
	//		break;
	//	}
		
	
	return 0;
}







