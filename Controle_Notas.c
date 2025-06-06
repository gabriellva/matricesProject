#include <stdio.h>
#include <locale.h>
#define MAX 50

char Nomes[20][MAX];
float NotaseMedia[20][3];

//FEITO POR GABRIEL LOPES VAZ DE ASSIS

void Armazena(int tamanho) {

    for(int i = 0; i < tamanho; i++) // Passa por todos os alunos (tamanho = quantidade de alunos)
    {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: ");
        while(getchar() != '\n'); // Limpa o buffer
        scanf(" %[^\n]s", Nomes[i]); // Aceita nomes com espaço

        
        printf("Nota 1: ");
        while(getchar() != '\n'); // Limpa o buffer
        scanf("%f", &NotaseMedia[i][0]); // Guarda no linha correspondente ao aluno, na coluna correspondente à primeira nota 
        
        do
        {
            if(NotaseMedia[i][0] > 10)
            {
                printf("Apenas valores entre 0 e 10.\n");
                while(getchar() != '\n'); // Limpa o buffer
                scanf("%f", &NotaseMedia[i][0]);
            }

        } while(NotaseMedia[i][0] > 10); // Laço de repetição para permitir apenas valores entre 0 e 10
        

        printf("Nota 2: "); 
        while(getchar() != '\n'); // Limpa o buffer
        scanf("%f", &NotaseMedia[i][1]); // Guarda no linha correspondente ao aluno, na coluna correspondente à segunda nota
        
        do
        {
            if (NotaseMedia[i][1] > 10)
            {
                printf("Apenas valores entre 0 e 10.\n");
                while(getchar() != '\n'); // Limpa o buffer
                scanf("%f", &NotaseMedia[i][1]);
            }
        
        } while (NotaseMedia[i][1] > 10); // Laço de repetição para permitir apenas valores entre 0 e 10

        NotaseMedia[i][2] = (NotaseMedia[i][0] + NotaseMedia[i][1]) / 2.0; // Cálculo da média das notas referentes a cada aluno
    }        
}
void ExibaListagemGeral(int tamanho){
    
    
    printf("\nEXIBINDO TODOS OS NOMES E NOTAS!\n");
    
    for (int i = 0; i < tamanho; i++)
    {
        printf("\nAluno %d:\n", i + 1);
        printf("Nome: %s\n", Nomes[i]);
        printf("Nota 1: %.2f\n", NotaseMedia[i][0]);
        printf("Nota 2: %.2f\n", NotaseMedia[i][1]); // Exibir todas as notas e médias de cada aluno
        printf("Media: %.2f\n", NotaseMedia[i][2]);
    }
}

void ExibaAprovados(int tamanho){

    printf("\nEXIBINDO ALUNOS APROVADOS!\n");
    for (int i = 0; i < tamanho; i++)
    {
        if (NotaseMedia[i][2] >= 6)
        {
            printf("\n%s aprovado(a)! Obteve media %.2f\n\n", Nomes[i], NotaseMedia[i][2]); // Mostra os alunos que foram aprovados e a média do aluno
        } 
    }
}

float MaiorMedia(int tamanho){

    float maiorMedia = NotaseMedia[0][2];

    for (int i = 0; i < tamanho; i++)
    {
        if (NotaseMedia[i][2] > maiorMedia)
        {
            maiorMedia = NotaseMedia[i][2]; // Verificação da maior nota entre os alunos
        }
    }

    return maiorMedia; // Retorno da maior nota
}

float mediaSala(int tamanho){

    float mediaSala;
    float soma;

    for (int i = 0; i < tamanho; i++)
    {
        soma += NotaseMedia[i][2]; // Incrementa à variável "soma" a média de todos os alunos
    }

    mediaSala = (soma / tamanho);
    return mediaSala; // Retorna o valor da média da sala
}

void ExibaAlunosMaiorMedia(int tamanho, float maiorMedia){

    printf("EXIBINDO ALUNOS COM A MAIOR MEDIA!\n");

    for (int i = 0; i < tamanho; i++)
    {
        if (NotaseMedia[i][2] == maiorMedia)
        {
            printf("\n%s: %.2f\n\n", Nomes[i], NotaseMedia[i][2]); // Verifica se a média do aluno selecionado no laço é igual à maior média, se sim, mostra o nome do aluno e sua média 
        }
    }
}

int main (){

    setlocale(LC_ALL, " "); // Adiciona a possibilidade de incluir acentos
    int qtdAlunos;

    printf("Digite a quantidade de alunos (Entre 4 e 20): ");
    scanf(" %d", &qtdAlunos); // Armazena a quantidade de alunos 
    do {
    
        if (qtdAlunos < 4 || qtdAlunos > 20) {
            printf("Quantidade de alunos inválida. Apenas valores entre 4 e 20 são permitidos.\n"); // Laço de repetição para permitir valores apenas entre 4 e 20
            scanf(" %d", &qtdAlunos);
        }

    } while (qtdAlunos < 4 || qtdAlunos > 20); // Laço de repetição para permitir valores apenas entre 4 e 20

    Armazena(qtdAlunos);
    ExibaListagemGeral(qtdAlunos); // Chama os métodos de armazenamento, exibição da lista e exibição dos aprovados
    ExibaAprovados(qtdAlunos);

    float maiorMediaDaSala = MaiorMedia(qtdAlunos); // Armazena o retorno do método para saber a maior média e mostra para o usuário
    printf("A maior media encotrada foi de %.2f\n", maiorMediaDaSala);

    float mediaDaSala = mediaSala(qtdAlunos); // Armazena o retorno do método para saber a média da sala e mostra para o usuário
    printf("A media da sala foi de %.2f\n\n", mediaDaSala);
    
    ExibaAlunosMaiorMedia(qtdAlunos, maiorMediaDaSala); // Chama o método que exibe os alunos com a maior média
}
