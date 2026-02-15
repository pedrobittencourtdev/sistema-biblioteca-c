//--- Sistema de armazenamento de bibliotecas de Livros---//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---constantes globais---//
#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100
#define TAM_STRING 100

//---Definindo a estrutura do Livro---//

struct Livro {
    char nome [TAM_STRING];
    char autor [TAM_STRING];
    char editora [TAM_STRING];
    int edicao;
    int disponivel; // 1 para disponível, 0 para emprestado
};

//---Definindo a estrutura do Empréstimo---//

struct Emprestimo {
    int indiceLivro;
    char nomeUsuario [TAM_STRING];
};

//---Função para limpar o buffer de entrada---//

//--- Ela "joga fora" qualquer caractere que tenha sobrado na memória temporária do teclado até encontrar um "Enter" ou o fim da leitura.---//

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
};

//---Função principal para cadastro de livros---//

int main ()  {

    struct Livro *biblioteca;
    struct Emprestimo *emprestimos;

    //--USamos calloc para o array de livros. Calloc(num_elementos, tamanho_de_cada_elemento)

    //--Vantagem: Usando calloc para alocar memória para a biblioteca e os empréstimos, garantindo que a memória seja inicializada com zeros.---//
    biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));

    //Usamos malloc para o array de empréstimos. malloc(tamanho_total_em_bytes)
    emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));


    //---Verificando se a alocação de memória foi bem-sucedida---//

    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1; // Encerra o programa com erro
    }


    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao; 


 //--Laço principal do menu do programa--//
    do{ 
        //---Exibindo o menu de opções---//
        printf("==========================\n");
        printf("\n    BIBLIOTECA   \n");
        printf("==========================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
        printf("3 - Realizar um empréstimo\n");
        printf("4 - Listar empréstimos\n");
        printf("0 - Sair\n");
        printf("--------------------------\n");
        printf("Escolha uma opcão: ");

        //---Lendo a opção do usuário---//
        scanf("%d", &opcao);

        limparBuffer(); // Limpa o "\n" deixado pelo scanf

    //---Processando a opção escolhida---//
         switch(opcao) {
            case 1: //---Cadastro do livro---//
                printf("---Cadastro de livro---\n");
                if(totalLivros < MAX_LIVROS){
                printf("Digite o nome do livro: ");
                fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                printf("Digite o autor do livro: ");
                fgets(biblioteca[totalLivros].autor, TAM_STRING,stdin);

                printf("Digite a editora do livro: ");
                fgets(biblioteca[totalLivros].editora, TAM_STRING,stdin);

                biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = 0;
                biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = 0;
                biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = 0;

                printf("Digite a edição do livro: ");
                scanf("%d", &biblioteca[totalLivros].edicao);
                limparBuffer(); // Limpa o "\n" deixado pelo scanf
                biblioteca[totalLivros].disponivel = 1; // Marca o livro como disponível
                totalLivros++;
                printf("\nLivro cadastrado com sucesso!\n");
                } else {
                    printf("Limite de livros atingido!\n");
            }
                printf("\nPressione Enter para continuar...\n");
                getchar(); //Pausa para o usuário ler a mensagem
            break;

            case 2: //---Listagem dos livros cadastrados---//
                printf("---Lista de livros cadastrados---\n");

                if (totalLivros==0){
                    printf("Nenhum livro cadastrado.\n");
                }else{
                    for (int i = 0; i <totalLivros; i++){
                        printf("--------------------------\n");
                        printf("Livro %d \n", i + 1);
                        printf("Nome: %s\n", biblioteca[i].nome);
                        printf("Autor: %s\n", biblioteca[i].autor);
                        printf("Editora: %s\n", biblioteca[i].editora);
                        printf("Edição: %d\n", biblioteca[i].edicao);  
                    }
                    printf("--------------------------\n");
                }
                //---Pausa para o usuário ler a lista---//
                printf("\nPressione Enter para continuar...\n");
                getchar(); 
            break;
            case 3: //---Realizar um empréstimo---//
                printf("---realizar um empréstimo---\n");
                
                if(totalEmprestimos >= MAX_EMPRESTIMOS){
                    printf("Limite de empréstimos atigindo!\n");
                }else{
                    printf("Livros disponíveis:\n");
                    int disponivel = 0;
                    for(int i = 0; i < totalLivros; i++){
                        if (biblioteca[i].disponivel){
                            printf("%d - %s\n", i + 1, biblioteca[i].nome);
                            disponivel++;
                        }
                    }
                    if (disponivel == 0){
                        printf("Nenhum livro disponível para empréstimo.\n");
                }else{
                    printf("Digite o número do livro que deseja emprestar: ");
                    int numLivro;
                    scanf("%d", &numLivro);
                    limparBuffer(); // Limpa o "\n" deixado pelo scanf

                    int indiceLivro = numLivro - 1; // Ajusta para índice do array

                    if (indiceLivro >=0 && indiceLivro  < totalLivros && biblioteca[indiceLivro].disponivel){
                        printf("Digite o nome do usuário que está pegando o livro emprestado: ");
                        fgets(emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                        emprestimos[totalEmprestimos].nomeUsuario[strcspn(emprestimos[totalEmprestimos].nomeUsuario, "\n")] = 0; // Remove o "\n"
                        emprestimos[totalEmprestimos].indiceLivro = indiceLivro;// Armazena o índice do livro emprestado
                        biblioteca[indiceLivro].disponivel = 0; // Marca o livro como emprestado
                        totalEmprestimos++;
                        printf("\nEmpréstimo realizado com sucesso!\n");
                    }else{
                        printf("\nOpção inválida ou livro não disponível.\n");
                    }
                }
            } printf("\nPressione Enter para continuar...\n");
                getchar(); //Pausa para o usuário ler a mensagem
            break;

            case 4: //---Listar empréstimos---//
                printf("---Lista de empréstimos---\n\n");
                if(totalEmprestimos == 0){
                    printf("Nenhum empréstimo registrado.\n");
                }else{
                    for (int i = 0; i < totalEmprestimos; i++){
                        int indiceLivro = emprestimos[i].indiceLivro;
                        printf("--------------------------\n");
                        printf("Empréstimo %d\n", i + 1);
                        printf("Usuário: %s\n", emprestimos[i].nomeUsuario);
                        printf("Livro: %s\n", biblioteca[indiceLivro].nome);
                        printf("--------------------------\n");
                    }
                } printf("\nPressione Enter para continuar...\n");
                getchar(); //Pausa para o usuário ler a mensagem
            break;
            case 0: //---Saída do programa---//
                printf("Saindo do sistema...\n");
            break;

            default : //---Opção inválida---//
                printf("Opção inválida! Tente novamente.\n");
                printf("\nPressione Enter para continuar...\n");
                getchar();
            break;
        } 
    }while (opcao != 0);

    //---Liberando a memória alocada---//

    free(biblioteca); // Libera a memória alocada para a biblioteca
    free(emprestimos); // Libera a memória alocada para os empréstimos
    printf("Memória liberada. Programa encerrado.\n");
    
return 0;   
}
