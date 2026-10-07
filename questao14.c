#include <stdio.h>

void copiar_string(char *copia, int tam, char *original) {
    int k;

    for (k = 0; k < tam && original[k] != '\0'; k++) {
        copia[k] = original[k];
    }
    copia[k] = '\0';
}

typedef struct {
    int Num;
    char Rua[100];
    char Complemento[50];
    char Bairro[100];
    char Cidade[100];
    char Estado[3];
    char CEP[10];
} Endereco;

typedef struct {
    char nome[51];
    int idade;
    char CPF[15];
    Endereco endereco;
    char estado_civil;
} Funcionario;

Endereco criar_endereco(
    int Num,
    char *Rua,
    char *Complemento,
    char *Bairro,
    char *Cidade,
    char *Estado,
    char *CEP
) {
    Endereco end;
    end.Num = Num;
    copiar_string(end.Rua, 100, Rua);
    copiar_string(end.Complemento, 50 ,Complemento);
    copiar_string(end.Bairro, 100 ,Bairro);
    copiar_string(end.Cidade, 100 ,Cidade);
    copiar_string(end.Estado, 3, Estado);
    copiar_string(end.CEP, 10, CEP);

    return end;
}

Funcionario criar_funcionario(
    char *nome,
    int idade,
    char *CPF,
    Endereco endereco,
    char estado_civil
) {
    Funcionario func;
    copiar_string(func.nome, 51 ,nome);
    func.idade = idade;
    copiar_string(func.CPF, 15 ,CPF);
    func.endereco = endereco;
    func.estado_civil = estado_civil;

    return func;
}

void imprimir_Endereco(Endereco end) {
    printf("%s, %d, %s, %s, %s - %s, %s\n", end.Rua, end.Num, end.Complemento, end.Bairro, end.Cidade, end.Estado, end.CEP);
}

void imprimir_funcionario(Funcionario func) {
    printf("Nome: %s\n", func.nome);
    printf("Idade: %d\n", func.idade);
    printf("CPF: %s\n", func.CPF);
    printf("Endereco: ");
    imprimir_Endereco(func.endereco);
    printf("Estado Civil: ");
    switch (func.estado_civil) {
        case 'S':
            printf("Solteiro.\n");
            break;
        case 'C':
            printf("Casado.\n");
            break;
        case 'D':
            printf("Divorciado.\n");
            break;
        case 'V':
            printf("Viuvo.\n");
            break;
        case 'J':
            printf("Separado Judicialmente.\n");
            break;
        default:
            printf("Nao informado.\n");
            break;
    }
}

int main() {
    Funcionario func1 = criar_funcionario("Jose Miguel", 23, "032.129.123-10", criar_endereco(67, "Rua Jose Chagas de Machado", "", "Silvania", "Jabitaca", "PE", "34428-120"), 'S');
    imprimir_funcionario(func1);
    return 0;
}