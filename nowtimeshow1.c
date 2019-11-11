#include <stdio.h>
#include <time.h>
int main(int argc, char **argv) {
  char date[64];
  time_t t = time(NULL);

  strftime(date, sizeof(date), "%Y/%m/%d %a %H:%M:%S", localtime(&t));
  printf("%d is %s\n",t, date);
  return 0;
}