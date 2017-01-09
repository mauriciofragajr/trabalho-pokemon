#include <stdlib.h>
#include <stdio.h>
#include "pokemon.h"

int main (){
    /**** PEGANDO O NÚMERO DE POKEMONS E ALOCANDO ESPAÇO NA MEMÓRIA ****/
    int p, i;
    printf("Digite o numero total de pokemons:\n");
    scanf("%d",&p);
    Pokemon *pont = (Pokemon *) malloc(p * sizeof(Pokemon));
    /**** COLOCANDO TODOS OS POKEMONS EM UM VETOR DE POKEMONS ****/
    for ( i = 0 ; i < p ; i++){
        pont[i] = leituraPokemon();
    }
    /**** INICIANDO O LOOP DO PRINCIPAL ****/
    printf("\n");
    char op = 'S';
    while ( op == 'S' ){
        int cont = 2;

        int primeiro,segundo;
        printf("Digite o numero do primeiro pokemon a atacar:\n");
        scanf("%d",&primeiro);
        printf("Digite o numero do segundo pokemon a atacar:\n");
        scanf("%d",&segundo);

        /**** CRIANDO OS POKEMONS QUE IRÃO BATALHA NA SEQUÊNCIA DE ACORDO COM O ESCOLHIDO ****/
        Pokemon p1 = pont[primeiro-1];
        Pokemon p2 = pont[segundo-1];

        /**** INICIANDO BATALHA ****/
        while(estaVivo(p1) && estaVivo(p2)){
            int m;
            if ( cont % 2 == 0 ){ // QUANDO CONT FOR PAR SIGNIFICA QUE O PRIMEIRO POKEMON ATACA
                printf("O pokemon %s esta atacando.\n",nomePokemon(&p1));
                printf("Digite o movimento que ele deve usar (1 a %d):\n",numeroGolpes(p1));
                scanf("%d",&m);
                printf("Dano causado em %s = %d\n",nomePokemon(&p2),ataque(p1,m,&p2));
            }
            else{ // QUANDO CONT FOR ÍMPAR SIGNIFICA QUE O SEGUNDO POKEMON ATACA
                printf("O pokemon %s esta atacando.\n",nomePokemon(&p2));
                printf("Digite o movimento que ele deve usar (1 a %d):\n",numeroGolpes(p2));
                scanf("%d",&m);
                printf("Dano causado em %s = %d\n",nomePokemon(&p1),ataque(p2, m, &p1));
            }
            cont++; // PASSANDO UMA RODADA
        }
        /**** QUANDO O PROGRAMA CHEGAR NESSA LINHA SIGNIFICA QUE ALGUM NOS POKEMONS ESTÁ MORTO ****/
        printf("Fim da batalha!\n");

        /**** VERIFICANDO O VENCEDOR ****/
        if (cont % 2 == 0)
            printf("O pokemon %s (# %d) venceu apos %d movimentos!\n",nomePokemon(&p2),numeroPokemon(p2),cont-2);
        else
            printf("O pokemon %s (# %d) venceu apos %d movimentos!\n",nomePokemon(&p1),numeroPokemon(p1),cont-2);

        /**** VERIFICANDO SE VAI TER OUTRA BATALHA ****/
        printf("Deseja simular outra batalha?\n");
        scanf("\n%c",&op);

        /**** CURANDO OS POKEMONS ****/
        curaPokemon(&p1);
        curaPokemon(&p2);

        printf("\n");
    }
    /**** PARA TODO MALLOC, HÁ UM FREE ( LEVANDO ISSO PARA VIDA ) ****/

    for ( i = 0; i < p; i++) desaloca(&pont[i]); //Desalocando os ponteiros de cada Pokemon
    free(pont); //Desalocando o vetor de Pokemons

	return 0;
}
