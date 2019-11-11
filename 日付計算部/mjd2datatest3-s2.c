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
    data->tm_year=floor(a/1461.0)-1900;
    data->tm_mon =floor(b/153.0)+2;
    data->tm_mday=floor(b%153/5.0)+1;
	
    if(11 < data->tm_mon ){
        data->tm_year+=1;
        data->tm_mon-=12;
    }
	/*data->tm_year-=1900;
	data->tm_mon-=1;*/

}


void main(){
    int mjd;
    struct tm data;
    char dc[64]={};
    scanf("%d",&mjd);
    mjd2data(mjd,&data);
    puts("hoge");
    /*printf("%4d/", data.tm_year);
    printf("%2d/", data.tm_mon);
    printf("%2d \n", data.tm_mday);
	data.tm_year-=1900;
	data.tm_mon-=1;*/
	strftime(dc, 64, "%Y”N%mŒŽ%d“ú", &data);
	printf("%s\n",dc);
}