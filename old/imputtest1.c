//http://stroll.hatenablog.com/entry/2015/07/20/221125 から。

#include <stdio.h>
#include <string.h>

int main(void) {
	char data[255];
	int i, n = 0, nsign = 1, flag = 0;
	printf("入力した文字列が数値のみの時はその値を返します。文字が含まれている場合はエラーを表\示します。\n");
	printf("9桁以内の数値を入力してください。>>\n");
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
					printf("桁が大きすぎます。再入力>>\n");
					break;
				} else {
					printf("エラー。文字が含まれています\n");
					flag = 1;
					break;
				}
			}
		}
		n = nsign * n;
		if (flag == 0) {
			printf("成功:%d\n", n);
		}
		n = 0;
		flag = 0;
		nsign = 1;
	}
}