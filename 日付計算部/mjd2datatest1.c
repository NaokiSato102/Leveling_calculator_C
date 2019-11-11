#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void mjd2data(int mjd, int *data){
	int n, a, b;
	n=mjd+678881;
	//printf("n=%d",n);
	a=4*n +3 +4*floor( 3/4.0* floor( 4*(n+1)/146067.0 ) );
	b=5*floor(a%1461/4.0 )+2;
	data[0]=floor(a/1461.0);
	data[1]=floor(b/153.0)+3;
	data[2]=floor(b%153/5.0)+1;
	if(12<data[1]){
		data[0]+=1;
		data[1]-=12;
	}
}
void main(){
	int mjd,data[3]={};
	scanf("%d",&mjd);
	mjd2data(mjd,data);
	printf("%d/%d/%d\n",data[0],data[1],data[2]);
}