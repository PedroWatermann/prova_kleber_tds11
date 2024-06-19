#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
struct produto{
	int codigo;
	char descricao[50];
	double preco;
	int estoque;
};
struct produto p[200];
void menu(){
	system("cls");
	printf("\nDigite a opção desejada");
	printf("\n1-Cadastro de produtos");
	printf("\n2-Relatório de produtos");
	printf("\n3-Realizar vendas");
	printf("\n4-Gerenciamento de estoque");
	printf("\n5-Sair");
	printf("\nOpção: ");
}
int seq=0,vd=1;
double vendas[200];

void cadastro(){
	system("cls");
	p[seq].codigo=seq+1;
	printf("\nDigite o nome do produto: ");
	fflush(stdin);
	gets(p[seq].descricao);
	printf("\nDigite o preço do produto: ");
	fflush(stdin);
	scanf("%lf", &p[seq].preco);
	printf("\nDigite o estoque inicial: ");
	scanf("%d", &p[seq].estoque);
	seq++;
}

void venda(){
	char resp = ' ';
	int cod,cont,qtde,existe=1;
	double valorTotal=0;
	while(resp != 'N' &&
	 resp != 'n') {
		printf("\nDigite o código do produto: ");
		scanf("%i",&cod);
		for(cont=0;cont<seq;cont++){
			if(cod==p[cont].codigo){
				printf("\nProduto: %s\n",p[cont].descricao);
				printf("\nDigite a quantidade: ");
				scanf("%i",&qtde);
				p[cont].estoque-=qtde;
				valorTotal=(qtde*p[cont].preco)+valorTotal;
				existe=1;
			}else{
				printf("\nProduto não cadastrado!\n");
				system("pause");
				existe=0;
				break;
			}
			printf("\ndeseja mais algum produto?\n S-sim N-não\n");
			fflush(stdin);
			scanf("%c",&resp);
			break;
		}
	}
	
	printf("\nO valor total da venda é: %.2lf\n",valorTotal);
	vendas[vd]=valorTotal;
	vd++;
}

void relatorio() {
	int x;
	for(x = 0; x < vd; x++) {
		printf("\n*********************\n");
		printf("\nVenda n: %i\nvalor: %.2lf\n", x + 1, vendas[x]);
		printf("Estoque atual: %i\n", p[x].estoque);
		
	}
	system("pause");
}

void gerenciamento() {
	int y, codp, qtde;
	printf("\nDigite o código do produto: ");
	scanf("%i", &codp);
	for(y = 0; y < seq; y++) {
		if(codp == p[y].codigo) {
			printf("\nDigite a quantidade ou 0 para sair: ");
			scanf("%i", &qtde);
			if(qtde != 0) {
				p[y].estoque += qtde;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "Portuguese");
	int op;
	while(op != 5) {
		menu();
		scanf("%i", &op);
		switch(op) {
			case 1:
				cadastro();
				break;
			case 2:
				relatorio();
				break;
			case 3:
				venda();
				break;
			case 4:
				gerenciamento();
				break;
			case 5:
				printf("\n Saindo da aplicação\n");
				system("pause");
				break;
			default:
				printf("\nOpção inválida!\n");
				break;
		}
	}
	return 0;
}
