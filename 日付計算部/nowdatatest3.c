/* header files */
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



/* main */
void getadvdatanow(data *a1){
    time_t timer;
    struct tm *local;

    /* Œ»ÝŽž‚ðŽæ“¾ */
    timer = time(NULL);

    local = localtime(&timer); /* ’n•ûŽž‚É•ÏŠ· */

	if(local->tm_hour < 5){
		local->tm_mday-=1;//Žž‚ª5Žž–¢–ž‚È‚ç‚Ü‚¾ð“ú‚Ì“ú‚É‚¿‚Æ‚·‚é
	}

	a1->y = local->tm_year + 1900;
	a1->m = local->tm_mon + 1;
	a1->d = local->tm_mday;
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




int main(void) {

    data a1;
	char format[]={"%Y”N%mŒŽ%d“ú"};

    getadvdatanow(&a1);

	putd(format,&a1);

}