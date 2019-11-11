/* header files */
#include <stdio.h>
#include <stdlib.h>
//#include <errno.h>
//#include <float.h>
/* macros */
#define N 256

/* main */
int main(void) {
    char s[N] = {}, *endptr;
    double x;

    /* 入力 */
    fgets(s, N, stdin);
    printf("変換前: %s", s);

    /* 変換 */
    x = strtod(s, &endptr);
    printf("変換後: %.2f\n", x);
    printf("endptr: %s\n", endptr);


	/*if (errno == ERANGE) {
		puts("オーバーフローとアンダーフローのいずれかが発生しました");
	}

	if (errno == ERANGE && x == DBL_MAX) {
		puts("オーバーフローが発生しました");
	}

	if (errno == ERANGE && x == DBL_MIN) {
		puts("アンダーフローが発生しました");
	}*/

    return EXIT_SUCCESS;
}