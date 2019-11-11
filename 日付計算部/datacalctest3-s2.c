#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char input[12]={},sep[]="./",*tok,ch;
	int i,fg,data[3]={};
	
	
	//i=0はループ継続 i=1は日付入力完了 i=2は今日の日付自動入力 i=3は昨日の日付自動入力

	for(fg=0;fg==0;){
		printf("[db]input is [%s]\n",input);

		
		puts("[db]入力してね");
		fgets(input,sizeof(input),stdin);
		if()
		
		

		 

	}
	puts("成功");

	printf("input is [%s]\n",input);

	for(i=0;input[i]!='\n'&&i<sizeof(input);++i){}
	printf("%dmozi\n",i);
	
	return 0;
}
