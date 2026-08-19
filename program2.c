#include<stdio.h>
int main()
{
int roll[100],n,i,j,temp;
printf("Enter the number of students: ");
scanf("%d",&n);
printf("Enter %d roll number: \n",n);
for(i=0;i<n;i++)
{
scanf("%d",&roll[i]);
}

for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(roll[j]>roll[j+1])
{

temp=roll[j];
roll[j]=roll[j+1];
roll[j+1]=temp;
}
}
printf("pass %d: ",i+1);
for(j=0;j<n;j++)
{
printf(" %d" ,roll[j]);
}
printf("\n");
}
printf("\n Sorted roll no in ascending order:\n");

for(i=0;i<n;i++)
{
printf(" %d",roll[i]);
}
printf("\n");
return 0;
}

