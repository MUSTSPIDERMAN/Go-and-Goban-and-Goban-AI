#include<stdio.h>
int main(){
	int total,i,get;
	scanf("%d",&total);
	int array[10000];
	for(i=1;i<=total;i++){
		scanf("%d",&get);
		array[i]=get;
	}
	 int array_used[10000]={0};  //storage id
	
	 int total_energy=0,current,next;
	 int temp[1000]={0};
	for(i=1;i<=total-1;i++)
	{
	current=i;
	next=i+1;
	while(array_used[next]!=0){
		next=next+1;
	}
	temp[i]=array[current]+array[next];
	}
	
	printf("%d\n",total_energy);
	
}



