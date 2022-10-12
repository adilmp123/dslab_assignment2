#include <stdio.h>
int main()
{
    int a[5][5], b[10][3],m,n,i,j,k;
    float sparcity;
    system("clear");
    printf("Enter number of rows: ");
    scanf("%d",&m);
    printf("Enter number of columns: ");
    scanf("%d",&n);
    printf("\nEnter elements: \n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    b[0][0]=m;
    b[0][1]=n;
    k=1;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]!=0)
            {
                b[k][0]=i;
                b[k][1]=j;
                b[k][2]=a[i][j];
                k++;
            }
        }
    }
    b[0][2]=k-1;
    printf("\n");
    for(i=0;i<k;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    sparcity = (float)((m*n+1)-k)/(m*n);
    printf("sparcity = %f",sparcity);

    
}