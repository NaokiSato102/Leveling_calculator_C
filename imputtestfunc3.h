//http://stroll.hatenablog.com/entry/2015/07/20/221125 ����ɊJ��
#ifndef imputtestfunc//��d��include����邱�Ƃ�h��
#define imputtestfunc

#include <stdio.h>
#include <string.h>

double dnkscan(int lim) {
	char data[256];
	int i,j, inum = 0, nsign = 1, flag = 0, isdecimal=0;
	double dnum;
	//printf("[db]���͕����񂪁u���p���l�y�ѐ����L��,�����_�v�̎��͂��̒l��Ԃ��܂��B����ȊO�͂̓G���[�ƂȂ�܂��B\n");
	printf("[db]%d���ȓ��̐��l����͂��Ă��������B>>\n",lim);
	do{
		i = 0;//�J�E���^
		j = 0;//�����_�ȉ������̃J�E���^
		inum=0;
		nsign=1;
		flag=0;//0:����,1:�G���[,2:�����ӂ�
		isdecimal=0;//

		//fgets(data,lim,stdin);//new ���ꂾ�Ɠ��͋��e�����Ŏ����I�ɐ؂�l�߂���OK���肪�o�Ă��܂��B
		scanf("%s", data) ;//old ���ꂾ�ƁA�I�[�o�[�t���[�̉\�����̂Ă���Ȃ��B
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
					printf("[db]�V�[�P���X inum=%d\n",inum);
					if(isdecimal==1) {
						j++;
					}
			}
			else{
				if(flag == 2) {
					printf("�����ӂ�G���[>>\n");
					break;
				}
				else{
					printf("�G���[>>\n");
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