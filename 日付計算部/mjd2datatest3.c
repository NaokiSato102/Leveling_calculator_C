#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void mjd2data(int mjd, struct tm *data){
    int n, a, b;
	n=mjd+678881;
    //printf("n=%d",n);
    a=4*n +3 +4*floor( 3/4.0* floor( 4*(n+1)/146067.0 ) );
    b=5*floor(a%1461/4.0 )+2;
    data->tm_year=floor(a/1461.0);
    data->tm_mon =floor(b/153.0)+3;
    data->tm_mday=floor(b%153/5.0)+1;
    if(12 < data->tm_mon ){
        data->tm_year+=1;
        data->tm_mon-=12;
    }

}
/*
char printd(struct tm *data, int fg){//fg=0なら4桁、1なら2桁
	if(fg){
		data->tm_year-=2000;
	}
	sprintf(a,"%d/%d/%d",data->tm_year,data->tm_mon,data->tm_mday);
	return a;
	tm構造体を使う場合、これの上位のstrftime(http://www.c-tipsref.com/reference/time/strftime.html)があるので無用である。
}*/


void main(){
    int mjd;
    struct tm data;
    char dc;
    scanf("%d",&mjd);
    mjd2data(mjd,&data);
    puts("hoge");
    /*printf("%4d/", data.tm_year);
    printf("%2d/", data.tm_mon);
    printf("%2d ", data.tm_mday);*/
	strftime(dc, 128, "%Y年%m月%d日", data);
	printf("%s\n",dc);
}