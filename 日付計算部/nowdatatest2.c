/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* main */
void getadvdatanow(int *data){
    time_t timer;
    struct tm *local;

    /* 現在時刻を取得 */
    timer = time(NULL);

    local = localtime(&timer); /* 地方時に変換 */

	if(local->tm_hour < 5){
		local->tm_mday-=1;//時刻が5時未満ならまだ昨日の日にちとする
	}

	data[0] = local->tm_year + 1900;
	data[1] = local->tm_mon + 1;
	data[2] = local->tm_mday;
}

int main(void) {
    int data[3]={};
    getadvdatanow(data);
   	printf("拡張地方日付: ");
    printf("%4d/", data[0]);
    printf("%2d/", data[1]);
    printf("%2d ", data[2]);

}