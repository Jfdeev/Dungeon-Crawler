#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

// Variaveis para controlar se o jogador possui as chaves
int chave1_obtida = 0; // Inicialmente o jogador nao possui a chave 1
int chave2_obtida = 0; // Inicialmente o jogador nao possui a chave 2
int chave3_obtida = 0; // Inicialmente o jogador nao possui a chave 3

//Voids
void tutorial();
void jogar();
void fase2();
void fase3();
//Menu Inicials
void menu(){
    int menu1;
    	printf("Menu Principal\n(1) Jogar\n(2) Tutorial\n(3) Sair\n");
    	scanf("%d", &menu1);
        if(menu1 == 1){
            jogar();
        }
        else if(menu1 == 2){
            tutorial();s
        }
        else if(menu1 == 3){
            system("cls");
            printf("Deseja sair do jogo? (S/N): ");
                char resposta;
                scanf(" %c", &resposta);
                if(resposta == 'S' || resposta == 's') {
                    printf("Voce saiu do jogo.\n");
                    system("cls");
                    exit(0);
                }
                if(resposta == 'n' || resposta == 'N'){
                    return menu();
                }
            exit(0);
        }
        else{
            system("cls");
            printf("Opcao invalida. Tente novamente!\n");
            getch();
            system("cls");
        }
    }
//Tutorial
void tutorial(){
    system("cls");
    printf("Bem vindo aventureiro, aqui voce tera uma nocaoo basica do jogo\nW -> Mover para cima\nA -> Mover para esquerda\nS -> Mover para baixo\nD -> Mover para direita\nI -> Para interagir com objeto que esta encima\nOs monstros sao representados por X e V, caso voce toque neles 3 vezes a fase e reniciada\n& -> Simbolo que representa o jogador.\nV -> Monstro inteligente que e capaz de destruir paredes e espinhos por conta da sua forca, use isso ao seu favor.\n# -> Simbolo representa um espinho que ao jogador toca-lo tres vezes o jogador morre\nO -> Simbolo representa um botao que ao jogador interagir com ele acontece uma surpresa...\nAo chegar na porta final po uma questao de algoritimo voce tera que dar um duplo clique no i para passar de fase, nas proximas fases isso sera corrrigido ou continuara do jeiro q esta, lembrando que voce tera que realizar o duplo clique em frente da porta = para abri-la e passar de fase.\n Fase 1 -> Uma Ruina antiga que foi ser explorada\n Fase 2 -> Um labirinto de grama alta onde tem um Monstro extremamente forte e inteligente, porem ele nao e tao rapido, ah ele pula alto tambem, cuidado...");
            printf("\nPressione qualquer tecla para voltar ao menu!");
            getch();
            system("cls");
            return menu();
	    }
//Jogo
void jogar(){
    int i, j;
    int vida = 3;
    
    system("cls");
        //Criar o Mapa
        char mapa1[10][10];
        for(i = 0; i < 10; i++){
            for(j = 0; j < 10; j++){
                //Paredes externas
                if(i == 0 || i == 9){
                    mapa1[i][j] = '*';
                }
                else if (j == 0 || j == 9){
                    mapa1[i][j] = '*';
                }
                //Parede interna
                else if (i == 3 && (j > 0 && j < 4)){
                    mapa1[i][j] = '*';
                }
                else if ((i == 6 && (j > 0 && j < 4)) || (i == 6 && (j > 5 && i < 10))){
                    mapa1[i][j] = '*';
                }
                else if(j == 3 && i < 4){
                    mapa1[i][j] = '*';
                }
                else if(j == 3 && i > 5){
                    mapa1[i][j] = '*';
                }
                else if(j == 6 && (i > 5 && i <= 9)){
                    mapa1[i][j] = '*';
                }
                //Espacos Vazios
                else if (i > 0 && i < 9){
                    mapa1[i][j] = ' ';
                }
            }
        }
        
        
        //Posicao inicial do jogador
        int x = 1, y = 8;
        //Posicao inicial do monstro
        //Colocar os elementos no mapa
        char chave1 = '@', chave2 = '@', chave3 = '@', porta1 = 'D', porta2 = 'D', porta3 = 'D';
        mapa1[1][3] = porta1;
        mapa1[8][8] = chave1;
        mapa1[6][2] = porta2;
        mapa1[2][1] = chave2;
        mapa1[6][7] = '=';
        mapa1[x][y] = '&';
        mapa1[9][1] = porta3;
        mapa1[8][2] = chave3;
 
        while(1){
            for(i = 0; i < 10; i ++){
                for(j = 0; j < 10; j ++){
                    printf("%c ", mapa1[i][j]);
                }
                printf("\n");
            }
            printf("\n\nPressione 'q' para sair.\n");
            int mov = getch();
            //Movimentacao do jogador
            if(mov == 'w'){
                if(mapa1[x-1][y] != '*'){
                    if(((mapa1[x-1][y] == porta1) && (chave1_obtida == 0)) ||
                       ((mapa1[x-1][y] == porta2) && (chave2_obtida == 0)) || 
                       ((mapa1[x-1][y] == porta3) && (chave3_obtida == 0))) {
                        printf("A porta esta trancada, ache a chave respectiva para ela");
                    }
                    else if (((mapa1[x-1][y] == porta1) && (chave1_obtida == 1)) ||
                             ((mapa1[x-1][y] == porta2) && (chave2_obtida == 1)) ||
                             ((mapa1[x-1][y] == porta3) && (chave3_obtida == 1))) {
                        x--;
                        mapa1[x+1][y] = ' ';
                    }
                    else if((mapa1[x][y] == mapa1[1][3]) || (mapa1[x][y] == mapa1[6][2]) ||(mapa1[x][y] == mapa1[9][1]) || (mapa1[x][y] == mapa1[6][7])){
                        x--;
                        mapa1[x+1][y] = '=';
                    }
                    else{
                        x--;
                        mapa1[x+1][y] = ' ';
                    }
                    if((((mapa1[x+1][y] == mapa1[8][8]) && chave1_obtida == 0) || ((mapa1[x+1][y] == mapa1[2][1]) && chave2_obtida == 0) || ((mapa1[x+1][y] == mapa1[8][2]) && chave3_obtida == 0)) ){
                        mapa1[x+1][y] = '@';
                    }
                    
                }
                system("cls");
            }
            else if(mov == 's'){
                if(mapa1[x+1][y] != '*' ){
                    if (((mapa1[x+1][y] == porta1) && (chave1_obtida == 0)) || 
                        ((mapa1[x+1][y] == porta2) && (chave2_obtida == 0)) || 
                        ((mapa1[x+1][y] == porta3) && (chave3_obtida == 0))){
                        printf("A porta esta trancada, ache a chave respectiva para ela");
                    }
                    else if(((mapa1[x+1][y] == porta1) && (chave1_obtida == 1)) ||
                            ((mapa1[x+1][y] == porta2) && (chave2_obtida == 1)) ||
                            ((mapa1[x+1][y] == porta3) && (chave3_obtida == 1))){
                        x++;
                        mapa1[x-1][y] = ' ';
                    }
                    else if((mapa1[x][y] == mapa1[1][3]) || (mapa1[x][y] == mapa1[6][2]) ||(mapa1[x][y] == mapa1[9][1]) || (mapa1[x][y] == mapa1[6][7])){
                        x++;
                        mapa1[x-1][y] = '=';
                    }
                    else{
                        x++;
                        mapa1[x-1][y] = ' ';
                    }
                    if((((mapa1[x-1][y] == mapa1[8][8]) && chave1_obtida == 0) || ((mapa1[x-1][y] == mapa1[2][1]) && chave2_obtida == 0) || ((mapa1[x-1][y] == mapa1[8][2]) && chave3_obtida == 0)) ){
                        mapa1[x-1][y] = '@';
                    }
                    
                }
                system("cls");  
            }
            else if(mov == 'a'){
                if (mapa1[x][y-1] != '*'){
                    if (((mapa1[x][y-1] == porta1) && (chave1_obtida == 0)) || 
                        ((mapa1[x][y-1] == porta2) && (chave2_obtida == 0)) || 
                        ((mapa1[x][y-1] == porta3) && (chave3_obtida == 0))){
                        printf("A porta esta trancada, ache a chave respectiva para ela");
                    }
                    else if(((mapa1[x][y-1] == porta1) && (chave1_obtida == 1)) || 
                            ((mapa1[x][y-1] == porta2) && (chave2_obtida == 1)) || 
                            ((mapa1[x][y-1] == porta3) && (chave3_obtida == 1))){
                        y--;
                        mapa1[x][y+1] = ' ';
                    }
                    else if((mapa1[x][y] == mapa1[1][3]) || (mapa1[x][y] == mapa1[6][2]) ||(mapa1[x][y] == mapa1[9][1]) || (mapa1[x][y] == mapa1[6][7])){
                        y--;
                        mapa1[x][y+1] = '=';
                    }
                    else{
                        y--;
                        mapa1[x][y+1] = ' ';
                    }
                    if((((mapa1[x][y+1] == mapa1[8][8]) && chave1_obtida == 0) || ((mapa1[x][y+1] == mapa1[2][1]) && chave2_obtida == 0) || ((mapa1[x][y+1] == mapa1[8][2]) && chave3_obtida == 0)) ){
                        mapa1[x][y+1] = '@';
                    }
                    
                }
                system("cls");
            }  
            else if(mov == 'd'){
                if(mapa1[x][y+1] != '*'){
                    if (((mapa1[x][y+1] == porta1) && (chave1_obtida == 0)) || 
                        ((mapa1[x][y+1] == porta2) && (chave2_obtida == 0)) || 
                        ((mapa1[x][y+1] == porta3) && (chave3_obtida == 0))){
                        printf("A porta esta trancada, ache a chave respectiva para ela");
                    }
                    else if(((mapa1[x][y+1] == porta1) && (chave1_obtida == 1)) || 
                            ((mapa1[x][y+1] == porta2) && (chave2_obtida == 1)) || 
                            ((mapa1[x][y+1] == porta3) && (chave3_obtida == 1))){
                        y++;
                        mapa1[x][y-1] = ' ';
                    }
                    else if((mapa1[x][y] == mapa1[1][3]) || (mapa1[x][y] == mapa1[6][2]) ||(mapa1[x][y] == mapa1[9][1]) || (mapa1[x][y] == mapa1[6][7])){
                        y++;
                        mapa1[x][y-1] = '=';
                    }
                    else{
                        y++;
                        mapa1[x][y-1] = ' ';    
                    }
                    if((((mapa1[x][y-1] == mapa1[8][8]) && chave1_obtida == 0) || ((mapa1[x][y-1] == mapa1[2][1]) && chave2_obtida == 0) || ((mapa1[x][y-1] == mapa1[8][2]) && chave3_obtida == 0)) ){
                        mapa1[x][y-1] = '@';
                    }
                    
                }
                system("cls");
            }
    		if(vida == 0){
    			printf("Voce Morreu, Voce e pessimo vai treinar\n");
        		printf("Pressione qualquer tecla para continuar...\n");
        		getch();
        		system("cls");
        		return jogar();
			}
            else if(mov == 'q'){
                printf("Deseja sair do jogo? (S/N): ");
                char resposta;
                scanf(" %c", &resposta);
                if(resposta == 'S' || resposta == 's') {
                    printf("Voce saiu do jogo.\n");
                    printf("Pressione qualquer tecla para voltar ao menu.\n");
                    getch();
                    system("cls");
                    return menu();
                }
                else{
                    system("cls");
                }
            }
            else if(mov == 'i' && (x == 8 && y == 8)){
                mapa1[8][8] = ' ';
                mapa1[1][3] = '=';
                chave1_obtida = 1;
                system("cls");
            }
            else if(mov == 'i' && (x == 2 && y == 1)){
                mapa1[2][1] = ' ';
                mapa1[6][2] = '=';
                chave2_obtida = 1;
                system("cls");
            }
            else if(mov == 'i' && (x == 8 && y == 2)){
                mapa1[8][2] = ' ';
                mapa1[9][1] = '=';
                chave3_obtida = 1;
                system("cls");
            }
            if(mov == 's' && (mapa1[x][y] == mapa1[9][1])){
                printf("Parabens, voce ajudou o Casseb a passar por esse primeira fase, mas tome cuidado que monstros estao por vir....\nBoa sorte guerreiro\n");
            	printf("Pressione qualquer tecla para continuar.\n");
            	getch();
            	system("cls");
				return fase2();
			}
            else{
                system("cls");
            }
                mapa1[x][y] = '&';
        }
    }
