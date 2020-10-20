#include<stdio.h>
#include <ctype.h>
int main(){
	int total,count=1;
	int class_c,class_math,class_english,sum;
	int array_sum[1000],array_c[1000];
	int class_c2[1000],class_math2[1000],class_english2[1000];
	int position=1;	
	int max=0,max_c=0,count_max=0,max_id=0;
	int i,d;
	scanf("%d",&total);
	while(count<=total){
		scanf("%d %d %d",&class_c,&class_math,&class_english);
		class_c2[position]=class_c,class_math2[position]=class_math,class_english2[position]=class_english;
		sum=class_c+class_math+class_english;
		max=sum;
		array_sum[position]=sum;
		array_c[position]=class_c;
		count++;position++;
	}
	count--;position--;
//	for(i=1;i<=total;i++)
//		printf("sum:%d c:%d\n",array_sum[i],array_c[i]);
	int array_used[100]={0};  //storage id
	int check_array_position=1;
	for(i=1;i<=5;i++)
	{
		max=0,max_c=0,max_id=0;
		for(d=1;d<=total;d++){
			for(check_array_position=1;check_array_position<=5;check_array_position++){
				if(array_used[check_array_position]==d)
				goto Restart; 
			}
			if(max<array_sum[d]){
				max=array_sum[d];
				max_c=array_c[d];
				max_id=d;
			}
			if(max==array_sum[d]){
				if(max_c<array_c[d]) {
					max=array_sum[d];
					max_c=array_c[d];
					max_id=d;
				}
			} 
				 
			Restart:;
		}
		array_used[i]=max_id;
		printf("%d %d %d %d\n",max_id,class_c2[max_id],class_math2[max_id],class_english2[max_id]);
	}
}
