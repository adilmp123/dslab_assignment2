#include <stdio.h>
typedef struct
{
    int row;
    int col;
    int val;
}term;
void sparseRepresentation(term a[],int n)
{
    int i;
    printf("Enter the sparse representation\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i].row);
        scanf("%d",&a[i].col);
        scanf("%d",&a[i].val);
    }
}
void isSymmetric(term a[],int n)
{
    int i,j,flag=0;
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            
            if(((a[i].col==a[j].row) && (a[i].row==a[j].col)))
            {
                if(a[i].val!=a[j].val)
                    flag=1;
            }
        }
    }
    if(flag)
    {
        printf("Not Symmetric\n\n");
    }
    else
        printf("Symmetric\n\n");
}
int main()
{
    int n;
    system("clear");
    printf("Enter the number of rows: ");
    scanf("%d",&n);
    term a[n];
    sparseRepresentation(a,n);
    isSymmetric(a,n);
}
