#include <stdio.h>
#include <string.h>

int main(void)
{
  char s1[] = "this is a pen. Hello-World...";
  char s2[] = " -.";  /* 空白+ハイフン+ピリオド */
  char *tok;

  tok = strtok( s1, s2 );
  while( tok != NULL ){
    printf( "%s\n", tok );
    tok = strtok( NULL, s2 );  /* 2回目以降 */
  }

  return 0;
}