void fase2(){
	int i, j;
	int movimento_contador = 0;
	int vida = 3;
    system("cls");
    printf("Segunda Fase.\n");
    char mapa2[20][20];
        for(i = 0; i < 20; i++){
            for(j = 0; j < 20; j++){
                //Paredes externas
                if(i == 0 || i == 19){
                    mapa2[i][j] = '*';
                }
                else if (j == 0 || j == 19){
                    mapa2[i][j] = '*';
                }
                //paredes internas
                else if (i % 2 == 0 && j % 2 == 0) {
            		mapa2[i][j] = '*';
       			}
                //Espacos Vazios
                else if (i > 0 && i < 19){
                    mapa2[i][j] = ' ';
                }
			  }
            }
            //Posicao inicial do jogador
        int x = 3, y = 3;
        //Posicao inicial do monstro 1
        int xm = 5, ym = 4;
    
        //elemantos
        char chave1 = '@', chave2 = '@', chave3 = '@', porta1 = 'D', porta2 = 'D', porta3 = 'D';
        char monstro = 'X';
        char espinho = '#';
        char botao = 'O'; 
        mapa2[xm][ym] = monstro;
        mapa2[x][y] = '&';
        mapa2[18][17] = botao;
        mapa2[1][18] = botao;
        mapa2[19][7] = porta1;
        mapa2[15][16] = espinho;
        mapa2[16][15] = espinho;
        mapa2[13][12] = espinho;
        mapa2[4][3] = espinho;
        mapa2[17][18] = espinho;
        mapa2[16][7] = espinho;
        mapa2[18][9] = espinho;
        mapa2[1][9] = espinho;
        mapa2[1][4] = espinho;
        mapa2[1][15] = espinho;
        mapa2[3][13] = espinho;
        mapa2[7][1] = espinho;
        mapa2[4][1] = espinho;
        mapa2[13][1] = espinho;
        mapa2[16][1] = espinho;
        mapa2[11][3] = espinho;
        mapa2[7][3] = espinho;
        mapa2[13][5] = espinho;
        mapa2[7][7] = espinho;
        mapa2[13][7] = espinho;
        mapa2[15][7] = espinho;
        mapa2[5][17] = espinho;
        mapa2[7][17] = espinho;
        mapa2[13][17] = espinho;
        
        while(1){
            for(i = 0; i < 20; i ++){
                for(j = 0; j < 20; j ++){
                    printf("%c ", mapa2[i][j]);
                }
                printf("\n");
            }
            // Monstro nivel 1
            srand(time(NULL));
            mapa2[xm][ym] = monstro;
            int o;
            o = rand()%4;
            if(o == 0){
                if(mapa2[xm - 1][ym] != '*' && mapa2[xm - 1][ym] != 'D' && mapa2[xm - 1][ym] != '=' && mapa2[xm - 1][ym] != 'h' && mapa2[xm - 1][ym] != '#'){
                    xm--;
                    mapa2[xm + 1][ym] = ' ';
                }
            }
            if(o == 1){
                if(mapa2[xm + 1][ym] != '*' && mapa2[xm + 1][ym] != 'D' && mapa2[xm + 1][ym] != '=' && mapa2[xm + 1][ym] != 'h' && mapa2[xm + 1][ym] != '#'){
                    xm++;
                    mapa2[xm - 1][ym] = ' ';
                }
            }
            if(o == 2){
                if(mapa2[xm][ym - 1] != '*' && mapa2[xm][ym - 1] != 'D' && mapa2[xm][ym - 1] != '=' && mapa2[xm][ym - 1] != 'h' && mapa2[xm][ym - 1] != '#'){
                    ym--;
                    mapa2[xm][ym + 1] = ' ';
                }
            }
            if(o == 3){
                if(mapa2[xm][ym + 1] != '*' && mapa2[xm][ym + 1] != 'D' && mapa2[xm][ym + 1] != '=' && mapa2[xm][ym + 1] != 'h' && mapa2[xm][ym + 1] != '#'){
                    ym++;
                    mapa2[xm][ym - 1] = ' ';
                }
            }
            printf("\n\nPressione 'q' para sair.\n");
            int mov = getch();
            //Movimentacao do jogador
            if(mov == 'w'){
                if(mapa2[x-1][y] != '*' && mapa2[x-1][y] != 'D'){
                    if((mapa2[x-1][y] == porta1) && (chave1_obtida == 0)) {
                        printf("A porta esta trancada, ache a chave respectiva para ela");
                    }
                    else if (((mapa2[x-1][y] == porta1) && (chave1_obtida == 1)) ||
                             ((mapa2[x-1][y] == porta2) && (chave2_obtida == 1)) ||
                             ((mapa2[x-1][y] == porta3) && (chave3_obtida == 1))) {
                        x--;
                        mapa2[x+1][y] = ' ';
                    }
                    else if((mapa2[x][y] == mapa2[1][18]) || (mapa2[x][y] == mapa2[18][17]) ){
                        x--;
                        mapa2[x+1][y] = 'O';
                    }
                    else if((mapa2[x][y] == mapa2[1][1] && chave1_obtida == 0)){
                    	x--;
                        mapa2[x+1][y] = '@';
                    }
                    else if((mapa2[x][y] == mapa2[15][16]) || 
        					(mapa2[x][y] == mapa2[4][3]) || 
        					(mapa2[x][y] == mapa2[16][15]) || 
        					(mapa2[x][y] == mapa2[13][12]) || 
        					(mapa2[x][y] == mapa2[17][18]) || 
        					(mapa2[x][y] == mapa2[16][7]) || 
        					(mapa2[x][y] == mapa2[18][9]) || 
        					(mapa2[x][y] == mapa2[1][9]) || 
        					(mapa2[x][y] == mapa2[1][4]) || 
        					(mapa2[x][y] == mapa2[1][15]) || 
        					(mapa2[x][y] == mapa2[3][13]) || 
       						(mapa2[x][y] == mapa2[7][1]) || 
        					(mapa2[x][y] == mapa2[4][1]) || 
        					(mapa2[x][y] == mapa2[13][1]) || 
        					(mapa2[x][y] == mapa2[16][1]) || 
        					(mapa2[x][y] == mapa2[11][3]) || 
        					(mapa2[x][y] == mapa2[7][3]) || 
        					(mapa2[x][y] == mapa2[13][5]) || 
        					(mapa2[x][y] == mapa2[7][7]) || 
        					(mapa2[x][y] == mapa2[13][7]) || 
        					(mapa2[x][y] == mapa2[15][7]) || 
        					(mapa2[x][y] == mapa2[5][17]) || 
        					(mapa2[x][y] == mapa2[7][17]) || 
        					(mapa2[x][y] == mapa2[13][17])) {
            			x--;
            			mapa2[x+1][y] = '#';
        			}
                    else{
                        x--;
                        mapa2[x+1][y] = ' ';
                    }
                    movimento_contador ++;
                }
            }
            else if(mov == 's'){
                if(mapa2[x+1][y] != '*' && mapa2[x+1][y] != 'D'){
                    if (((mapa2[x+1][y] == porta1) && (chave1_obtida == 0)) || 
                        ((mapa2[x+1][y] == porta2) && (chave2_obtida == 0)) || 
                        ((mapa2[x+1][y] == porta3) && (chave3_obtida == 0))){
                        printf("A porta esta trancada, ache a chave respectiva para ela");
                    }
                    else if(((mapa2[x+1][y] == porta1) && (chave1_obtida == 1)) ||
                            ((mapa2[x+1][y] == porta2) && (chave2_obtida == 1)) ||
                            ((mapa2[x+1][y] == porta3) && (chave3_obtida == 1))){
                        x++;
                        mapa2[x-1][y] = ' ';
                    }
                    else if((mapa2[x][y] == mapa2[1][18]) || (mapa2[x][y] == mapa2[18][17]) ){
                        x++;
                        mapa2[x-1][y] = 'O';
                    }
                    else if((mapa2[x][y] == mapa2[19][7])){
                        x++;
                        mapa2[x-1][y] = '=';
                    }
                    else if((mapa2[x][y] == mapa2[1][1] && chave1_obtida == 0)){
                    	x++;
                        mapa2[x-1][y] = '@';
                    }
                    else if((mapa2[x][y] == mapa2[15][16]) || 
        					(mapa2[x][y] == mapa2[4][3]) || 
        					(mapa2[x][y] == mapa2[16][15]) || 
        					(mapa2[x][y] == mapa2[13][12]) || 
        					(mapa2[x][y] == mapa2[17][18]) || 
        					(mapa2[x][y] == mapa2[16][7]) || 
        					(mapa2[x][y] == mapa2[18][9]) || 
        					(mapa2[x][y] == mapa2[1][9]) || 
        					(mapa2[x][y] == mapa2[1][4]) || 
        					(mapa2[x][y] == mapa2[1][15]) || 
        					(mapa2[x][y] == mapa2[3][13]) || 
       						(mapa2[x][y] == mapa2[7][1]) || 
        					(mapa2[x][y] == mapa2[4][1]) || 
        					(mapa2[x][y] == mapa2[13][1]) || 
        					(mapa2[x][y] == mapa2[16][1]) || 
        					(mapa2[x][y] == mapa2[11][3]) || 
        					(mapa2[x][y] == mapa2[7][3]) || 
        					(mapa2[x][y] == mapa2[13][5]) || 
        					(mapa2[x][y] == mapa2[7][7]) || 
        					(mapa2[x][y] == mapa2[13][7]) || 
        					(mapa2[x][y] == mapa2[15][7]) || 
        					(mapa2[x][y] == mapa2[5][17]) || 
        					(mapa2[x][y] == mapa2[7][17]) || 
        					(mapa2[x][y] == mapa2[13][17])) {
            			x++;
            			mapa2[x-1][y] = '#';
        			}
                    else{
                        x++;
                        mapa2[x-1][y] = ' ';
                    }
					movimento_contador ++;  
                }
            }
            else if(mov == 'a'){
                if (mapa2[x][y-1] != '*' && mapa2[x][y-1] != 'D'){
                    if (((mapa2[x][y-1] == porta1) && (chave1_obtida == 0)) || 
                        ((mapa2[x][y-1] == porta2) && (chave2_obtida == 0)) || 
                        ((mapa2[x][y-1] == porta3) && (chave3_obtida == 0))){
                        printf("A porta esta trancada, ache a chave respectiva para ela");
                    }
                    else if(((mapa2[x][y-1] == porta1) && (chave1_obtida == 1)) || 
                            ((mapa2[x][y-1] == porta2) && (chave2_obtida == 1)) || 
                            ((mapa2[x][y-1] == porta3) && (chave3_obtida == 1))){
                        y--;
                        mapa2[x][y+1] = ' ';
                    }
                    else if((mapa2[x][y] == mapa2[15][16]) || 
        					(mapa2[x][y] == mapa2[4][3]) || 
        					(mapa2[x][y] == mapa2[16][15]) || 
        					(mapa2[x][y] == mapa2[13][12]) || 
        					(mapa2[x][y] == mapa2[17][18]) || 
        					(mapa2[x][y] == mapa2[16][7]) || 
        					(mapa2[x][y] == mapa2[18][9]) || 
        					(mapa2[x][y] == mapa2[1][9]) || 
        					(mapa2[x][y] == mapa2[1][4]) || 
        					(mapa2[x][y] == mapa2[1][15]) || 
        					(mapa2[x][y] == mapa2[3][13]) || 
       						(mapa2[x][y] == mapa2[7][1]) || 
        					(mapa2[x][y] == mapa2[4][1]) || 
        					(mapa2[x][y] == mapa2[13][1]) || 
        					(mapa2[x][y] == mapa2[16][1]) || 
        					(mapa2[x][y] == mapa2[11][3]) || 
        					(mapa2[x][y] == mapa2[7][3]) || 
        					(mapa2[x][y] == mapa2[13][5]) || 
        					(mapa2[x][y] == mapa2[7][7]) || 
        					(mapa2[x][y] == mapa2[13][7]) || 
        					(mapa2[x][y] == mapa2[15][7]) || 
        					(mapa2[x][y] == mapa2[5][17]) || 
        					(mapa2[x][y] == mapa2[7][17]) || 
        					(mapa2[x][y] == mapa2[13][17])) {
            			y--;
            			mapa2[x][y+1] = '#';
        			}
                    else if((mapa2[x][y] == mapa2[1][18]) || (mapa2[x][y] == mapa2[18][17]) ){
                        y--;
                        mapa2[x][y+1] = 'O';
                    }
                    else{
                        y--;
                        mapa2[x][y+1] = ' ';
                    }
                    if((mapa2[x][y] == mapa2[1][1] && chave1_obtida == 0)){
                        mapa2[x][y+1] = '@';
                    }
                    movimento_contador ++;
                }
            }  
            else if(mov == 'd'){
                if(mapa2[x][y+1] != '*' && mapa2[x][y-1] != 'D'){
                    if (((mapa2[x][y+1] == porta1) && (chave1_obtida == 0)) || 
                        ((mapa2[x][y+1] == porta2) && (chave2_obtida == 0)) || 
                        ((mapa2[x][y+1] == porta3) && (chave3_obtida == 0))){
                        printf("A porta esta trancada, ache a chave respectiva para ela");
                    }
                    else if(((mapa2[x][y+1] == porta1) && (chave1_obtida == 1)) || 
                            ((mapa2[x][y+1] == porta2) && (chave2_obtida == 1)) || 
                            ((mapa2[x][y+1] == porta3) && (chave3_obtida == 1))){
                        y++;
                        mapa2[x][y-1] = ' ';
                    }
                    else if((mapa2[x][y] == mapa2[15][16]) || 
        					(mapa2[x][y] == mapa2[4][3]) || 
        					(mapa2[x][y] == mapa2[16][15]) || 
        					(mapa2[x][y] == mapa2[13][12]) || 
        					(mapa2[x][y] == mapa2[17][18]) || 
        					(mapa2[x][y] == mapa2[16][7]) || 
        					(mapa2[x][y] == mapa2[18][9]) || 
        					(mapa2[x][y] == mapa2[1][9]) || 
        					(mapa2[x][y] == mapa2[1][4]) || 
        					(mapa2[x][y] == mapa2[1][15]) || 
        					(mapa2[x][y] == mapa2[3][13]) || 
       						(mapa2[x][y] == mapa2[7][1]) || 
        					(mapa2[x][y] == mapa2[4][1]) || 
        					(mapa2[x][y] == mapa2[13][1]) || 
        					(mapa2[x][y] == mapa2[16][1]) || 
        					(mapa2[x][y] == mapa2[11][3]) || 
        					(mapa2[x][y] == mapa2[7][3]) || 
        					(mapa2[x][y] == mapa2[13][5]) || 
        					(mapa2[x][y] == mapa2[7][7]) || 
        					(mapa2[x][y] == mapa2[13][7]) || 
        					(mapa2[x][y] == mapa2[15][7]) || 
        					(mapa2[x][y] == mapa2[5][17]) || 
        					(mapa2[x][y] == mapa2[7][17]) || 
        					(mapa2[x][y] == mapa2[13][17])) {
            			y++;
            			mapa2[x][y-1] = '#';
        			}
                    else{
                        y++;
                        mapa2[x][y-1] = ' ';    
                    }
                    if((mapa2[x][y] == mapa2[1][1] && chave1_obtida == 0)){
                        mapa2[x][y-1] = '@';
                    }
                 	movimento_contador ++;   
                }
            }
            if (x == xm && y == ym){
            	vida--;
        		printf("Voce foi pego pelo monstro, Voce tem %d vidas!\n", vida);
        		printf("Pressione qualquer tecla para continuar...\n");
        		getch();
        		system("cls");
    		}
    		if (mapa2[x][y] == espinho){
    			vida--;
    			printf("Voce foi atingido por um espinho venenoso, Voce tem %d vidas\n", vida);
        		printf("Pressione qualquer tecla para continuar...\n");
        		getch();
        		system("cls");
			}
			if(vida==0){
				printf("Voce Morreu, Voce e pessimo vai treinar\n");
        		printf("Pressione qualquer tecla para continuar...\n");
        		getch();
        		system("cls");
        		return fase2();
			}
            else if(mov == 'q'){
                printf("Deseja sair do jogo? (S/N): ");
                char resposta;
                scanf(" %c", &resposta);
                if(resposta == 'S' || resposta == 's') {
                    printf("Voce saiu do jogo.\n");
                    printf("Pressione qualquer tecla para voltar ao menu.\n");
                    getch();
                    system("cls");
                    return menu();
                }
                else{
                    system("cls");
                }
            }
            else if(mov == 'i' && (x==18 && y == 17)){
            	mapa2[1][1] = '@';
            	system("cls");
			}
			else if(mov == 'i' && (x==1 && y == 18)){
            	printf("Voce nao escutou barulho de nenhuma porta abrir, continue explorando.");
            	printf("Pressione qualquer tecla para continuar.\n");
            	getch();
            	system("cls");
            	
			}
            else if(mov == 'i' && (x == 1 && y == 1)){
                mapa2[1][1] = ' ';
                mapa2[19][7] = '=';
                chave1_obtida++;
                system("cls");
            }
            else if(mov == 's' && (x == 19 && y == 7)){
            	printf("Parabens, voce escapou do labirinto da morte e passou para a ultima fase para finalmente poder salvar Pedro Girotto\nAgora esteja preparado para enfrentar os montros e espinhos");
            	printf("Pressione qualquer tecla para continuar.\n");
            	getch();
            	system("cls");
            	return fase3();
			}
            else{
                system("cls");
            }
                mapa2[x][y] = '&';
                mapa2[xm][ym] = monstro;  
      
	   }
   }

