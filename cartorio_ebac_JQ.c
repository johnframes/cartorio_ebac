#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por registrar usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem de caracteres utilizados em lingua portuguesa
	
	//Início da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variáveis/string
	
	
	printf("Você escolheu o registro de nomes!\n"); 
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //Refere-se ao armazenamento de strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //Cria o arquivo do banco de dados
	file = fopen(arquivo, "w"); //Cria o arquivo na pasta de desenvolvimento do programa. "W" significa write, escrever.
	fprintf(file,cpf); //Salva o valor da variável
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("\npause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
	printf("Você escolheu consultar nomes!\n");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEstas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
		
	system("\npause");
}

int deletar()
{
	char cpf[40];

	printf("Você escolheu deletar nomes!\n\n");
	printf("Digite o CPF a ser deletado:\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!\n");
	}
	
	else(file != NULL);
	{
		printf("O registro foi excluído\n");
	}
	
	system("pause");
	
}

int main()
{
	int opcao=0; //Definindo variáveis
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
		system("cls");
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
		
		printf("### Cartório da EBAC ###\n\n"); //Início do Menu
		printf("Escolha a opção desejada no menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do Sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system ("cls"); //Responsável por limpar a tela
	
		switch(opcao) //Início da seleção do menu
		{
			case 1: //Início da seleção
			registro(); //Chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default: //Seleção além das indicadas
			printf("Esta opção não está disponível!\n");
			system("pause");
			break;
			//fim da seleção		
	}
	
	}
}
