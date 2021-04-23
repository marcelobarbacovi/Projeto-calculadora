#include <stdio.h>
#include <stdlib.h>
#include <math.h> //Permite a utiliza��o de fun��es matem�ticas como pow, para pot�ncias
#include <locale.h> //permite a utiliza��o de acentos e marcas gr�ficas
#define tamanho 100 //define o valor fixo (80) para tamanho de array

int main(){
    setlocale(LC_ALL, "Portuguese"); //Permite a utiliza��o de acentos e marca��es gr�ficas
    int opcao=0; //Vari�vel para escolha da op��o
    int numero, auxiliar = 0; //Vari�vel para numero a ser inserido e auxiliar nas convers�es
    long int resultado; //Vari�vel de resultado
    long int numBinario[tamanho]; //Vetor utilizado na convers�o de bases
    int tamanhoArray, expoente=0, numValido = 1; //Vari�veis para definir o tamanho do vetor, o expoente na convers�o e valida��o do n�mero
    int a=0, i=0; //Vari�veis utilizadas em la�os de repeti��o para incremento/decremento

    while(opcao != 3){
        //Inicializa e redefine os valores ap�s um uso do programa
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
        //Final das inicializa��es e redefini��o de valores
        //Impress�o do menu inicial
        printf("-----Conversor de Base-----");
        printf("\n1 - Decimal para bin�rio");
        printf("\n2 - Bin�rio para decimal");
        printf("\n3 - Sair");
        printf("\n---------------------------");
        printf("\nEscolha uma op��o: "); //Solicita��o de escolha de op��o
        scanf("%d", &opcao); //Leitura para receber a op��o escolhida
        fflush(stdin); //Limpa o buffer do scanf para evitar erros ao inserir valores do tipo Char
        system("CLS"); //Limpa a tela, removendo todos os caracteres

        switch(opcao){ //Verifica a op��o e permite a execu��o das instru��es referentes � op��o escolhida
            case 1:
                //Seleciona convers�o de base 10 para base 2
                printf("-----Decimal para bin�rio-----");
                printf("\nDigite o n�mero: ");
                scanf("%d", &numero); //Leitura para receber o n�mero a ser convertido
                printf("\n%d em bin�rios: ",numero); //Imprime o n�mero digitado e, ap�s as seguintes instru��es, imprimir� o resultado

                //Algoritmo de divis�es sucessivas para a convers�o
                i = 1; //Define a vari�vel da posi��o (0,1,2 para definir "unidade, dezena, centena") como 1
                while (numero != 0){ //Percorre o n�mero, efetuando a convers�o enquanto for diferente de 0
                    resultado += (numero % 2) * i; //O resultado da convers�o � o resto da divis�o por 8 e � multiplicado por i para indicar a posi��o (0,1,2 etc)
                    numero /= 2; //Divide o n�mero por 8 para seguir a l�gica de divis�es sucessivas
                    i *= 10; //Multiplica por 10 para efetuar o c�lculo referente ao pr�ximo digito
                } //Fim da convers�o de dados
                printf("%ld(2)\n", resultado); //Imprime a base do n�mero e salta uma linha
                system("PAUSE"); //Aguarda o usu�rio para continuar
            break;
            case 2:
                //Seleciona convers�o de base 2 para base 10
                printf("-----Bin�rio para decimal-----");
                printf("\nDigite o n�mero: ");
                scanf("%d", &numero); //Leitura para receber o n�mero a ser convertido
                printf("\n"); //Quebra uma linha
                auxiliar = numero; //Atribui o valor do n�mero recebido � vari�vel auxiliar
                //Valida��o para checar se o n�mero bin�rio possui apenas zeros e uns
                while (auxiliar != 0 && numValido ==1) { //Percorre o n�mero dividindo-o por 10 para eliminar o �ltimo digito
                    if ((auxiliar % 10) != 0 && (auxiliar % 10) != 1) { //Verifica se o �ltimo digito � um 0 ou 1, indicando se o n�mero possui apenas esses algarismos
                        numValido = 0; //caso possua outros, o n�mero � marcado como inv�lido
                    } else{
                        numValido = 1; //Caso passe na valida��o, o n�mero � marcado como v�lido
                    }
                    auxiliar /= 10;
                }
                if(numValido == 1){ //caso o n�mero seja v�lido, executa a convers�o
                    //Transfere o n�mero bin�rio inserido para um vetor
                    while (numero != 0){
                        numBinario[i] = numero%10; //Armazena o �ltimo digito em um vetor
                        numero /= 10; //Divide o n�mero por 10 para remover o �ltimo digito e buscar o pr�ximo
                        i++; //Incrementa para continuar percorrendo o n�mero
                    }
                    if(numBinario[i]==0){
                        i--;
                    }
                    numero = 0; //limpa a vari�vel para exibir o resultado no final
                    tamanhoArray = i; //define o tamanho do array como o n�mero de itera��es necess�rias para percorrer o n�mero
                    long int numConversao[tamanhoArray]; //cria o vetor do tamanho necess�rio

                   //inverte o n�mero bin�rio utilizando um vetor auxiliar (j� que o n�mero � invertido ao ser transferido para string)
                    for (a = i, i=0; a >= 0; a--, i++){
                        numConversao[i] = numBinario[a]; //transfere o �ltimo digito de um vetor para o primeiro do outro (invertendo e colocando na ordem certa)
                        printf("%ld", numConversao[i]); //imprime o n�mero digitado em bin�rio
                    }

                    //inicia convers�o de dados
                    for (a = tamanhoArray; a >= 0; a--){
                        numConversao[a] = numConversao[a] * pow(2, expoente); //multiplica o digito pela base elevada � posi��o
                        numero += numConversao[a]; //Soma o valor multiplicado para exibir o resultado
                        expoente++; //incrementa o expoente
                    } //Finaliza convers�o de dados
                    //Inicia a impress�o do n�mero convertido
                    printf("(2) em decimal: %d", numero); //Imprime o n�mero j� convertido
                } else {
                    printf("\nO n�mero inserido n�o pertence a base 2! Tente novamente!"); //Caso o n�mero seja inv�lido, exibe mensagem de erro e retorna para o menu
                }
                printf("\n");
                system("PAUSE"); //Aguarda o usu�rio para continuar
            break;




            case 3:
                //Seleciona op��o de sair
                printf("O programa ser� encerrado.\n"); //Mensagem indicando a finaliza��o do programa
                system("PAUSE"); //Aguarda o usu�rio para continuar
            break;

            default:
                //Seleciona op��o padr�o caso o valor inserido n�o atenda nenhuma condi��o dos 'cases'
                printf("Op��o inv�lida, tente novamente.\n"); //Mensagem indicando que a op��o escolhida � inv�lida
                system("PAUSE"); //Aguarda o usu�rio para continuar
            break;
        }
    }
    return 0;
    }


