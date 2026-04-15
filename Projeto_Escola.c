#include <stdio.h>
#include <string.h>

#define TAM 50 

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    int matricula;
    char nome[50];
    char sexo;
    Data nascimento;
    char cpf[15];
    int ativo; 
} Pessoa;

typedef struct {
    char nome[50];
    int codigo;
    int semestre;
    int matProfessor;
    int alunosMatriculados[TAM];
    int qtdAlunosNaDisc;
} Disciplina;

Pessoa listaAlunos[TAM];
int qtdAlunos = 0;

Pessoa listaProfessores[TAM];
int qtdProfessores = 0;

Disciplina listaDisciplinas[TAM];
int qtdDisciplinas = 0;

void menuPrincipal();
void cadastrarPessoa(int tipo); 
void cadastrarDisciplina();
void gerenciarAlunoDisciplina(int acao); 
void listarPessoas(int tipo, int ordem); 
void listarDisciplinas(int detalhado);

int main() {
    int opcao = -1;
    while (opcao != 0) {
        printf("\n--- ESCOLA ---");
        printf("\n1. Cadastrar Aluno\n2. Cadastrar Professor\n3. Cadastrar Disciplina");
        printf("\n4. Matricular Aluno em Disciplina\n5. Desmatricular Aluno");
        printf("\n6. Relatorios\n0. Sair\nEscolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: cadastrarPessoa(1); break;
            case 2: cadastrarPessoa(2); break;
            case 3: cadastrarDisciplina(); break;
            case 4: gerenciarAlunoDisciplina(1); break;
            case 5: gerenciarAlunoDisciplina(2); break;
            case 6: 
                printf("\n1. Alunos por Nome\n2. Alunos por Nascimento\n3. Professores por Sexo\n4. Listar Disciplinas\nEscolha: ");
                int opRel; scanf("%d", &opRel);
                if(opRel == 1) listarPessoas(1, 1);
                if(opRel == 2) listarPessoas(1, 2);
                if(opRel == 3) listarPessoas(2, 3);
                if(opRel == 4) listarDisciplinas(0);
                break;
        }
    }
    return 0;
}

void cadastrarPessoa(int tipo) {
    Pessoa nova;
    printf("\nMatricula: ");
    scanf("%d", &nova.matricula); getchar();
    printf("Nome: ");
    fgets(nova.nome, 50, stdin); nova.nome[strcspn(nova.nome, "\n")] = 0;
    printf("Sexo (M/F): ");
    scanf("%c", &nova.sexo);
    printf("Data Nasc (dd mm aaaa): ");
    scanf("%d %d %d", &nova.nascimento.dia, &nova.nascimento.mes, &nova.nascimento.ano); getchar();
    printf("CPF: ");
    fgets(nova.cpf, 15, stdin); nova.cpf[strcspn(nova.cpf, "\n")] = 0;
    nova.ativo = 1;

    if (tipo == 1) listaAlunos[qtdAlunos++] = nova;
    else listaProfessores[qtdProfessores++] = nova;
    printf("Cadastro realizado!\n");
}

void cadastrarDisciplina() {
    printf("Nome da Disciplina: ");
    fgets(listaDisciplinas[qtdDisciplinas].nome, 50, stdin);
    listaDisciplinas[qtdDisciplinas].nome[strcspn(listaDisciplinas[qtdDisciplinas].nome, "\n")] = 0;
    printf("Codigo (int): ");
    scanf("%d", &listaDisciplinas[qtdDisciplinas].codigo);
    printf("Semestre: ");
    scanf("%d", &listaDisciplinas[qtdDisciplinas].semestre);
    printf("Matricula do Professor: ");
    scanf("%d", &listaDisciplinas[qtdDisciplinas].matProfessor);
    listaDisciplinas[qtdDisciplinas].qtdAlunosNaDisc = 0;
    qtdDisciplinas++;
}

void gerenciarAlunoDisciplina(int acao) {
    int codDisc, matAlu, i, j, achouD = -1;
    printf("Codigo da Disciplina: ");
    scanf("%d", &codDisc);
    printf("Matricula do Aluno: ");
    scanf("%d", &matAlu);

    for(i=0; i<qtdDisciplinas; i++) if(listaDisciplinas[i].codigo == codDisc) achouD = i;

    if(achouD != -1) {
        if(acao == 1) { // Inserir
            listaDisciplinas[achouD].alunosMatriculados[listaDisciplinas[achouD].qtdAlunosNaDisc++] = matAlu;
            printf("Aluno matriculado!\n");
        } else { // Excluir
            for(j=0; j<listaDisciplinas[achouD].qtdAlunosNaDisc; j++) {
                if(listaDisciplinas[achouD].alunosMatriculados[j] == matAlu) {
                    listaDisciplinas[achouD].alunosMatriculados[j] = -1; 
                    printf("Aluno removido da disciplina!\n");
                }
            }
        }
    }
}

void listarPessoas(int tipo, int ordem) {
    Pessoa copia[TAM], aux;
    int n = (tipo == 1) ? qtdAlunos : qtdProfessores;
    
   
    for(int i=0; i<n; i++) copia[i] = (tipo == 1) ? listaAlunos[i] : listaProfessores[i];


    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            int troca = 0;
            if(ordem == 1 && strcmp(copia[j].nome, copia[j+1].nome) > 0) troca = 1;
            if(ordem == 2) { // Ordenar por Data (Ano -> Mes -> Dia)
                long d1 = copia[j].nascimento.ano*10000 + copia[j].nascimento.mes*100 + copia[j].nascimento.dia;
                long d2 = copia[j+1].nascimento.ano*10000 + copia[j+1].nascimento.mes*100 + copia[j+1].nascimento.dia;
                if(d1 > d2) troca = 1;
            }
            if(troca) { aux = copia[j]; copia[j] = copia[j+1]; copia[j+1] = aux; }
        }
    }

    for(int i=0; i<n; i++) {
        if(copia[i].ativo)
            printf("%d - %s (%c) - %02d/%02d/%d\n", copia[i].matricula, copia[i].nome, copia[i].sexo, copia[i].nascimento.dia, copia[i].nascimento.mes, copia[i].nascimento.ano);
    }
}

void listarDisciplinas(int detalhado) {
    for(int i=0; i<qtdDisciplinas; i++) {
        printf("\nDisc: %s [%d] | Prof Mat: %d", listaDisciplinas[i].nome, listaDisciplinas[i].codigo, listaDisciplinas[i].matProfessor);
    }
}    