#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings
#include <windows.h> //biblioteca com API's do Windows

int registro() //Fun��o respons�vel por registrar usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem de caracteres utilizados em lingua portuguesa
	
	//In�cio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�veis/string
	
	
	printf("Voc� escolheu o registro de nomes!\n"); 
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //Refere-se ao armazenamento de strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //Cria o arquivo do banco de dados
	file = fopen(arquivo, "w"); //Cria o arquivo na pasta de desenvolvimento do programa. "W" significa write, escrever.
	fprintf(file,cpf); //Salva o valor da vari�vel
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
	
	printf("Voc� escolheu consultar nomes!\n");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEstas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
		
	system("\npause");
}

int deletar()
{
	char cpf[40];

	printf("Voc� escolheu deletar nomes!\n\n");
	printf("Digite o CPF a ser deletado:\n");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!\n");
	}
	
	else(file != NULL);
	{
		printf("O registro foi exclu�do\n");
	}
	
	system("pause");
	
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada[10]="a"; //Senha fixa para o acesso do sistema
	int comparacao; //este int retorno significa o retorno que a fun��o strcmp vai me dar, caso o retorno for 0 significa que a array � igual a admin, se for diferente de zero, no caso else, vai dar como senha inv�lida
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",&senhadigitada); //Devemos colocar o & para atribuir o valor para a vari�vel
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		for(laco=1;laco=1;)
		{	
			setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
		
			printf("### Cart�rio da EBAC ###\n\n"); //In�cio do Menu
			printf("Escolha a op��o desejada no menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Sair do Sistema\n\n");
			printf("Op��o: "); //Fim do menu
	
			scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
			system ("cls"); //Respons�vel por limpar a tela
	
			switch(opcao) //In�cio da sele��o do menu
			{
				case 1: //In�cio da sele��o
				registro(); //Chamada de fun��es
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
			
				default: //Sele��o al�m das indicadas
				printf("Esta op��o n�o est� dispon�vel!\n");
				system("pause");
				break;	
			}//fim da sele��o
		}	
	}
	
	else
		printf("Senha incorreta!");
}
