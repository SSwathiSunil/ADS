#include<stdio.h>
void main()
{
    int a[5],b[5],c[10],n,m,i,j,temp=0,k,x;
    printf("enter the first array size\n");
    scanf("%d",&n);
    printf("enter %d elements of first array\n",n);
    for(i=0;i<n;i++)
    {
    scanf("%d",&a[i]);
    }
    printf("enter size of second array\n");
    scanf("%d",&m);
    printf("enter %d elements of second array\n",m);
    for(i=0;i<m;i++)
    {
        scanf("%d",&b[i]);
    
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("first array after sorting\n");
    for(i=0;i<n;i++)
    printf(" %d",a[i]);

    for(i=0;i<m;i++)
    {
        for(j=i+1;j<m;j++)
        {
        if(b[i]>b[j])
        {
            temp=b[i];
            b[i]=b[j];
            b[j]=temp;

        }
        }}
        printf("second array after sorting\n");
        for(i=0;i<m;i++)
        printf(" %d",b[i]);
        x=m+n;
        k=0;
        for(i=0;i<n;i++)
        {
            c[k]=a[i];
            k++;
        }
        k=n;
        for(i=0;i<m;i++)
        {
            c[k]=b[i];
            k++;

    
        }
        for(i=0;i<x;i++)
        {
            for(j=i+1;j<x;j++)
            {
                if (c[i]>c[j])
                {
                    temp=c[i];
                    c[i]=c[j];
                    c[j]=temp;
                }
                
                
            }
        }
        printf("merged array is\n");
        for(i=0;i<x;i++)
        printf(" %d",c[i]);
}