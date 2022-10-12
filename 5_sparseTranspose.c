#include <stdio.h>
int main()
{
    int a[10][3],a1[5][5],b[10][3],b1[5][5];
    int m,k,i,j;
    system("clear");
    printf("Enter the number of rows of matrix: ");
    scanf("%d",&m);
    printf("Enter first sparse matrix in order\n");
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
            b1[i][j]=a1[j][i];
        }
    }

    printf("\n");
    for(i=0;i<a[0][0];i++)
    {
        for(j=0;j<a[0][1];j++)
        {
            printf("%d\t",b1[i][j]);
        }
        printf("\n");
    }
    //poi
    b[0][0]=a[0][1];
    b[0][1]=a[0][0];
    b[0][2]=a[0][2];
    k=1;
    for(i=0;i<a[0][1];i++)
    {
        for(j=0;j<a[0][0];j++)
        {
            if(b1[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=b1[i][j];
                k++;
            }
        }
    }
    printf("\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
}