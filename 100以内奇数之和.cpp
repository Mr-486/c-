# include <stdio.h>

int main(void)
{
	int i;
	int sum1 = 0;
	int sum2 = 0;
	int count = 0;
	
	for (i=1; i<=100; i+=2)
	      sum1+=i;
	printf("sum1 = %d", sum1);
	
	printf("\n");
	
	for (i=0; i<=100; i+=2)
	      sum2+=i;
    printf("sum2 = %d", sum2);
    
    printf("\n");
    printf("һ������ż��Ϊ��\n"); 
    
    for (i=1; i<=100; ++i)
       {
       	  if(i%2 ==0)
       	    {
			   count = count+1;
			   printf("%d ", i);
			}
	   }
	printf("\n");
	printf("һ������ż����Ϊ��\n");
	printf("count = %d", count);
	
	printf("\n");
	printf("һ����������Ϊ��\n");
	count = 0;
	
	for(i=1; i<=100; ++i)
	    {
	      if(i%2 ==1)
	        {
			  count = count+1;
			  printf("%d ", i);
			}
		}
	printf("\n");
	printf("һ������������Ϊ��\n");
	printf("count = %d",count);
	
	return 0;
}
