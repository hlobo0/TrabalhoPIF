#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include "forca.c"
#include "cli-lib-main/keyboard.c"
#include "cli-lib-main/screen.c"
#include "cli-lib-main/timer.c"

char palavrasecreta[TAMANHO_PALAVRA];
partida jogo;
pontuacao jogo_pontuacao;

int main(void){

    /*funcao para printar na tela o comeco do jogo, apertar alguma tecla para comecar*/

    escolhepalavra(palavrasecreta);

    inserenome();
}

void alocanome(){
    char buffer[100];
    printf("Digite seu nome: ");
    scanf("%99s", buffer);

    jogo_pontuacao.nome = malloc(strlen(buffer)+1);

    strcpy(jogo_pontuacao.nome, buffer);
}

int nomevalido(){
    bool nome_valido = true;
    for(int i=0; jogo_pontuacao.nome[i] != '\0'; i++){
        if(!isalpha(jogo_pontuacao.nome[i])){
            nome_valido = false;
            break;
        }
        jogo_pontuacao.nome[i] = toupper(jogo_pontuacao.nome[i]); 
    }
    if(!nome_valido){
        printf("Por favor, digite um nome válido apenas com letras do alfabeto.\n");
        free(jogo_pontuacao.nome);
        return 0;
    }else{
        printf("Bem-vindo, %s!\n", jogo_pontuacao.nome);
        return 1;
    }
}

void inserenome(){
    do{
        alocanome();
    }while(!nomevalido());
}