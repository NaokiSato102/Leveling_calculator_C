#include <stdio.h>

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



int main(){
	int year;
	scanf("%d",&year);
	if(isleapyear(year)){
		puts("���邤");
	}
	else{
		puts("���邤����Ȃ�");
	}
}