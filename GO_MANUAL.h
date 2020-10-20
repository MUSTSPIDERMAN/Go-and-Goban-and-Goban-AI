// ÐÞÏþ³¿ 1809853D-I011-0045  D1   2019Äê4ÔÂ22ÈÕ

#include<stdio.h>
#include <string.h>

#define m 40
#define n 40
// ºÚÆå 2£¬°×Æå1£»ºÚÆï´úÌæ 4£¬°×Æå´úÌæ3£»°×Æå×Ó±»³Ô5£¬ºÚÆå×Ó±»³Ô6£»
 
void show_go(int  chessboard_go[m][n],int m11,int n11);

int checkqi(int  chessboard_go[m][n], int m4,int n4,int m11,int n11);
//int checkqi2(int chessboard_go[20][20],int num1,int num2);
void recover(int  chessboard_go[m][n],int m11,int n11);
int remove2(int  chessboard_go[m][n],int m11,int n11);
//int check_go(int  chessboard_go[m][n],struct measures measuree,int m11,int n11);


struct measures measure;
void count( struct measures measure,int m11,int n11 );

int i,j,k,num;

int chessboard_go[m][n];
int choice1,choice2;
char option;
int black,white;

struct measures 
{
   int black;
   int white;
   
};
int size1,size2;

int GO_MANUAL()
{    printf("Enter two number and divide them by space (like 15 15)to choice the size of chessboard\n ,");
	 scanf("%d %d", &size1 , &size2);
	
    while(1)
    {
    	
    	
        show_go(chessboard_go,size1,size2);
		RESTART:
        printf("Black side please, divide them by space\n");
        scanf("%d %d", &choice1 , &choice2);
        if(choice1 <1 || choice1 > size1  || choice2 <1 || choice2 > size2)
        {
        	printf("The wrong range of numbers \n do it again\n");
        	goto RESTART;
        	
        }
        if(chessboard_go[choice1][choice2] != 0)
		{printf("There's already has a chess or it has no qi\n");
		goto RESTART;
		 } 
        chessboard_go[choice1][choice2] = 2;
        remove2(chessboard_go,size1,size2);
        
        
        
        
        RESTART2:;
        show_go(chessboard_go,size1,size2);
        printf("White side please, divide them by space\n");
        scanf("%d %d", &choice1 , &choice2);
        if(choice1 <1 || choice1 > size1  || choice2 <1 || choice2 > size2)
        {
        	printf("The wrong range of numbers \n do it again");
        	goto RESTART;
        	
        }
        if(chessboard_go[choice1][choice2] != 0)
		{printf("There's already has a chess or it has no qi\n");
		goto RESTART2;
		 }
        chessboard_go[choice1][choice2] = 1; 
        show_go(chessboard_go,size1,size2);
        
		remove2(chessboard_go,size1,size2);
		count( measure ,size1,size2);
		if(check_go(chessboard_go,measure,size1,size2)==1)
		   return 0;
    }
    
    return 0;
}

 void show_go(int  chessboard_go[m][n],int m11,int n11)
{ 
    int j,k;
    int size1=m11,size2=n11;
    int num;
    printf("   1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19\n");
    for(j=1;j<=size1;j++)
    {
	    if(j < 10)
		    printf("%d  ", j);
        else
            printf("%d ",j);
		for(k=1;k<=size1;k++)
        {
            num = chessboard_go[j][k];
            if(num==6 || num==5)
                num=0;
          
            if(k<10)
                printf("%d  ",num);
            else
                printf("%d  ",num);
		}
         printf("\n");
    }
    
}





