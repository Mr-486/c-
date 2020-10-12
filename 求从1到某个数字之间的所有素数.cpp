# include <stdio.h>
/* 2019/3/3
  目的：比较单用主函数编写程序与利用构造其他函数的方式 
*/


//利用主函数求各素数的值 
/*
int main(void)
{
	int i;
	int j;
	int n;
	
	printf("请输入任意一个数字； ");
	scanf("%d", &n);
	 
	for (i=2; i<=n; ++i)
	  {
	  	for (j=2; j<=i; ++j)
	  	  {
	  	  	if (i%j ==0)
	  	  	  break;
		  }
		if (i == j)
		  printf("%d\n", i);
	  }
	
	return 0;
 }
 */ 
 
 
 
 //利用构造其他函数来求各素数的值
# include <stdio.h>

bool Isprime(int i)
{
	int num;
	
	for (num=2; num<=i; ++num)
	  {
	  	if(i%num ==0)
	  	  break;
	  }
	if (num==i)
	  return true;
	else
	  return false;
}

int cnt(int n)
{
	int i;
	
	for (i=2; i<=n; ++i)
      {
      	if (Isprime(i))
      	  printf("%d\n", i);
	  }

}

int main(void)
{
	int n;
	printf("请输入任意一个数； ");
	scanf("%d", &n);
	
	cnt(n); 
	return 0;
}
