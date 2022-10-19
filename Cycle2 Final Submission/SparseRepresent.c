#include <stdio.h>
typedef struct{
    int row;
    int col;
    int val;
}sparse;
void printSparse(sparse a[])
{
    int i;
    for(i=0;i<=a[0].val;i++)
    {
        printf("\n%d %d %d",a[i].row,a[i].col,a[i].val);
    }
    printf("\n\n");
}
void readSparse(int b[][10],int m,int n)
{
    int i,j;
    printf("Enter the sparse matrix\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    
}
void represent(int b[][10],int m,int n,sparse a[])
{
    float sparsity;
    int i,j,k=1;
    a[0].row=m;
    a[0].col=n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(b[i][j]!=0)
            {
                a[k].row=i;
                a[k].col=j;
                a[k].val=b[i][j];
                k++;
            }
        }
    }
    a[0].val=k-1;
    printSparse(a);
    sparsity = (float) (m*n+1-k)/(m*n);
    printf("\nsparsity = %f",sparsity);
}
int main()
{
    int i,j,m,n,k=1,element;
    sparse a[100];
    system("clear");
    printf("Enter the number of rows: ");
    scanf("%d",&m);
    printf("Enter the number of columns: ");
    scanf("%d",&n);
    int b[m][n];
    readSparse(b,m,n);
    represent(b,m,n,a);
}
