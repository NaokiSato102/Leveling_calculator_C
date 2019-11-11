//http://stroll.hatenablog.com/entry/2015/07/20/221125 を基に開発
#ifndef imputtestfunc//二重でincludeされることを防ぐ
#define imputtestfunc

#include <stdio.h>
#include <string.h>

double dnkscan(int lim) {
	char data[256];
	int i,j, inum = 0, nsign = 1, flag = 0, isdecimal=0;
	double dnum;
	//printf("[db]入力文字列が「半角数値及び正負記号,小数点」の時はその値を返します。それ以外ははエラーとなります。\n");
	printf("[db]%d桁以内の数値を入力してください。>>\n",lim);
	do{
		i = 0;//カウンタ
		j = 0;//小数点以下部分のカウンタ
		inum=0;
		nsign=1;
		flag=0;//0:成功,1:エラー,2:桁あふれ
		isdecimal=0;//

		//fgets(data,lim,stdin);//new これだと入力許容桁数で自動的に切り詰められてOK判定が出てしまう。
		scanf("%s", data) ;//old これだと、オーバーフローの可能性が捨てきれない。
		if (strlen(data) > lim) {
			flag = 2;
		}
		
		if (flag == 0 && data[0] == '+') {
			i++;
		}
		if (flag == 0 && data[0] == '-') {
			nsign = -1;
			i++;
		}
		//printf("[db]flag is %d data[i] is %c isdecimal is %d j is %d\n",flag,data[i],isdecimal,j);
		for (; i < strlen(data); i++) {
			printf("[db]flag is %d, data[i] is %c, isdecimal is %d, j is %d, i is %d \n",flag,data[i],isdecimal,j,i);

			if (flag == 0 && data[i] == '.'&&isdecimal==0) {
				isdecimal = 1;
				//i--;
			}
			else if (flag == 0 && (data[i] >= '0' && data[i] <= '9')  ) {				
					inum = inum * 10 + data[i] - '0';
					printf("[db]シーケンス inum=%d\n",inum);
					if(isdecimal==1) {
						j++;
					}
			}
			else{
				if(flag == 2) {
					printf("桁あふれエラー>>\n");
					break;
				}
				else{
					printf("エラー>>\n");
					flag = 1;
					break;
				}
			}

		}
		printf("[db]flag is %d, data[i] is %c, isdecimal is %d, j is %d, i is %d \n",flag,data[i],isdecimal,j,i);
	}while (flag!=0);
	dnum=inum;
	for(i=0,inum=1;i<j;i++){
		inum*=10;
	}
	return nsign*dnum/inum;
}
#endif