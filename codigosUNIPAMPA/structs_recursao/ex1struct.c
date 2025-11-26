/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

    struct tipo_endereco
    {
        char rua [50];
        int numero;

    };
    
    struct ficha_pessoal
    {
        char nome [50];
        long int telefone;
        struct tipo_endereco endereco;
    };
    
  
    int main(){
        
    struct ficha_pessoal f1;
    struct tipo_endereco end1;


        printf("Insira o nome: ");
        scanf("%s", &f1.nome);
        printf("Insira o numero: ");
        scanf("%d", &f1.telefone);
        
        printf("Insira a rua: ");
        scanf("%s", &end1.rua);
        printf("Insira o numero: ");
        scanf("%d", &end1.numero);
        
        
        printf("\n %s", f1.nome);
         printf("\n%d", f1.telefone);
          printf("\n %s", end1.rua);
           printf("\n%d", end1.numero);
        
        
        
    
        return 0;
    }