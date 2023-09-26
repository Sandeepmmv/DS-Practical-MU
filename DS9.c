#include <stdio.h>
#include <conio.h>

int HT[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
void linear_probing(int key)
{
    int k,i;
    for(i=0;i<10;i++)
    {
        k = ((key%10)+i)%10 ;
        if( HT[k]==-1)
        {
            HT[k]= key;
            break;
        }
    }
}
void search(int val)
{
    int k,i;
    for(i=0;i<10;i++)
    {
        k = ((val%10)+i)%10 ;
        if( HT[k]==val)
        {
	    printf("Element found at %d index \n",k);
            break;
        }
    }
    if(i>=10)
    {
        printf("Element not found \n");
    }
}
void main()
{

    int A[10], i, n, c=-1,s;
    clrscr();
    printf("Enter n(<10) \n");
    scanf("%d", &n);
    for( i= 0; i<n; i++)
    {
        scanf("%d",&A[i]);
    }
printf("Enter \n1 for storing numbers into hash table \n2 for searching a particular number \n3 for displaying hash table \n0 to exit \n");
    while(c!=0)
    {
    printf("\nEnter: ");
    scanf("%d",&c);
    switch(c)
    {
        case 1: for(i=0;i<n;i++)
                {
                    linear_probing(A[i]);
                }
                break;
        case 2: printf("Enter element to be searched \n");
                scanf("%d",&s);
                search(s);
                break;
        case 3: for(i=0;i<10;i++)
                {
                    printf("0%d \t",i);
                }
                printf("\n");
                for(i=0;i<10;i++)
                {
                    printf("%d \t",HT[i]);
                }
                printf("\n");
    }
    }
}
