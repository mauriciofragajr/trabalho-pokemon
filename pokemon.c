#include<stdio.h>
#include "pokemon.h"

Pokemon leituraPokemon(){

	Pokemon p;
	int i;

	/**** ALOCANDO PARA O NOME DO POKEMON****/
	p.nome = (char *) malloc(100*sizeof(char));

    printf("Digite o nome do pokemon:\n");
	scanf("%s",p.nome);
	printf("Digite o numero do pokemon:\n");
	scanf("%d",&p.numero);
	printf("Digite o nivel do pokemon:\n");
	scanf("%d",&p.nivel);
	printf("Digite os valores de ataque, defesa e hp do pokemon:\n");
	scanf("%d %d %d",&p.atq,&p.def,&p.hp);

	printf("Digite o numero de golpes do pokemon:\n");
	scanf("%d",&p.m);

    /**** ALOCANDO ESPAÇO NA MEMÓRIA PARA OS GOLPES DE ACORDO COM A QUANTIDADE CERTA ****/
	p.move = (Move *) malloc(p.m * sizeof(Move));

	for (i = 0; i < p.m ; i++){
        printf("Digite o nome do golpe do pokemon:\n");

        /**** ALOCANDO PARA O NOME DO GOLPE ****/
        p.move[i].nome = (char *) malloc(100*sizeof(char));

        scanf("%s",p.move[i].nome);
        printf("Digite o valor base do golpe do pokemon:\n");
        scanf("%d",&p.move[i].base);
	}

	p.hpmax = p.hp;
	return p;
}
int estaVivo(Pokemon p){
	if (p.hp > 0) return 1;
	else return 0;
}
char* nomePokemon(Pokemon *p){
    char* n = p->nome;
	return n;
}
int numeroPokemon(Pokemon p){
	return p.numero;
}
int ataque(Pokemon p1, int m, Pokemon *p2){
    int dano;
	dano = ( ( (2*(float)p1.nivel+10) / 250 ) * ((float)p1.atq/(*p2).def*p1.move[m-1].base) + 2 ) * 4;
	(*p2).hp = (*p2).hp - dano;
	return dano;
}
void curaPokemon(Pokemon *p){
    p->hp = p->hpmax;
}
int numeroGolpes(Pokemon p){
    return p.m;
}

/**** FUNÇÃO CRIADA PARA O FREE DE TODOS OS PONTEIROS DO POKEMON ****/
void desaloca(Pokemon *p){
    int i;
    free((*p).nome);
    for (i = 0; i < (*p).m ; i++) free((*p).move[i].nome);
    free((*p).move);
}

