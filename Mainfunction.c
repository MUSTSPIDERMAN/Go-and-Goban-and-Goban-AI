// ÐÞÏþ³¿ 1809853D-I011-0045  D1   2019Äê4ÔÂ22ÈÕ

#include<stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctype.h>

#include "AI_GOBAN.h"
#include "GOBAN_MANUAL.h"
#include "GO_MANUAL.h"

int main(int argc,const char * argv[] ){
	int choice;
	if(argc >= 2 ){
		if(argv[1]=1)
		   GO_MANUAL();
		if(argv[1]=2)
		    GOBAN_MANUAL();
		if(argv[1]=3)
		    GOBAN_AI();
	}
	printf("chooes which one you want to play\n");
	printf("Enter 1 for GO_MANUAL,  2 for GOBAN_MANUAL, 3 for AIGOBAN\n ");
	scanf("%d",&choice);
	switch (choice)
	{
		case 1: GO_MANUAL();
		    break;
	    case 2: GOBAN_MANUAL();
		    break;
		case 3: GOBAN_AI();
		    break;
	 } 
	 
	 return 0;
}
