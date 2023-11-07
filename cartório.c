#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 	
#include <string.h> //biblioteca respons�vel por cuidar das string
 
int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
 {
 	//inicio de cria��o de vari�veis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��es do usu�rio 
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo	
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa "escrever"
    fprintf(file,cpf); //salvo o valor da variavel		
    fclose(file); //fecha o arquivo 
    
    file = fopen(arquivo, "a"); // abrindo o arquivo e atualizando os dados dele
    fprintf(file,",");// colocando uma virgula ap�s a atualiza��o de dados para que n�o fique "embolado" quando outro dado por atualizado posteriormente 
    fclose(file);//fechando o arquivo
    
    printf("Digite o nome a ser cadastrado: ");//coletando informa��es do usu�rio	
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");//abrindo o arquivo e o atualizando de acordo com as novas informa��es fornecidas pelo usu�rio
    fprintf(file,nome);//salvando o arquivo
    fclose(file);//fechando o arquivo
    
	file = fopen(arquivo, "a");//abrindo e atualizando o arquivo
    fprintf(file,",");//adicionando uma virgula ap�s a atualiza��o 
    fclose(file);//fechando o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: ");//coletando novas informa��es do usu�rio
    scanf("%s",sobrenome);//salvando a variavel fornecida
    
    file = fopen(arquivo, "a");//abrindo o arquivo e atualizando com o novo dado fornecido
    fprintf(file,sobrenome);//salvando a variavel no arquivo
    fclose(file);//fechando o arquivo
    
	file = fopen(arquivo, "a");//abrindo e atualizando o arquivo
    fprintf(file,",");//adicionando uma virgula ap�s a atualiza��o 
    fclose(file);//fechando o arquivo
    
    printf("Digite o cargo a ser cadastrado: ");//coletando novas informa��es do usu�rio
    scanf("%s",cargo);//salvando variavel fornecida
    
    file = fopen(arquivo, "a");//abrindo o arquivo e atualizando com o novo dado fornecido
    fprintf(file,cargo);//salvando a variavel no arquivo
    fclose(file);//fechando o arquivo
    
    system("pause");
 }
 
int consulta()//fun��o respons�vel por consultar usu�rios cadastrados no sistema
 {
    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem que ser� usada
    
    //inicio de cria��o de vari�veis/string
    char cpf[40];
    char conteudo[200];
    //fim da cria��o de vari�veis/string
    
	printf("Digite o cpf a ser consultado: ");// coletando informa��es do usu�rio 
    scanf("%s",cpf);//salvando a variavel fornecida
    
    FILE *file;//acessando a fun��o file no par�metro "arquivo"
    file = fopen(cpf,"r");//abrindo o arquivo e lendo("r") o arquivo "cpf"
    
    if(file == NULL)//fun��o que o programa deve fazer caso o arquivo n�o seja encontrado/inexistente
    {
    printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");	//resultado de pesquisa nula
	}
	
	while(fgets(conteudo, 200, file) != NULL)//buscando no arquivo conteudos (no maximo 200 vezes) at� que ele seja nulo. Se for nulo, quer dizer que o arquivo n�o existe, n�o foi encontrado, ou seja, n�o � necess�rio continuar a consulta, pois todos os arquivos foram consultados e n�o encontraram a pesquisa
	{
		printf("\n Essas s�o as informa��es do usu�rio: ");//resultados da consulta
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
 }

int deletar()
{
  //inicio de cria��o de vari�veis/string
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
  
    remove(cpf); 
    print("O usu�rio foi deletado com sucesso!/n.");

  //fim da cria��o de vari�veis/string    
  
    
    FILE *file; //acessando a fun��o file no par�metro "arquivo"
    file = fopen(cpf,"r"); //abrindo o arquivo e lendo("r") o arquivo "cpf"
    
    if(file == NULL) //fun��o que o programa deve fazer caso o arquivo n�o seja encontrado/inexistente
    {
    	printf("O usu�rio n�o se encontra no sistema!.\n");
    	system("pause");
    	
	}
 
	
	
}


int main()
{

	int opcao=0; //Definindo vari�veis
	int laco=1;
	for(laco=1;laco=1;)
	{
		system("cls");//respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem que ser� usada

	    printf("### Cart�rio da EBAC ###\n\n"); //menu inicial 
	    printf("Escolha a op��o desejada no menu abaixo:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n\n"); 
	    printf("Op��o: ");//fim do menu
	
	    scanf("%d",&opcao); //armazenando a escolha do usu�rio
	
	    system("cls");//respons�vel por limpar a tela
	     
	    switch(opcao)//resultados da escolha do usu�rio
	    {
            case 1:
		    registro();//chamada de fun��es
            break;
            
            case 2:
		    consulta();
    	    break;
    	    
    	    case 3:
    	    deletar();
    	    break;
            
            default:
            printf("Essa op��o n�o est� disponivel!\n");
    		system("pause");
    		break;		
		}
	//fim da sele��o
	
	}
}
