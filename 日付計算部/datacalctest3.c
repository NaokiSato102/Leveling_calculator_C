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
		
		ch=input[0];
		if( (ch=='t'||ch=='y')&&input[1]=='\n' ){
			puts("自動入力判別");
			printf("[debug]fg=%d ch=%c\n",fg,ch);
			switch (ch) {
				case 't' :
					fg=2;
					break;
				case 'y' :
					fg=3;
					break;
			}
		}		
		else if(input[10]=='\n'||input[8]=='\n'){
			printf("[debug]fg=%d ch=%c\n",fg,ch);
			puts("手動入力判定");
			for(i=0,fg=1;input[i]!='\n'&&i<sizeof(input);++i){
				printf("[db]i is %d\n",i);
				ch=input[i];
				if(isdigit(ch)||ch=='.'||ch=='/'){
					//printf("[db]input[%d] is OK\n",i);
				}
				else{
					fg=0;
					i = sizeof(input);//ループを抜けさせる。
					puts("数字と区切り文字以外が入力された");
				}
			}
		}
		else if(input[10]!='\n'&&strlen(input)>=10){
			printf("[db]input is [%s]\n",input);
			puts("入力エラー：長すぎる入力。バッファクリアのため読み飛ばしを行う");
			while(getchar()!='\n');//読み飛ばし
			puts("読み飛ばし終了");
		}	
		else{
			puts("入力エラー：定形外入力");			
		}
		puts("条件文抜けた");
		printf("[debug]fg=%d ch=%c\n",fg,ch);
		
		ch='\0';
		printf("[db]input is [%s]\n",input);

		

		 

	}
	puts("成功");

	printf("input is [%s]\n",input);

	for(i=0;input[i]!='\n'&&i<sizeof(input);++i){}
	printf("%dmozi\n",i);
	
	return 0;
}
