#include <stdio.h>
int result;
int a, e;
char h,p;
int main()
{

   scanf("%d %c %d", &a, &h, &e);
   
   
   if (h == '+')
   {
      result = a + e;
      printf("%d", result);
   }
   else if (h=='-')
   {
      printf("%d", a - e);
   }
   else if (h == '*')
   {
      printf("%d", a * e);
   }
   else if (h == '/')
   {
      printf("%d", a / e);
   }

}