void fase3(){
	int vida = 3;
	int i, j;
	int tunel_aberto = 0;
    int movimento_contador = 0;
    // Posicao inicial do jogador
    int x = 33, y = 5;
    // Posicao inicial do monstro 1
    int xm = 4, ym = 4;
    // Posicao inicial do monstro 2
    int xm2 = 20, ym2 = 20;
    system("cls");
    printf("Terceira Fase\n");
    char mapa3[40][40];
    int chave1_obtida = 0, chave2_obtida = 0, chave3_obtida = 0;
    for (i = 0; i < 40; i++) {
        for (j = 0; j < 40; j++) {
            // Paredes externas
            if (i == 0 || i == 39 || j == 0 || j == 39) {
                mapa3[i][j] = '*';
            }
            // Paredes internas
            else if ((i == 1 || i == 10) && j >= 1 && j <= 10) {
                mapa3[i][j] = '*';
            } else if ((j == 1 || j == 10) && i >= 1 && i <= 10) {
                mapa3[i][j] = '*';
            }
            // Sala superior direita
            else if ((i == 1 || i == 10) && j >= 29 && j <= 38) {
                mapa3[i][j] = '*';
                mapa3[5][1] = '>';
                mapa3[9][9] = 'O';
            } else if ((j == 29 || j == 38) && i >= 1 && i <= 10) {
                mapa3[i][j] = '*';
            }
            // Sala inferior esquerda
            else if ((i == 29 || i == 38) && j >= 1 && j <= 10) {
                mapa3[i][j] = '*';
            } else if ((j == 1 || j == 10) && i >= 29 && i <= 38) {
                mapa3[i][j] = '*';
            }
            // Sala inferior direita
            else if ((i == 29 || i == 38) && j >= 29 && j <= 38) {
                mapa3[i][j] = '*';
            } else if ((j == 29 || j == 38) && i >= 29 && i <= 38) {
                mapa3[i][j] = '*';
            }
            // Paredes da sala central 8x8
            // Horizontais
            else if ((i == 11 || i == 28) && j >= 11 && j <= 28) {
                mapa3[i][j] = '*';
                mapa3[28][19] = '>';
            }
            // Verticais
            else if ((j == 11 || j == 28) && i >= 11 && i <= 28) {
                mapa3[i][j] = '*';
            }
            // Espacos vazios
            else {
                mapa3[i][j] = ' ';
            }
        }
    }

    // Elementos 
    char monstro = 'X';
    char chave1 = '@', chave2 = '@', chave3 = '@', porta1 = 'D', porta2 = 'D', porta3 = 'D';
    char espinho = '#';
    char botao = 'O';
    char teletransporte = '>';
    mapa3[x][y] = '&';
    mapa3[xm2][ym2] = 'V';
    mapa3[xm][ym] = monstro;
    mapa3[30][5] = botao;
    mapa3[3][38] = porta1;
    mapa3[3][39] = porta1;
    mapa3[29][34] = teletransporte;
    mapa3[11][19] = teletransporte;
    
    // Espinhos sala central
    mapa3[12][20] = espinho;
    mapa3[13][20] = espinho;
    mapa3[14][20] = espinho;
    mapa3[14][21] = espinho;
    mapa3[14][22] = espinho;
    mapa3[14][23] = espinho;
    mapa3[14][24] = espinho;
    mapa3[15][25] = espinho;
    mapa3[16][25] = espinho;
    mapa3[17][25] = espinho;
    mapa3[18][25] = espinho;
    mapa3[19][25] = espinho;
    mapa3[19][26] = espinho;
    mapa3[19][27] = espinho;
    mapa3[19][27] = espinho;
    mapa3[20][27] = espinho;
    mapa3[21][27] = espinho;
    mapa3[22][26] = espinho;
    mapa3[22][25] = espinho;
    mapa3[22][25] = espinho;
    mapa3[23][24] = espinho;
    mapa3[23][23] = espinho;
    mapa3[24][23] = espinho;
    mapa3[25][23] = espinho;
    mapa3[26][22] = espinho;
    mapa3[27][22] = espinho;
    mapa3[27][21] = espinho;
    mapa3[27][20] = espinho;
    mapa3[14][17] = espinho;
    mapa3[15][17] = espinho;
    mapa3[16][18] = espinho;
    mapa3[17][19] = espinho;
    mapa3[18][19] = espinho;
    mapa3[19][19] = espinho;
    mapa3[19][20] = espinho;
    mapa3[22][19] = espinho;
    mapa3[22][18] = espinho;
    mapa3[23][18] = espinho;
    mapa3[24][18] = espinho;
    mapa3[25][18] = espinho;
    mapa3[26][18] = espinho;
    mapa3[27][18] = espinho;
    mapa3[12][13] = espinho;
    mapa3[12][12] = espinho;
    mapa3[13][12] = espinho;
    mapa3[14][12] = espinho;
    mapa3[15][12] = espinho;
    mapa3[16][12] = espinho;
    mapa3[17][12] = espinho;
    mapa3[17][13] = espinho;
    mapa3[17][14] = espinho;
    mapa3[18][15] = espinho;
    mapa3[19][15] = espinho;
    mapa3[20][14] = espinho;
    mapa3[21][13] = espinho;
    mapa3[21][12] = espinho;
    mapa3[22][12] = espinho;
    mapa3[23][12] = espinho;
    mapa3[24][12] = espinho;
    mapa3[24][13] = espinho;
    mapa3[24][14] = espinho;
    mapa3[25][12] = espinho;
    mapa3[25][13] = espinho;
    mapa3[25][14] = espinho;
    mapa3[25][15] = espinho;
    mapa3[26][12] = espinho;
    mapa3[26][13] = espinho;
    mapa3[26][14] = espinho;
    mapa3[27][12] = espinho;
    mapa3[27][13] = espinho;
    mapa3[27][14] = espinho;
    mapa3[27][15] = espinho;
    mapa3[27][16] = espinho;
    mapa3[27][17] = espinho;
    mapa3[26][25] = espinho;
    mapa3[26][26] = espinho;
    mapa3[25][26] = espinho;
    
   

    while (1) {
        // Imprimindo o mapa
        for (i = 0; i < 40; i++) {
            for (j = 0; j < 40; j++) {
                printf("%c ", mapa3[i][j]);
            }
            printf("\n");
        }

        // Monstro nivel 1
        srand(time(NULL));
        int o;
        o = rand() % 4;
        if (o == 0) {
            if (mapa3[xm - 1][ym] != '*' && mapa3[xm - 1][ym] != 'D' && mapa3[xm - 1][ym] != '=' && mapa3[xm - 1][ym] != 'h' && mapa3[xm - 1][ym] != '#') {
                mapa3[xm][ym] = ' ';
                xm--;
                mapa3[xm][ym] = monstro;
            }
        }
        if (o == 1) {
            if (mapa3[xm + 1][ym] != '*' && mapa3[xm + 1][ym] != 'D' && mapa3[xm + 1][ym] != '=' && mapa3[xm + 1][ym] != 'h' && mapa3[xm + 1][ym] != '#') {
                mapa3[xm][ym] = ' ';
                xm++;
                mapa3[xm][ym] = monstro;
            }
        }
        if (o == 2) {
            if (mapa3[xm][ym - 1] != '*' && mapa3[xm][ym - 1] != 'D' && mapa3[xm][ym - 1] != '=' && mapa3[xm][ym - 1] != 'h' && mapa3[xm][ym - 1] != '#') {
                mapa3[xm][ym] = ' ';
                ym--;
                mapa3[xm][ym] = monstro;
            }
        }
        if (o == 3) {
            if (mapa3[xm][ym + 1] != '*' && mapa3[xm][ym + 1] != 'D' && mapa3[xm][ym + 1] != '=' && mapa3[xm][ym + 1] != 'h' && mapa3[xm][ym + 1] != '#') {
                mapa3[xm][ym] = ' ';
                ym++;
                mapa3[xm][ym] = monstro;
            }
        }

        // Monstro nivel 2
        if (movimento_contador == 2) {
            int dif_x = x - xm2;
            int dif_y = y - ym2;
            if (abs(dif_x) > abs(dif_y)) {
                if (dif_x > 0 && mapa3[xm2 + 1][ym2] != '*' && mapa3[xm2 + 1][ym2] != 'D' && mapa3[xm2 + 1][ym2] != '#'){
                    mapa3[xm2][ym2] = ' ';
                    xm2++;
                    mapa3[xm2][ym2] = 'V';
                } else if (dif_x < 0 && mapa3[xm2 - 1][ym2] != '*' && mapa3[xm2 - 1][ym2] != 'D' && mapa3[xm2 - 1][ym2] != '#') {
                    mapa3[xm2][ym2] = ' ';
                    xm2--;
                    mapa3[xm2][ym2] = 'V';
                }
            } else {
                if (dif_y > 0 && mapa3[xm2][ym2 + 1] != '*' && mapa3[xm2][ym2 + 1] != 'D' && mapa3[xm2][ym2 + 1] != '#') {
                    mapa3[xm2][ym2] = ' ';
                    ym2++;
                    mapa3[xm2][ym2] = 'V';
                } else if (dif_y < 0 && mapa3[xm2][ym2 - 1] != '*' && mapa3[xm2][ym2 - 1] != 'D' && mapa3[xm2][ym2 - 1] != '#') {
                    mapa3[xm2][ym2] = ' ';
                    ym2--;
                    mapa3[xm2][ym2] = 'V';
                }
            }
            movimento_contador = 0;
        }

        printf("\n\nPressione 'q' para sair.\n");
        int mov = getch();

        // Movimentacao do jogador
        if (mov == 'w') {
            if (mapa3[x - 1][y] != '*' && mapa3[x - 1][y] != 'D') {
                if (((mapa3[x - 1][y] == porta1) && (chave1_obtida == 0)) ||
                    ((mapa3[x - 1][y] == porta2) && (chave2_obtida == 0)) ||
                    ((mapa3[x - 1][y] == porta3) && (chave3_obtida == 0))) {
                    printf("A porta esta trancada, ache a chave respectiva para ela");
                } else if (((mapa3[x - 1][y] == porta1) && (chave1_obtida == 1)) ||
                           ((mapa3[x - 1][y] == porta2) && (chave2_obtida == 1)) ||
                           ((mapa3[x - 1][y] == porta3) && (chave3_obtida == 1))) {
                    x--;
                    mapa3[x + 1][y] = ' ';
                    movimento_contador++;
                }
                else if((mapa3[x][y] == mapa3[37][37] && chave1_obtida == 0)){
                    	x--;
                        mapa3[x+1][y] = '@';
                }
                else if((mapa3[x][y] == mapa3[29][34] || (mapa3[x][y] == mapa3[11][19]))){
                    	x--;
                        mapa3[x+1][y] = '>';
                }
                else if((mapa3[x][y] == mapa3[30][5]) || (mapa3[x][y] == mapa3[18][17]) ){
                        x--;
                        mapa3[x+1][y] = 'O';
                }
                else if((mapa3[x][y] == mapa3[12][20]) ||
                		(mapa3[x][y] == mapa3[13][20]) ||
						(mapa3[x][y] == mapa3[14][20]) ||
						(mapa3[x][y] == mapa3[14][21]) ||
						(mapa3[x][y] == mapa3[14][22]) ||
						(mapa3[x][y] == mapa3[14][23]) ||
						(mapa3[x][y] == mapa3[14][24]) ||
						(mapa3[x][y] == mapa3[15][25]) ||
						(mapa3[x][y] == mapa3[16][25]) ||
						(mapa3[x][y] == mapa3[17][25]) ||
						(mapa3[x][y] == mapa3[18][25]) ||
						(mapa3[x][y] == mapa3[19][25]) ||
						(mapa3[x][y] == mapa3[19][26]) ||
						(mapa3[x][y] == mapa3[19][27]) ||
						(mapa3[x][y] == mapa3[19][27]) ||
						(mapa3[x][y] == mapa3[20][27]) ||
						(mapa3[x][y] == mapa3[21][27]) ||
						(mapa3[x][y] == mapa3[22][26]) ||
						(mapa3[x][y] == mapa3[22][25]) ||
						(mapa3[x][y] == mapa3[22][25]) ||
						(mapa3[x][y] == mapa3[23][24]) ||
						(mapa3[x][y] == mapa3[23][23]) ||
						(mapa3[x][y] == mapa3[24][23]) ||
						(mapa3[x][y] == mapa3[25][23]) ||
						(mapa3[x][y] == mapa3[26][22]) ||
						(mapa3[x][y] == mapa3[27][22]) ||
						(mapa3[x][y] == mapa3[27][21]) ||
						(mapa3[x][y] == mapa3[27][20]) ||
						(mapa3[x][y] == mapa3[14][17]) ||
						(mapa3[x][y] == mapa3[15][17]) ||
						(mapa3[x][y] == mapa3[16][18]) ||
						(mapa3[x][y] == mapa3[17][19]) ||
						(mapa3[x][y] == mapa3[18][19]) ||
						(mapa3[x][y] == mapa3[19][19]) ||
						(mapa3[x][y] == mapa3[19][20]) ||
						(mapa3[x][y] == mapa3[22][19]) ||
						(mapa3[x][y] == mapa3[22][18]) ||
						(mapa3[x][y] == mapa3[23][18]) ||
						(mapa3[x][y] == mapa3[24][18]) ||
						(mapa3[x][y] == mapa3[25][18]) ||
						(mapa3[x][y] == mapa3[26][18]) ||
						(mapa3[x][y] == mapa3[27][18]) ||
						(mapa3[x][y] == mapa3[12][13]) ||
						(mapa3[x][y] == mapa3[12][12]) ||
						(mapa3[x][y] == mapa3[13][12]) ||
						(mapa3[x][y] == mapa3[14][12]) ||
						(mapa3[x][y] == mapa3[15][12]) ||
						(mapa3[x][y] == mapa3[16][12]) ||
						(mapa3[x][y] == mapa3[17][12]) ||
						(mapa3[x][y] == mapa3[17][13]) ||
						(mapa3[x][y] == mapa3[17][14]) ||
						(mapa3[x][y] == mapa3[18][15]) ||
						(mapa3[x][y] == mapa3[19][15]) ||
						(mapa3[x][y] == mapa3[20][14]) ||
						(mapa3[x][y] == mapa3[21][13]) ||
						(mapa3[x][y] == mapa3[21][12]) ||
						(mapa3[x][y] == mapa3[22][12]) ||
						(mapa3[x][y] == mapa3[23][12]) ||
						(mapa3[x][y] == mapa3[24][12]) ||
						(mapa3[x][y] == mapa3[24][13]) ||
						(mapa3[x][y] == mapa3[24][14]) ||
						(mapa3[x][y] == mapa3[25][12]) ||
						(mapa3[x][y] == mapa3[25][13]) ||
						(mapa3[x][y] == mapa3[25][14]) ||
						(mapa3[x][y] == mapa3[25][15]) ||
						(mapa3[x][y] == mapa3[26][12]) ||
						(mapa3[x][y] == mapa3[26][13]) ||
						(mapa3[x][y] == mapa3[26][14]) ||
						(mapa3[x][y] == mapa3[27][12]) ||
						(mapa3[x][y] == mapa3[27][13]) ||
						(mapa3[x][y] == mapa3[27][14]) ||
						(mapa3[x][y] == mapa3[27][15]) ||
						(mapa3[x][y] == mapa3[27][16]) ||
						(mapa3[x][y] == mapa3[27][17]) ||
						(mapa3[x][y] == mapa3[26][25]) ||
						(mapa3[x][y] == mapa3[26][26]) ||
						(mapa3[x][y] == mapa3[25][26])) {
						x--;
						mapa3[x+1][y] = '#';
					}
                 else {
                    x--;
                    mapa3[x + 1][y] = ' ';
                    movimento_contador++;
                }
                mapa3[x][y] = '&';
                system("cls");
            }
        } else if (mov == 's') {
            if (mapa3[x + 1][y] != '*' && mapa3[x + 1][y] != 'D') {
                if (((mapa3[x + 1][y] == porta1) && (chave1_obtida == 0)) ||
                    ((mapa3[x + 1][y] == porta2) && (chave2_obtida == 0)) ||
                    ((mapa3[x + 1][y] == porta3) && (chave3_obtida == 0))) {
                    printf("A porta esta trancada, ache a chave respectiva para ela");
                } else if (((mapa3[x + 1][y] == porta1) && (chave1_obtida == 1)) ||
                           ((mapa3[x + 1][y] == porta2) && (chave2_obtida == 1)) ||
                           ((mapa3[x + 1][y] == porta3) && (chave3_obtida == 1))) {
                    x++;
                    mapa3[x - 1][y] = ' ';
                    movimento_contador++;
                }
                else if((mapa3[x][y] == mapa3[37][37] && chave1_obtida == 0)){
                    	x++;
                        mapa3[x-1][y] = '@';
                }
                else if((mapa3[x][y] == mapa3[29][34]) || (mapa3[x][y] == mapa3[11][19])){
                    	x++;
                        mapa3[x-1][y] = '>';
                }	
                else if((mapa3[x][y] == mapa3[30][5]) || (mapa3[x][y] == mapa3[18][17]) ){
                        x++;
                        mapa3[x-1][y] = 'O';
                }
                else if((mapa3[x][y] == mapa3[12][20]) ||
                		(mapa3[x][y] == mapa3[13][20]) ||
						(mapa3[x][y] == mapa3[14][20]) ||
						(mapa3[x][y] == mapa3[14][21]) ||
						(mapa3[x][y] == mapa3[14][22]) ||
						(mapa3[x][y] == mapa3[14][23]) ||
						(mapa3[x][y] == mapa3[14][24]) ||
						(mapa3[x][y] == mapa3[15][25]) ||
						(mapa3[x][y] == mapa3[16][25]) ||
						(mapa3[x][y] == mapa3[17][25]) ||
						(mapa3[x][y] == mapa3[18][25]) ||
						(mapa3[x][y] == mapa3[19][25]) ||
						(mapa3[x][y] == mapa3[19][26]) ||
						(mapa3[x][y] == mapa3[19][27]) ||
						(mapa3[x][y] == mapa3[19][27]) ||
						(mapa3[x][y] == mapa3[20][27]) ||
						(mapa3[x][y] == mapa3[21][27]) ||
						(mapa3[x][y] == mapa3[22][26]) ||
						(mapa3[x][y] == mapa3[22][25]) ||
						(mapa3[x][y] == mapa3[22][25]) ||
						(mapa3[x][y] == mapa3[23][24]) ||
						(mapa3[x][y] == mapa3[23][23]) ||
						(mapa3[x][y] == mapa3[24][23]) ||
						(mapa3[x][y] == mapa3[25][23]) ||
						(mapa3[x][y] == mapa3[26][22]) ||
						(mapa3[x][y] == mapa3[27][22]) ||
						(mapa3[x][y] == mapa3[27][21]) ||
						(mapa3[x][y] == mapa3[27][20]) ||
						(mapa3[x][y] == mapa3[14][17]) ||
						(mapa3[x][y] == mapa3[15][17]) ||
						(mapa3[x][y] == mapa3[16][18]) ||
						(mapa3[x][y] == mapa3[17][19]) ||
						(mapa3[x][y] == mapa3[18][19]) ||
						(mapa3[x][y] == mapa3[19][19]) ||
						(mapa3[x][y] == mapa3[19][20]) ||
						(mapa3[x][y] == mapa3[22][19]) ||
						(mapa3[x][y] == mapa3[22][18]) ||
						(mapa3[x][y] == mapa3[23][18]) ||
						(mapa3[x][y] == mapa3[24][18]) ||
						(mapa3[x][y] == mapa3[25][18]) ||
						(mapa3[x][y] == mapa3[26][18]) ||
						(mapa3[x][y] == mapa3[27][18]) ||
						(mapa3[x][y] == mapa3[12][13]) ||
						(mapa3[x][y] == mapa3[12][12]) ||
						(mapa3[x][y] == mapa3[13][12]) ||
						(mapa3[x][y] == mapa3[14][12]) ||
						(mapa3[x][y] == mapa3[15][12]) ||
						(mapa3[x][y] == mapa3[16][12]) ||
						(mapa3[x][y] == mapa3[17][12]) ||
						(mapa3[x][y] == mapa3[17][13]) ||
						(mapa3[x][y] == mapa3[17][14]) ||
						(mapa3[x][y] == mapa3[18][15]) ||
						(mapa3[x][y] == mapa3[19][15]) ||
						(mapa3[x][y] == mapa3[20][14]) ||
						(mapa3[x][y] == mapa3[21][13]) ||
						(mapa3[x][y] == mapa3[21][12]) ||
						(mapa3[x][y] == mapa3[22][12]) ||
						(mapa3[x][y] == mapa3[23][12]) ||
						(mapa3[x][y] == mapa3[24][12]) ||
						(mapa3[x][y] == mapa3[24][13]) ||
						(mapa3[x][y] == mapa3[24][14]) ||
						(mapa3[x][y] == mapa3[25][12]) ||
						(mapa3[x][y] == mapa3[25][13]) ||
						(mapa3[x][y] == mapa3[25][14]) ||
						(mapa3[x][y] == mapa3[25][15]) ||
						(mapa3[x][y] == mapa3[26][12]) ||
						(mapa3[x][y] == mapa3[26][13]) ||
						(mapa3[x][y] == mapa3[26][14]) ||
						(mapa3[x][y] == mapa3[27][12]) ||
						(mapa3[x][y] == mapa3[27][13]) ||
						(mapa3[x][y] == mapa3[27][14]) ||
						(mapa3[x][y] == mapa3[27][15]) ||
						(mapa3[x][y] == mapa3[27][16]) ||
						(mapa3[x][y] == mapa3[27][17]) ||
						(mapa3[x][y] == mapa3[26][25]) ||
						(mapa3[x][y] == mapa3[26][26]) ||
						(mapa3[x][y] == mapa3[25][26])) {
						x++;
						mapa3[x-1][y] = '#';
					}
                 else {
                    x++;
                    mapa3[x - 1][y] = ' ';
                    movimento_contador++;
                }
                mapa3[x][y] = '&';
                system("cls");
            }
        } else if (mov == 'a') {
            if (mapa3[x][y - 1] != '*' && mapa3[x][y - 1] != 'D') {
                if (((mapa3[x][y - 1] == porta1) && (chave1_obtida == 0)) ||
                    ((mapa3[x][y - 1] == porta2) && (chave2_obtida == 0)) ||
                    ((mapa3[x][y - 1] == porta3) && (chave3_obtida == 0))) {
                    printf("A porta esta trancada, ache a chave respectiva para ela");
                } else if (((mapa3[x][y - 1] == porta1) && (chave1_obtida == 1)) ||
                           ((mapa3[x][y - 1] == porta2) && (chave2_obtida == 1)) ||
                           ((mapa3[x][y - 1] == porta3) && (chave3_obtida == 1))) {
                    y--;
                    mapa3[x][y + 1] = ' ';
                    movimento_contador++;
                }
                else if((mapa3[x][y] == mapa3[37][37] && chave1_obtida == 0)){
                    	y--;
                        mapa3[x][y+1] = '@';
                }
                else if((mapa3[x][y] == mapa3[29][34] || (mapa3[x][y] == mapa3[11][19]))){
                    	y--;
                        mapa3[x][y+1] = '>';
                }
                else if((mapa3[x][y] == mapa3[30][5]) || (mapa3[x][y] == mapa3[18][17]) ){
                        y--;
                        mapa3[x][y+1] = 'O';
                }
                else if((mapa3[x][y] == mapa3[12][20]) ||
                		(mapa3[x][y] == mapa3[13][20]) ||
						(mapa3[x][y] == mapa3[14][20]) ||
						(mapa3[x][y] == mapa3[14][21]) ||
						(mapa3[x][y] == mapa3[14][22]) ||
						(mapa3[x][y] == mapa3[14][23]) ||
						(mapa3[x][y] == mapa3[14][24]) ||
						(mapa3[x][y] == mapa3[15][25]) ||
						(mapa3[x][y] == mapa3[16][25]) ||
						(mapa3[x][y] == mapa3[17][25]) ||
						(mapa3[x][y] == mapa3[18][25]) ||
						(mapa3[x][y] == mapa3[19][25]) ||
						(mapa3[x][y] == mapa3[19][26]) ||
						(mapa3[x][y] == mapa3[19][27]) ||
						(mapa3[x][y] == mapa3[19][27]) ||
						(mapa3[x][y] == mapa3[20][27]) ||
						(mapa3[x][y] == mapa3[21][27]) ||
						(mapa3[x][y] == mapa3[22][26]) ||
						(mapa3[x][y] == mapa3[22][25]) ||
						(mapa3[x][y] == mapa3[22][25]) ||
						(mapa3[x][y] == mapa3[23][24]) ||
						(mapa3[x][y] == mapa3[23][23]) ||
						(mapa3[x][y] == mapa3[24][23]) ||
						(mapa3[x][y] == mapa3[25][23]) ||
						(mapa3[x][y] == mapa3[26][22]) ||
						(mapa3[x][y] == mapa3[27][22]) ||
						(mapa3[x][y] == mapa3[27][21]) ||
						(mapa3[x][y] == mapa3[27][20]) ||
						(mapa3[x][y] == mapa3[14][17]) ||
						(mapa3[x][y] == mapa3[15][17]) ||
						(mapa3[x][y] == mapa3[16][18]) ||
						(mapa3[x][y] == mapa3[17][19]) ||
						(mapa3[x][y] == mapa3[18][19]) ||
						(mapa3[x][y] == mapa3[19][19]) ||
						(mapa3[x][y] == mapa3[19][20]) ||
						(mapa3[x][y] == mapa3[22][19]) ||
						(mapa3[x][y] == mapa3[22][18]) ||
						(mapa3[x][y] == mapa3[23][18]) ||
						(mapa3[x][y] == mapa3[24][18]) ||
						(mapa3[x][y] == mapa3[25][18]) ||
						(mapa3[x][y] == mapa3[26][18]) ||
						(mapa3[x][y] == mapa3[27][18]) ||
						(mapa3[x][y] == mapa3[12][13]) ||
						(mapa3[x][y] == mapa3[12][12]) ||
						(mapa3[x][y] == mapa3[13][12]) ||
						(mapa3[x][y] == mapa3[14][12]) ||
						(mapa3[x][y] == mapa3[15][12]) ||
						(mapa3[x][y] == mapa3[16][12]) ||
						(mapa3[x][y] == mapa3[17][12]) ||
						(mapa3[x][y] == mapa3[17][13]) ||
						(mapa3[x][y] == mapa3[17][14]) ||
						(mapa3[x][y] == mapa3[18][15]) ||
						(mapa3[x][y] == mapa3[19][15]) ||
						(mapa3[x][y] == mapa3[20][14]) ||
						(mapa3[x][y] == mapa3[21][13]) ||
						(mapa3[x][y] == mapa3[21][12]) ||
						(mapa3[x][y] == mapa3[22][12]) ||
						(mapa3[x][y] == mapa3[23][12]) ||
						(mapa3[x][y] == mapa3[24][12]) ||
						(mapa3[x][y] == mapa3[24][13]) ||
						(mapa3[x][y] == mapa3[24][14]) ||
						(mapa3[x][y] == mapa3[25][12]) ||
						(mapa3[x][y] == mapa3[25][13]) ||
						(mapa3[x][y] == mapa3[25][14]) ||
						(mapa3[x][y] == mapa3[25][15]) ||
						(mapa3[x][y] == mapa3[26][12]) ||
						(mapa3[x][y] == mapa3[26][13]) ||
						(mapa3[x][y] == mapa3[26][14]) ||
						(mapa3[x][y] == mapa3[27][12]) ||
						(mapa3[x][y] == mapa3[27][13]) ||
						(mapa3[x][y] == mapa3[27][14]) ||
						(mapa3[x][y] == mapa3[27][15]) ||
						(mapa3[x][y] == mapa3[27][16]) ||
						(mapa3[x][y] == mapa3[27][17]) ||
						(mapa3[x][y] == mapa3[26][25]) ||
						(mapa3[x][y] == mapa3[26][26]) ||
						(mapa3[x][y] == mapa3[25][26])) {
						y--;
						mapa3[x][y+1] = '#';
					}
                 else {
                    y--;
                    mapa3[x][y + 1] = ' ';
                    movimento_contador++;
                }
                mapa3[x][y] = '&';
                system("cls");
            }
        } else if (mov == 'd') {
            if (mapa3[x][y + 1] != '*' && mapa3[x][y + 1] != 'D') {
                if (((mapa3[x][y + 1] == porta1) && (chave1_obtida == 0)) ||
                    ((mapa3[x][y + 1] == porta2) && (chave2_obtida == 0)) ||
                    ((mapa3[x][y + 1] == porta3) && (chave3_obtida == 0))) {
                    printf("A porta esta trancada, ache a chave respectiva para ela");
                } else if (((mapa3[x][y + 1] == porta1) && (chave1_obtida == 1)) ||
                           ((mapa3[x][y + 1] == porta2) && (chave2_obtida == 1)) ||
                           ((mapa3[x][y + 1] == porta3) && (chave3_obtida == 1))) {
                    y++;
                    mapa3[x][y - 1] = ' ';
                    movimento_contador++;
                }
                else if((mapa3[x][y] == mapa3[37][37] && chave1_obtida == 0)){
                    	y++;
                        mapa3[x][y-1] = '@';
                }
                else if((mapa3[x][y] == mapa3[29][34] || (mapa3[x][y] == mapa3[11][19]))){
                    	y++;
                        mapa3[x][y-1] = '>';
                }
                else if((mapa3[x][y] == mapa3[30][5]) || (mapa3[x][y] == mapa3[18][17]) ){
                        y++;
                        mapa3[x][y-1] = 'O';
                }
                else if((mapa3[x][y] == mapa3[12][20]) ||
                		(mapa3[x][y] == mapa3[13][20]) ||
						(mapa3[x][y] == mapa3[14][20]) ||
						(mapa3[x][y] == mapa3[14][21]) ||
						(mapa3[x][y] == mapa3[14][22]) ||
						(mapa3[x][y] == mapa3[14][23]) ||
						(mapa3[x][y] == mapa3[14][24]) ||
						(mapa3[x][y] == mapa3[15][25]) ||
						(mapa3[x][y] == mapa3[16][25]) ||
						(mapa3[x][y] == mapa3[17][25]) ||
						(mapa3[x][y] == mapa3[18][25]) ||
						(mapa3[x][y] == mapa3[19][25]) ||
						(mapa3[x][y] == mapa3[19][26]) ||
						(mapa3[x][y] == mapa3[19][27]) ||
						(mapa3[x][y] == mapa3[19][27]) ||
						(mapa3[x][y] == mapa3[20][27]) ||
						(mapa3[x][y] == mapa3[21][27]) ||
						(mapa3[x][y] == mapa3[22][26]) ||
						(mapa3[x][y] == mapa3[22][25]) ||
						(mapa3[x][y] == mapa3[22][25]) ||
						(mapa3[x][y] == mapa3[23][24]) ||
						(mapa3[x][y] == mapa3[23][23]) ||
						(mapa3[x][y] == mapa3[24][23]) ||
						(mapa3[x][y] == mapa3[25][23]) ||
						(mapa3[x][y] == mapa3[26][22]) ||
						(mapa3[x][y] == mapa3[27][22]) ||
						(mapa3[x][y] == mapa3[27][21]) ||
						(mapa3[x][y] == mapa3[27][20]) ||
						(mapa3[x][y] == mapa3[14][17]) ||
						(mapa3[x][y] == mapa3[15][17]) ||
						(mapa3[x][y] == mapa3[16][18]) ||
						(mapa3[x][y] == mapa3[17][19]) ||
						(mapa3[x][y] == mapa3[18][19]) ||
						(mapa3[x][y] == mapa3[19][19]) ||
						(mapa3[x][y] == mapa3[19][20]) ||
						(mapa3[x][y] == mapa3[22][19]) ||
						(mapa3[x][y] == mapa3[22][18]) ||
						(mapa3[x][y] == mapa3[23][18]) ||
						(mapa3[x][y] == mapa3[24][18]) ||
						(mapa3[x][y] == mapa3[25][18]) ||
						(mapa3[x][y] == mapa3[26][18]) ||
						(mapa3[x][y] == mapa3[27][18]) ||
						(mapa3[x][y] == mapa3[12][13]) ||
						(mapa3[x][y] == mapa3[12][12]) ||
						(mapa3[x][y] == mapa3[13][12]) ||
						(mapa3[x][y] == mapa3[14][12]) ||
						(mapa3[x][y] == mapa3[15][12]) ||
						(mapa3[x][y] == mapa3[16][12]) ||
						(mapa3[x][y] == mapa3[17][12]) ||
						(mapa3[x][y] == mapa3[17][13]) ||
						(mapa3[x][y] == mapa3[17][14]) ||
						(mapa3[x][y] == mapa3[18][15]) ||
						(mapa3[x][y] == mapa3[19][15]) ||
						(mapa3[x][y] == mapa3[20][14]) ||
						(mapa3[x][y] == mapa3[21][13]) ||
						(mapa3[x][y] == mapa3[21][12]) ||
						(mapa3[x][y] == mapa3[22][12]) ||
						(mapa3[x][y] == mapa3[23][12]) ||
						(mapa3[x][y] == mapa3[24][12]) ||
						(mapa3[x][y] == mapa3[24][13]) ||
						(mapa3[x][y] == mapa3[24][14]) ||
						(mapa3[x][y] == mapa3[25][12]) ||
						(mapa3[x][y] == mapa3[25][13]) ||
						(mapa3[x][y] == mapa3[25][14]) ||
						(mapa3[x][y] == mapa3[25][15]) ||
						(mapa3[x][y] == mapa3[26][12]) ||
						(mapa3[x][y] == mapa3[26][13]) ||
						(mapa3[x][y] == mapa3[26][14]) ||
						(mapa3[x][y] == mapa3[27][12]) ||
						(mapa3[x][y] == mapa3[27][13]) ||
						(mapa3[x][y] == mapa3[27][14]) ||
						(mapa3[x][y] == mapa3[27][15]) ||
						(mapa3[x][y] == mapa3[27][16]) ||
						(mapa3[x][y] == mapa3[27][17]) ||
						(mapa3[x][y] == mapa3[26][25]) ||
						(mapa3[x][y] == mapa3[26][26]) ||
						(mapa3[x][y] == mapa3[25][26])) {
						y++;
						mapa3[x][y-1] = '#';
					}
                 else {
                    y++;
                    mapa3[x][y - 1] = ' ';
                    movimento_contador++;
                }
                mapa3[x][y] = '&';
                system("cls");
            }
        }
        system("cls");
        
        if(mov == 'i' && mapa3[x][y] == mapa3[30][5]){
        	//Tunel Cima
        	mapa3[33][10] = ' ';
        	mapa3[33][29] = ' ';
        	mapa3[32][11] = '*';
        	mapa3[32][12] = '*';
        	mapa3[32][13] = '*';
        	mapa3[32][14] = '*';
        	mapa3[32][15] = '*';
        	mapa3[32][16] = '*';
        	mapa3[32][17] = '*';
        	mapa3[32][18] = '*';
        	mapa3[32][19] = '*';
        	mapa3[32][20] = '*';
        	mapa3[32][21] = '*';
        	mapa3[32][22] = '*';
        	mapa3[32][23] = '*';
        	mapa3[32][24] = '*';
        	mapa3[32][25] = '*';
        	mapa3[32][26] = '*';
        	mapa3[32][27] = '*';
        	mapa3[32][28] = '*';
        	mapa3[32][29] = '*';
        	//Tunel Baixo
        	mapa3[34][11] = '*';
        	mapa3[34][12] = '*';
        	mapa3[34][13] = '*';
        	mapa3[34][14] = '*';
        	mapa3[34][15] = '*';
        	mapa3[34][16] = '*';
        	mapa3[34][17] = '*';
        	mapa3[34][18] = '*';
        	mapa3[34][19] = '*';
        	mapa3[34][20] = '*';
        	mapa3[34][21] = '*';
        	mapa3[34][22] = '*';
        	mapa3[34][23] = '*';
        	mapa3[34][24] = '*';
        	mapa3[34][25] = '*';
        	mapa3[34][26] = '*';
        	mapa3[34][27] = '*';
        	mapa3[34][28] = '*';
        	mapa3[34][29] = '*';
        	//Chave
        	mapa3[37][37] = '@';
		}
		if(mov == 'i' && mapa3[x][y] == mapa3[9][9]){
        	//Tunel Cima parte superior
        	mapa3[5][10] = ' ';
        	mapa3[5][29] = ' ';
        	mapa3[4][11] = '*';
        	mapa3[4][12] = '*';
        	mapa3[4][13] = '*';
        	mapa3[4][14] = '*';
        	mapa3[4][15] = '*';
        	mapa3[4][16] = '*';
        	mapa3[4][17] = '*';
        	mapa3[4][18] = '*';
        	mapa3[4][19] = '*';
        	mapa3[4][20] = '*';
        	mapa3[4][21] = '*';
        	mapa3[4][22] = '*';
        	mapa3[4][23] = '*';
        	mapa3[4][24] = '*';
        	mapa3[4][25] = '*';
        	mapa3[4][26] = '*';
        	mapa3[4][27] = '*';
        	mapa3[4][28] = '*';
        	mapa3[4][29] = '*';
        	//Tunel Baixo parte superior
        	mapa3[6][11] = '*';
        	mapa3[6][12] = '*';
        	mapa3[6][13] = '*';
        	mapa3[6][14] = '*';
        	mapa3[6][15] = '*';
        	mapa3[6][16] = '*';
        	mapa3[6][17] = '*';
        	mapa3[6][18] = '*';
        	mapa3[6][19] = '*';
        	mapa3[6][20] = '*';
        	mapa3[6][21] = '*';
        	mapa3[6][22] = '*';
        	mapa3[6][23] = '*';
        	mapa3[6][24] = '*';
        	mapa3[6][25] = '*';
        	mapa3[6][26] = '*';
        	mapa3[6][27] = '*';
        	mapa3[6][28] = '*';
        	mapa3[6][29] = '*';
        	//Chave
        	mapa3[37][37] = '@';
		}
		else if(mov == 'i' && (x == 37 && y == 37)){
                chave1_obtida++;
                mapa3[3][38] = '=';
                mapa3[3][39] = '=';
                system("cls");
        }
		if(mov == 'w' && (x == 29 && y == 34)){
			mapa3[x][y] = ' ';
			mapa3[29][34] = '>';
			int destX = 12;
			int destY = 19;
			x = destX;
    		y = destY;
    		mapa3[x][y] = '&';
		}
		if(mov == 'w' && (x == 11 && y == 19)){
			mapa3[x][y] = ' ';
			mapa3[11][19] = '>';
			int destX = 29;
			int destY = 34;
			x = destX;
    		y = destY;
    		mapa3[x][y] = '&';
		}
		if(mov == 's' && (x == 28 && y == 19)){
			mapa3[x][y] = ' ';
			mapa3[28][19] = '>';
			int destX = 5;
			int destY = 2;
			x = destX;
    		y = destY;
    		mapa3[x][y] = '&';
		}
		if(mov == 'a' && (x == 5 && y == 1)){
			mapa3[x][y] = ' ';
			mapa3[5][1] = '>';
			int destX = 27;
			int destY = 19;
			x = destX;
    		y = destY;
    		mapa3[x][y] = '&';
		}
					 if((mapa3[x][y] == mapa3[12][20]) ||
                		(mapa3[x][y] == mapa3[13][20]) ||
						(mapa3[x][y] == mapa3[14][20]) ||
						(mapa3[x][y] == mapa3[14][21]) ||
						(mapa3[x][y] == mapa3[14][22]) ||
						(mapa3[x][y] == mapa3[14][23]) ||
						(mapa3[x][y] == mapa3[14][24]) ||
						(mapa3[x][y] == mapa3[15][25]) ||
						(mapa3[x][y] == mapa3[16][25]) ||
						(mapa3[x][y] == mapa3[17][25]) ||
						(mapa3[x][y] == mapa3[18][25]) ||
						(mapa3[x][y] == mapa3[19][25]) ||
						(mapa3[x][y] == mapa3[19][26]) ||
						(mapa3[x][y] == mapa3[19][27]) ||
						(mapa3[x][y] == mapa3[19][27]) ||
						(mapa3[x][y] == mapa3[20][27]) ||
						(mapa3[x][y] == mapa3[21][27]) ||
						(mapa3[x][y] == mapa3[22][26]) ||
						(mapa3[x][y] == mapa3[22][25]) ||
						(mapa3[x][y] == mapa3[22][25]) ||
						(mapa3[x][y] == mapa3[23][24]) ||
						(mapa3[x][y] == mapa3[23][23]) ||
						(mapa3[x][y] == mapa3[24][23]) ||
						(mapa3[x][y] == mapa3[25][23]) ||
						(mapa3[x][y] == mapa3[26][22]) ||
						(mapa3[x][y] == mapa3[27][22]) ||
						(mapa3[x][y] == mapa3[27][21]) ||
						(mapa3[x][y] == mapa3[27][20]) ||
						(mapa3[x][y] == mapa3[14][17]) ||
						(mapa3[x][y] == mapa3[15][17]) ||
						(mapa3[x][y] == mapa3[16][18]) ||
						(mapa3[x][y] == mapa3[17][19]) ||
						(mapa3[x][y] == mapa3[18][19]) ||
						(mapa3[x][y] == mapa3[19][19]) ||
						(mapa3[x][y] == mapa3[19][20]) ||
						(mapa3[x][y] == mapa3[22][19]) ||
						(mapa3[x][y] == mapa3[22][18]) ||
						(mapa3[x][y] == mapa3[23][18]) ||
						(mapa3[x][y] == mapa3[24][18]) ||
						(mapa3[x][y] == mapa3[25][18]) ||
						(mapa3[x][y] == mapa3[26][18]) ||
						(mapa3[x][y] == mapa3[27][18]) ||
						(mapa3[x][y] == mapa3[12][13]) ||
						(mapa3[x][y] == mapa3[12][12]) ||
						(mapa3[x][y] == mapa3[13][12]) ||
						(mapa3[x][y] == mapa3[14][12]) ||
						(mapa3[x][y] == mapa3[15][12]) ||
						(mapa3[x][y] == mapa3[16][12]) ||
						(mapa3[x][y] == mapa3[17][12]) ||
						(mapa3[x][y] == mapa3[17][13]) ||
						(mapa3[x][y] == mapa3[17][14]) ||
						(mapa3[x][y] == mapa3[18][15]) ||
						(mapa3[x][y] == mapa3[19][15]) ||
						(mapa3[x][y] == mapa3[20][14]) ||
						(mapa3[x][y] == mapa3[21][13]) ||
						(mapa3[x][y] == mapa3[21][12]) ||
						(mapa3[x][y] == mapa3[22][12]) ||
						(mapa3[x][y] == mapa3[23][12]) ||
						(mapa3[x][y] == mapa3[24][12]) ||
						(mapa3[x][y] == mapa3[24][13]) ||
						(mapa3[x][y] == mapa3[24][14]) ||
						(mapa3[x][y] == mapa3[25][12]) ||
						(mapa3[x][y] == mapa3[25][13]) ||
						(mapa3[x][y] == mapa3[25][14]) ||
						(mapa3[x][y] == mapa3[25][15]) ||
						(mapa3[x][y] == mapa3[26][12]) ||
						(mapa3[x][y] == mapa3[26][13]) ||
						(mapa3[x][y] == mapa3[26][14]) ||
						(mapa3[x][y] == mapa3[27][12]) ||
						(mapa3[x][y] == mapa3[27][13]) ||
						(mapa3[x][y] == mapa3[27][14]) ||
						(mapa3[x][y] == mapa3[27][15]) ||
						(mapa3[x][y] == mapa3[27][16]) ||
						(mapa3[x][y] == mapa3[27][17]) ||
						(mapa3[x][y] == mapa3[26][25]) ||
						(mapa3[x][y] == mapa3[26][26]) ||
						(mapa3[x][y] == mapa3[25][26])){
    			vida--;
    			printf("Voce foi atingido por um espinho venenoso, Voce tem %d vidas\n", vida);
        		printf("Pressione qualquer tecla para continuar...\n");
        		getch();
        		system("cls");
		   }
		if (x == xm && y == ym){
            	vida--;
        		printf("Voce foi pego pelo monstro, Voce tem %d vidas!\n", vida);
        		printf("Pressione qualquer tecla para continuar...\n");
        		getch();
        		system("cls");
    		}
    	if (x == xm2 && y == ym2){
            	vida--;
        		printf("Voce foi pego pelo monstro, Voce tem %d vidas!\n", vida);
        		printf("Pressione qualquer tecla para continuar...\n");
        		getch();
        		system("cls");
    		}
		if(vida==0){
				printf("Voce Morreu, Voce e pessimo vai treinar\n");
        		printf("Pressione qualquer tecla para continuar...\n");
        		getch();
        		system("cls");
        		return fase3();
			}
		else if(mov == 'd' && (x == 3 && y == 39)){
            	printf("E FINALMENTE CASSEB ACHA O GIRROTO\nGirroto: Casseb! Voce nao sabe como e bom ver uma cara amiga. Achei que nunca mais sairia dessa caverna.\n"
           				"Casseb: Girroto! Que alivio te encontrar! Estava te procurando ha horas. Voce esta bem?\n"
           				"Girroto: Agora estou melhor, mas foi assustador. A caverna e um verdadeiro labirinto. Cada passagem parecia igual, e eu acabei me perdendo completamente.\n"
           				"Casseb: Imagino o desespero. Mas fique tranquilo, ja estamos quase fora. Por onde voce entrou?\n"
           				"Girroto: Entrei por uma abertura estreita perto de um grande carvalho. Estava seguindo algumas pegadas, mas elas sumiram de repente, e eu acabei entrando mais fundo na caverna.\n"
           				"Casseb: Essa caverna e traicoeira. Muita gente ja se perdeu por aqui. Ainda bem que trouxe minha tocha e alguns suprimentos. Aqui, tome um pouco de agua.\n"
           				"Girroto: Muito obrigado, Casseb. Nao sei como te agradecer. Estava comecando a perder as esperancas.\n"
           				"Casseb: Nao precisa agradecer, Girroto. Somos amigos, e claro que eu viria te procurar. Alem disso, voc� faria o mesmo por mim.\n"
           				"Girroto: Com certeza faria. Mas agora, so quero sair daqui. Sabe o caminho?\n"
           				"Casseb: Sim, seguimos por aqui. Tenho uma marcacao no caminho que fiz para nao me perder tambem. Vamos devagar e com cuidado.\n"
           				"Girroto: Tudo bem. S� de saber que estamos saindo ja me sinto mais aliviado.\n"
           				"Casseb: Vamos la, Girroto. Logo estaremos fora dessa escuridao. E depois disso, prometo que nunca mais nos aventuramos em uma caverna sem um bom mapa!\n"
           				"Girroto: Combinado. Agora, vamos sair daqui e respirar um pouco de ar fresco. Estou mais do que pronto para isso.\n");
           				printf("\nPARABENS VOCE ZEROU O GAME DO GOAT CASSEB E O MESTRE GIRAS, PARABENS E OBRIGADO POR JOGAR!\n");
            		printf("Pressione qualquer tecla para voltar ao menu.\n");
            	getch();
            	system("cls");
            	return menu();
			}
        else if(mov == 'q'){
            printf("Deseja sair do jogo? (S/N): ");
            char resposta;
            scanf(" %c", &resposta);
            if(resposta == 'S' || resposta == 's') {
                printf("Voce saiu do jogo.\n");
                printf("Pressione qualquer tecla para voltar ao menu.\n");
                getch();
                system("cls");
                return menu();
            }
    }
}
}
int main() {
    menu();
    return 0;
}
