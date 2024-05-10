Oi pessoal! Queria compartilhar com vocês um projeto em C que desenvolvi em Outubro do ano passado junto com mais 5 alunos da Universidade Paulista. É um sistema bem básico de cadastro e consulta de clientes e funcionários.

Vou explicar como ele funciona!

Primeiro, a gente tem duas estruturas: uma para clientes e outra para funcionários. Cada uma dessas estruturas armazena algumas informações importantes, como nome, CPF/CNPJ, telefone, endereço, cargo e salário.

Depois, temos algumas funções principais. A função `fazerLogin` cuida da autenticação do usuário, pedindo um nome de usuário e uma senha. Se as credenciais estiverem corretas, o usuário é autenticado. Se não, ele pode tentar de novo, com um limite máximo de tentativas.

A função `mostrarMenu` exibe as opções disponíveis para o usuário, como cadastrar clientes, cadastrar funcionários, gerar relatórios, consultar dados, consultar funcionários e sair do sistema.

Os dados dos clientes e funcionários são armazenados em arrays. Por exemplo, quando alguém cadastra um novo cliente, os dados são armazenados em um array de clientes. O mesmo vale para os funcionários.

O usuário pode escolher entre várias opções no menu. Por exemplo, ele pode cadastrar um novo cliente ou funcionário, gerar relatórios, ou consultar dados de clientes ou funcionários.

E por fim, temos algumas funções específicas para cada uma dessas ações. Por exemplo, a função `cadastrarCliente` pede os dados de um novo cliente (como nome, CNPJ, telefone e endereço) e os armazena em um array de clientes.