int checkqi(int  chessboard_go[m][n], int m4,int n4,int m11,int n11)
{
    int size1=m11,size2=n11;
	int num2,mark,mark2;
	int k1,k2,k3,k4;
	if(m4 <1 || m4 > size1  || n4 <1 || n4 > size2)
                return 0;
                
     num2= chessboard_go[m4][n4];
	  
     if(num2==0)
     {k1=n4-1,k2=m4-1,k3=n4+1,k4=m4+1;
     
     	if(k1<1||k1>size1  || k2<1||k2>size2 || k3<1||k3>size1 || k4<1||k4>size2)
                return 0;
     	if( chessboard_go[m4][k1]==chessboard_go[k2][n4] ==chessboard_go[m4][k3]==chessboard_go[k4][n4] )
     	{
     		if(chessboard_go[k4][n4]==1)
     		     chessboard_go[m4][n4]=6;
     		else if(chessboard_go[k4][n4]==2)
     		      chessboard_go[m4][n4]=5;
     	}
     }
	 if(num2==5 || num2==6)
	 	     return 1;
	 	     
     if(num2 == 1)
	  {
          chessboard_go[m4][n4]=3;
          mark=3,mark2=6;
      }
     else if(num2 ==2) 
	 {
	 chessboard_go[m4][n4]=4;
	 mark=4,mark2=5;
     }
     
	printf(" num2:%d    m4: %d   n4:%d\n",num2,m4,n4);
    int m3,n3,m5,n5; 
    int num;   
            m3=m4,n3=n4;
            n3--;
            m5=m4,n5=n4;
            n5=n5-2;
            
           if((chessboard_go[m3][n3]==0&&(m3>=1&&m3<=size1&&n4>=1&&n4<=size2))  || (chessboard_go[m5][n5]==num2 && chessboard_go[m3][n3]==mark)||(chessboard_go[m3][n3] == mark2)) //*****
            {
            if(chessboard_go[m5][n5]==num2)
            {
            	if(checkqi(chessboard_go,m5,n5,size1,size2) == 1)
            	              return 1; 
            }
            else
         	  {return 1;}           
            }
   
            m3=m4,n3=n4;
            m3--;
             m5=m4,n5=n4;
            m5=m5-2;
         if((chessboard_go[m3][n3]==0&&(m3>=1&&m3<=size1&&n4>=1&&n4<=size2))   || (chessboard_go[m5][n5]==num2 && chessboard_go[m3][n3]==mark)||(chessboard_go[m3][n3] == mark2)) //*****
            {
           	if(chessboard_go[m5][n5]==num2)
            {
            if(checkqi(chessboard_go,m5,n5,size1,size2) == 1)
            	              return 1;
            }
            else
              {return 1;}  
			              
            }

            m3=m4,n3=n4;
            n3++;
             m5=m4,n5=n4;
            n5=n5+2;
            printf("situation: (%d,%d) m5:%d n5:%d  num2:%d  ÓÒÒÆ2:%d \n",m4,n4,m5,n5,num2,chessboard_go[m5][n5]);
         if((chessboard_go[m3][n3]==0&&(m3>=1&&m3<=size1&&n4>=1&&n4<=size2))   || (chessboard_go[m5][n5]==num2 && chessboard_go[m3][n3]==mark)||(chessboard_go[m3][n3] == mark2)) //*****
            {
            	
           	if(chessboard_go[m5][n5]==num2)
            {
            	show_go(chessboard_go,size1,size2);
            if(checkqi(chessboard_go,m5,n5,size1,size2) == 1)
            	              return 1;
            }
            else
              {return 1;}
			               
            }
     

            m3=m4,n3=n4;
            m3++; 
             m5=m4,n5=n4;
            m5=m5+2;
          if((chessboard_go[m3][n3]==0&&(m3>=1&&m3<=size1&&n4>=1&&n4<=size2))  || (chessboard_go[m5][n5]==num2 && chessboard_go[m3][n3]==mark)||(chessboard_go[m3][n3] == mark2)) //*****
            {
         	if(chessboard_go[m5][n5]==num2)
            {
            if(checkqi(chessboard_go,m5,n5,size1,size2) == 1)
            	              return 1;
            }
            else
             {return 1;}    
            }

               
     
            
            
          m3=m4,n3=n4;
		  n3--;       
           if(chessboard_go[m3][n3] == num2) 
              {
               if(checkqi(chessboard_go,m3,n3,size1,size2) == 1)
			   {return 1;
			                  }               
              }
          m3=m4,n3=n4;
          m3--;
           if(chessboard_go[m3][n3] ==num2)  
            {
             if(checkqi(chessboard_go,m3,n3,size1,size2) == 1)
			   {return 1;
			                  }        
            }
          m3=m4,n3=n4;
          n3++;
            if(chessboard_go[m3][n3] ==num2)
            {
               if(checkqi(chessboard_go,m3,n3,size1,size2) == 1)
			   {return 1;
			                  }          
            }
          m3=m4,n3=n4;
          m3++;
            if(chessboard_go[m3][n3] ==num2)
            {
              if(checkqi(chessboard_go,m3,n3,size1,size2) == 1)
			   {return 1;
			                  }  
            }
      
	  
	  
	        
    m3=m4,n3=n4;   
    show_go(chessboard_go,size1,size2);
	recover(chessboard_go,size1,size2); 
	if(chessboard_go[m3][n3] == 1 || chessboard_go[m3][n3]==2)
	{   
  // chessboard_go[m3][n3]=0;
   if(chessboard_go[m3][n3]==1)
        chessboard_go[m3][n3]=5;
        
   if(chessboard_go[m3][n3]==2)
        chessboard_go[m3][n3]=6;
    
   printf("%d %d is killed %d\n",m3,n3,chessboard_go[m3][n3]);
    }
  
    END:; 
    return 0;
    
}


int remove2(int  chessboard_go[m][n],int m11,int n11)
{
	int j,k;
    int size1=m11,size2=n11;
    int num;
   
    for(j=1;j<=size1;j++)
    {
		for(k=1;k<=size1;k++)
        {
            num = chessboard_go[j][k];
            
            if(num != 0)
            {
            	
				 checkqi(chessboard_go,j,k,size1,size2);
				 END2:;
            }
            recover(chessboard_go,size1,size2);
            
		}
    
    }	
	
	return 0;
}

void recover(int  chessboard_go[m][n],int m11,int n11)
{
    int j,k;
    int size1=m11,size2=n11;
    int num;
   
    for(j=1;j<=size1;j++)
    {
		for(k=1;k<=size1;k++)
        {
            num = chessboard_go[j][k];
            if(num == 3)
            {
            	chessboard_go[j][k]=1;
            }
            else if(num==4)
            {
            	chessboard_go[j][k]=2;
            }
		}
    
    }	
}


void count( struct measures measure ,int m11,int n11)
{
	
	int black=0,white=0;
	
	for(j=1;j<=size1;j++)
    {
		for(k=1;k<=size2;k++)
        {
            num = chessboard_go[j][k];
            if(num == 3 || num ==1 ||num==6)
            {
            	white++;
            }
            if(num==4 || num ==2 || num==5)
            {
            	black++;
            }
		}
    
    }
	
	printf("white:%d  black:%d\n",measure.white=white,measure.black=black);
	
		
    
}

int check_go(int  chessboard_go[m][n],struct measures measuree,int m11,int n11)
{
	 int j,k;
    
    int num;
   
    for(j=1;j<=size1;j++)
    {
		for(k=1;k<=size1;k++)
        {
            num = chessboard_go[j][k];
            if(num == 0)
            {
                   return 0;          	
            }
           
		}
    
    }
    count( measure ,size1,size2);
    if(measure.black>=measure.white+3){
        printf("Black win the game!\n");
    return 1;}
    else{
       printf("White win the game!\n");
    return 1;}
    
    return 0;
}











