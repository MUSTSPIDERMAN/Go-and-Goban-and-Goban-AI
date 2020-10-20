#include<stdio.h>
int grid(n){
	if (n == 1)
        return 1;
    else if (n ==2)
        return 2;
    else
        return grid(n-1)+grid(n-2);
}
    


int main(){
	int i;
	while(scanf("%d",&i)==1)
	{
		printf("%d\n",grid(i));
	}
	
	return 0;
}
