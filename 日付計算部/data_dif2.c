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
int data2mjd(int y, int m, int d){
	if(m<3){
		y-=1;
		m+=12;
	}
	return floor(365.25*y)+floor(y/400.0)-floor(y/100.0)+floor(30.59*(m-2))+d-678912;
}
int data_dif(int y1, int m1, int d1, int y2, int m2, int d2){
	return abs( data2mjd(y1,m1,d1)-data2mjd(y2,m2,d2) );
}
void main(){
	int data1[3]={},data2[3]={},data3[3]={};
	scanf("%d%d%d",&data1[0],&data1[1],&data1[2]);
	scanf("%d%d%d",&data2[0],&data2[1],&data2[2]);
	printf("%d/\n", data_dif(data1[0],data1[1],data1[2],data2[0],data2[1],data2[2]) );

}