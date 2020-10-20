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
	 int check_array_position=1,d,min_id=0,current_min=0,current_min2=0,min_id2=0;
	 int total_energy=0;
	for(i=1;i<=total-1;i++)
	{
		min_id=0,current_min=0,current_min2=0,min_id2=0;
		for(d=1;d<=total;d++){
			for(check_array_position=1;check_array_position<=total;check_array_position++){
				if(array_used[check_array_position]==d)
				goto Restart; 
			}
			if(current_min<array[d])
			{ 
				current_min=array[d];
				min_id=d;
			}
			 
			Restart:;
		}
		array_used[i]=min_id;
		
		
		for(d=1;d<=total;d++){
			for(check_array_position=1;check_array_position<=total;check_array_position++){
				if(array_used[check_array_position]==d)
				goto Restart2; 
			}
			if(current_min2<array[d])
			{
				current_min2=array[d];
				min_id2=d;
			}
			 
			Restart2:;
		}
		//array_used[i]=min_id2;
		
		total_energy=total_energy+current_min*current_min2;
		array[min_id2]=current_min+current_min2;
		
	
	}
	
	printf("%d\n",total_energy);
	
}






	
