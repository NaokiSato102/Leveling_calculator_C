#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
	int y;
	int m;
	int d;
}data;



int isleapyear(int year){
	//���邤�N�Ȃ琳1���A�Ⴄ�Ȃ畉0���o�͂���ȒP�Ȋ֐��B
	//�ȒP�ȏ����Ȃ��炵������イ�g�����s��H���̂ō쐬�B
	if(year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
		return 1;
	}
	else{
		return 0;
	}
}

int ismaxday(data *a1){
	//�e���̍ő�����𒴂���=1���A�����Ă��Ȃ�=0����Ԃ��֐��B���isleapyear��������Ă���B
	const int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(a1->m==2){
		a1->d-=isleapyear(a1->y);
	}
	if(a1->d>days[a1->m-1]){
		return 1;
	}
	else{
		return 0;
	}
}


void getadvdatanow(data *a1){
    time_t timer;
    struct tm *local;

    /* ���ݎ������擾 */
    timer = time(NULL);

    local = localtime(&timer); /* �n�����ɕϊ� */

	if(local->tm_hour < 5){
		local->tm_mday-=1;//������5�������Ȃ�܂�����̓��ɂ��Ƃ���
	}

	a1->y = local->tm_year + 1900;
	a1->m = local->tm_mon + 1;
	a1->d = local->tm_mday;
}

void putd(char *format,data *a1){
	struct tm data;
	char *result;
	data.tm_year=a1->y-1900;
	data.tm_mon=a1->m-1;
	data.tm_mday=a1->d;
	result = malloc( sizeof(char)*strlen(format)*2 );
	//printf("[db]format is [%s]\n",format);
	strftime(result, strlen(format)*2 ,format ,&data );
	printf("%s\n",result);
}





void datainputer(data *a1){
	char input[12]={},sep[]="./",*tok;
	int i,fg,tmp;//data[0]�͔N�A[1]�͌��A[2]�͓��B�\���̎g���������ǂ��H
	char *endptr;
	data a2;
	a2=*a1;

	while(getchar()!='\n');
	
	for(fg=0;fg==0;){
		//printf("[db]input is [%s]\n",input);
		
		puts("���͂��Ă�");
		fgets(input,sizeof(input),stdin);
		

		if( ( input[0]=='t' || input[0]=='y' ) && input[1]=='\n' ){
			//puts("�������̓V�[�P���X");
			//printf("[debug]fg=%d input[0]=%c\n",fg,input[0]);
			getadvdatanow(&a2);
			if(input[0]=='y'){
				a2->d--;//������[�h�Ȃ����̓��t�ɂ���
			}
			fg=1;
		}
		else if(input[10]!='\n'&&strlen(input)>10){
			//printf("[db]input is [%s]\n",input);
			puts("���̓G���[�F����������́B�o�b�t�@�N���A�̂��ߓǂݔ�΂����s��");
			while(getchar()!='\n');//�ǂݔ�΂�
			//puts("[db]�ǂݔ�΂��I��");
		}
		else{
			
			//puts("�蓮���͔���");
			//printf("input[0]=%c sizeof(input)=%d",input[0],strlen(input) );
			for(i=0,fg=1;input[i]!='\n'&&i<strlen(input);++i){
				//printf("[db]i is %d\n",i);
				if(isdigit(input[i])||input[i]=='.'||input[i]=='/'){
					//printf("[db]input[%d] is OK\n",i);
				}
				else{
					fg=0;
					i = sizeof(input);//���[�v�𔲂�������B
					puts("�����Ƌ�؂蕶���ȊO�����͂��ꂽ");
				}
			}
			if(fg==1){//�蓮���͕ϊ��V�[�N�G���X
				
				//�N�̓��͔���
				tmp = (int)strtol( strtok( input, sep ),&endptr,10 );
				//printf("[db]tmp=%d endptr=[%s]\n",tmp,endptr);
								
				if(tmp<100){
					a2.y=tmp+2000;//2��:100�N�����̏ꍇ20nn�N�ƔF������B
				}
				else if(tmp<10000){
					a2.y=tmp;
				}
				else{
					puts("�G���[ 10000�N");
					fg=0;
				}

				//���̓��͔���
				tmp = (int)strtol( strtok( NULL, sep ),&endptr,10 );	
				//printf("[db]tmp=%d endptr=[%s]\n",tmp,endptr);
				if(tmp<1||12<tmp){
					puts("�G���[ �͈͊O");
					fg=0;
				}
				else{
					a2.m=tmp;
				}

				//���̓��͔���
				a2.d = (int)strtol( strtok( NULL, sep ),&endptr,10 );	
				//printf("[db]tmp=%d endptr=[%s]\n",tmp,endptr);
				if( ismaxday(&a2)||tmp<1 ){
					puts("�G���[ �͈͊O");
					fg=0;
				}
				else{
					puts("[db]day ok");
				}

				//
				printf("[db]�c��=[%s]\n",strtok( NULL, sep ) );

								
			}//�蓮���͕ϊ��V�[�N�G���X�I��
		}



	}
	//puts("[db]����");
	*a1=a2;

}


void main(){
	data a1;
	char format[]={"%Y�N%m��%d��"};

	datainputer(&a1);
	putd(format,&a1);
}
