//http://stroll.hatenablog.com/entry/2015/07/20/221125 から。

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
	char data[255];
	int i,j, n = 0,m=0, nsign = 1, flag = 0, isdecimal=0;
	double dnam;
	printf("入力した文字列が数値のみの時はその値を返します。文字が含まれている場合はエラーを表\示します。\n");
	printf("9桁以内の数値を入力してください。>>\n");
	do{
		n = 0;
		m=0;
		flag = 0;
		nsign = 1;
		isdecimal = 0;

		scanf("%s", data) ;
		if (strlen(data) > 9) {
			flag = 2;
		}
		i = 0;
		j = 0;
		if (flag == 0 && data[0] == '+') {
			i++;
		}
		if (flag == 0 && data[0] == '-') {
			nsign = -1;
			i++;
		}

		
		printf("[db]flag is %d data[i] is %c isdecimal is %d j is %d\n",flag,data[i],isdecimal,j);
		for (; i < strlen(data); i++) {
			printf("[db]flag is %d data[i] is %c isdecimal is %d j is %d\n",flag,data[i],isdecimal,j);

			if (flag == 0 && data[i] == '.'&&isdecimal==0) {
				isdecimal = 1;
				//i++;
			}
			
			else if (flag == 0 && data[i] >= 48 && data[i] <= 57&&isdecimal==0) {
				n = n * 10 + data[i] - '0';
				printf("[db]整数部シーケンス n=%d\n",n);

			}
			else if (flag == 0 && data[i] >= 48 && data[i] <= 57&&isdecimal==1) {
				m = m * 10 + data[i] - '0';
				printf("[db]小数部シーケンス m=%d\n",m);
				j++;
			}
			/*else if(isdecimal==0&&flag==0&&data[i]=='.'){
				puts("[db]入力逃がし");
				//なにもしない。入力逃がし
			}*/
			else {
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
		printf("[db]flag is %d data[i] is %c isdecimal is %d j is %d\n",flag,data[i],isdecimal,j);
		if (flag == 0) {
			dnam = nsign*( (double)n+ m*pow(0.1,j) );
			printf("成功:%lf\n", dnam);
		}
	}while (flag!=0);
}