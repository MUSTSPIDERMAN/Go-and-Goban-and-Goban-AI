#include<stdio.h>
int main(){
	int total,count1,count2=0,get;
	int array1[1000];
	scanf("%d",&total);
	while(getchar()!= '\n')
	     continue; 
	count1=total;
	while(count1>=0){
		count1--;
		if(count1<0)
			break;
		scanf("%d",&get);
		array1[count2]=get;
		printf("get:%d",get);
		count2++;
		
	}
	count1=0;
	printf("count2:%d",count2);
	count2--;
	printf("\n");
	while(count2>=0){
		printf("%d ",array1[count2]);
		count2--;
	}
	return 666;
}
