#include <stdio.h>

int main(){
	//ファイル構造体へのポインタを宣言
	//読込み用、書き込み用それぞれ宣言する
	FILE *fp;

	if( (fp = fopen("file-a-test.txt", "a") ) == NULL ){//ファイルを追加書き込みモードで開く
		//fprintf(stderr, "%sの追加書き込みモードでのオープンに失敗しました.\n", filename);
		return -1;
	}
	fputs("hoge\n",fp);
	fclose(fp);

	return 0;
}
