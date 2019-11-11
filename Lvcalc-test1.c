#include <stdio.h>
#include "Lvlist.h"
int main(){
	int lv,next,acclv;

	printf("現在のLvは:");
	scanf("%d",&lv);
	printf("次のLvまでの必要EXPは:");
	scanf("%d",&next);

	printf("現在の累計EXPは%dです。",lvlist[lv]-next);
	//一つ上のLvを参照する+1と、カウント開始をずらす-1とが相殺して+-0である。




	
}