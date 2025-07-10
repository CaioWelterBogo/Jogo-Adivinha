#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void escolheModo(int *opcao){

    do{
        printf("=========Jogo da Adivinhação=========\n")/
        printf("Selecione o modo:\n[ 1 ] - Usuário Adivinha\n[ 2 ] - Computador Adivinha\n\n"); 
        printf("Sua Escolha: ");
        scanf("%d", opcao);
        printf("%d\n", *opcao);
    }while(*opcao != 1 && *opcao != 2);

}

void usuarioAdivinha(){
    int tentativaUsuario = 0;
    int numeroComputador;
    int quantidadeTentativas = 0;
    srand(time(NULL));

    do{
       numeroComputador = rand() % 1025; 
    }while(numeroComputador == 0);
    
    printf("\n-- O computador pensou em um numero entre 1 e 1024. Tente Adivinhar! --\n\n");
    while(tentativaUsuario != numeroComputador){

        printf("\nTentativa %d\n", ++quantidadeTentativas);
        printf("Qual o seu palpite: ");
        scanf("%d", &tentativaUsuario);

        if(numeroComputador > tentativaUsuario){
            printf("O numero que eu pensei é maior que %d", tentativaUsuario);
        }
        else if(numeroComputador < tentativaUsuario){
            printf("O numero que eu pensei é menor que %d", tentativaUsuario);
        }
        else{
            printf("Parabéns! Eu pensei no numero %d\n", numeroComputador);
            printf("Você precisou de %d Tentativas para acertar.", quantidadeTentativas);
        }
    }
}

void computadorAdivinha(){
    int numeroUsuario;
    int tentativaComputador;
    int quantidadeTentativas = 0;
    int parametro = 0;
    int numMaximo = 1024;
    int numMinimo = 0;

    printf("\n-- Eu vou tentar acertar o seu número --\n");
    sleep(2);
    printf("Pense em um número entre 1 e 1024\n\n");
    sleep(1);
    printf("Utilize os seguintes paramêtros para me ajudar\n");
    sleep(1);
    printf("[ 1 ] - O numero que eu chutei é menor que o seu\n[ 0 ] - O numero que eu chutei é o seu numero\n[ -1 ] - O numero que eu chutei é maior que o seu\n\n");
    sleep(3);

    while(parametro != 0 || quantidadeTentativas < 1){
        tentativaComputador = numMinimo + ((numMaximo - numMinimo) / 2);

        printf("Tentativa %d\n", ++quantidadeTentativas);
        printf("O meu chute é %d\n", tentativaComputador);
        printf("Parametro: ");
        scanf("%d", &parametro);

        if(parametro == -1){
            numMaximo = tentativaComputador;
        }
        else if(parametro == 1){
            numMinimo = tentativaComputador;
        }
        else{
            printf("Ebaaaaaa! Eu consegui ler sua mente!\n");
            printf("Eu precisei de %d Tentativas para adivinhar\n", quantidadeTentativas);
        }
    }


}

int main(){
    int modoJogo;

    escolheModo(&modoJogo);

    if(modoJogo == 1){
        usuarioAdivinha();
    }else{
        computadorAdivinha();
    }

    printf("Obrigado por Jogar!\n");

}