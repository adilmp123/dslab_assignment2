#include <stdio.h>
int main()
{
    int a[10][3],a1[5][5],m,i,j,flag=0;
    system("clear");
    printf("Enter the number of rows: ");
    scanf("%d",&m);
    printf("Enter representation of sparse matrix in order\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<a[0][0];i++)
    {
        for(j=0;j<a[0][1];j++)
        {
            a1[i][j]=0;
        }
    }
    for(i=1;i<m;i++)
    {
        for(j=0;j<3;j++)
        {
            a1[a[i][0]][a[i][1]]=a[i][2];
        }
    }

    for(i=0;i<a[0][0];i++)
    {
        for(j=0;j<a[0][1];j++)
        {
            if(a1[i][j]!=a1[j][i])
            {
                flag=1;
                break;
            }
        }
    }
    if(flag)
    {
        printf("Not Symmetric");
    }
    else
        printf("Symmetric");

}