#include <stdio.h>
int main(){
	FILE *lf,*sf;
	char fname[1024],str[1024];
	int hoge,huga,piyo;
	
	hoge=0;
	sprintf(fname,"map%02d.txt",hoge);
	while( (lf = fopen(fname, "r")) != NULL ){
		hoge++;
		fclose(lf);
		sprintf(fname,"map%02d.txt",hoge);
		printf("[db]�t�@�C�����J�E���g��\n");
	}
	printf("[db]hoge is %d\n",hoge);

	for(huga=0,piyo=0;huga<hoge;huga++){
		printf("[db]huga is %d\n",huga);
		sprintf(fname,"map%02d.txt",huga);
		//printf("[debug]%s\n",fname);
		lf = fopen(fname, "r");//�t�@�C����ǂݍ��݃��[�h�ŊJ��
		piyo=0;
		while((fgets(str,256,lf))!=NULL){
       		++piyo;    // �s���J�E���g 
        	if(piyo<0&&piyo <= 1){    // �J�E���^piyo���͈͓��̎� 
            	printf("%s", str);    // 1�s�\�� 
			}
   		}
		fclose(lf);
		puts("");
	}


}