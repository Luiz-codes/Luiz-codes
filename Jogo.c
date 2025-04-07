#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_NAME 50 
#define MAX_POTIONS 3
#define PLAYER_MAX_HP 100
#define ENEMY_COUNT 3

typedef struct{
	char nome[MAX_NAME];
	int hp;
	int ataque;
	int defesa;
	int potions
}Personagem;

typedef struct{
	char nome[MAX_NAME];
	int hp;
	int ataque;
	int defesa;
}Inimigo;

void limparTela(){
	printf("\n===============================\n");
}

void exibirStatus(Personagem p){
	printf("\n[%s]\n",p.nome);
	printf("HP:%d | Ataque: %d | Defesa: %d | Pocoes: %d\n",p.hp, p.ataque, p.defesa, p.potions);	
}

void exibirInimigo(Inimigo e){
	printf("\n[Inimigo : %s]\n,", e.nome);
	printf("HP: %d | Ataque: %d | Defesa: %d\n", e.hp, e.ataque, e.defesa);	
}
int calcularDano(int ataque, int defesa){
	int danoBase = ataque - defesa;
	if(danoBase < 0) danoBase = 0;
	
	if(rand() % 10 == 0){
		printf("Critico!\n");
		danoBase *= 2;
	}
	return danoBase;
}

void usarPocao(Personagem *p){
    if(p->potions > 0){
    	int cura = 25 + (rand()% 11);
    	p->hp += cura;
    	if(p->hp > PLAYER_MAX_HP) p->hp = PLAYER_MAX_HP;
    	p->potions--;
    	 printf("%s usou uma pocao e recuperação %d de HP!\n ", p->nome, cura,);
	} else{
		printf("Perigo!, Você nao tem mais porcoes!\n");
	}	
}

int turnoDoJogador(Personagem* player, Inimigo *inimigo){
	int escolha;
	printf("\nSeu turno! O que deseja fazer?\n");
	printf("1 - Atacar\n");
	printf("2 - Usar porcao\n");
	printf("Escolha: ");
	scanf("%d",&escolha);
	
	if (escolha == 1){
		int dano  = calcularDano(player->ataque, inimigo->defesa);
		inimigo->hp -= dano;
		if(inimgo->hp < 0) inimigo->hp = 0;
		printf("Voce causou %d de dano em %s!\n", dano, inimigo->nome);	
	} else if(escolha == 2){
		usarPocao(player);
	} else {
		printf("Escolha invalida. Perdeu a vez!\n");
	}
	 return inimigo->hp <=0;
} 
int turnoDoInimigo(Personagem *player, Inimigo*inimigo){
	printf("%s causou %d de dano em voce!\n",inimigo->nome, dano);
	int dano = calcularDano(inimigo ->ataque,player->defesa);
	player->hp -= dano;
	if (player ->hp < 0) player->hp =;
	printf("%s causou %d de dan em voce!\n",inimigo->nome, dano);
	
	return player->hp <= 0;
}
 Inimigo gerarInimigo(int nivel){
 	inimigo e;
 	sprintf(e.nome,"Globoli Nivel %d",nivel + 1);
 	e.hp = 40 + rand() % 20 +(nivel * 10);
 	e.ataque = 10 + nivel * 2;
 	e.defesa = 5 + rand() % 3;
 	return e;
 }
 void iniciarBatalha(Personagem *jogador){
 	for (int i = 0; i < ENEMY_COUNT; i++){
 		Inimigo inimigo = gerarInimigo(i);
		 limparTela();
		 printf("Batalha!, Enfrentando %s!\n",inimigo.nome);
		 
		 while (jogador->hp > 0 && inimigo;hp > 0){
		 	exibirStatus(*jogador);
		 	exibirInimigo(inimigo);
		 	
		 	if (turnoDoJogador(jogador, &inimigo)){
		 		printf("\nVoce derrotou! %s!\n",inimigo.nome);
			 }
			 if (turnoDoInimigo(jogador,&inimigo)){
			 	printf ("\nNAO!,Voce foi derrotado por %...\n",inimigo.nome);
			 	return;
			 }
			 
		 }
		 printf("\nSupresa, Recompensa: +1 porcao!\n");
		 jogador -> potions++;
		 if(jogador ->potions > MAX_POTIONS) jogador->ataque = MAX_POTIONS;
		 
		 printf("Pressione Enter para continuar...");
		 getchar(); getchar();
     }
    printf("Viva!,%s! Voce derrotou os inimigos!\n", jogador->nome);
 }
 int main(){
 	srand(time(NULL));
 	
 	Persongem jogador;
 	printf("Digite o nome do seu personagem: ");
 	fgets(jogador.nome, MAX_NAME stdin);
 	jogador.nome[strcspn(jogador.nome,"\n")] = '\0';
 	jogador.hp = PLAYER_MAX_HP;
    jogador.ataque = 20;
    jogador.defesa = 10;
    jogador.potions = 2;
    
    iniciarBatalha(&jogador);
    
    return 0;
}
