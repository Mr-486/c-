# include <stdio.h>
/* 2019/3/3
  Ŀ�ģ��Ƚϵ�����������д���������ù������������ķ�ʽ 
*/


//�������������������ֵ 
/*
int main(void)
{
	int i;
	int j;
	int n;
	
	printf("����������һ�����֣� ");
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
 
 
 
 //���ù����������������������ֵ
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
	printf("����������һ������ ");
	scanf("%d", &n);
	
	cnt(n); 
	return 0;
}
