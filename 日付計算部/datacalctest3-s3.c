#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
	char input[12]={},sep[]="./",*tok,ch;
	int i,fg,tmp,data[3]={};//data[0]�͔N�A[1]�͌��A[2]�͓�
	char *endptr;
	
	
	//i=0�̓��[�v�p�� i=1�͓��t���͊��� i=2�͍����̓��t�������� i=3�͍���̓��t��������

	for(fg=0;fg==0;){
		printf("[db]input is [%s]\n",input);

		
		puts("[db]���͂��Ă�");
		fgets(input,sizeof(input),stdin);
		

		if( ( input[0]=='t' || input[0]=='y' ) && input[1]=='\n' ){
			puts("�������̓V�[�P���X�̔���");
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
			puts("���̓G���[�F����������́B�o�b�t�@�N���A�̂��ߓǂݔ�΂����s��");
			while(getchar()!='\n');//�ǂݔ�΂�
			puts("�ǂݔ�΂��I��");
		}
		else{
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
			if(fg==1){
				tmp = (int)strtol( strtok( input, sep ),&endptr,10 );
				printf("tmp=%d endptr=[%s]\n",tmp,endptr);
				if( 10000 >= tmp ){
					puts("hoge");
				}
				for(i=0; tok != NULL;i++ ){
					tok = strtok( NULL, sep );  /* 2��ڈȍ~ */
				}
			}
		}
		

		 

	}
	puts("����");

	printf("input is [%s]\n",input);

	for(i=0;input[i]!='\n'&&i<sizeof(input);++i){}
	printf("%dmozi\n",i);
	
	return 0;
}
