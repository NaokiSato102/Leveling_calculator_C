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
	//���邤�N�Ȃ琳1���A�Ⴄ�Ȃ畉0���o�͂���ȒP�Ȋ֐��B
	//�ȒP�ȏ����Ȃ��炵������イ�g�����s��H���̂ō쐬�B
	if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return 1;
	}
	else{
		return 0;
	}
}

int ismaxday(data *a1){
	//�e���̍ő�����𒴂���=1���A�����Ă��Ȃ�=0����Ԃ��֐��B���isleapyear��������Ă���B
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
		puts("������");
	}
	else{
		puts("�z���Ȃ�����");
	}
	printf("%d.%d.%d\n",a1.y,a1.m,a1.d);


}