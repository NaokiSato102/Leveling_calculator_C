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

    /* ���� */
    fgets(s, N, stdin);
    printf("�ϊ��O: %s", s);

    /* �ϊ� */
    x = strtod(s, &endptr);
    printf("�ϊ���: %.2f\n", x);
    printf("endptr: %s\n", endptr);


	/*if (errno == ERANGE) {
		puts("�I�[�o�[�t���[�ƃA���_�[�t���[�̂����ꂩ���������܂���");
	}

	if (errno == ERANGE && x == DBL_MAX) {
		puts("�I�[�o�[�t���[���������܂���");
	}

	if (errno == ERANGE && x == DBL_MIN) {
		puts("�A���_�[�t���[���������܂���");
	}*/

    return EXIT_SUCCESS;
}