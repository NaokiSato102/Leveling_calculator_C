#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
	char input[12]={},sep[]="./",*tok,ch;
	int i,fg,tmp,data[3]={};//data[0]は年、[1]は月、[2]は日
	char *endptr;
	
	
	//i=0はループ継続 i=1は日付入力完了 i=2は今日の日付自動入力 i=3は昨日の日付自動入力

	for(fg=0;fg==0;){
		printf("[db]input is [%s]\n",input);

		
		puts("[db]入力してね");
		fgets(input,sizeof(input),stdin);
		

		if( ( input[0]=='t' || input[0]=='y' ) && input[1]=='\n' ){
			puts("自動入力シーケンスの判別");
			printf("[debug]fg=%d input[0]=%c\n",fg,input[0]);
			switch (input[0]) {
				case 't' :
					fg=2;
					break;
				case 'y' :
					fg=3;
					break;
			}
		}
		else if(input[10]!='\n'&&strlen(input)>=10){
			printf("[db]input is [%s]\n",input);
			puts("入力エラー：長すぎる入力。バッファクリアのため読み飛ばしを行う");
			while(getchar()!='\n');//読み飛ばし
			puts("読み飛ばし終了");
		}
		else{
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
			if(fg==1){
				tmp = (int)strtol( strtok( input, sep ),&endptr,10 );
				printf("tmp=%d endptr=[%s]\n",tmp,endptr);
				if( 10000 >= tmp ){
					puts("hoge");
				}
				for(i=0; tok != NULL;i++ ){
					tok = strtok( NULL, sep );  /* 2回目以降 */
				}
			}
		}
		

		 

	}
	puts("成功");

	printf("input is [%s]\n",input);

	for(i=0;input[i]!='\n'&&i<sizeof(input);++i){}
	printf("%dmozi\n",i);
	
	return 0;
}
