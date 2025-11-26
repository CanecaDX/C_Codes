 #include <stdio.h>

int main(){

	int idade, opiniao, qtdRegular = 0, qtdBom = 0, qtdExcelente = 0, somaIdades = 0;


	for(int x = 0; x < 20; x++){
		printf("informe sua idade: ");
		scanf("%d", &idade);
		do{

		printf("\ninforme sua opniao: \n1 - Regular \n2 - Bom \n3 - Exelente \n: ");
		scanf("%d", &opiniao);
	} while(opiniao != 1 && opiniao != 2 && opiniao != 3);


		switch(opiniao){
			case 1:
				qtdRegular++;
				break;
			case 2:
				qtdBom++;
				break;
			case 3:
				qtdExcelente++;
				somaIdades += idade;
				break;

		}


	}

	float mediaIdades = somaIdades / qtdExcelente;

	printf("\n Media de idade das pessoas que votaram em excelente = %.2f", mediaIdades );
	printf("\n quanidade de pessoas que votaram em regular = %df", qtdRegular );

	float percentual = qtdBom * 100 / 5;

	printf("\n Percentual de pessoas que votaram em bom = %.2f %%", percentual);

return 0;
}
