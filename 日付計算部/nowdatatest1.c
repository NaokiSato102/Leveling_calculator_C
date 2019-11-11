/* header files */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* main */
int main(void) {
    time_t timer;
    struct tm *local;
	int data[3]={};

    /* Œ»ÝŽž‚ðŽæ“¾ */
    timer = time(NULL);

    local = localtime(&timer); /* ’n•ûŽž‚É•ÏŠ· */

	if(local->tm_hour < 5){
		local->tm_mday-=1;//Žž‚ª5Žž–¢–ž‚È‚ç‚Ü‚¾ð“ú‚Ì“ú‚É‚¿‚Æ‚·‚é
	}

	data[0] = local->tm_year + 1900;
	data[1] = local->tm_mon + 1;
	data[2] = local->tm_mday;

   	printf("Šg’£’n•ûŽž: ");
    printf("%4d/", data[0]);
    printf("%2d/", data[1]);
    printf("%2d ", data[2]);

    return EXIT_SUCCESS;
}