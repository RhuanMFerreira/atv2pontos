#include <stdio.h>

int validaQuantidade(int quantidade);
float calculaSalario(int quantidade);
void mostraFinal(int totalFuncionarios);

int main()
{
    int totalFuncionarios;

    printf("Informe o numero total de funcionarios: ");
    scanf("%d", &totalFuncionarios);

    for (int i = 1; i <= totalFuncionarios; i++)
    {
        int quantidadePecas;

        printf("Informe a quantidade de pecas fabricadas pelo funcionario %d: ", i);
        scanf("%d", &quantidadePecas);

        if (validaQuantidade(quantidadePecas))
        {

            printf("O salario do funcionario %d e R$ %.2f\n", i, calculaSalario(quantidadePecas));
        }
        else
        {
            printf("Quantidade invalida de pecas. Tente novamente.\n");
            i--;
        }
    }

    mostraFinal(totalFuncionarios);

    return 0;
}

int validaQuantidade(int quantidade)
{
    return quantidade >= 0;
}

float calculaSalario(int quantidade)
{
    float salarioBase = 600.0;
    float adicional = 0.0;

    if (quantidade > 50)
    {
        adicional += 0.50 * (quantidade - 50);

        if (quantidade > 80)
        {
            adicional += 0.75 * (quantidade - 80);
        }
    }

    return salarioBase + adicional;
}

void mostraFinal(int totalFuncionarios)
{
    printf("\nResumo:\n");
    printf("Numero total de funcionarios: %d\n", totalFuncionarios);
    printf("Fim do programa.\n");
}