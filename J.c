#include<stdio.h>
int mi(int num1,int num2){
	int i=2,n=num2;
	int k=1;
	if(num2==0)
		return 1;
	if(num2==1)
		return 2;
	for(k=1;k<num2;k++)
		i=i*2;
		
	return i; 
	
}
int test(int number){
	int i,count=0,count2=0,t;
	int array[1000],array2[1000];
	
	//scanf("%d",&i);
	i=number;
	while((i/10 != 0) ||(i%10!=0)) {
		array[count]=i%10;
		i=i/10; 
		count++;
	}
	
	for(t=0;t<count;t++){
	}
	count--;
	while(count2<=count){
		array2[count2]=array[count-count2];
	
		count2++;
	}
	count2--;
	i=0;
	int total=8,d,add_array[100];
	while(i<total-count2){
		add_array[i]=0;
		i++;
	}
	count=0;
	while(i<9){
		add_array[i]=array2[count];
		count++;
		i++;
	}
	
	int one=0,two=0,three=0,four=0;
	int final_array[10];
	final_array[1]=add_array[0];
	final_array[2]=add_array[1];
	final_array[3]=add_array[2];  
	final_array[4]=add_array[5];
	final_array[5]=add_array[8];
	final_array[6]=add_array[7];
	final_array[7]=add_array[6];
	final_array[8]=add_array[3];
	int lc=add_array[4];
	for(i=1;i<=8;i++){
	
		one =one +(lc!=final_array[i])*mi(2,8-i);
	}
	
	
	final_array[1]=add_array[6];
	final_array[2]=add_array[3];
	final_array[3]=add_array[0];
	final_array[4]=add_array[1];
	final_array[5]=add_array[2];
	final_array[6]=add_array[5];
	final_array[7]=add_array[8];
	final_array[8]=add_array[7];
    lc=add_array[4];
	for(i=1;i<=8;i++){
	
		two =two +(lc!=final_array[i])*mi(2,8-i);
	}
	
	final_array[1]=add_array[8];
	final_array[2]=add_array[7];
	final_array[3]=add_array[6];
	final_array[4]=add_array[3];
	final_array[5]=add_array[0];
	final_array[6]=add_array[1];
	final_array[7]=add_array[2];
	final_array[8]=add_array[5];
    lc=add_array[4];
	for(i=1;i<=8;i++){
	
		three =three +(lc!=final_array[i])*mi(2,8-i);
	}
	//180
	
	final_array[1]=add_array[2];
	final_array[2]=add_array[5];
	final_array[3]=add_array[8];
	final_array[4]=add_array[7];
	final_array[5]=add_array[6];
	final_array[6]=add_array[3];
	final_array[7]=add_array[0];
	final_array[8]=add_array[1];
    lc=add_array[4];
	for(i=1;i<=8;i++){
	
		four =four +(lc!=final_array[i])*mi(2,8-i);
	}
	
	int result=one;
	if(two<result)
		result=two;
	if(three<result)
		result=three;
	if(four<result)
		result=four;
	
	//printf("%d\n",result);
	
	
	return result;
} 
int main(){
	int i,k,num;
	scanf("%d",&i);
	int array[10];
	for(k=1;k<=i;k++){
		scanf("%d",&num);
		array[k]=num;
		//printf("\n%d\n",test());
	}
	for(k=1;k<=i;k++){
		
		printf("%d\n",test(array[k]));
	}
	return 0;
}
