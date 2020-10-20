#include<stdio.h>
#include <ctype.h>
int main(){
	long long int array[20000]={0};
	long long int i,x,d,u,position;
	scanf("%lld",&i);
	for(x=1;x<=i;x++){
		scanf("%lld",&d);
		u=array[d];
		u++;
		array[d]=u;
	}
	u=array[0];
	position=0;
	for(x=1;x<=i;x++){
		if(u<array[x]){
			position=x;
			u=array[x];
		}
	}
	printf("%lld",position);
	return 0;
}
