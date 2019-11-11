/*
https://detail.chiebukuro.yahoo.co.jp/qa/question_detail/q1453529394
‚É‚Äang********‚³‚ñ‚ª‰ñ“š‚µ‚Ä‚¢‚½A‘½”{’·‰‰Z‚Æ‚¢‚¤‚à‚Ì‚ğ‚µ‚½*/
#include <stdio.h>
int main(void) {
	double	a=1*10000.0,
			b=2*1000.0,
			c=3*100.0,
			d=4*10.0,
			e=5.0,
			f=6*0.1,
			g=7*0.01,
			h=8*0.001,
			i=9*0.0001;
	printf("%20.20lf\n",a);
	printf("%20.20lf\n",b);
	printf("%20.20lf\n",c);
	printf("%20.20lf\n",d);
	printf("%20.20lf\n",e);
	printf("%20.20lf\n",f);
	printf("%20.20lf\n",g);
	printf("%20.20lf\n",h);
	printf("%20.20lf\n",i);
	printf("%20.20lf\n",a+b+c+d+e+f+g+h+i);
}