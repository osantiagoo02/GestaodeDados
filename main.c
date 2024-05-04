#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_CLIENTES 100

// Estrutura para armazenar informações do cliente
struct Cliente {
    char nome[50];
    char cnpj[20];
    char telefone[15];
    char endereco[100];
};

struct Funcionario {
    char nome[50];
    char cpf[15];
    char cargo[50];
    float salario;
};

// Funções
int fazerLogin();
void mostrarMenu();
void cadastrarCliente(struct Cliente clientes[], int *numClientes);
void gerarRelatorio();
void salvarRelatorio(int relatorioNumero);
void consultarCliente(struct Cliente clientes[], int numClientes);
void cadastrarFuncionario(struct Funcionario funcionarios[], int *numFuncionarios);
void consultarFuncionario(struct Funcionario funcionarios[], int numFuncionarios);

int main() {
    setlocale(LC_ALL, "Portuguese");
    int logado = 0;
    int tentativas = 0;
    const int MAX_TENTATIVAS = 3; // Máximo de tentativas como segurança

    while (!logado) {
        logado = fazerLogin();
        tentativas++;

        if (tentativas >= MAX_TENTATIVAS) {
            printf("Número máximo de tentativas excedido. O programa será encerrado.\n");
            return 1;
        }
    }
struct Cliente clientes[MAX_CLIENTES];
    int numClientes = 0;

struct Funcionario funcionarios[MAX_CLIENTES];
int numFuncionarios = 0;

    int opcao;
    do {
        mostrarMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        while (getchar() != '\n');

        switch (opcao) {
            case 1:
                cadastrarCliente(clientes, &numClientes);
                break;
            case 2:
                cadastrarFuncionario(funcionarios, &numFuncionarios);
                break;
            case 3:
                gerarRelatorio();
                break;
            case 4:
                consultarCliente(clientes, numClientes);
                break;
            case 5:
                consultarFuncionario(funcionarios, numFuncionarios);
                break;
            case 6:
                printf("Saindo do sistema.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}

int fazerLogin() {
    char usuario[20];
    char senha[20];

    printf("===== Tela de Login =====\n");
    printf("Usuário: ");
    fgets(usuario, sizeof(usuario), stdin);
    usuario[strcspn(usuario, "\n")] = '\0';
    printf("Senha: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = '\0';
    // credenciais teste
    if (strcmp(usuario, "admin") == 0 && strcmp(senha, "12345") == 0) {
        printf("Login bem-sucedido!\n");
        return 1; // Login bem-sucedido
    } else {
        printf("Login falhou. Tente novamente.\n");
        return 0; // Login falhou
    }
}

void cadastrarCliente(struct Cliente clientes[], int *numClientes) {
    char nome[50];
    char cnpj[20];
    char telefone[15];
    char endereco[100];

    printf("===== Cadastro de Clientes =====\n");
    printf("Nome da empresa: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    printf("CNPJ: ");
    fgets(cnpj, sizeof(cnpj), stdin);
    cnpj[strcspn(cnpj, "\n")] = '\0';
    printf("Telefone: ");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strcspn(telefone, "\n")] = '\0';
    printf("Endereço: ");
    fgets(endereco, sizeof(endereco), stdin);
    endereco[strcspn(endereco, "\n")] = '\0';

    // dados do cliente
    strcpy(clientes[*numClientes].nome, nome);
    strcpy(clientes[*numClientes].cnpj, cnpj);
    strcpy(clientes[*numClientes].telefone, telefone);
    strcpy(clientes[*numClientes].endereco, endereco);

    (*numClientes)++;
}

int cadastrarEmpresa() {
    int cadastrarClienteFlag = 1;

    if (cadastrarClienteFlag == 1) {
        struct Cliente clientes[100];
        int numClientes = 0;
        cadastrarCliente(clientes, &numClientes);
    }

    return 0;
}

void mostrarMenu() {
    printf("===== Menu Inicial =====\n"); // Opções do menu
    printf("Opções:\n");
    printf("1. Cadastro de Clientes\n");
    printf("2. Cadastro de Funcionários\n");
    printf("3. Relatórios\n");
    printf("4. Consultar Dados\n");
    printf("5. Consultar Funcionário\n");
    printf("6. Sair\n");
}

void gerarRelatorio() {
    int relatorioNumero;

    printf("===== Relatórios =====\n");
    printf("1. Relatório 1\n");
    printf("2. Relatório 2\n");
    printf("3. Voltar\n");
    printf("Escolha um relatório para baixar (1/2/3): ");
    scanf("%d", &relatorioNumero);

    if (relatorioNumero == 1 || relatorioNumero == 2) {
        salvarRelatorio(relatorioNumero);
    } else if (relatorioNumero == 3) {
        printf("Voltando ao menu.\n");
    } else {
        printf("Opção inválida.\n");
    }
}

void salvarRelatorio(int relatorioNumero) {
    char nomeArquivo[50];
    char conteudo[200];

    printf("Digite o nome do arquivo para salvar o relatório (ex: relatorio.txt): ");
    scanf("%s", nomeArquivo);

    // Gerar relatório
    snprintf(conteudo, sizeof(conteudo), "Conteúdo do Relatório %d: Conteúdo para teste do Relatório", relatorioNumero);


    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    } else {

        fprintf(arquivo, "%s", conteudo);
        fclose(arquivo);
        printf("Relatório salvo em %s.\n", nomeArquivo);
    }
}void consultarCliente(struct Cliente clientes[], int numClientes) {
    char cnpjBusca[20];
    printf("Digite o CNPJ para consulta: ");
    scanf("%s", cnpjBusca);

    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cnpj, cnpjBusca) == 0) {
            printf("Cliente encontrado:\n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("CNPJ: %s\n", clientes[i].cnpj);
            printf("Telefone: %s\n", clientes[i].telefone);
            printf("Endereço: %s\n", clientes[i].endereco);
            return; // Sai da função após encontrar o cliente
        }
    }

    printf("Cliente com CNPJ %s não encontrado.\n", cnpjBusca);
}
void cadastrarFuncionario(struct Funcionario funcionarios[], int *numFuncionarios) {
    char nome[50];
    char cpf[15];
    char cargo[50];
    float salario;

    printf("===== Cadastro de Funcionários =====\n");
    printf("Nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    printf("CPF: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';
    printf("Cargo: ");
    fgets(cargo, sizeof(cargo), stdin);
    cargo[strcspn(cargo, "\n")] = '\0';
    printf("Salário: ");
    scanf("%f", &salario);

    // Dados do funcionário
    strcpy(funcionarios[*numFuncionarios].nome, nome);
    strcpy(funcionarios[*numFuncionarios].cpf, cpf);
    strcpy(funcionarios[*numFuncionarios].cargo, cargo);
    funcionarios[*numFuncionarios].salario = salario;

    (*numFuncionarios)++;
}

void consultarFuncionario(struct Funcionario funcionarios[], int numFuncionarios) {
    char cpfBusca[15];
    printf("Digite o CPF para consulta: ");
    scanf("%s", cpfBusca);

    for (int i = 0; i < numFuncionarios; i++) {
        if (strcmp(funcionarios[i].cpf, cpfBusca) == 0) {
            printf("Funcionário encontrado:\n");
            printf("Nome: %s\n", funcionarios[i].nome);
            printf("CPF: %s\n", funcionarios[i].cpf);
            printf("Cargo: %s\n", funcionarios[i].cargo);
            printf("Salário: %.2f\n", funcionarios[i].salario);
            return; // Sai da função após encontrar o funcionário
        }
    }

    printf("Funcionário com CPF %s não encontrado.\n", cpfBusca);
}
