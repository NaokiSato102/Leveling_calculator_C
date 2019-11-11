#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

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

int ismaxday(int y, int m, int d){
	//各月の最大日数を超えた=1か、超えていない=0かを返す関数。上のisleapyearを内封している。
	const int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(m==2){
		d-=isleapyear(y);
	}
	if(d>days[m-1]){
		return 1;
	}
	else{
		return 0;
	}
}

void getadvdatanow(int *data){
    time_t timer;
    struct tm *local;

    /* 現在時刻を取得 */
    timer = time(NULL);

    local = localtime(&timer); /* 地方時に変換 */

	if(local->tm_hour < 5){
		local->tm_mday-=1;//時刻が5時未満ならまだ昨日の日にちとする
	}

	data[0] = local->tm_year + 1900;
	data[1] = local->tm_mon + 1;
	data[2] = local->tm_mday;
}


void datainputer(int *data){
	char input[12]={},sep[]="./",*tok;
	int i,fg,tmp;//data[0]は年、[1]は月、[2]は日。構造体使った方が良い？
	char *endptr;

	while(getchar()!='\n');
	
	for(fg=0;fg==0;){
		//printf("[db]input is [%s]\n",input);
		
		puts("入力してね");
		fgets(input,sizeof(input),stdin);
		

		if( ( input[0]=='t' || input[0]=='y' ) && input[1]=='\n' ){
			//puts("自動入力シーケンス");
			//printf("[debug]fg=%d input[0]=%c\n",fg,input[0]);
			getadvdatanow(data);
			if(input[0]=='y'){
				data[2]--;//昨日モードなら昨日の日付にする
			}
			fg=1;
		}
		else if(input[10]!='\n'&&strlen(input)>10){
			//printf("[db]input is [%s]\n",input);
			puts("入力エラー：長すぎる入力。バッファクリアのため読み飛ばしを行う");
			while(getchar()!='\n');//読み飛ばし
			//puts("[db]読み飛ばし終了");
		}
		else{
			
			//puts("手動入力判定");
			//printf("input[0]=%c sizeof(input)=%d",input[0],strlen(input) );
			for(i=0,fg=1;input[i]!='\n'&&i<strlen(input);++i){
				//printf("[db]i is %d\n",i);
				if(isdigit(input[i])||input[i]=='.'||input[i]=='/'){
					//printf("[db]input[%d] is OK\n",i);
				}
				else{
					fg=0;
					i = sizeof(input);//ループを抜けさせる。
					puts("数字と区切り文字以外が入力された");
				}
			}
			if(fg==1){//手動入力変換シークエンス
				
				//年の入力判定
				tmp = (int)strtol( strtok( input, sep ),&endptr,10 );
				//printf("[db]tmp=%d endptr=[%s]\n",tmp,endptr);
								
				if(tmp<100){
					data[0]=tmp+2000;//2桁:100年未満の場合20nn年と認識する。
				}
				else if(tmp<10000){
					data[0]=tmp;
				}
				else{
					puts("エラー 10000年");
					fg=0;
				}

				//月の入力判定
				tmp = (int)strtol( strtok( NULL, sep ),&endptr,10 );	
				//printf("[db]tmp=%d endptr=[%s]\n",tmp,endptr);
				if(tmp<1||12<tmp){
					puts("エラー 範囲外");
					fg=0;
				}
				else{
					data[1]=tmp;
				}

				//日の入力判定
				tmp = (int)strtol( strtok( NULL, sep ),&endptr,10 );	
				//printf("[db]tmp=%d endptr=[%s]\n",tmp,endptr);
				
				if( ismaxday(data[0], data[1], tmp)||tmp<1 ){
					puts("エラー 範囲外");
					fg=0;
				}
				else{
					data[2]=tmp;
				}

				//
				printf("[db]残り=[%s]\n",strtok( NULL, sep ) );

								
			}//手動入力変換シークエンス終了
		}



	}
	//puts("[db]成功");


}


void main(){
	int data[3]={};
	datainputer(data);
	printf("%d/%d/%d\n",data[0],data[1],data[2]);

}
