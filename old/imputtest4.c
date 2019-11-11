//http://stroll.hatenablog.com/entry/2015/07/20/221125 を基に開発

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
	int lim=9;
	double dnam;

	char data[1024];
	int i,j, intp = 0,decp=0, nsign = 1, flag = 0, isdecimal=0;

	printf("入力文字列が「半角数値及び正負記号,小数点」の時はその値を返します。それ以外ははエラーとなります。\n");
	printf("%d桁以内の数値を入力してください。>>\n",lim);
	do{
		intp=0;decp=0;flag=0;nsign=1;isdecimal=0;

		//fgets(data,lim,stdin);//new これだと入力許容桁数で自動的に切り詰められてOK判定が出てしまう。
		scanf("%s", data) ;//old これだと、オーバーフローの可能性が捨てきれない。
		if (strlen(data) > lim) {
			flag = 2;
		}
		i = 0;j = 0;
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
				//i++;//いるか？
			}
			
			else if (flag == 0 && (data[i] >= '0' && data[i] <= '9')&&isdecimal==0) {
				intp = intp * 10 + data[i] - '0';
				printf("[db]整数部シーケンス intp=%d\n",intp);

			}
			else if(flag == 0 && (data[i] >= '0' && data[i] <= '9')&&isdecimal==1) {
				decp = decp * 10 + data[i] - '0';
				printf("[db]小数部シーケンス decp=%d\n",decp);
				j++;
			}
			else{
				if(flag == 2) {
					printf("桁が大きすぎます。再入力>>\n");
					break;
				}else{
					printf("エラー\n");
					flag = 1;
					break;
				}
			}
		}
		printf("[db]flag is %d data[i] is %c isdecimal is %d j is %d\n",flag,data[i],isdecimal,j);
		if (flag == 0) {
			dnam = nsign*( intp+ decp*pow(0.1,j) );
			printf("成功:%lf\n", dnam);
		}
	}while (flag!=0);
}