#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char input[12]={},sep[]="./",*tok,ch;
	int i,fg,data[3]={};
	
	
	//i=0�̓��[�v�p�� i=1�͓��t���͊��� i=2�͍����̓��t�������� i=3�͍���̓��t��������

	for(fg=0;fg==0;){
		fgets(input,sizeof(input),stdin);
		
		ch=input[0];
		if( (ch=='t'||ch=='y')&&input[1]=='\n' ){
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
			puts("[db]hoge");
			for(i=0,fg=1;input[i]!='\n'&&i<sizeof(input);++i){
				printf("[db]i is %d",i);
				ch=input[i];
				if(isdigit(ch)||ch=='.'||ch=='/'){
					printf("input[%d] is OK\n",i);
				}
				else{
					fg=0;
					i = sizeof(input);//���[�v�𔲂�������B
					puts("�����Ƌ�؂蕶���ȊO�����͂��ꂽ");
				}
			}
		}else{
			puts("input�̒���������Ȃ�����");
			while(getchar()!='\n');//�ǂݔ�΂�
		}
		printf("[debug]fg=%d\n",fg);
	}
	puts("����");

	printf("input is [%s]",input);

	for(i=0;input[i]!='\n'&&i<sizeof(input);++i){}
	printf("%dmozi\n",i);
	
	return 0;
}
