#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int data2mjd(int y, int m, int d){
	if(m<3){
		y-=1;
		m+=12;
	}
	return floor(365.25*y)+floor(y/400.0)-floor(y/100.0)+floor(30.59*(m-2))+d-678912;
}
void main(){
	int y, m, d;
	scanf("%d%d%d",&y,&m,&d);
	printf("%d",data2mjd(y, m, d));
}