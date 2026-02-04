//--- Sistema de armazenamento de bibliotecas de Livros---//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---constantes globais---//
#define MAX_LIVROS 50
#define TAM_STRING 100

//---Definindo a estrutura do Livro---//

struct Livro {
    char nome [TAM_STRING];
    char autor [TAM_STRING];
    char editora [TAM_STRING];
    int edicao;
};

//---Função para limpar o buffer de entrada---//

//--- Ela "joga fora" qualquer caractere que tenha sobrado na memória temporária do teclado até encontrar um "Enter" ou o fim da leitura.---//


void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
};

//---Função principal para cadastro de livros---//

int main ()  {
    struct Livro biblioteca [MAX_LIVROS]; 
    int totalLivros = 0;
    int opcao; 


 //--Laço principal do menu do programa--//
    do{ 
        //---Exibindo o menu de opções---//
        printf("==========================\n");
        printf("\n    BIBLIOTECA   \n");
        printf("==========================\n");
        printf("1 - Cadastrar novo livro\n");
        printf("2 - Listar todos os livros\n");
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

            case 0: //---Saída do programa---//
                printf("Saindo do programa...\n");
            break;

            default : //---Opção inválida---//
                printf("Opção inválida! Tente novamente.\n");
                printf("\nPressione Enter para continuar...\n");
                getchar();
            break;
        } 
    }while (opcao != 0);
return 0;   
}
