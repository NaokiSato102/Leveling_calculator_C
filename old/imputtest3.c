//http://stroll.hatenablog.com/entry/2015/07/20/221125 ����B

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void) {
	char data[255];
	int i,j, n = 0,m=0, nsign = 1, flag = 0, isdecimal=0;
	double dnam;
	printf("���͂��������񂪐��l�݂̂̎��͂��̒l��Ԃ��܂��B�������܂܂�Ă���ꍇ�̓G���[��\\�����܂��B\n");
	printf("9���ȓ��̐��l����͂��Ă��������B>>\n");
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
				printf("[db]�������V�[�P���X n=%d\n",n);

			}
			else if (flag == 0 && data[i] >= 48 && data[i] <= 57&&isdecimal==1) {
				m = m * 10 + data[i] - '0';
				printf("[db]�������V�[�P���X m=%d\n",m);
				j++;
			}
			/*else if(isdecimal==0&&flag==0&&data[i]=='.'){
				puts("[db]���͓�����");
				//�Ȃɂ����Ȃ��B���͓�����
			}*/
			else {
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
		printf("[db]flag is %d data[i] is %c isdecimal is %d j is %d\n",flag,data[i],isdecimal,j);
		if (flag == 0) {
			dnam = nsign*( (double)n+ m*pow(0.1,j) );
			printf("����:%lf\n", dnam);
		}
	}while (flag!=0);
}