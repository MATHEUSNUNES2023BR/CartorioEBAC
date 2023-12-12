#include <stdio.h> // Biblioteca de comunicação com usuário
#include <stdlib.h> // Biblioteca de alocação de espaço em memória
#include <locale.h> // Biblioteca de alocação de texto por região
#include <string.h> // Biblioteca responsável por cuidar das strings
int registro()
{
	printf("Você escolheu o registro de nomes!\n\n");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite seu CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);//Responsável por copiar valores das strings
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w") ; //Cria o arquivo na pasta onde salvou o sistema
	fprintf(file, cpf); //salva o valor da variável
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
	
	printf("Você escolheu consultar os nomes!\n\n");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{		
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s",conteudo);
		printf("\n\n");
		
	}
	system("pause");
}
int deletar()
{
	printf("Você escolheu deletar os nomes!\n\n");
	
	char cpf[40];
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}else{
		fclose(file);
		remove(cpf);
		printf("Usuário deletado com sucesso!\n");
		system("pause");
	}	

}

int main()
{
	
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
	int opcao = 0; //Definindo variáveis
	int laco = 1;
	char a;
	for(laco=1; laco=1;){
		
		system("cls");
		
		printf("### CARTÓRIO EBAC ###\n");//inicio do menu
		printf("Escolha a opção desejada no menu:\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair\n\n");
		printf("Opção: ");//fim do menu
		
		scanf("%d", &opcao);//armazenando a escolha do usuário
		
		system("cls");
		switch(opcao){
			case 1:
				registro();
				while(1)//Loop para continuar cadastrando usuário caso não aperte S ou s
				{
					printf("\nDeseja continuar? S/N ");
					scanf("%s", &a);
					if (a == 'S' || a == 's') {
				    	printf("\nVocê optou por continuar\n");
				    	registro();
				  	} 
					else {
				    	printf("\nVocê optou por não continuar\n");
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
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;
		}//fim da seleção
	}	
	
}
