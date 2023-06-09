#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 50

typedef struct
{
    char nome[50];
    float nota[4];
    int ativo;

} Alunos;
Alunos aluno[Max];

void menu();
void cadastrar();
void remover();
void aprovados();
void reprovados();
void pesquisar();
void listar();
void salvar();
void editar();

int main(int argc, char const *argv[])
{
    menu();
    salvar();

    return 0;
}

void menu()
{
    int op;
    do
    {
        system("cls");
        printf("\n1-Cadastrar aluno\n2-Remover aluno\n3-Alunos aprovados\n4-Alunos reprovados\n");
        printf("5-Pesquisar aluno\n6-Listar todos os alunos\n7-Edidar cadastro de aluno\n0-Sair\nEscolha: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            cadastrar();
            break;
        case 2:
            remover();
            break;
        case 3:
            aprovados();
            break;
        case 4:
            reprovados();
            break;
        case 5:
            pesquisar();
            break;
        case 6:
            listar();
            break;
        case 7:
            editar();
            break;
        }
        getchar();
    } while (op != 0);
}
void cadastrar()
{
    char nome[50];
    float nota[4];
    int op;
    do
    {
        system("cls");
        getchar();
        printf("\nNome: ");
        fgets(nome, sizeof(nome), stdin);
        printf("Nota do primeiro bimestre: ");
        scanf("%f", &nota[0]);
        printf("Nota do segundo bimestre: ");
        scanf("%f", &nota[1]);
        printf("Nota do terceiro bimestre: ");
        scanf("%f", &nota[2]);
        printf("Nota do quarto bimestre: ");
        scanf("%f", &nota[3]);
        for (int i = 0; i < Max; i++)
        {
            if (aluno[i].ativo == 0)
            {
                aluno[i].nota[0] = nota[0];
                aluno[i].nota[1] = nota[1];
                aluno[i].nota[2] = nota[2];
                aluno[i].nota[3] = nota[3];
                strcpy(aluno[i].nome, nome);
                aluno[i].ativo = 1;
                break;
            }
        }
        printf("\n1 - continuar 0 - sair\n");
        scanf("%d", &op);
    } while (op != 0);
}
void remover()
{
    system("cls");
    int matricula;
    listar();
    printf("\nMatricula do aluno para remover: ");
    scanf("%d", &matricula);
    --matricula;
    aluno[matricula].ativo = 0;
    printf("\n%s removido(a) com sucesso", aluno[matricula].nome);
    getchar();
}
void reprovados()
{
    system("cls");
    int i;
    float media;
    printf("\n\tLista de todos os alunos reprovados\n\n");
    for (i = 0; i < Max; i++)
    {
        if (aluno[i].ativo == 1)
        {
            media = 0;
            media = aluno[i].nota[0] + aluno[i].nota[1] + aluno[i].nota[2] + aluno[i].nota[3];
            media = media / 4;
            if (media < 7.0)
            {
                printf("Matricula: %d\n", i + 1);
                printf("Nome: %s\n", aluno[i].nome);
                printf("1 BIM: %.2f\n", aluno[i].nota[0]);
                printf("2 BIM: %.2f\n", aluno[i].nota[1]);
                printf("3 BIM: %.2f\n", aluno[i].nota[2]);
                printf("4 BIM: %.2f\n", aluno[i].nota[3]);
                printf("\n------------------------------\n");
            }
        }
    }
    getchar();
}

void aprovados()
{
    system("cls");
    int i;
    float media;
    printf("\n\tLista de todos os alunos aprovados\n\n");
    for (i = 0; i < Max; i++)
    {
        if (aluno[i].ativo == 1)
        {
            media = 0;
            media = aluno[i].nota[0] + aluno[i].nota[1] + aluno[i].nota[2] + aluno[i].nota[3];
            media = media / 4;
            if (media > 7.0)
            {
                printf("Matricula: %d\n", i + 1);
                printf("Nome: %s\n", aluno[i].nome);
                printf("1 BIM: %.2f\n", aluno[i].nota[0]);
                printf("2 BIM: %.2f\n", aluno[i].nota[1]);
                printf("3 BIM: %.2f\n", aluno[i].nota[2]);
                printf("4 BIM: %.2f\n", aluno[i].nota[3]);
                printf("\n------------------------------\n");
            }
        }
    }
    getchar();
}

