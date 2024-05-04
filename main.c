#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_CLIENTES 100

// Estrutura para armazenar informa��es do cliente
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

// Fun��es
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
    const int MAX_TENTATIVAS = 3; // M�ximo de tentativas como seguran�a

    while (!logado) {
        logado = fazerLogin();
        tentativas++;

        if (tentativas >= MAX_TENTATIVAS) {
            printf("N�mero m�ximo de tentativas excedido. O programa ser� encerrado.\n");
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
        printf("Escolha uma op��o: ");
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
                printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}

int fazerLogin() {
    char usuario[20];
    char senha[20];

    printf("===== Tela de Login =====\n");
    printf("Usu�rio: ");
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
    printf("Endere�o: ");
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
    printf("===== Menu Inicial =====\n"); // Op��es do menu
    printf("Op��es:\n");
    printf("1. Cadastro de Clientes\n");
    printf("2. Cadastro de Funcion�rios\n");
    printf("3. Relat�rios\n");
    printf("4. Consultar Dados\n");
    printf("5. Consultar Funcion�rio\n");
    printf("6. Sair\n");
}

void gerarRelatorio() {
    int relatorioNumero;

    printf("===== Relat�rios =====\n");
    printf("1. Relat�rio 1\n");
    printf("2. Relat�rio 2\n");
    printf("3. Voltar\n");
    printf("Escolha um relat�rio para baixar (1/2/3): ");
    scanf("%d", &relatorioNumero);

    if (relatorioNumero == 1 || relatorioNumero == 2) {
        salvarRelatorio(relatorioNumero);
    } else if (relatorioNumero == 3) {
        printf("Voltando ao menu.\n");
    } else {
        printf("Op��o inv�lida.\n");
    }
}

void salvarRelatorio(int relatorioNumero) {
    char nomeArquivo[50];
    char conteudo[200];

    printf("Digite o nome do arquivo para salvar o relat�rio (ex: relatorio.txt): ");
    scanf("%s", nomeArquivo);

    // Gerar relat�rio
    snprintf(conteudo, sizeof(conteudo), "Conte�do do Relat�rio %d: Conte�do para teste do Relat�rio", relatorioNumero);


    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
    } else {

        fprintf(arquivo, "%s", conteudo);
        fclose(arquivo);
        printf("Relat�rio salvo em %s.\n", nomeArquivo);
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
            printf("Endere�o: %s\n", clientes[i].endereco);
            return; // Sai da fun��o ap�s encontrar o cliente
        }
    }

    printf("Cliente com CNPJ %s n�o encontrado.\n", cnpjBusca);
}
void cadastrarFuncionario(struct Funcionario funcionarios[], int *numFuncionarios) {
    char nome[50];
    char cpf[15];
    char cargo[50];
    float salario;

    printf("===== Cadastro de Funcion�rios =====\n");
    printf("Nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    printf("CPF: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';
    printf("Cargo: ");
    fgets(cargo, sizeof(cargo), stdin);
    cargo[strcspn(cargo, "\n")] = '\0';
    printf("Sal�rio: ");
    scanf("%f", &salario);

    // Dados do funcion�rio
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
            printf("Funcion�rio encontrado:\n");
            printf("Nome: %s\n", funcionarios[i].nome);
            printf("CPF: %s\n", funcionarios[i].cpf);
            printf("Cargo: %s\n", funcionarios[i].cargo);
            printf("Sal�rio: %.2f\n", funcionarios[i].salario);
            return; // Sai da fun��o ap�s encontrar o funcion�rio
        }
    }

    printf("Funcion�rio com CPF %s n�o encontrado.\n", cpfBusca);
}
