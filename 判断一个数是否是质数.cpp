#include <stdio.h> 
   int work(int i)
   {int a,z;
   for(a=2;a<i-1;a++)
     {if(i%a==0)z=0;
	 }
    return(z);
   }
   int main()
   {int x,m;
    int work(int i);
    scanf("%d",&x);
    m=work(x);
    if(m==0)printf("%d不是素数",x);
	else printf("%d是素数",x);
   }
