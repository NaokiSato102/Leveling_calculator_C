/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* main */
void getadvdatanow(int *data){
    time_t timer;
    struct tm *local;

    /* ���ݎ������擾 */
    timer = time(NULL);

    local = localtime(&timer); /* �n�����ɕϊ� */

	if(local->tm_hour < 5){
		local->tm_mday-=1;//������5�������Ȃ�܂�����̓��ɂ��Ƃ���
	}

	data[0] = local->tm_year + 1900;
	data[1] = local->tm_mon + 1;
	data[2] = local->tm_mday;
}

int main(void) {
    int data[3]={};
    getadvdatanow(data);
   	printf("�g���n�����t: ");
    printf("%4d/", data[0]);
    printf("%2d/", data[1]);
    printf("%2d ", data[2]);

}