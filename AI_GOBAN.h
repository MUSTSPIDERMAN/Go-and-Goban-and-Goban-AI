
// ÐÞÏþ³¿ 1809853D-I011-0045  D1   2019Äê4ÔÂ22ÈÕ
#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>


int GOBAN_AI()
{
    
    #define m 40
    #define n 40
    
    int memory(int chessboard[m][n],int n11,int n22);
    void read_file(int chessboard[m][n],int n11,int n22);
    void show(int  chessboard[m][n],int n1,int n2);
    int check(int  chessboard[m][n],int n11,int n22);
    int ai(int  chessboard[m][n],int n11,int n22);
    
    int i,j,k,num;
    int chessboard[m][n];
    int choice1,choice2;
    char option;
    int size1,size2;
    
    
      	printf("Enter two number and divide them by space (like 15 15)to choice the size of chessboard\n ");
    	scanf("%d %d",&size1,&size2);

    for(j=1;j<=size1;j++)
    {
        
        for(k=1;k<=size2;k++)
        {
            chessboard[j][k] =0;
        }
        
    }
    printf("Do you want to start from the last time?\n enter y to continue \n");
    option=getchar();
    
    if(option == 'y')
    {
        read_file(chessboard,size1,size2);
    }
		while(getchar()!= '\n')
	     continue; 


    while(1)
    {
        show(chessboard,size1,size2);
    RESTART:;
        printf("Black first ,please, divide them by space\n");
        scanf("%d %d", &choice1 , &choice2);
        if(choice1 <1 || choice1 > size1  || choice2 <1 || choice2 > size2)
        {
            printf("The wrong range of numbers \n do it again\n");
            goto RESTART;
            
        }
        if(chessboard[choice1][choice2] != 0){
          printf("This place is occupied, try again\n");
         goto RESTART;
	    }
        chessboard[choice1][choice2] = 2;
        
        /* printf("White side please, divide them by space\n");
         scanf("%d %d", &choice1 , &choice2);
         if(choice1 <1 || choice1 > 15  || choice2 <1 || choice2 > 15)
         {
         printf("The wrong range of numbers \n do it again");
         goto RESTART;
         
         }
         chessboard[choice1][choice2] = 1;
         */
        if(check(chessboard,size1,size2) == 1)
            return 0;
        ai(chessboard,size1,size2);
        if(check(chessboard,size1,size2) == 1)
            return 0;
        /*
         FILE *fpWrite=fopen("chessdata.txt","w");
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
         */
        memory(chessboard,size1,size2);
    }
    
    return 0;
}

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

int memory(int chessboard[m][n],int n11,int n22)
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





 int check(int  chessboard[m][n],int n11,int n22)
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



