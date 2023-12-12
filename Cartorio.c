#include <stdio.h> // Biblioteca de comunica��o com usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // Biblioteca de aloca��o de texto por regi�o
#include <string.h> // Biblioteca respons�vel por cuidar das strings
int registro()
{
	printf("Voc� escolheu o registro de nomes!\n\n");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite seu CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);//Respons�vel por copiar valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w") ; //Cria o arquivo na pasta onde salvou o sistema
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
		
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	
	printf("Voc� escolheu consultar os nomes!\n\n");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{		
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s",conteudo);
		printf("\n\n");
		
	}
	system("pause");
}
int deletar()
{
	printf("Voc� escolheu deletar os nomes!\n\n");
	
	char cpf[40];
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}else{
		fclose(file);
		remove(cpf);
		printf("Usu�rio deletado com sucesso!\n");
		system("pause");
	}	

}

int main()
{
	
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
	int opcao = 0; //Definindo vari�veis
	int laco = 1;
	char a;
	for(laco=1; laco=1;){
		
		system("cls");
		
		printf("### CART�RIO EBAC ###\n");//inicio do menu
		printf("Escolha a op��o desejada no menu:\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair\n\n");
		printf("Op��o: ");//fim do menu
		
		scanf("%d", &opcao);//armazenando a escolha do usu�rio
		
		system("cls");
		switch(opcao){
			case 1:
				registro();
				while(1)//Loop para continuar cadastrando usu�rio caso n�o aperte S ou s
				{
					printf("\nDeseja continuar? S/N ");
					scanf("%s", &a);
					if (a == 'S' || a == 's') {
				    	printf("\nVoc� optou por continuar\n");
				    	registro();
				  	} 
					else {
				    	printf("\nVoc� optou por n�o continuar\n");
				    	break;
				  	}
			  	}
				break;
			case 2:
				consulta();
				break;
			case 3:
				deletar();
				break;
			case 4:
				return 0;
				break;
			default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
		}//fim da sele��o
	}	
	
}
