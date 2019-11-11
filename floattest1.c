#include <stdio.h>
#include <float.h>
 
int main(void) {
 
  /* float */
  printf("float の最大値 = %e\n", FLT_MAX);
  printf("float の最小値 = %e\n", -FLT_MAX);
  printf("float の浮動小数点で表\現できる最小値 = %e\n\n", FLT_MIN);
  /* double */
  printf("double の最大値 = %e\n", DBL_MAX); 
  printf("double の最小値 = %e\n", -DBL_MAX); 
  printf("double の浮動小数点で表\現できる最小値 = %e\n\n", DBL_MIN);
 
  /* long double */
  printf("long double の最大値 = %Le\n", LDBL_MAX);
  printf("long double の最小値 = %Le\n", -LDBL_MAX);
  printf("long double の浮動小数点で表\現できる最小値 = %Le\n\n", LDBL_MIN);
 
  return 0;
}
