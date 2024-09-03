#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h>


struct Funcionario
{
	char nome[50];
	int idade;
	char cpf[12];
	char matricula[15];
	char email[50];
	char cargo[25];
	char departamento[5];
	float salario;
} funcionario;
	
//fun��o listar funcion�rio
	void read_funcionario()
	{
		FILE *arquivo;
		arquivo = fopen("funcionarios.txt", "rb");

		if(arquivo == NULL)
		{
			printf("algo deu errado");
		}
		else
		{
			while( fread( &funcionario, sizeof(funcionario), 1, arquivo) == 1)
			{
				printf("Nome: %s\n", funcionario.nome);
				printf("Idade: %d\n", funcionario.idade);
				printf("CPF: %s\n", funcionario.cpf);
				printf("Matr�cula: %s\n", funcionario.matricula);
				printf("Email: %s\n", funcionario.email);
				printf("Cargo: %s\n", funcionario.cargo);
				printf("Departamento: %s\n", funcionario.departamento);
				printf("Sal�rio: R$%.2f\n", funcionario.salario);
				printf("---------------------\n\n");
			}
		}
		fclose(arquivo);
		getch();
	}
//fun��o criar funcion�rio
	void create_funcionario()
	{

		FILE *arquivo;
		arquivo = fopen("funcionarios.txt", "ab");

		if(arquivo == NULL)
		{
			printf("algo deu errado");
		}
		else
		{
			do
			{
				fflush(stdin);
				printf("Digite seu Nome:");
				gets(funcionario.nome);

				fflush(stdin);
				printf("\nDigite sua Idade:");
				scanf("%d", &funcionario.idade);
				
				fflush(stdin);
				printf("\nDigite seu CPF:");
				gets(funcionario.cpf);

				fflush(stdin);
				printf("\nDigite sua Matricula:");
				gets(funcionario.matricula);

				fflush(stdin);
				printf("\nDigite seu E-mail:");
				gets(funcionario.email);

				fflush(stdin);
				printf("\nDigite seu Cargo:");
				gets(funcionario.cargo);

				fflush(stdin);
				printf("\nDigite seu Departamento:");
				gets(funcionario.departamento);

				fflush(stdin);
				printf("\nDigite seu Sal�rio:");
				scanf("%f", &funcionario.salario);
	

				fwrite(&funcionario, sizeof(funcionario), 1, arquivo);

				int i;

				printf("\nOs dados ser�o limpos da tela em...\n");
				for (i = 5; i > 0; i--)
				{
					printf("%d\n", i);
					Sleep(1000);
				}

				system("cls || clear");
				printf("deseja continuar [s/n]");
				getchar();
			}
			while(getchar() == 's');
		}
		fclose(arquivo);
	}
//fun��o deletar duncion�rio
	void delete_funcionario()
	{
		FILE *originfile;
		FILE *newfile;
		char matricula[15];

		originfile = fopen("funcionarios.txt", "rb");
		newfile = fopen("newfuncionarios.txt", "ab");

		if(originfile == NULL || newfile == NULL)
		{
			printf("Algo deu errado");
		}
		else
		{
			fflush(stdin);
			printf("Digite a matricula do funcionario a ser exluido: ");
			gets(matricula);

			while( fread (&funcionario, sizeof(funcionario), 1, originfile) == 1)
			{
				if (strcmp(matricula, funcionario.matricula) != 0)
				{
					fwrite (&funcionario, sizeof(funcionario), 1, newfile);

				}
			}

		}
		fclose(originfile);
		fclose(newfile);
		remove("funcionarios.txt");
		rename("newfuncionarios.txt", "funcionarios.txt");
		printf("Funcion�rio removido!");
		getch();
	}
