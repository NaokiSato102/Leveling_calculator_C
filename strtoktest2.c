#include <stdio.h>
#include <string.h>

int main(void)
{
  char s1[] = "18/12/8";
  char s2[] = "/";  
  char *tok;

  tok = strtok( s1, s2 );
  while( tok != NULL ){
    printf( "%s\n", tok );
    tok = strtok( NULL, s2 );  /* 2âÒñ⁄à»ç~ */
  }

  return 0;
}