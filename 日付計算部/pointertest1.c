#include <stdio.h>
void testp (int *data){
	data[0]=1;
	data[1]=2;
	data[2]=3;
}
void main(){
	int data[3]={},i;
	testp(data);
	printf("[%d][%d][%d]",data[0], data[1], data[2]);

}