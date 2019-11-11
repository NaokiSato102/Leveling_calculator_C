#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char input[12]={},sep[]="./",*tok,ch;
	int i,fg,data[3]={};
	
	
	//i=0はループ継続 i=1は日付入力完了 i=2は今日の日付自動入力 i=3は昨日の日付自動入力

	for(fg=0;fg==0;){
		fgets(input,sizeof(input),stdin);

		
		if(input[10]=='\n'||input[8]=='\n'){
			for(i=0,fg=1;input[i]!='\n'&&i<sizeof(input);++i){
				ch=input[i];
				if(isdigit(ch)&&ch=='.'&&ch=='/'){
					printf("input[%d] is OK\n",i);
				}
				else{
					fg=0;
					puts("数字と区切り文字以外が入力された\n");
				}
			}
		}else{
			puts("inputの長さが足りなかった\n");
			while(getchar()!='\n');//読み飛ばし
			puts("読み飛ばし終了");
		}
		printf("[debug]fg=%d\n",fg);
	}
	puts("成功");

	printf("input is [%s]",input);

	for(i=0;input[i]!='\n'&&i<sizeof(input);++i){}
	printf("%dmozi\n",i);
	
	return 0;
}
