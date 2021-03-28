#include <stdio.h>
#include<math.h>

int eq2(float a, float b, float c, float* raiz_1, float* raiz_2);

int main()
{
   float raiz_1, raiz_2, a, b, c;
   scanf("%f %f %f", &a, &b,&c);
   switch (eq2(a, b, c, &raiz_1, &raiz_2))
       {
        case 0:
	   printf("nao ha raiz real\n");
	break;
	case 1:
	   printf("%.4f\n", raiz_1);
	break;
	case 2:
	   printf("%.4f %.4f\n", raiz_1, raiz_2);
        break;
       }
   return 0;
}


int eq2(float a, float b, float c, float* raiz_1, float* raiz_2) 
{
   float delta;
   delta = b * b - 4 * a * c;
   if(delta > 0)
   {
       *raiz_1 = (-b + sqrt(delta)) / (2 * a); 
       *raiz_2 = (-b - sqrt(delta)) / (2 * a); 
       return 2;   
   }else if(delta < 0)
   {
       return 0;
   }else
   {
	   *raiz_1 = -b / (2 * a);
       return 1;
   }
}
