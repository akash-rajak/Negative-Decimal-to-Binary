//program to find binary form of negative decimal no. from -1 to 100
// Given n, the formula to find the no of digits in which it can be represented in binary form is floor(log2) + 1;

/*
	input format be like :
	n		num
	-1		1
	-2 		2
	-3		2
	-4 		3
	so on....
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
FILE *fp1;
int i,a[50],b[50],c[50],sum,sum1,m,m1,m2,count1,count2;
int negdecimaltobase2(int base1,int base2,int n,int num);
int decimaltobase2(int base1,int base2,int n);
int base1todecimal(int base1,int base2,int n);
int comp21(int n,int num);
int main()
{
	fp1=fopen("table1.txt","a");
	fprintf(fp1,"%s","Binary form of negative Decimal number.\nTwo decimal no. one positive anf one negative equivalent to one binary digit.\n");
	//This line is run only for the first run
	int base1=10,base2=2,n,num;
	printf("Enter the no. : \n");
	scanf("%d",&n);
	printf("Enter the no. of digits :\n");
	scanf("%d",&num);
	printf("For n = %d\n",n);
	fprintf(fp1,"For n = %d\n",n);
	negdecimaltobase2(base1,base2,n,num);//num enetered will be equal to number of digit in binary form of positive number of n
										//snum should be equal to the power of nearest 2 to the power term
										//eg. -55 then num=6 because pow(2,6)=64 and 55<64
										//eg. -256 then num=9 because pow(2,9)=512 and 256<512
	return 0;
}
int negdecimaltobase2(int base1,int base2,int n,int num)
{
	m=n-(2*n);
	//printf("%d\n",m);
	m2=decimaltobase2(10,2,m);
	//printf("%d\n",m2);
	printf("   Binary form of %d = ",n);//--------------------------------->>2
	fprintf(fp1,"   Binary form of %d = ",n);
	comp21(m2,num);
	return 0;
}
int decimaltobase2(int base1,int base2,int n)
{
	printf("   Binary form of %d = ",n);//---------------------------->>1 and 3
	fprintf(fp1,"   Binary form of %d = ",n);
	while(n!=0)
	{
		a[i]=n%base2;
		n=n/base2;
		i++;
	}
	int count1=i;
	for(i=count1-1;i>=0;i--)
	{
		printf("%d ",a[i]);
		fprintf(fp1,"%d ",a[i]);
	}
	printf("\n");
	fprintf(fp1,"%s","\n");
	for(i=0;i<=count1-1;i++)
	{
		sum1=sum1+a[i]*pow(10,i);
	}
	//printf("%d\n",sum1);
	i=0;count1=0;
	return sum1;
}
int base1todecimal(int base1,int base2,int n)
{
	while(n!=0)
	{
		b[i]=n%10;
		a[i]=b[i]*pow(base1,i);
		n=n/10;
		i++;
	}
	int count2=i;
	for(i=0;i<=count2-1;i++)
	{
		sum=sum+a[i];
	}
	//printf("%d\n",sum);
	i=0;count2=0;
	return sum;
}
int comp21(int n,int num)
{
	base1todecimal(2,10,n);
	//printf("%d\n",sum);
	m1=pow(2,num+1)-sum;
	//printf("%d\n",m1);
	decimaltobase2(10,2,m1);
	sum=0;m1=0;
	return 0;
}
