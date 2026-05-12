#include <stdio.h>

int main(void){
	
	FILE *fptr;
	char ch;
	
	if ((fptr = fopen("exercicio1.txt", "w")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.");
		return 1;
	}
	
	while((ch=getchar()) != '\n'){
			fputc(ch,fptr);
	}
	
	fclose(fptr);
	
	
return 0;
}
