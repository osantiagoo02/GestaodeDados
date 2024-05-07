Este é um projeto em linguagem C que visa criar um sistema básico de gerenciamento de informações de clientes e funcionários de uma empresa. Aqui está uma visão geral do que foi feito:

Definição de Estruturas: Duas estruturas foram definidas, uma para representar clientes (struct Cliente) e outra para representar funcionários (struct Funcionario). Cada estrutura tem campos para armazenar informações relevantes, como nome, CPF/CNPJ, telefone, endereço, cargo e salário.
Função de Login: Implementou-se uma função fazerLogin() para simular um processo de autenticação. Ela solicita ao usuário um nome de usuário e senha, e compara-os com credenciais predefinidas ("admin" e "12345") para permitir ou negar o acesso.
Menu de Opções: O programa exibe um menu com várias opções que o usuário pode escolher, como cadastrar clientes, cadastrar funcionários, gerar relatórios, consultar dados de clientes, consultar dados de funcionários e sair do programa.
Implementação de Funcionalidades: Cada opção do menu tem uma função associada que realiza uma determinada tarefa. Por exemplo:
cadastrarCliente(): Permite ao usuário cadastrar um novo cliente, solicitando informações como nome da empresa, CNPJ, telefone e endereço.
cadastrarFuncionario(): Permite ao usuário cadastrar um novo funcionário, solicitando informações como nome, CPF, cargo e salário.
gerarRelatorio(): Permite ao usuário escolher entre dois tipos de relatórios para gerar e salvar em um arquivo.
consultarCliente(): Permite ao usuário consultar os dados de um cliente existente, fornecendo o CNPJ como entrada.
consultarFuncionario(): Permite ao usuário consultar os dados de um funcionário existente, fornecendo o CPF como entrada.
Loop Principal: O programa entra em um loop principal que continua executando até que o usuário escolha a opção para sair.
Internacionalização: Foi incluída a biblioteca locale.h para configurar o idioma do programa para Português.
Validação de Entrada: A entrada do usuário é validada em várias partes do código para garantir que não haja problemas ao ler e armazenar as informações.
Resumidamente, este projeto consiste em um sistema simples de gerenciamento de informações de clientes e funcionários, com funcionalidades básicas de cadastro, consulta e geração de relatórios.
