#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	char input[12]={},sep[]="./",*tok,ch;
	int i,fg,data[3]={};
	
	
	//i=0�̓��[�v�p�� i=1�͓��t���͊��� i=2�͍����̓��t�������� i=3�͍���̓��t��������

	for(fg=0;fg==0;){
		printf("[db]input is [%s]\n",input);

		
		puts("[db]���͂��Ă�");
		fgets(input,sizeof(input),stdin);
		
		ch=input[0];
		if( (ch=='t'||ch=='y')&&input[1]=='\n' ){
			puts("�������͔���");
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
			puts("�蓮���͔���");
			for(i=0,fg=1;input[i]!='\n'&&i<sizeof(input);++i){
				printf("[db]i is %d\n",i);
				ch=input[i];
				if(isdigit(ch)||ch=='.'||ch=='/'){
					//printf("[db]input[%d] is OK\n",i);
				}
				else{
					fg=0;
					i = sizeof(input);//���[�v�𔲂�������B
					puts("�����Ƌ�؂蕶���ȊO�����͂��ꂽ");
				}
			}
		}
		else if(input[10]!='\n'&&strlen(input)>=10){
			printf("[db]input is [%s]\n",input);
			puts("���̓G���[�F����������́B�o�b�t�@�N���A�̂��ߓǂݔ�΂����s��");
			while(getchar()!='\n');//�ǂݔ�΂�
			puts("�ǂݔ�΂��I��");
		}	
		else{
			puts("���̓G���[�F��`�O����");			
		}
		puts("������������");
		printf("[debug]fg=%d ch=%c\n",fg,ch);
		
		ch='\0';
		printf("[db]input is [%s]\n",input);

		

		 

	}
	puts("����");

	printf("input is [%s]\n",input);

	for(i=0;input[i]!='\n'&&i<sizeof(input);++i){}
	printf("%dmozi\n",i);
	
	return 0;
}
