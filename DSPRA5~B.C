#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int selection_sort(int n);
int A[20];
int selection_sort(int n)
{
int imin,i,j,temp;
for(i=0;i<n;i++)
{
imin=i;
for(j=i+1;j<n;j++)
{
if(A[imin]>A[j])
{
imin=j;
}
}
temp = A[i];
A[i] = A[imin];
A[imin] = temp;
}
printf(" sorted using Selection sort :");return 0;
}
int main()
{
int n,i;
printf("Enter the size :");
scanf("%d",&n);
printf("Enter the element :\n");
for(i=0;i<n;i++)
{
scanf("%d",&A[i]);
printf("\n");
}

selection_sort(n);
for(i=0;i<n;i++)
{
printf("\n %d\n",A[i]);
} getch();
return 0;
}