//fun��o pesquisar funcion�rio
	void search()
	{
		FILE *arquivo;
		char matricula [15];

		arquivo = fopen("funcionarios.txt", "rb");
		if(arquivo == NULL)
		{
			printf("Algo deu errado\n");
		}
		else
		{
			fflush(stdin);
			printf("Digite a matr�cula do funcion�rio: ");
			gets(matricula);
			while( fread( &funcionario, sizeof(funcionario), 1, arquivo) == 1)
			{
				if( strcmp(matricula, funcionario.matricula ) == 0)
				{
					printf("Nome: %s\n", funcionario.nome);
					printf("Idade: %d\n", funcionario.idade);
					printf("CPF: %s\n", funcionario.cpf);
					printf("Matr�cula: %s\n", funcionario.matricula);
					printf("Email: %s\n", funcionario.email);
					printf("Cargo: %s\n", funcionario.cargo);
					printf("Departamento: %s\n", funcionario.departamento);
					printf("Sal�rio: R$%.2f\n", funcionario.salario);
					printf("---------------------\n\n");
				}

			}
		}
		fclose(arquivo);
		getche();
	}
//fun��o atualizar funcion�rio
	void update_funcionario() {
		FILE *originfile;
    FILE *newfile;
    char matricula[15];
    int found = 0;

    originfile = fopen("funcionarios.txt", "rb");
    newfile = fopen("newfuncionarios.txt", "wb");

    if (originfile == NULL || newfile == NULL) {
        printf("Algo deu errado");
    } else {
        fflush(stdin);
        printf("Digite a matr�cula do funcion�rio a ser atualizado: ");
        gets(matricula);

        while (fread(&funcionario, sizeof(funcionario), 1, originfile) == 1) {
            if (strcmp(matricula, funcionario.matricula) == 0) {
                found = 1;
                printf("Digite as novas informa��es do funcion�rio:\n");

                fflush(stdin);
                printf("Nome (%s): ", funcionario.nome);
                gets(funcionario.nome);

                fflush(stdin);
                printf("Idade (%d): ", funcionario.idade);
                scanf("%d", &funcionario.idade);

                fflush(stdin);
                printf("CPF (%s): ", funcionario.cpf);
                gets(funcionario.cpf);

                fflush(stdin);
                printf("Matr�cula (%s): ", funcionario.matricula);
                gets(funcionario.matricula);

                fflush(stdin);
                printf("Email (%s): ", funcionario.email);
                gets(funcionario.email);

                fflush(stdin);
                printf("Cargo (%s): ", funcionario.cargo);
                gets(funcionario.cargo);

                fflush(stdin);
                printf("Departamento (%s): ", funcionario.departamento);
                gets(funcionario.departamento);

                fflush(stdin);
                printf("Sal�rio (%.2f): ", funcionario.salario);
                scanf("%f", &funcionario.salario);
            }
            fwrite(&funcionario, sizeof(funcionario), 1, newfile);
        }

        if (!found) {
            printf("Funcion�rio com matr�cula %s n�o encontrado.\n", matricula);
        }
    }

    fclose(originfile);
    fclose(newfile);
    remove("funcionarios.txt");
    rename("newfuncionarios.txt", "funcionarios.txt");

    if (found) {
        printf("Funcion�rio atualizado com sucesso!\n");
    }

    getch();
	}
	
	/* Outras Fun��es*/
	void cabecalho()
	{
		system("cls||clear");
		printf("====== Escolha uma das op��es abaixo: ======\n\n");
	}
	
	void sair()
	{
		printf("Saiu!\n");
	}

//Menu main
	int main()
	{

		setlocale(LC_ALL, "Portuguese");

		int continuar = 1;

		do
		{
			cabecalho();
			printf("1. Criar Funcion�rio\n");
			printf("2. Ler Todos os Funcion�rio\n");
			printf("3. Atualizar Funcion�rio\n");
			printf("4. Deletar Funcion�rio\n");
			printf("5. Buscar Funcion�rio por matr�cula\n");
			printf("0. Sair\n\n");
			printf("Escolha: ");
			scanf("%d", &continuar);
			printf("=============================================================\n");
			system("cls || clear");

			switch(continuar)
			{
			case 1:
				create_funcionario();
				break;

			case 2:
				read_funcionario();
				break;

			case 3:
				update_funcionario();
				break;

			case 4:
				delete_funcionario();
				break;

			case 5:
				search();
				break;

			case 0:
				sair();
				break;

			default:
				printf("Digite uma op��o v�lida!\n\n");
			}

		}
		while(continuar);

		return 0;
	}