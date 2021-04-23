# Projeto-calculadora
Projeto calculadora conversão decimal/binario
#include <stdio.h>
#include <stdlib.h>
#include <math.h> //Permite a utilização de funções matemáticas como pow, para potências
#include <locale.h> //permite a utilização de acentos e marcas gráficas
#define tamanho 100 //define o valor fixo (80) para tamanho de array

int main(){
    setlocale(LC_ALL, "Portuguese"); //Permite a utilização de acentos e marcações gráficas
    int opcao=0; //Variável para escolha da opção
    int numero, auxiliar = 0; //Variável para numero a ser inserido e auxiliar nas conversões
    long int resultado; //Variável de resultado
    long int numBinario[tamanho]; //Vetor utilizado na conversão de bases
    int tamanhoArray, expoente=0, numValido = 1; //Variáveis para definir o tamanho do vetor, o expoente na conversão e validação do número
    int a=0, i=0; //Variáveis utilizadas em laços de repetição para incremento/decremento

    while(opcao != 3){
        //Inicializa e redefine os valores após um uso do programa
        system("CLS"); //Limpa a tela, removendo todos os caracteres
        for(i=0; i < tamanho; i++){
            numBinario[i] = 0;
        }
        a=0;
        i = 0;
        auxiliar = 0;
        expoente=0;
        numero = 0;
        numValido = 1;
        resultado = 0;
        tamanhoArray = 0;
        //Final das inicializações e redefinição de valores
        //Impressão do menu inicial
        printf("-----Conversor de Base-----");
        printf("\n1 - Decimal para binário");
        printf("\n2 - Binário para decimal");
        printf("\n3 - Sair");
        printf("\n---------------------------");
        printf("\nEscolha uma opção: "); //Solicitação de escolha de opção
        scanf("%d", &opcao); //Leitura para receber a opção escolhida
        fflush(stdin); //Limpa o buffer do scanf para evitar erros ao inserir valores do tipo Char
        system("CLS"); //Limpa a tela, removendo todos os caracteres

        switch(opcao){ //Verifica a opção e permite a execução das instruções referentes à opção escolhida
            case 1:
                //Seleciona conversão de base 10 para base 2
                printf("-----Decimal para binário-----");
                printf("\nDigite o número: ");
                scanf("%d", &numero); //Leitura para receber o número a ser convertido
                printf("\n%d em binários: ",numero); //Imprime o número digitado e, após as seguintes instruções, imprimirá o resultado

                //Algoritmo de divisões sucessivas para a conversão
                i = 1; //Define a variável da posição (0,1,2 para definir "unidade, dezena, centena") como 1
                while (numero != 0){ //Percorre o número, efetuando a conversão enquanto for diferente de 0
                    resultado += (numero % 2) * i; //O resultado da conversão é o resto da divisão por 8 e é multiplicado por i para indicar a posição (0,1,2 etc)
                    numero /= 2; //Divide o número por 8 para seguir a lógica de divisões sucessivas
                    i *= 10; //Multiplica por 10 para efetuar o cálculo referente ao próximo digito
                } //Fim da conversão de dados
                printf("%ld(2)\n", resultado); //Imprime a base do número e salta uma linha
                system("PAUSE"); //Aguarda o usuário para continuar
            break;
            case 2:
                //Seleciona conversão de base 2 para base 10
                printf("-----Binário para decimal-----");
                printf("\nDigite o número: ");
                scanf("%d", &numero); //Leitura para receber o número a ser convertido
                printf("\n"); //Quebra uma linha
                auxiliar = numero; //Atribui o valor do número recebido à variável auxiliar
                //Validação para checar se o número binário possui apenas zeros e uns
                while (auxiliar != 0 && numValido ==1) { //Percorre o número dividindo-o por 10 para eliminar o último digito
                    if ((auxiliar % 10) != 0 && (auxiliar % 10) != 1) { //Verifica se o último digito é um 0 ou 1, indicando se o número possui apenas esses algarismos
                        numValido = 0; //caso possua outros, o número é marcado como inválido
                    } else{
                        numValido = 1; //Caso passe na validação, o número é marcado como válido
                    }
                    auxiliar /= 10;
                }
                if(numValido == 1){ //caso o número seja válido, executa a conversão
                    //Transfere o número binário inserido para um vetor
                    while (numero != 0){
                        numBinario[i] = numero%10; //Armazena o último digito em um vetor
                        numero /= 10; //Divide o número por 10 para remover o último digito e buscar o próximo
                        i++; //Incrementa para continuar percorrendo o número
                    }
                    if(numBinario[i]==0){
                        i--;
                    }
                    numero = 0; //limpa a variável para exibir o resultado no final
                    tamanhoArray = i; //define o tamanho do array como o número de iterações necessárias para percorrer o número
                    long int numConversao[tamanhoArray]; //cria o vetor do tamanho necessário

                   //inverte o número binário utilizando um vetor auxiliar (já que o número é invertido ao ser transferido para string)
                    for (a = i, i=0; a >= 0; a--, i++){
                        numConversao[i] = numBinario[a]; //transfere o último digito de um vetor para o primeiro do outro (invertendo e colocando na ordem certa)
                        printf("%ld", numConversao[i]); //imprime o número digitado em binário
                    }

                    //inicia conversão de dados
                    for (a = tamanhoArray; a >= 0; a--){
                        numConversao[a] = numConversao[a] * pow(2, expoente); //multiplica o digito pela base elevada à posição
                        numero += numConversao[a]; //Soma o valor multiplicado para exibir o resultado
                        expoente++; //incrementa o expoente
                    } //Finaliza conversão de dados
                    //Inicia a impressão do número convertido
                    printf("(2) em decimal: %d", numero); //Imprime o número já convertido
                } else {
                    printf("\nO número inserido não pertence a base 2! Tente novamente!"); //Caso o número seja inválido, exibe mensagem de erro e retorna para o menu
                }
                printf("\n");
                system("PAUSE"); //Aguarda o usuário para continuar
            break;




            case 3:
                //Seleciona opção de sair
                printf("O programa será encerrado.\n"); //Mensagem indicando a finalização do programa
                system("PAUSE"); //Aguarda o usuário para continuar
            break;

            default:
                //Seleciona opção padrão caso o valor inserido não atenda nenhuma condição dos 'cases'
                printf("Opção inválida, tente novamente.\n"); //Mensagem indicando que a opção escolhida é inválida
                system("PAUSE"); //Aguarda o usuário para continuar
            break;
        }
    }
    return 0;
    }
