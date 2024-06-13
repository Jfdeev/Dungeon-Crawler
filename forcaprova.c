#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TENTATIVAS 6
#define MAX_PALAVRAS 100
#define MAX_TAMANHO_PALAVRA 50

void exibirForca(int tentativas);
void inicializarPalavraOculta(const char *palavraSecreta, char *palavraOculta);

void exibirForca(int tentativas) {
    printf("----\n");
    printf("|  ");
    if (tentativas >= 1) printf("O");
    printf("\n| ");
    if (tentativas >= 2) printf("/");
    if (tentativas >= 3) printf("|");
    if (tentativas >= 4) printf("\\");
    printf("\n| ");
    if (tentativas >= 5) printf("/");
    if (tentativas >= 6) printf(" \\");
    printf("\n|\n\n");
}

void inicializarPalavraOculta(const char *palavraSecreta, char *palavraOculta) {
    int i;
    for (i = 0; i < strlen(palavraSecreta); i++) {
        palavraOculta[i] = '?';
    }
    palavraOculta[strlen(palavraSecreta)] = '\0';
}

int main() {
    char *palavras[MAX_PALAVRAS] = {"batman", "superman", "arlequina", "joker", "flash", "shazam", "robin"};
    int numPalavras = 7;
    char palavraSecreta[MAX_TAMANHO_PALAVRA], palavraOculta[MAX_TAMANHO_PALAVRA], chute;
    int tentativas, acertou, correto, pontos;
    char escolha;
    int i, tamanho;

    srand(time(NULL));

    while (1) {
        printf("(a) Jogar\n(b) Adicionar palavra\n(c) Sair\n");
        scanf(" %c", &escolha);
        escolha = tolower(escolha);
        if (escolha == 'a') {
            tentativas = 0;
            acertou = 0;
            pontos = 0;
            strcpy(palavraSecreta, palavras[rand() % numPalavras]);
            inicializarPalavraOculta(palavraSecreta, palavraOculta);
            tamanho = strlen(palavraSecreta);

            while (tentativas < MAX_TENTATIVAS && !acertou) {
            	system("cls");
                printf("Palavra: %s\n", palavraOculta);
                exibirForca(tentativas);
                printf("Pontuacao: %d\n", pontos);
                printf("Tentativa %d de %d\n", tentativas, MAX_TENTATIVAS);
                printf("Digite uma letra: ");
                scanf(" %c", &chute);
                chute = tolower(chute);
                correto = 0;
                for (i = 0; i < tamanho; i++) {
                    if (tolower(palavraSecreta[i]) == chute) {
                        if (palavraOculta[i] == '?') {
                            palavraOculta[i] = palavraSecreta[i];
                            correto = 1;
                        }
                    }
                }
                if (correto) {
                    pontos += 2;  
                } else {
                    tentativas++;
                    pontos -= 1;  
                }
                if (strcmp(palavraOculta, palavraSecreta) == 0) {
                    acertou = 1;
                }
            }
            if (acertou) {
                printf("Voce acertou a palavra!\nA palavra era %s\n", palavraSecreta);
                printf("Pontuacao final: %d\n", pontos);
            } else {
                printf("Voce perdeu!\nA palavra era %s\n", palavraSecreta);
                printf("Pontuacao final: %d\n", pontos);
            }
        } else if (escolha == 'b') {
        	system("cls");
            if (numPalavras < MAX_PALAVRAS) {
                char novaPalavra[MAX_TAMANHO_PALAVRA];
                printf("Digite a palavra para adicionar: ");
                scanf("%s", novaPalavra);
                palavras[numPalavras] = (char *)malloc(strlen(novaPalavra) + 1);
                strcpy(palavras[numPalavras], novaPalavra);
                numPalavras++;
                printf("Palavra adicionada!\n");
            } else {
                printf("Limite de palavras atingido!\n");
            }
        } else if (escolha == 'c') {
            break;
        } else {
            printf("Opcao invalida!\n");
        }
    }
    
    return 0;
}
