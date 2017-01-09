#ifndef	POKEMON_H
#define POKEMON_H
#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char *nome;
    int base;
}Move;

typedef struct{
	char *nome;
    int numero, nivel, atq, def, hp, hpmax, m;
	Move *move;
}Pokemon;

Pokemon leituraPokemon();
int estaVivo(Pokemon p);
char* nomePokemon(Pokemon *p);
int numeroPokemon(Pokemon p);
int ataque(Pokemon p1, int m, Pokemon *p2);
void curaPokemon(Pokemon *p);
int numeroGolpes(Pokemon p);
void desaloca(Pokemon *p);

#endif
