#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char input[12]={},sep[]="./",*tok,ch;
	int i,fg,data[3]={};
	
	
	//i=0�̓��[�v�p�� i=1�͓��t���͊��� i=2�͍����̓��t�������� i=3�͍���̓��t��������

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
					puts("�����Ƌ�؂蕶���ȊO�����͂��ꂽ\n");
				}
			}
		}else{
			puts("input�̒���������Ȃ�����\n");
			while(getchar()!='\n');//�ǂݔ�΂�
			puts("�ǂݔ�΂��I��");
		}
		printf("[debug]fg=%d\n",fg);
	}
	puts("����");

	printf("input is [%s]",input);

	for(i=0;input[i]!='\n'&&i<sizeof(input);++i){}
	printf("%dmozi\n",i);
	
	return 0;
}
