#include <stdio.h> //biblioteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocações de texto por região 	
#include <string.h> //biblioteca responsável por cuidar das string
 
int registro() //função responsável por cadastrar os usuários no sistema
 {
 	//inicio de criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informações do usuário 
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo	
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa "escrever"
    fprintf(file,cpf); //salvo o valor da variavel		
    fclose(file); //fecha o arquivo 
    
    file = fopen(arquivo, "a"); // abrindo o arquivo e atualizando os dados dele
    fprintf(file,",");// colocando uma virgula após a atualização de dados para que não fique "embolado" quando outro dado por atualizado posteriormente 
    fclose(file);//fechando o arquivo
    
    printf("Digite o nome a ser cadastrado: ");//coletando informações do usuário	
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");//abrindo o arquivo e o atualizando de acordo com as novas informações fornecidas pelo usuário
    fprintf(file,nome);//salvando o arquivo
    fclose(file);//fechando o arquivo
    
	file = fopen(arquivo, "a");//abrindo e atualizando o arquivo
    fprintf(file,",");//adicionando uma virgula após a atualização 
    fclose(file);//fechando o arquivo
    
    printf("Digite o sobrenome a ser cadastrado: ");//coletando novas informações do usuário
    scanf("%s",sobrenome);//salvando a variavel fornecida
    
    file = fopen(arquivo, "a");//abrindo o arquivo e atualizando com o novo dado fornecido
    fprintf(file,sobrenome);//salvando a variavel no arquivo
    fclose(file);//fechando o arquivo
    
	file = fopen(arquivo, "a");//abrindo e atualizando o arquivo
    fprintf(file,",");//adicionando uma virgula após a atualização 
    fclose(file);//fechando o arquivo
    
    printf("Digite o cargo a ser cadastrado: ");//coletando novas informações do usuário
    scanf("%s",cargo);//salvando variavel fornecida
    
    file = fopen(arquivo, "a");//abrindo o arquivo e atualizando com o novo dado fornecido
    fprintf(file,cargo);//salvando a variavel no arquivo
    fclose(file);//fechando o arquivo
    
    system("pause");
 }
 
int consulta()//função responsável por consultar usuários cadastrados no sistema
 {
    setlocale(LC_ALL, "Portuguese"); //definindo a linguagem que será usada
    
    //inicio de criação de variáveis/string
    char cpf[40];
    char conteudo[200];
    //fim da criação de variáveis/string
    
	printf("Digite o cpf a ser consultado: ");// coletando informações do usuário 
    scanf("%s",cpf);//salvando a variavel fornecida
    
    FILE *file;//acessando a função file no parâmetro "arquivo"
    file = fopen(cpf,"r");//abrindo o arquivo e lendo("r") o arquivo "cpf"
    
    if(file == NULL)//função que o programa deve fazer caso o arquivo não seja encontrado/inexistente
    {
    printf("Não foi possivel abrir o arquivo, não localizado!.\n");	//resultado de pesquisa nula
	}
	
	while(fgets(conteudo, 200, file) != NULL)//buscando no arquivo conteudos (no maximo 200 vezes) até que ele seja nulo. Se for nulo, quer dizer que o arquivo não existe, não foi encontrado, ou seja, não é necessário continuar a consulta, pois todos os arquivos foram consultados e não encontraram a pesquisa
	{
		printf("\n Essas são as informações do usuário: ");//resultados da consulta
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
 }

int deletar()
{
  //inicio de criação de variáveis/string
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s",cpf);
  
    remove(cpf); 
    print("O usuário foi deletado com sucesso!/n.");

  //fim da criação de variáveis/string    
  
    
    FILE *file; //acessando a função file no parâmetro "arquivo"
    file = fopen(cpf,"r"); //abrindo o arquivo e lendo("r") o arquivo "cpf"
    
    if(file == NULL) //função que o programa deve fazer caso o arquivo não seja encontrado/inexistente
    {
    	printf("O usuário não se encontra no sistema!.\n");
    	system("pause");
    	
	}
 
	
	
}


int main()
{

	int opcao=0; //Definindo variáveis
	int laco=1;
	for(laco=1;laco=1;)
	{
		system("cls");//responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem que será usada

	    printf("### Cartório da EBAC ###\n\n"); //menu inicial 
	    printf("Escolha a opção desejada no menu abaixo:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n\n"); 
	    printf("Opção: ");//fim do menu
	
	    scanf("%d",&opcao); //armazenando a escolha do usuário
	
	    system("cls");//responsável por limpar a tela
	     
	    switch(opcao)//resultados da escolha do usuário
	    {
            case 1:
		    registro();//chamada de funções
            break;
            
            case 2:
		    consulta();
    	    break;
    	    
    	    case 3:
    	    deletar();
    	    break;
            
            default:
            printf("Essa opção não está disponivel!\n");
    		system("pause");
    		break;		
		}
	//fim da seleção
	
	}
}
