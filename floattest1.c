#include <stdio.h>
#include <float.h>
 
int main(void) {
 
  /* float */
  printf("float �̍ő�l = %e\n", FLT_MAX);
  printf("float �̍ŏ��l = %e\n", -FLT_MAX);
  printf("float �̕��������_�ŕ\\���ł���ŏ��l = %e\n\n", FLT_MIN);
  /* double */
  printf("double �̍ő�l = %e\n", DBL_MAX); 
  printf("double �̍ŏ��l = %e\n", -DBL_MAX); 
  printf("double �̕��������_�ŕ\\���ł���ŏ��l = %e\n\n", DBL_MIN);
 
  /* long double */
  printf("long double �̍ő�l = %Le\n", LDBL_MAX);
  printf("long double �̍ŏ��l = %Le\n", -LDBL_MAX);
  printf("long double �̕��������_�ŕ\\���ł���ŏ��l = %Le\n\n", LDBL_MIN);
 
  return 0;
}
