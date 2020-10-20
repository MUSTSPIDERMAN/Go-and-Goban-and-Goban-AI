#include<stdio.h>
int main(){
	int i,count=0,count2=0,t;
	int array[1000],array2[1000];
	scanf("%d",&i);
	while((i/10 != 0) ||(i%10!=0)) {
		array[count]=i%10;
		printf("i|/|10=%d  i|%|10=%d \n",i/10,i%10);
		i=i/10;
		printf("i:%d\n",i); 
		count++;
	}
	
	printf("last------------ i:%d\n",i); 
		printf("i|/|10=%d  i|%|10=%d \n",i/10,i%10);
	for(t=0;t<count;t++){
		printf("%d",array[t]);
	}
	count--;
	printf("\n");
	while(count2<=count){
		array2[count2]=array[count-count2];
		printf("count-count2:%d\n",count-count2);
		count2++;
	}
	count2--;
	printf("Done\n");
	for(count=0;count<=count2;count++){
		printf("%d",array2[count]);
	}
	return 0;
} 
