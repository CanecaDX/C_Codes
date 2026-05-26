#ifndef MUSICA_H
#define MUSICA_H

#include <stdlib.h>
#include <stdio.h>

typedef struct{
	char artista[256];
	int codigo;
	char titulo[256];
	char letra[256];
	int execucoes;
} musica;

#endif
