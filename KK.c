
#include<bits/stdc++.h>

using namespace std;

const int N=1010;

struct node{

    int b,j;

    bool operator<(const node q)const{

        return j>q.j;

    }

}a[N];

int main(){

    int n,i,Case=0;

    while(scanf("%d",&n)==1 && n){

        Case++;

        for(i=0;i<n;i++)

            scanf("%d%d",&a[i].b,&a[i].j);

        sort(a,a+n);int nowTime=0,ans=0;

        for(i=0;i<n;i++){

            nowTime+=a[i].b;

            ans=max(ans,nowTime+a[i].j);

        }

        printf("Case %d: %d\n",Case,ans);

    }

    return 0;

}

