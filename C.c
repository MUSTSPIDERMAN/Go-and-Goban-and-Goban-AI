#include<stdio.h>
#include <ctype.h>
///65-90 97-122
int main(){
	char get_char;
	int code;
	int array1[1000],count=0,count2=0;
	int check,check_count=0;
	//get_char=getchar();
	//code=get_char;
	//printf("%d",code);
	while(1){
		while(get_char=getchar()){
		if(get_char== '\n')
			break;
		code=get_char;
		if(code ==32)
			continue;
		if(code==35)
		{
			return 0;
		}
		array1[count]=code;
		count++;
	}
	while(count2<count){
		printf("%d ",array1[count2]);
		count2++;
	}
	
	
	}
	

	return 0;
}
