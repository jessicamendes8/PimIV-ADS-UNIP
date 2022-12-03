#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h> //necessário para usar setlocale
#include<string.h> //necessário para strcmp
#include<time.h> //necessário para usar localtime() e struct tm
#define SIZE 200

char option;
int cadastro();
int grupos_de_risco();
int grupo_com_comorbidade();
int grupo_sem_risco();
int pesquisa();
int lista();
int login();
int ano;
int mostrar();

typedef struct CADASTRO cadastro2; //redefinindo a struct para encurtar o comando na declaração
struct CADASTRO{
char nome[50];
char cpf[15];
char email[40];
long fone;
char rua[40];
char bairro[40];
char numero[10];
char cidade[30];
char estado[20];
char cep[10];
int nascimento;
int ano;
int confirma;
char comorbidade[20];

int data;
int mes;
int dia;
int hora;
int minutos;
int segundos;

};


int op;
int linha=0;


struct{

    char nome[50];
    char login[20];
    char senha[16];
} usuarios[10];


int i;

int main (){

    system("color C");
    setlocale(LC_ALL, "Portuguese");

    strcpy(usuarios[0].nome, "admin");
    strcpy(usuarios[0].login, "admin");
    strcpy(usuarios[0].senha, "1234");
    while(login()==0);

    do{
       system("cls"); // limpa a tela de saída

       printf("\t\t-------------MENU PRINCIPAL--------------\t\t");
       printf("\t\n-------------------------------------------------------------------\t\n");

       printf("\t\n#--------------------------------------------#\t\n");
       printf("\t\n|[1] - CADASTRAR                               |\t\n");
       printf("\t\n|[2] - PESQUISAR POR PACIENTES CADASTRADOS     |\t\n");
       printf("\t\n|[3] - GRUPOS DE PACIENTES                     |\t\n");
       printf("\t\n|[4] - SAIR                                    |\t\n");
       printf("\t\n#--------------------------------------------#\t\n");
       printf("\t\n Selecione a Opção Desejada: ");
       op=getch();

            switch(op){

            case '1':
                cadastro();

                break; //força a saída imediata do loop

            case '2':
                pesquisa();

                break;

            case '3':
                lista();

                break;

            case '4':

                break;

            default:
                printf("Opção Inválida!\n");
                break;
            }

    }while(op!='4');

    system("cls");
    printf("\t\t\t SAINDO DO SISTEMA!!! \n");
    system("pause");
}

