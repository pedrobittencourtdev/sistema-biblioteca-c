# Sistema de Gerenciamento de Biblioteca 📚

Este é um projeto desenvolvido em **Linguagem C** para o gerenciamento simplificado de um acervo de livros. O sistema permite o cadastro, a listagem, empréstimos e listagem de empréstimos das obras, através de uma interface via terminal.

## 🚀 Novidades da Última Atualização (Refatoração)

O código fonte foi recentemente refatorado para abandonar os *arrays* estáticos simples e implementar conceitos fundamentais e mais avançados de programação em C:

* **Estruturas de Dados (`struct`):** Criação de modelos dedicados para `Livro` e `Emprestimo`, tornando o código muito mais organizado, legível e orientado a entidades.
* **Ponteiros:** Utilização de ponteiros para uma manipulação mais direta e eficiente dos dados em memória.
* **Alocação Dinâmica de Memória:** * Uso de `calloc` para alocar e inicializar automaticamente a zeros o espaço do catálogo da biblioteca.
    * Uso de `malloc` para dimensionar a matriz de empréstimos na memória.
* **Gestão Segura de Recursos:** Implementação da função `free()` no encerramento do programa para garantir a devolução da memória ao sistema operativo, evitando vazamentos de memória (*memory leaks*).
* **Modolurização:** Modularização do código, com o objetivo de organizar o código para futuras alterações, sem comprometer o progranma.

## ⚙️ Funcionalidades

* **Registar novo livro:** Adiciona livros com título, autor, editora, edição e define automaticamente o estado inicial como "disponível".
* **Listar todos os livros:** Exibe o catálogo completo registado no sistema.
* **Realizar empréstimo:** Verifica a disponibilidade e permite associar um livro a um utilizador específico.
* **Listar empréstimos:** Mostra o histórico de livros atualmente requisitados e o nome dos respetivos utilizadores.

## 💻 Como executar:

- Para rodar este projeto, você precisará de um compilador de C (GCC, Clang ou o próprio VS Code configurado).

 ## 📥 Como baixar e testar o projeto

Se você quiser testar este sistema na sua máquina, siga os passos abaixo:

1. **Clone o repositório:**
   ```bash
   git clone https://github.com/pedrobittencourtdev/sistema-biblioteca-c.git

2. **Entre no terminal e na pasta:**
   ```bash
   cd sistema-biblioteca-c
3. **Compile o código:**
   ```bash
   gcc cadastroLivros.c -o sistema
4. **Execute:**
   ```bash
   ./sistema
   
