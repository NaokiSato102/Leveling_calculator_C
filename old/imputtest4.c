//http://stroll.hatenablog.com/entry/2015/07/20/221125 ����ɊJ��

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
	int lim=9;
	double dnam;

	char data[1024];
	int i,j, intp = 0,decp=0, nsign = 1, flag = 0, isdecimal=0;

	printf("���͕����񂪁u���p���l�y�ѐ����L��,�����_�v�̎��͂��̒l��Ԃ��܂��B����ȊO�͂̓G���[�ƂȂ�܂��B\n");
	printf("%d���ȓ��̐��l����͂��Ă��������B>>\n",lim);
	do{
		intp=0;decp=0;flag=0;nsign=1;isdecimal=0;

		//fgets(data,lim,stdin);//new ���ꂾ�Ɠ��͋��e�����Ŏ����I�ɐ؂�l�߂���OK���肪�o�Ă��܂��B
		scanf("%s", data) ;//old ���ꂾ�ƁA�I�[�o�[�t���[�̉\�����̂Ă���Ȃ��B
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
				//i++;//���邩�H
			}
			
			else if (flag == 0 && (data[i] >= '0' && data[i] <= '9')&&isdecimal==0) {
				intp = intp * 10 + data[i] - '0';
				printf("[db]�������V�[�P���X intp=%d\n",intp);

			}
			else if(flag == 0 && (data[i] >= '0' && data[i] <= '9')&&isdecimal==1) {
				decp = decp * 10 + data[i] - '0';
				printf("[db]�������V�[�P���X decp=%d\n",decp);
				j++;
			}
			else{
				if(flag == 2) {
					printf("�����傫�����܂��B�ē���>>\n");
					break;
				}else{
					printf("�G���[\n");
					flag = 1;
					break;
				}
			}
		}
		printf("[db]flag is %d data[i] is %c isdecimal is %d j is %d\n",flag,data[i],isdecimal,j);
		if (flag == 0) {
			dnam = nsign*( intp+ decp*pow(0.1,j) );
			printf("����:%lf\n", dnam);
		}
	}while (flag!=0);
}