int cadastro(){
  int pessoa;

FILE* arquivo; //ponteiro para o arquivo
cadastro2 add;

arquivo = fopen("Paciente.txt","ab"); //abrindo o arquivo com tipo de abertura ab

if(arquivo == NULL){ //testando se o arquivo foi aberto com sucesso
    printf("Problemas Na Abertura");
}

else {
 struct tm *data_hora_atual; //ponteiro para struct que armazena data e hora
        time_t segundos;    //variável do tipo time_t para armazenar o tempo em segundos
        time(&segundos);
        data_hora_atual = localtime(&segundos);
        data_hora_atual->tm_hour;
        data_hora_atual->tm_min;
        data_hora_atual->tm_sec;
        data_hora_atual->tm_mday;
        data_hora_atual->tm_mon+1;
        add.dia = data_hora_atual->tm_mday;//dia//
        add.mes = data_hora_atual->tm_mon+1;//mes//
        add.ano = data_hora_atual->tm_year+1900;//ano//


    do{
        system("cls");
        printf("\t\t----------CADASTRAMENTO DE PACIENTES--------\t\n");
        printf("\t\t|------------------------------------------|\n\n");

        fflush(stdin);
        printf("\nNome: ");
        gets(add.nome);
        fflush(stdin);
        printf("\nCPF: ");
        gets(add.cpf);
        fflush(stdin);
        printf("\nEmail: ");
        gets(add.email);
        fflush(stdin);
        printf("\nTelefone: ");
        scanf("%ld", &add.fone);
        fflush(stdin);
        printf("\nRua: ");
        gets(add.rua);
        fflush(stdin);
        printf("\nBairro: ");
        gets(add.bairro);
        fflush(stdin);
        printf("\nNúmero: ");
        gets(add.numero);
        fflush(stdin);
        printf("\nCidade: ");
        gets(add.cidade);
        fflush(stdin);
        printf("\nEstado: ");
        gets(add.estado);
        fflush(stdin);
        printf("\nCEP: ");
        gets(add.cep);
        fflush(stdin);
        printf("\nAno de Nascimento: ");
        scanf("%d", &pessoa);
        add.nascimento = add.ano - pessoa;
        fflush(stdin);
        printf("\nIdade: ");
        printf("%d", add.nascimento);
        printf("\n ");
        printf("\nO Paciente Possui Comorbidade? Digite (S)Sim ou (N)Não: ");

        option = toupper (getch());

        if(option == 'S'){

           fflush(stdin);
           printf("\n\nTipo de comorbidade: ");
           gets(add.comorbidade);
           add.confirma = 1; // Confirma que o paciente tem comorbidade
        }
        else{
            add.confirma = 3; // Paciente fora do grupo comorbidade
        }

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        printf("\n\nDATA....: %d/%d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        printf("\nHORA....:%d:%d:%d", tm.tm_hour, tm.tm_min, tm.tm_sec);

        fflush(stdin);

        printf("\n\n");
        printf("Dados do Paciente Salvos!\n\n");

        printf("-------------------------------\n");
        printf("1 - Tentar Novamente           \n");
        printf("2 - Finalizar Cadastro         \n");
        printf("-------------------------------\n");

       fwrite(&add,sizeof(cadastro2),1,arquivo);

        printf("Opção Escolhida: ");
        scanf("%d", &op);


   } while(op != 2);

  fclose(arquivo); //usando fclose para fechar o arquivo


       if(add.nascimento >= 66 ){ //condição para decidir se o paciente tem idade maior ou igual a 66 anos

         FILE *dados;

        dados=fopen("Risco.txt","a"); //abrindo o arquivo
        fprintf(dados,"CEP: %s\n",add.cep);
        fprintf(dados,"Idade: %d\n\n\n",add.nascimento);
        fclose(dados); // fechando arquivo

        }

}
return 0;

}

int pesquisa(){
     system("cls");
     FILE* arquivo; //ponteiro para o arquivo
     cadastro2 add;
     char cpfpaciente[50];

     arquivo = fopen("Paciente.txt", "rb"); //abrindo o arquivo com tipo de abertura rb(leitura)
     if(arquivo == NULL){ //testando se o arquivo foi realmente criado
        printf("Problemas na Abertura");

     }else{
        fflush(stdin);
        printf("\nDigite o CPF: ");
        gets(cpfpaciente);

     while(fread(&add, sizeof(cadastro2), 1,arquivo)==1){ //fread - Lê um arquivo binário
        if(strcmp(cpfpaciente, add.cpf)==0){
        if(add.nascimento <= 65  && add.confirma <=1){



         printf("\t\t-------GRUPO COM COMORBIDADE-------\t\n");
         printf("\t\t-----------------------------------\n\n");
         printf("------------------------------------\n");
         printf("Nome: %s\n", add.nome);
         printf("CPF: %s\n", add.cpf);
         printf("Email: %s\n", add.email);
         printf("Fone: %ld\n", add.fone);
         printf("Rua: %s\n", add.rua);
         printf("Bairro: %s\n", add.bairro);
         printf("Número: %s\n", add.numero);
         printf("Cidade: %s\n", add.cidade);
         printf("Estado: %s\n", add.estado);
         printf("CEP: %s\n", add.cep);
         printf("Idade: %d\n", add.nascimento);
         printf("Data do Diagnóstico.....: %d/%d/%d", add.dia, add.mes, add.ano);
         printf("\n-----------------------------------\n");

        }
       if(add.nascimento <= 65 && add.confirma >=3){

         printf("\t\t-------GRUPO SEM RISCO-------\t\n");
         printf("\t\t------------------------------\n\n");
         printf("------------------------------------\n");

         printf("Nome: %s\n", add.nome);
         printf("CPF: %s\n", add.cpf);
         printf("Email: %s\n", add.email);
         printf("Fone: %ld\n", add.fone);
         printf("Rua: %s\n", add.rua);
         printf("Bairro: %s\n", add.bairro);
         printf("Número: %s\n", add.numero);
         printf("Cidade: %s\n", add.cidade);
         printf("Estado: %s\n", add.estado);
         printf("CEP: %s\n", add.cep);
         printf("Idade: %d\n", add.nascimento);
         printf("Data do Diagnóstico.....: %d/%d/%d", add.dia, add.mes, add.ano);
         printf("\n-----------------------------------\n");

       }
          if(add.nascimento > 65 && add.confirma>=0){

         printf("\t\t-------GRUPO DE RISCO-------\t\n");
         printf("\t\t------------------------------\n\n");
         printf("------------------------------------\n");

         printf("Nome: %s\n", add.nome);
         printf("CPF: %s\n", add.cpf);
         printf("Email: %s\n", add.email);
         printf("Fone: %ld\n", add.fone);
         printf("Rua: %s\n", add.rua);
         printf("Bairro: %s\n", add.bairro);
         printf("Número: %s\n", add.numero);
         printf("Cidade: %s\n", add.cidade);
         printf("Estado: %s\n", add.estado);
         printf("CEP: %s\n", add.cep);
         printf("Idade: %d\n", add.nascimento);
         printf("Data do Diagnóstico.....: %d/%d/%d", add.dia, add.mes, add.ano);
         printf("\n-----------------------------------\n");

     }

     fclose(arquivo); // fechando arquivo
     system("pause"); //pausa na tela, somente para Windows
     }
     }

     }
     return 0;
}

int lista(){

    system("cls");
    printf("\t\t---------GRUPO DE PACIENTES CADASTRADOS NO SISTEMA-------\t\n");
    printf("\t\t|-------------------------------------------------------|\n\n");

        printf("\n[1] - Grupo De Risco\n\n");
        printf("\n[2] - Grupo Com Comorbidade\n\n");
        printf("\n[3] - Grupo Sem Risco\n\n");

        printf("Opção Desejada: ");
        scanf("%d", &op);
        system("cls");

        switch(op){

            case 1:
               grupos_de_risco();

              break;

            case 2:
                grupo_com_comorbidade();

                break;

            case 3:
                grupo_sem_risco();

                break;

            default:
                printf("Opção Inválida!\n");

                break;

            }

            printf("\n--------------------------------\n");
            printf("1 - Voltar Ao Menu Principal     |\n");
            printf("--------------------------------\n");
            printf("Selecione a Opção Desejada: ");
            scanf("%d", &op);

            return 0;
}

int grupos_de_risco(){

     system("cls");
     FILE* arquivo; //ponteiro para o arquivo
     cadastro2 add;

     arquivo = fopen("Paciente.txt", "rb"); //abrindo o arquivo com tipo de abertura rb(leitura)
     if(arquivo == NULL){  //testando se o arquivo foi realmente criado
        printf("Problemas na Abertura");

     }
     else{
        fflush(stdin);

     while(fread(&add, sizeof(cadastro2), 1,arquivo)==1){ //fread - Lê um arquivo binário
            if(add.nascimento > 65 && add.confirma>=0){

         printf("\t\t-------GRUPO DE RISCO-------\t\n");
         printf("\t\t------------------------------\n\n");
         printf("------------------------------------\n");

         printf("Nome: %s\n", add.nome);
         printf("CPF: %s\n", add.cpf);
         printf("Email: %s\n", add.email);
         printf("Fone: %ld\n", add.fone);
         printf("Rua: %s\n", add.rua);
         printf("Bairro: %s\n", add.bairro);
         printf("Número: %s\n", add.numero);
         printf("Cidade: %s\n", add.cidade);
         printf("Estado: %s\n", add.estado);
         printf("CEP: %s\n", add.cep);
         printf("Idade: %d\n", add.nascimento);
         printf("Data do Diagnóstico.....: %d/%d/%d", add.dia, add.mes, add.ano);
         printf("\n\n-----------------------------------\n\n");

     }
     }
     }
     fclose(arquivo);
     return 0;

}
int grupo_com_comorbidade(){

     system("cls");
     FILE* arquivo; //ponteiro para o arquivo
     cadastro2 add;

     arquivo = fopen("Paciente.txt", "rb"); //abrindo o arquivo com tipo de abertura rb(leitura)
     if(arquivo == NULL){  //testando se o arquivo foi realmente criado
        printf("Problemas na Abertura");

     }
     else{
        fflush(stdin);

     while(fread(&add, sizeof(cadastro2), 1,arquivo)==1){ //fread - Lê um arquivo binário
        if(add.nascimento <= 65  && add.confirma <=1){

         printf("\t\t-------GRUPO COM COMORBIDADE-------\t\n");
         printf("\t\t-----------------------------------\n\n");

         printf("Nome: %s\n", add.nome);
         printf("CPF: %s\n", add.cpf);
         printf("Email: %s\n", add.email);
         printf("Fone: %ld\n", add.fone);
         printf("Rua: %s\n", add.rua);
         printf("Bairro: %s\n", add.bairro);
         printf("Número: %s\n", add.numero);
         printf("Cidade: %s\n", add.cidade);
         printf("Estado: %s\n", add.estado);
         printf("CEP: %s\n", add.cep);
         printf("Idade: %d\n", add.nascimento);
         printf("Comorbidade: %s\n", add.comorbidade);
         printf("Data do Diagnóstico.....: %d/%d/%d", add.dia, add.mes, add.ano);
         printf("\n\n-----------------------------------\n\n");

     }
     }
     }

     fclose(arquivo);
     return 0;

}

int grupo_sem_risco(){

     system("cls");
     FILE* arquivo; //ponteiro para o arquivo
     cadastro2 add;

     arquivo = fopen("Paciente.txt", "rb"); //abrindo o arquivo com tipo de abertura rb(leitura)
     if(arquivo == NULL){  //testando se o arquivo foi realmente criado
        printf("Problemas na Abertura");

     }
     else {
        fflush(stdin);

     while(fread(&add, sizeof(cadastro2), 1,arquivo)==1){ //fread - Lê um arquivo binário
      if(add.nascimento <= 65 && add.confirma >=3){

         printf("\t\t-------GRUPO SEM RISCO-------\t\n");
         printf("\t\t------------------------------\n\n");
         printf("------------------------------------\n");

         printf("Nome: %s\n", add.nome);
         printf("CPF: %s\n", add.cpf);
         printf("Email: %s\n", add.email);
         printf("Fone: %ld\n", add.fone);
         printf("Rua: %s\n", add.rua);
         printf("Bairro: %s\n", add.bairro);
         printf("Número: %s\n", add.numero);
         printf("Cidade: %s\n", add.cidade);
         printf("Estado: %s\n", add.estado);
         printf("CEP: %s\n", add.cep);
         printf("Idade: %d\n", add.nascimento);
         printf("Data do Diagnóstico.....: %d/%d/%d", add.dia, add.mes, add.ano);
         printf("\n\n-----------------------------------\n\n");

     }
     }
     }

     fclose(arquivo); //fechando o arquivo
     return 0;

}

int login (){

    system("cls");

    char login[20], senha[16];
    int i=0;

    printf("\t\t------LOGIN DO PROGRAMA------\t\t");
    printf("\t\n------------------------------------------------------------\t\n");
    printf("\t\n------------------------------------------------------------\t\n");

    printf("\t LOGIN: ");
    gets(login);
    printf("\n\t SENHA: ");
    gets(senha);

            if(strcmp(usuarios[i].login, login)==0 && strcmp(usuarios[i].senha, senha)==0){
             return 1;
        main();

            }

        else{

        printf("\n\n");
        printf("---------------------------------------------\n");
        printf("| Login incorreto!\7\7 Por favor, tente novamente. |\n");
        printf("---------------------------------------------\n\n");

        }

        system("pause");

        return 0;
}


