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
//Menu Inicial
void menu(){
    int menu1;
    	printf("Menu Principal\n(1) Jogar\n(2) Tutorial\n(3) Sair\n");
    	scanf("%d", &menu1);
        if(menu1 == 1){
            jogar();
        }
        else if(menu1 == 2){
            tutorial();
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
        //Posicao inicial do monstro 2
        int xm2 = 16, ym2 = 9;
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
            // Monstro nivel 2
             mapa2[xm2][ym2] = 'V';
        if (movimento_contador == 2){
            int dif_x = x - xm2;
            int dif_y = y - ym2;
            if (abs(dif_x) > abs(dif_y)){
                if (dif_x > 0){
                    xm2 ++;
                    mapa2[xm2 - 1][ym2] = ' ';
                }
                else if (dif_x < 0){
                    xm2 --;
                    mapa2[xm2 + 1][ym2] = ' ';
                }
            }
            else{
                if (dif_y > 0){
                    ym2 ++;
                    mapa2[xm2][ym2 - 1] = ' ';
                }
                else if (dif_y < 0){
                    ym2 --;
                    mapa2[xm2][ym2 + 1] = ' ';
                }
            }
            movimento_contador = 0;
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
    		if (x == xm2 && y == ym2){
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
            	printf("Parabens, voce escapou do labirinto da morte e passou para a fase 3.\n");
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
	int vida;
	int i, j;
	system("cls");
	printf("Terceira Fase\n");
    char mapa3[40][40];
        for(i = 0; i < 40; i++){
            for(j = 0; j < 40; j++){
                //Paredes externas
                if(i == 0 || i == 39){
                    mapa3[i][j] = '*';
                }
                else if (j == 0 || j == 39){
                    mapa3[i][j] = '*';
                }
                //Espacos Vazios
                else if (i > 0 && i < 39){
                    mapa3[i][j] = ' ';
                }
			  }
            }
            while(1){
    			//impriminmdo o mapa
    			for(i=0;i<40;i++){
    				for(j=0;j<40;j++){
    					printf("%c ", mapa3[i][j]);
					}
					printf("\n");
				}
			
			}
}
int main() {
    menu();
    return 0;
}
