#include<stdio.h>
#include <ctype.h>
int main(){
	long int distribute_array[10000],work_array[10000],sum_array[10000];
	long int dist,work;
	long int total,count;
	scanf("%ld",&total);
	for(count=1;count<=total;count++){
		scanf("%ld %ld",&dist,&work);
		distribute_array[count]=dist;
		work_array[count]=work;
		sum_array[count]=work+dist;
	}

	long int array_used[10000]={0};  //storage id
	long int check_array_position=1,i,d,max_id=0,current_max=0;
	
	for(i=1;i<=total;i++)
	{
		max_id=0,current_max=0;
		for(d=1;d<=total;d++){
			for(check_array_position=1;check_array_position<=total;check_array_position++){
				if(array_used[check_array_position]==d)
				goto Restart; 
			}
			if(current_max<sum_array[d])
			{
				current_max=sum_array[d];
				max_id=d;
			}
			 
			Restart:;
		}
		array_used[i]=max_id;
	
	}
	
	
	long int max_time=sum_array[array_used[1]];
	long int dist_total=distribute_array[array_used[1]];
	long int current_time=0;
	if(total==1){
		printf("Project %ld: %ld\n",1,max_time);
		return 0;
	}
	for(i=2;i<=total;i++){
		if(max_time<dist_total +sum_array[array_used[i]])
		{
			max_time=dist_total +sum_array[array_used[i]];
		}
		dist_total=dist_total+distribute_array[i];
	}
	
	printf("Project %ld: %ld\n",total,max_time);
	
	
	/*
	int i,d,dist_total=0,total_time=0;

	int array_time[1000];
	for(i=1;i<=total;i++)
	{
		dist_total=0;
		for(d=1;d<=i;d++){ 
			dist_total=dist_total+distribute_array[d];
		//	printf("dist_total:%d\n",dist_total);
		}
		total_time=dist_total+	work_array[i];
		array_time[i]=total_time;
	//	printf("%d %d\n",distribute_array[i],work_array[i]);
	}
	int final=0,id=0;
	for(d=1;d<=total;d++){
			if(final<array_time[d])
			{
			//	printf("array_time:%d\n",array_time[d]);
				id=d;
				final=array_time[d];
			}
		}
		*/
//	printf("Project %d: %d\n",total,final); 
	
	
	return 0;
}
