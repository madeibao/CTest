
/**

0 9 0 0 0 0 0 6 0
8 0 1 0 0 0 5 0 9
0 5 0 3 0 4 0 7 0
0 0 8 0 7 0 9 0 0
0 0 0 9 0 8 0 0 0
0 0 6 0 2 0 7 0 0
0 8 0 7 0 5 0 4 0
2 0 5 0 0 0 8 0 7
0 6 0 0 0 0 0 9 0

7 9 3 8 5 1 4 6 2
8 4 1 2 6 7 5 3 9
6 5 2 3 9 4 1 7 8
3 2 8 4 7 6 9 5 1
5 7 4 9 1 8 6 2 3
9 1 6 5 2 3 7 8 4
1 8 9 7 3 5 2 4 6
2 3 5 6 4 9 8 1 7
4 6 7 1 8 2 3 9 5

**/



#include<iostream>
#include<bits/stdc++.h>
int rnumb[9][9];
int temp[9][9];
int col[9][10];
int row[9][10];
int gongge[9][10];

void shudu(int n)
{
    if(n==81)
    {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                temp[i][j]=rnumb[i][j];
        return;
    }
    int x=n/9,y=n%9;
    if(rnumb[x][y]==0)
    {
        for(int i=1;i<=9;i++)
        {
            if(row[x][i]!=1&&col[y][i]!=1&&gongge[x/3*3+y/3][i]!=1)
            {
                row[x][i]=1;
                col[y][i]=1;
                gongge[x/3*3+y/3][i]=1;
                rnumb[x][y]=i;
                shudu(n+1);
                row[x][i]=0;
                col[y][i]=0;
                gongge[x/3*3+y/3][i]=0;
                rnumb[x][y]=0;
            }
        }
    }
    else
        shudu(n+1);
}

int main()
{
    int cn;
    memset(col,0,sizeof(col));
    memset(row,0,sizeof(row));
    memset(gongge,0,sizeof(gongge));
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        {
            std::cin>>cn;
            rnumb[i][j]=cn;
            if(cn!=0)
            {
            row[i][cn]=1;
            col[j][cn]=1;
            gongge[i/3*3+j/3][cn]=1;
            }
        }
    shudu(0);
    for(int i=0;i<9;i++)
    {
        int j;
        for(j=0;j<8;j++)
            std::cout<<temp[i][j]<<" ";
        std::cout<<temp[i][j]<<std::endl;
    }
}
