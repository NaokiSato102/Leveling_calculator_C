#include <stdio.h>
typedef struct{
	int n;
	double sum_x;
	double sum_y;
	double sum_xx;
	double sum_xy;
	double a0;
	double a1;
} lsmdata;



lsmdata lsm(double *x, double *y, int N){
	int i;
	lsmdata hoge={};

	for (i=0;i<N;i++){
		hoge.sum_x+=x[i];
		hoge.sum_y+=y[i];
		hoge.sum_xx+=x[i]*x[i];
		hoge.sum_xy+=x[i]*y[i];
	}
	hoge.n=N;
	hoge.a0 = (hoge.sum_y*hoge.sum_xx-hoge.sum_x*hoge.sum_xy) / (hoge.n*hoge.sum_xx-hoge.sum_x*hoge.sum_x);
	hoge.a1 = (hoge.n*hoge.sum_xy-hoge.sum_x*hoge.sum_y) / (hoge.n*hoge.sum_xx-hoge.sum_x*hoge.sum_x);
	printf("[db]a0=%f a1=%f\n", hoge.a0, hoge.a1);
	return hoge;
}
 
int main(){
	double x[]={1.1,2.3,2.8,4.2,5.1};
	double y[]={0.7,1.9,3.1,4.2,5.6};
	lsmdata hoge={};
	
	// データの個数
	int N = 5; 
	
	// 最小二乗法の計算
	hoge=lsm(x,y,N);

	printf("a0=%f a1=%f\n", hoge.a0, hoge.a1);
	
	return 0;
}