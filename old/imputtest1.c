//http://stroll.hatenablog.com/entry/2015/07/20/221125 ����B

#include <stdio.h>
#include <string.h>

int main(void) {
	char data[255];
	int i, n = 0, nsign = 1, flag = 0;
	printf("���͂��������񂪐��l�݂̂̎��͂��̒l��Ԃ��܂��B�������܂܂�Ă���ꍇ�̓G���[��\\�����܂��B\n");
	printf("9���ȓ��̐��l����͂��Ă��������B>>\n");
	while (scanf("%s", data) != EOF) {
		if (strlen(data) > 9) {
			flag = 2;
		}
		i = 0;
		if (flag == 0 && data[0] == '+') {
			i++;
		}
		if (flag == 0 && data[0] == '-') {
			nsign = -1;
			i++;
		}
		for (; i < strlen(data); i++) {
			if (flag == 0 && data[i] >= 48 && data[i] <= 57) {
				n = n * 10 + data[i] - '0';
			} else {
				if (flag == 2) {
					printf("�����傫�����܂��B�ē���>>\n");
					break;
				} else {
					printf("�G���[�B�������܂܂�Ă��܂�\n");
					flag = 1;
					break;
				}
			}
		}
		n = nsign * n;
		if (flag == 0) {
			printf("����:%d\n", n);
		}
		n = 0;
		flag = 0;
		nsign = 1;
	}
}