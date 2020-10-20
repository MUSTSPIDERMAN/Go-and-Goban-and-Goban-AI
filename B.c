#include<stdio.h>
#include <ctype.h>
int main(){
	int month[]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	int month2[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	char get_char,clear2;
	int year,m,d,total_day=0,start_year=2000,start_month=1;
	int week,day;
	while(scanf("%d %d %d",&year,&m,&d)==3)
	{
		total_day=0,start_year=2000,start_month=1;
		
			while(start_year<year){
		if(start_year%4==0)
		{
			total_day=total_day+366;
			
		}
		else if(start_year %4 !=0)
		{
			total_day=total_day+365;
		}
		start_year++; 
	}
	
	
		
	while(start_month<m){
			if(year%4==0)
	{
		total_day=total_day+ month[start_month];
		
	}
	else if(year%4!=0){
		total_day=total_day+ month2[start_month];
	
	}
		start_month++;	
	} 
	total_day=total_day+d; 

	week=(total_day/4)+1;
	if(total_day%4==0)
	{
	day=4;
	week=week-1;
	} 	
	else{
		day=total_day%4;
	}
	printf("%d %d\n",week,day);
	
	}

	return 0;
}
