#include <stdio.h>

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



int main(){
	int year;
	scanf("%d",&year);
	if(isleapyear(year)){
		puts("うるう");
	}
	else{
		puts("うるうじゃない");
	}
}