void pesquisar()
{
    int op, i;
    char nome[50];
    do
    {
        system("cls");
        printf("Nome do aluno para pesquisar: ");
        fgets(nome, sizeof(nome), stdin);
        for (i = 0; i < Max; i++)
        {
            if (strstr(aluno[i].nome, nome) != NULL)
            {
                printf("Matricula: %d\n", i + 1);
                printf("Nome: %s\n", aluno[i].nome);
                printf("1 BIM: %.2f\n", aluno[i].nota[0]);
                printf("2 BIM: %.2f\n", aluno[i].nota[1]);
                printf("3 BIM: %.2f\n", aluno[i].nota[2]);
                printf("4 BIM: %.2f\n", aluno[i].nota[3]);
                printf("\n------------------------------\n");
            }
        }
        printf("1-(outra pesquisa) 0-(sair): ");
        scanf("%d", &op);
        getchar();
    } while (op != 0);
}
void listar()
{
    system("cls");
    printf("\n\tLista de todos os alunos\n\n");
    for (int i = 0; i < Max; i++)
    {
        if (aluno[i].ativo == 1)
        {
            printf("Matricula: %d\n", i + 1);
            printf("Nome: %s\n", aluno[i].nome);
            printf("1 BIM: %.2f\n", aluno[i].nota[0]);
            printf("2 BIM: %.2f\n", aluno[i].nota[1]);
            printf("3 BIM: %.2f\n", aluno[i].nota[2]);
            printf("4 BIM: %.2f\n", aluno[i].nota[3]);
            printf("\n------------------------------\n");
        }
    }
    getchar();
}

void salvar()
{
    FILE *arq;

    arq = fopen("Cadastros.txt", "a + b");
    if (arq == NULL)
    {
        printf("Erro ao salvar");
        exit(1);
    }
    int i;

    for (i = 0; i < Max; i++)
    {
        if (aluno[i].ativo == 1)
        {
            fprintf(arq, "Aluno: %s ", aluno[i].nome);
            fprintf(arq, "Notas: %.2f, %.2f, %.2f, %.2f\n", aluno[i].nota[0], aluno[i].nota[1], aluno[i].nota[2], aluno[i].nota[3]);
        }
    }
    fclose(arq);
    printf("\n\nDados salvos com sucesso\n");
}

void editar()
{
    system("cls");
    listar();
    int matricula;
    printf("Digite a matricula do aluno para editar: ");
    scanf("%d", &matricula);
    matricula--;
    if (aluno[matricula].ativo == 0)
    {
        printf("\nNao encontrei nenhum aluno com essa matricula\n");
        getchar();
        return;
    }
    printf("\nEsses sao os dados atuais desse aluno\n\n");
    printf("Nome: %s\n", aluno[matricula].nome);
    printf("1 BIM: %.2f\n", aluno[matricula].nota[0]);
    printf("2 BIM: %.2f\n", aluno[matricula].nota[1]);
    printf("3 BIM: %.2f\n", aluno[matricula].nota[2]);
    printf("4 BIM: %.2f\n", aluno[matricula].nota[3]);

    getchar();

    printf("\n\n Agora digite os novos dados\n\n");
    printf("Nome: ");
    fgets(aluno[matricula].nome, sizeof(aluno[matricula].nome), stdin);
    printf("1 BIM: ");
    scanf("%f", &aluno[matricula].nota[0]);
    printf("2 BIM: ");
    scanf("%f", &aluno[matricula].nota[1]);
    printf("3 BIM: ");
    scanf("%f", &aluno[matricula].nota[2]);
    printf("4 BIM: ");
    scanf("%f", &aluno[matricula].nota[3]);

    salvar();
    printf("Tecle enter para voltar\n");
    getchar();
}