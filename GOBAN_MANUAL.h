// ÐÞÏþ³¿ 1809853D-I011-0045  D1   2019Äê4ÔÂ22ÈÕ

#include<stdio.h>
#define m 40
#define n 40

//extern int memory(int chessboard[m][n],int n11,int n22);
 //void show(int  chessboard[m][n],int n1,int n2);
//extern int check(int  chessboard[m][n],int n11,int n22);

	int i,j,k,num;
int chessboard[m][n];
int choice1,choice2;
char option;

 int size1,size2;
 
 
    
int GOBAN_MANUAL()
{
	printf("Enter two number and divide them by space (like 15 15)to choice the size of chessboard\n ,");
    scanf("%d %d",&size1,&size2);
      for(j=1;j<=size1;j++)
    {
        
        for(k=1;k<=size2;k++)
        {
            chessboard[j][k] =0;
        }
        
    }
    	while(getchar()!= '\n')
	     continue; 
   	printf("Do you want to start from the last time?\n enter y to continue \n");
    	option=getchar();
    	if(option == 'y')
    	{
    		FILE *fpRead=fopen("chessdata.txt","r");
	if(fpRead==NULL)
	{
		return 0;
	}
	
	
		for(j=1;j<=size1;j++)
    {
	   
		for(k=1;k<=size1;k++)
        {
            fscanf(fpRead,"%d ",chessboard[j][k]);
		}
	
    }
    fclose(fpRead);
    	}
    while(1)
    {
	    
    
    		
        show(chessboard,size1,size2);
		RESTART:
        printf("Black side please, divide them by space such as 3 3\n");
        scanf("%d %d", &choice1 , &choice2);
        if(choice1 <1 || choice1 > size1  || choice2 <1 || choice2 > size1)
        {
        	printf("The wrong range of numbers \n do it again\n");
        	goto RESTART;
        	
        }
        chessboard[choice1][choice2] = 2;
        
        show(chessboard,size1,size2);
        printf("White side please, divide them by space  such as 3 3\n");
        scanf("%d %d", &choice1 , &choice2);
        if(choice1 <1 || choice1 > 15  || choice2 <1 || choice2 > 15)
        {
        	printf("The wrong range of numbers \n do it again");
        	goto RESTART;
        	
        }
        chessboard[choice1][choice2] = 1; 
        check(chessboard,size1,size2);
       /*
       FILE *fpWrite=fopen("chessdata.txt","w");
	if(fpWrite==NULL)
	{
		return 0;
	}
	

	
		
	for(j=1;j<=15;j++)
    {
	   
		for(k=1;k<=15;k++)
        {
            num = chessboard[j][k];
         
            fprintf(fpWrite,"%d ",num);
    
		}
		fprintf(fpWrite,"\n"); 
    }
	fclose(fpWrite);
    */
    memory(chessboard,size1,size2);
    }
    
    
}
/*
void show(int  chessboard[m][n],int n11,int n22)
{
    int j,k;
    int size1=n11,size2=n22;
    int num;
    printf("   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15\n");
    for(j=1,size1;j<=size1;j++)
    {
        if(j < 10)
            printf("%d  ", j);
        else
            printf("%d ",j);
        for(k=1;k<=size2;k++)
        {
            num = chessboard[j][k];
            if(k<10)
                printf("%d  ",num);
            else
                printf("%d  ",num);
        }
        printf("\n");
    }
    
}


extern int memory(int chessboard[m][n],int n11,int n22)
{    int i,j,k,num;
    int size1=n11,size2=n22;
    FILE *fpWrite=fopen("chessdata","w");
    if(fpWrite==NULL)
    {
        return 0;
    }
    
    
    
    
    for(j=1;j<=size1;j++)
    {
        
        for(k=1;k<=size2;k++)
        {
            num = chessboard[j][k];
            
            fprintf(fpWrite,"%d ",num);
            
        }
        fprintf(fpWrite,"\n");
    }
    fclose(fpWrite);
    return 0;
    
}








extern extern int check(int  chessboard[m][n],int n11,int n22)
{
    int size1=n11,size2=n22;
    int m3,n3;
    int m1,n1;
    m1=n1=1;
    int num,num2;
    int count=0;
    
    for(m1=1;m1<=size1;m1++)
    {
        for(n1=1;n1<=size2;n1++)
        {
            num = chessboard[m1][n1];
            m3=m1,n3=n1,count=0;
            
            if(num== 0)
            {
                goto end;
            }
            //  while((n3<=15 && n3 >=1) && (m3 <=15 && m3 >= 1 ))
            
            while(chessboard[m3][n3] == num)
            {
                
                n3--;
                count++;
                if(count==5)
                {
                    printf("%d side win the Game, congratulation\n", num);
                    return 1;
                }
                // printf("\n******************* (%d,%d) num: %d, count :%d \n",m3,n3, num,count);
                
            }
            
            m3=m1,n3=n1,count=0;
            while(chessboard[m3][n3] == num)
            {
                
                n3--;
                m3--;
                count++;
                if(count==5)
                {
                    printf("%d side win the Game, congratulation\n", num);
                    return 1;
                }
                // printf("\n******************* (%d,%d) num: %d, count :%d \n",m3,n3, num,count);
                
            }
            
            m3=m1,n3=n1,count=0;
            while(chessboard[m3][n3] == num)
            {
                
                
                m3--;
                count++;
                if(count==5)
                {
                    printf("%d side win the Game, congratulation\n", num);
                    return 1;
                }
                //printf("\n******************* (%d,%d) num: %d, count :%d \n",m3,n3, num,count);
                
            }
            m3=m1,n3=n1,count=0;
            while(chessboard[m3][n3] == num)
            {
                
                n3++;
                m3--;
                count++;
                if(count==5)
                {
                    printf("%d side win the Game, congratulation\n", num);
                    return 1;
                }
                // printf("\n******************* (%d,%d) num: %d, count :%d \n",m3,n3, num,count);
                
            }
            
            m3=m1,n3=n1,count=0;
            while(chessboard[m3][n3] == num)
            {
                
                n3++;
                
                count++;
                if(count==5)
                {
                    printf("%d side win the Game, congratulation\n", num);
                    return 1;
                }
                //printf("\n******************* (%d,%d) num: %d, count :%d \n",m3,n3, num,count);
                
            }
            
            m3=m1,n3=n1,count=0;
            while(chessboard[m3][n3] == num)
            {
                
                n3++;
                m3++;
                count++;
                if(count==5)
                {
                    printf("%d side win the Game, congratulation\n", num);
                    return 1;
                }
                //  printf("\n******************* (%d,%d) num: %d, count :%d \n",m3,n3, num,count);
                
            }
            
            m3=m1,n3=n1,count=0;
            while(chessboard[m3][n3] == num)
            {
                m3++;
                count++;
                if(count==5)
                {
                    printf("%d side win the Game, congratulation\n", num);
                    return 1;
                }
                //  printf("\n******************* (%d,%d) num: %d, count :%d \n",m3,n3, num,count);
                
            }
            
            m3=m1,n3=n1,count=0;
            while(chessboard[m3][n3] == num)
            {
                n3--;
                m3++;
                count++;
                if(count==5)
                {
                    printf("%d side win the Game, congratulation\n", num);
                    return 1;
                }
                // printf("\n******************* (%d,%d) num: %d, count :%d \n",m3,n3, num,count);
                
            }
            
        end:;
        }
        
    }
    return 0;
}

*/


