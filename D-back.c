#include<stdio.h>
#include <ctype.h>
int main(){
	int array1[100],array2[100],array3[100];
	int total,count1=0,count2=0,count3=0,count_position=1,get_num;
	int i;
	scanf("%d",&total);
	while(getchar()!= '\n')
	     continue; 
	while(1){
		scanf("%d",&get_num);
		array1[count1]=get_num;
		count1++;count_position++;
		if(count_position>total)
			break;
			
		scanf("%d",&get_num);
		array2[count2]=get_num;
		count2++;count_position++;
		if(count_position>total)
			break;
			
		scanf("%d",&get_num);
		array3[count3]=get_num;
		count3++;count_position++;
		if(count_position>total)
			break;
		
	}
	for(i=0;i<count1;i++)
	{
		printf("%d",array1[i]);
		if(i+1>=count1){
			printf("\n");
			break;
		} 
		printf(" ");
	}
	for(i=0;i<count2;i++)
	{
		printf("%d",array2[i]);
		if(i+1>=count2){
			printf("\n");
			break;
		} 
		printf(" ");
	}
	for(i=0;i<count3;i++)
	{
		printf("%d",array3[i]);
		if(i+1>=count3){
			printf("\n");
			break;
		} 
		printf(" ");
	}
	
	return 0;
	
}
