#include <stdio.h>

int main(void){
	
	FILE *fptr;
	char ch;
	
	if ((fptr = fopen("exercicio1.txt", "r")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.");
		return 1;
	}
	
	while((ch=fgetc(fptr)) != EOF){
		printf("%c", ch);
	}
	
	fclose(fptr);
	
	
return 0;
}

