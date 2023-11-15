#include <stdio.h>
#include <stdlib.h>

char obterSexo();
float obterSalario();
int validaSalario(float salario);
void classificaSalario(float salario);
void mostraClassificacao(float salario, char sexo);
void mostraEstatisticas(int abaixoSalarioMinimo, int acimaSalarioMinimo);

int main()
{
    int totalAssalariados, abaixoSalarioMinimo = 0, acimaSalarioMinimo = 0;

    printf("Informe o numero total de assalariados: ");
    scanf("%d", &totalAssalariados);

    for (int i = 1; i <= totalAssalariados; i++)
    {
        char sexo = obterSexo();
        float salario = obterSalario();

        if (validaSalario(salario))
        {

            classificaSalario(salario);

            mostraClassificacao(salario, sexo);

            if (salario < 1400.00)
            {
                abaixoSalarioMinimo++;
            }
            else
            {
                acimaSalarioMinimo++;
            }
        }
        else
        {
            printf("Salario invalido. Tente novamente.\n");
            i--;
        }
    }

    mostraEstatisticas(abaixoSalarioMinimo, acimaSalarioMinimo);

    return 0;
}

char obterSexo()
{
    char sexo;
    printf("Informe o sexo (M para masculino ou F para feminino): ");
    scanf(" %c", &sexo);
    return sexo;
}

float obterSalario()
{
    float salario;
    printf("Informe o salario do assalariado (maior que R$1,00): ");
    scanf("%f", &salario);
    return salario;
}

int validaSalario(float salario)
{
    return salario > 1.00;
}

void classificaSalario(float salario)
{
    if (salario < 1400.00)
    {
        printf("Salario abaixo do salario minimo.\n");
    }
    else if (salario == 1400.00)
    {
        printf("Salario igual ao salario minimo.\n");
    }
    else
    {
        printf("Salario acima do salario minimo.\n");
    }
}

void mostraClassificacao(float salario, char sexo)
{
    printf("Salario: R$ %.2f\n", salario);
    printf("Classificacao em relacao ao salario minimo: ");
    classificaSalario(salario);
    printf("Sexo: %s\n", (sexo == 'M' || sexo == 'm') ? "Masculino" : "Feminino");
    printf("\n");
}

void mostraEstatisticas(int abaixoSalarioMinimo, int acimaSalarioMinimo)
{
    printf("\nEstatisticas Finais:\n");
    printf("Assalariados com salario abaixo do salario minimo: %d\n", abaixoSalarioMinimo);
    printf("Assalariados com salario acima do salario minimo: %d\n", acimaSalarioMinimo);
    printf("Fim do programa.\n");
}