int ai(int  chessboard[m][n],int n11,int n22)
{
    int size1=n11,size2=n22;
    int a1,a2,a3,a4,a5,a6,a7,a8;
    int b1,b2,b3,b4,b5,b6,b7,b8;
    int c1,c2,c3,c4,c5,c6,c7,c8;
    int a[9];
    int b[9];
    int i;
    for(i=1;i<=8;i++)
    {
        a[i]=0;
        b[i]=0;
    }
    
    int m3,n3;
    int m4,n4;
    
    int m1,n1;
    m1=n1=1;
    int num,num2;
    int count=0,count1=0;
    for(m1=1;m1<=8;m1++)
        a[i]=0;
    
    
    
    for(m1=1;m1<=size1;m1++)
    {
        for(n1=1;n1<=size2;n1++)
        {
            num = chessboard[m1][n1];
            m3=m1,n3=n1,count=0;
            //  printf("(%d,%d)\n",m1,n1);
            
            if(num==2)
            {
                //  while((n3<=15 && n3 >=1) && (m3 <=15 && m3 >= 1 ))
                
                while(chessboard[m3][n3] == num )
                {
                    
                    n3--;
                    count++;
                }
                if((chessboard[m3][n3]==0 || chessboard[m3][n3+count+1]==0)&&(m3>=1 && m3<=15 && n3>=1&&n3<=15)&&( (n3+count+1)>=1&&(n3+count+1)<=15))
                {
                    if(a[1]<count)
                    {
                        a[1]=count;
                    }
                }
                
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    n3--;
                    m3--;
                    count++;
                }
                if((chessboard[m3][n3]==0 || chessboard[m3+count+1][n3+count+1]==0)&&(m3>=1 && m3<=15 && n3>=1&&n3<=15) && ( (m3+count+1)>=1&&(m3+count+1)<=15 && (n3+count+1)>=1&&(n3+count+1)<=15   ) )
                {
                    if(a[2]<count)
                    {
                        a[2]=count;
                    }
                }
                
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    m3--;
                    count++;
                }
                
                if((chessboard[m3][n3]==0 || chessboard[m3+count+1][n3]==0)&&(m3>=1 && m3<=15 && n3>=1&&n3<=15) &&( (m3+count+1)>=1 &&(m3+count+1)<=15 ))
                {
                    if(a[3]<count)
                    {
                        a[3]=count;
                    }
                }
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    n3++;
                    m3--;
                    count++;
                }
                
                if((chessboard[m3][n3]==0 || chessboard[m3+count+1][n3-count-1]==0)&&(m3>=1 && m3<=15 && n3>=1&&n3<=15) && ( (m3+count+1)>=1&&(m3+count+1)<=15&&(n3-count-1)>=1&&(n3-count-1)<=15     ))
                {
                    if(a[4]<count)
                    {
                        a[4]=count;
                    }
                }
                
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    n3++;
                    count++;
                }
                
                if((chessboard[m3][n3]==0 || chessboard[m3][n3-count-1]==0)&&(m3>=1 && m3<=15 && n3>=1&&n3<=15)&&( (n3-count-1)>=1&&(n3-count-1)<=15 ))
                {
                    if(a[5]<count)
                    {
                        a[5]=count;
                    }
                }
                
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    n3++;
                    m3++;
                    count++;
                }
                
                if((chessboard[m3][n3]==0 || chessboard[m3-count-1][n3-count-1]==0)&&(m3>=1 && m3<=15 && n3>=1&&n3<=15)&&((m3-count-1)>=1&&(m3-count-1)<=15 && (n3-count-1)>=1&&(n3-count-1)<=15  ))
                {
                    if(a[6]<count)
                    {
                        a[6]=count;
                    }
                }
                
                
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    m3++;
                    count++;
                }
                
                if((chessboard[m3][n3]==0 || chessboard[m3-count-1][n3]==0)&&(m3>=1 && m3<=15 && n3>=1&&n3<=15)&&( (m3-count-1)>=1&&(m3-count-1)<=15 ))
                {
                    if(a[7]<count)
                    {
                        a[7]=count;
                    }
                }
                
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    n3--;
                    m3++;
                    count++;
                }
                
                if((chessboard[m3][n3]==0 || chessboard[m3-count-1][n3+count+1]==0) &&(m3>=1 && m3<=15 && n3>=1&&n3<=15)&& ((m3-count-1)>=1&&(m3-count-1)<=15 &&(n3+count+1)>=1&&(n3+count+1)<=15))
                {
                    if(a[8]<count)
                    {
                        a[8]=count;
                    }
                }
            END:;
            }
            if(num==1)
            {
                
                
                m3=m1,n3=n1,count1=0;
                
                while(chessboard[m3][n3] == num )
                {
                    
                    n3--;
                    count1++;
                }
                
                if((chessboard[m3][n3]==0 || chessboard[m3][n3+count1+1]==0)&&(m3>=1 && m3<=15 && n3>=1&&n3<=15)&&( (n3+count1+1)>=1&&(n3+count1+1)<=15))
                {
                    if(b[1]<count1)
                    {
                        b[1]=count1;
                    }
                }
                
                m3=m1,n3=n1,count1=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    n3--;
                    m3--;
                    count1++;
                }//printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^count1 2: %d\n",count1);
                if((chessboard[m3][n3]==0 || chessboard[m3+count1+1][n3+count1+1]==0)&&(m3>=1 && m3<=15 && n3>=1&&n3<=15) && ( (m3+count1+1)>=1&&(m3+count1+1)<=15 && (n3+count1+1)>=1&&(n3+count1+1)<=15   ) )
                {
                    if(b[2]<count1)
                    {
                        b[2]=count1;
                    }
                }
                
                
                m3=m1,n3=n1,count1=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    m3--;
                    count1++;
                }
                
                if((chessboard[m3][n3]==0 || chessboard[m3+count1+1][n3]==0)&&(m3>=1 && m3<=15 && n3>=1&&n3<=15) &&( (m3+count1+1)>=1 &&(m3+count1+1)<=15 ))
                {
                    if(b[3]<count1)
                    {
                        b[3]=count1;
                    }
                }
                
                m3=m1,n3=n1,count1=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    n3++;
                    m3--;
                    count1++;
                }
                
                if((chessboard[m3][n3]==0 || chessboard[m3+count1+1][n3-count1-1]==0)&&(m3>=1 && m3<=15 && n3>=1&&n3<=15) && ( (m3+count1+1)>=1&&(m3+count1+1)<=15&&(n3-count1-1)>=1&&(n3-count1-1)<=15     ))
                {
                    if(b[4]<count1)
                    {
                        b[4]=count1;
                    }
                }
                
                m3=m1,n3=n1,count1=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    n3++;
                    count1++;
                }
                
                if((chessboard[m3][n3]==0 || chessboard[m3][n3-count1-1]==0)&&(m3>=1 && m3<=15 && n3>=1&&n3<=15)&&( (n3-count1-1)>=1&&(n3-count1-1)<=15 ))
                {
                    if(b[5]<count1)
                    {
                        b[5]=count1;
                    }
                }
                
                
                m3=m1,n3=n1,count1=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    n3++;
                    m3++;
                    count1++;
                }
                
                if((chessboard[m3][n3]==0 || chessboard[m3-count1-1][n3-count1-1]==0)&&(m3>=1 && m3<=15 && n3>=1&&n3<=15)&&((m3-count1-1)>=1&&(m3-count1-1)<=15 && (n3-count1-1)>=1&&(n3-count1-1)<=15  ))
                {
                    if(b[6]<count1)
                    {
                        b[6]=count1;
                    }
                }
                
                
                m3=m1,n3=n1,count1=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    m3++;
                    count1++;
                }
                
                if((chessboard[m3][n3]==0 || chessboard[m3-count1-1][n3]==0)&&(m3>=1 && m3<=15 && n3>=1&&n3<=15)&&( (m3-count1-1)>=1&&(m3-count1-1)<=15 ))
                {
                    if(b[7]<count1)
                    {
                        b[7]=count1;
                    }
                }
                
                m3=m1,n3=n1,count1=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    n3--;
                    m3++;
                    count1++;
                }
                
                if((chessboard[m3][n3]==0 || chessboard[m3-count1-1][n3+count1+1]==0) &&(m3>=1 && m3<=15 && n3>=1&&n3<=15)&& ((m3-count1-1)>=1&&(m3-count1-1)<=15 &&(n3+count1+1)>=1&&(n3+count1+1)<=15))
                {
                    if(b[8]<count1)
                    {
                        b[8]=count1;
                    }
                }
                
            }
            
            
        }
    }
    
    
    int d=0,d1=0,compare=22;
    int x;
    i = 1;
    for(;i<=8;i++)
    {
        if(d < a[i])
            d = a[i];
        if(d1<b[i])
            d1=b[i];
    }
    if(d1>d||d1==d){
        compare=11;}
    
    
    if(compare==22)
    {
        for(m1=1;m1<=size1;m1++)
        {
            for(n1=1;n1<=size2;n1++)
            {
                num = chessboard[m1][n1];
                m3=m1,n3=n1,count=0;
                printf("\n new (%d,%d)",m1,n1);
                if(num!= 2)
                {
                    goto END2;
                }
                
                while(chessboard[m3][n3] == num)
                {
                    
                    n3--;
                    count++;
                }
                
                printf("count 11: %d\n",count);
                if(count==d)
                {
                    
                    if(chessboard[m3][n3] == 0 && (m3>=1 && m3<=15 && n3>=1&&n3<=15))
                    {
                        chessboard[m3][n3] = 1; return 0;
                    }
                }
                
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num)
                {
                    n3--;
                    m3--;
                    count++;
                }
                
                printf("count 22: %d\n",count);
                if(count==d)
                {
                    
                    
                    if(chessboard[m3][n3] ==0 && (m3>=1 && m3<=15 && n3>=1&&n3<=15))
                    {
                        chessboard[m3][n3] = 1;return 0;
                    }
                }
                
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num )
                {
                    
                    m3--;
                    count++;
                }
                
                printf("count 33: %d\n",count);
                if(count==d)
                {
                    
                    if(chessboard[m3][n3] ==0 && (m3>=1 && m3<=15 && n3>=1&&n3<=15))
                    {
                        chessboard[m3][n3] = 1;return 0;
                    }
                }
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num)
                {
                    n3++;
                    m3--;//put
                    count++;
                    
                }
                
                printf("count 44: %d\n",count);
                if(count==d)
                {
                    
                    if(chessboard[m3][n3] == 0 && (m3>=1 && m3<=15 && n3>=1&&n3<=15))
                    {
                        chessboard[m3][n3] = 1;return 0;
                    }
                }
                
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    n3++;
                    count++;
                }
                
                printf("count 55: %d\n",count);
                if(count==d)
                {
                    
                    if(chessboard[m3][n3] == 0 && (m3>=1 && m3<=15 && n3>=1&&n3<=15))
                    {
                        chessboard[m3][n3] = 1;return 0;
                    }
                }
                
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    n3++;
                    m3++;
                    count++;
                }
                
                printf("count 66:%d \n",count);
                if(count==d)
                {
                    
                    if(chessboard[m3][n3] == 0 && (m3>=1 && m3<=15 && n3>=1&&n3<=15))
                    {
                        chessboard[m3][n3] = 1;return 0;
                    }
                }
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num )
                {
                    
                    m3++;
                    count++;
                }
                
                printf("count 77:%d \n",count);
                if(count==d)
                {
                    
                    if(chessboard[m3][n3] == 0 && (m3>=1 && m3<=15 && n3>=1&&n3<=15))
                    {
                        chessboard[m3][n3] = 1;return 0;
                    }
                }
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num )
                {
                    
                    n3--;
                    m3++;
                    count++;
                }
                
                
                if(count==d)
                {
                    
                    if(chessboard[m3][n3] == 0 && (m3>=1 && m3<=15 && n3>=1&&n3<=15))
                    {
                        chessboard[m3][n3] = 1;return 0;
                    }
                }
                
            END2:;
            }
        }
    }
    
    if(compare==11)
    {
        for(m1=1;m1<=size1;m1++)
        {
            for(n1=1;n1<=size2;n1++)
            {
                num = chessboard[m1][n1];
                m3=m1,n3=n1,count=0;
                
                if(num != 1)
                {
                    goto END3;
                }
                
                
                while(chessboard[m3][n3] == num)
                {
                    
                    n3--;
                    count++;
                }
                
                
                if(count==d)
                {
                    
                    if(chessboard[m3][n3] == 0 && (m3>=1 && m3<=15 && n3>=1&&n3<=15))
                    {
                        chessboard[m3][n3] = 1; return 0;
                    }
                }
                
                
                
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    n3--;
                    m3--;
                    count++;
                }
                
                if(count==d)
                {
                    //put
                    
                    if(chessboard[m3][n3] ==0 && (m3>=1 && m3<=15 && n3>=1&&n3<=15))
                    {
                        chessboard[m3][n3] = 1;return 0;
                    }
                }
                
                
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num )
                {
                    
                    m3--;
                    count++;
                }
                
                if(count==d)
                {
                    
                    if(chessboard[m3][n3] ==0 && (m3>=1 && m3<=15 && n3>=1&&n3<=15))
                    {
                        chessboard[m3][n3] = 1;return 0;
                    }
                }
                
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num)
                {
                    n3++;
                    m3--;//put
                    count++;
                    
                }
                if(count==d)
                {
                    
                    if(chessboard[m3][n3] == 0 && (m3>=1 && m3<=15 && n3>=1&&n3<=15))
                    {
                        chessboard[m3][n3] = 1;return 0;
                    }
                }
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    n3++;
                    count++;
                }
                if(count==d)
                {
                    
                    if(chessboard[m3][n3] == 0 && (m3>=1 && m3<=15 && n3>=1&&n3<=15))
                    {
                        chessboard[m3][n3] = 1;return 0;
                    }
                }
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num)
                {
                    
                    n3++;
                    m3++;
                    count++;
                }
                if(count==d)
                {
                    
                    if(chessboard[m3][n3] == 0 && (m3>=1 && m3<=15 && n3>=1&&n3<=15))
                    {
                        chessboard[m3][n3] = 1;return 0;
                    }
                }
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num )
                {
                    
                    m3++;
                    count++;
                }
                if(count==d)
                {
                    
                    if(chessboard[m3][n3] == 0 && (m3>=1 && m3<=15 && n3>=1&&n3<=15))
                    {
                        chessboard[m3][n3] = 1;return 0;
                    }
                }
                
                m3=m1,n3=n1,count=0;
                while(chessboard[m3][n3] == num )
                {
                    
                    n3--;
                    m3++;
                    count++;
                }
                
                if(count==d)
                {
                    
                    if(chessboard[m3][n3] == 0 && (m3>=1 && m3<=15 && n3>=1&&n3<=15))
                    {
                        chessboard[m3][n3] = 1;return 0;
                    }
                }
                
            END3:;
            }
        }
        
    }
    printf("\n");
    return 0;
}

void read_file(int chessboard[m][n],int n1,int n2) {
    int ch;
    FILE *fp; // "file pointer"
    
    int j=1,k=1;
    if ((fp = fopen("chessdata", "r")) == NULL) {
        printf("Can't open %s\n", "chesssdata");
        exit(1);
    }
    
   int size1,size2;
    size1=n1,size2=n2;
    for(j=1;j<=size1;j++)
    {
        
        for(k=1;k<=size2;k++)
        {
        GET:;
            ch=0;
            ch = getc(fp);
            
            if(isdigit(ch) &&(ch==48 || ch==49||ch==50))
            {
                switch (ch)
                {
                    case 48: ch=0;
                        break;
                    case 49: ch=1;
                        break;
                    case 50: ch=2;
                        break;
                }
                chessboard[j][k]=ch;
                
            }
            else
                goto GET;
            
        }
    }
    
    if(fclose(fp) != 0)
        fprintf(stderr, "error in closing");
    
}

        
            
  
        
        




