#include <stdio.h>
#include <stdlib.h>

void desenharTabuleiro(char tabuleiro[][3]){
	system ("clear");//limpa a tela
		printf("\n");
		for(int i=0; i< 3; i++){
			for(int j=0; j< 3; j++){
				printf(" %c ", tabuleiro[i][j]);
				if(j < 2){
					printf("|");
				}
			}
			printf("\n");
			if(i < 2){
				printf("   +   +   \n");
			}
		}
		printf("\n");
}

char jogar(char tabuleiro[][3], int posicao, int jogadorAtual){
    int linha =(posicao - 1) / 3;
	int coluna = (posicao - 1) % 3;
    
    if(tabuleiro[linha][coluna] != 'X'  && tabuleiro[linha][coluna] != 'O'){
        tabuleiro[linha][coluna] = jogadorAtual;
    	return 0; 
	}
   
   return 1;
}

char verificaVitoria(char tabuleiro[][3]){
	for(int i=0; i<3; i++){
		if(tabuleiro[i][0]== tabuleiro[i][1] && tabuleiro[i][1]== tabuleiro[i][2]){
			return 1;
		}
	}
	
	for(int i=0; i < 3; i++){
		if(tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro [1][i]== tabuleiro[2][1]){
			return 1;
		}
	}
	
	if (tabuleiro[0][0]== tabuleiro[1][1] && tabuleiro[1][1]== tabuleiro[2][2]){
		return 1;
	}
	
	
	if (tabuleiro[0][2]== tabuleiro[1][1] && tabuleiro[1][1]== tabuleiro[2][0]){
		return 1;
	}
	
	
	return 0;
}

int main (int argc, char *argv[]){
	
	char tabuleiro[3][3]= {
		'1', '2', '3',
		'4', '5', '6',
		'7', '8', '9'
	};
	
	int jogada = 0;
	int posicao;
	
	while(jogada < 9){ //o jogo da velha tem no max. 9 jogadas
		desenharTabuleiro(tabuleiro);
		
		printf("Jogador %c, escolha uma posicao (1-9): ", (jogada % 2 == 0) ? 'X' : 'O');
		scanf("%d", &posicao);
		
		if(posicao < 1 || posicao > 9){
			printf("Posicao invalida! Escolha um numero de 1 a 9\n");
			printf("Pressione Enter para continuar...");
			getchar();
			continue;
		}
		
		char jogadorAtual = (jogada % 2 == 0) ? 'X' : 'O'; 
		if(jogar(tabuleiro, posicao, jogadorAtual)){
			printf("Posicao ocupada! Tente novamente\n");
			printf("Pressione Enter para continuar...");
			getchar();
			continue;
		}
		if (verificaVitoria(tabuleiro)){
			desenharTabuleiro(tabuleiro);
			printf("Jogador %c venceu!!\n", jogadorAtual);
			break;
		}
		
		jogada++;
	}
	
	printf("Fim do jogo! Pressione enter para sair...\n");
	getchar();
	getchar();//limpa o buffer e aguarda o comandodo usuario
	
	return 0;
}
