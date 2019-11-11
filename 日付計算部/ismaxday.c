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



int isleapyear(int year){
	//うるう年なら正1を、違うなら負0を出力する簡単な関数。
	//簡単な処理ながらしょっちゅう使うし行を食うので作成。
	if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return 1;
	}
	else{
		return 0;
	}
}

int ismaxday(data *a1){
	//各月の最大日数を超えた=1か、超えていない=0かを返す関数。上のisleapyearを内封している。
	const int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(a1->m==2){
		a1->d-=isleapyear(a1->y);
	}
	if(a1->d>days[a1->m-1]){
		return 1;
	}
	else{
		return 0;
	}
}


int main(){
	data a1;
	scanf("%d%d%d",&a1.y,&a1.m,&a1.d);
	if(ismaxday(&a1) ){
		puts("超えた");
	}
	else{
		puts("越えなかった");
	}
	printf("%d.%d.%d\n",a1.y,a1.m,a1.d);


}