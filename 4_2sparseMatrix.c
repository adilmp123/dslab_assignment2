#include <stdio.h>
int main()
{
    int a[10][3],b[10][3],c[10][3],a1[5][5],b1[5][5],c1[5][5],q;
    int m,n,k,i,j;
    system("clear");
    printf("Enter the number of rows of first matrix: ");
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

    printf("\n");
    for(i=0;i<a[0][0];i++)
    {
        for(j=0;j<a[0][1];j++)
        {
            printf("%d\t",a1[i][j]);
        }
        printf("\n");
    }

    printf("Enter the number of rows of second matrix: ");
    scanf("%d",&n);
    printf("\nEnter second sparse matrix in order\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<b[0][0];i++)
    {
        for(j=0;j<b[0][1];j++)
        {
            b1[i][j]=0;
        }
    }
    for(i=1;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            b1[b[i][0]][b[i][1]]=b[i][2];
        }
    }

    printf("\n");
    for(i=0;i<b[0][0];i++)
    {
        for(j=0;j<b[0][1];j++)
        {
            printf("%d\t",b1[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<a[0][0];i++)
    {
        for(j=0;j<a[0][1];j++)
        {
            c1[i][j]=a1[i][j]+b1[i][j];
        }
    }
    printf("\n");
    for(i=0;i<b[0][0];i++)
    {
        for(j=0;j<b[0][1];j++)
        {
            if(c1[i][j]!=0)
                k++;
            printf("%d\t",c1[i][j]);
        }
        printf("\n");
    }
    q=k;

    //cccccccccccccccccccccccccccccccccccccccc

    c[0][0]=a[0][0];
    c[0][1]=a[0][1];
    c[0][2]=q;
    k=1;
    for(i=0;i<a[0][0];i++)
    {
        for(j=0;j<a[0][1];j++)
        {
            if(c1[i][j]!=0)
            {
                c[k][0]=i;
                c[k][1]=j;
                c[k][2]=c1[i][j];
                k++;
            }
        }
    }
    printf("\n");
    for(i=0;i<q+1;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
}