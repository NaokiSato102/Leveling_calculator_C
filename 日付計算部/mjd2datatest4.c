#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct{
	int y;
	int m;
	int d;
}data;



void mjd2data(int mjd,  data *a1){
    int n, a, b;
	n=mjd+678881;
    //printf("n=%d",n);
    a=4*n +3 +4*floor( 3/4.0* floor( 4*(n+1)/146067.0 ) );
    b=5*floor(a%1461/4.0 )+2;
    a1->y=floor(a/1461.0);
    a1->m =floor(b/153.0)+3;
    a1->d=floor(b%153/5.0)+1;
    if(12 < a1->m ){
        a1->y+=1;
        a1->m-=12;
    }
}
void putd(char *format,data *a1){
	struct tm data;
	char *result;
	data.tm_year=a1->y-1900;
	data.tm_mon=a1->m-1;
	data.tm_mday=a1->d;
	result = malloc( sizeof(char)*strlen(format)*2 );
	//printf("[db]format is [%s]\n",format);
	strftime(result, strlen(format)*2 ,format ,&data );
	printf("%s\n",result);
}



void main(){
    int mjd;
    data a1;
	char format[]={"%Y”N%mŒŽ%d“ú"};
    scanf("%d",&mjd);
    mjd2data(mjd,&a1);
    puts("hoge");
	putd(format,&a1);
}