# Questões para praticar estrutura de dados

## Funções recursivas

1. Escreva um programa com um função recursiva que recebe um número e calcule a raiz quadrada por aproximações de pontencia de 2.
Exemplo
```
sqrt(16) = 16 * 1/4
sqrt(5) = 5 * (1/4 + 1/8 + 1/16 + 1/128 + 1/1024 + 1/2048 + 1/4096 + ...)
```

2. Escreva um programa com uma função recursiva que recebe dois números M e N de ordem crescente e calcule a soma de todos os números primos de M até N.

3. Escreva um programa com uma função recursiva que recebe um numero inteiro N e imprime a forma expandidade de (a+b)^N.
```
(a+b)^2 = a^2 + 2 * a * b + b^2
(a+b)^5 = a^5 + 5 * a^4 * b + 10 * a^3 * b^2 + 10 * a^2 * b^3 + 5 * a * b^4 + b^5
```

## Vetores

4. Escreva um programa com um função que calcule o desvio padrão de um vetor de numeros reais usando a raiz quadrada da questao 1.

5. Em um país com N lugares turísticos, que queremos visitar cada lugar x vezes, será que é possivel visitar só deslocando de lugares próximos. Com base nisso, dado um vetor {x1, x2, x3, x4, ..., xN} é possivel visitar quantos lugares no máximo se avançarmos só um casa no vetor e começando x1, nós não queremos ultrapassar a meta? Por exemplo:
```
vetor1 = {2, 2, 1}
é possivel de x1 -> x2 -> x1 -> x2 -> x3
visitando todos os lugares.

vetor2 = {4, 3, 1, 1}
é possivel no máximo de x1 -> x2 -> x1 -> x2 -> x1 -> x2 -> x3 -> x4
visitando apenas o x2 x3 e x4.
```

## Matrizes

6. Escreva um programa que calcule em uma matriz de 3x3 formado por 'X', '-' e 'O', quem ganhou o jogo da velha, ou se ainda dá para jogar ou se ouve empate.

7. Escreva um programa de uma imagem de 16x16 formada pela as cores RGB e transforme ela em uma imagem em preto e branco baixando a saturação.

## Ponteiros

8. Escreva um programa com uma função que recebe 3 ponteiros de inteiros e ordene em as variaveis em ordem crescente.

9. Escreva um programa com uma função que receba um ponteiro do inicio de vetor de inteiros ordenado e um número inteiro N e retorne o ponteiro do N que está presente dentro da vetor, caso não tenha o número retorne o NULL.

10. Escreva um programa com uma função que receba um ponteiro do inicio de uma matriz quadrada formada e retorne um ponteiro de inicio de um vetor com as somas das linhas.

11. Escreva um programa com uma função que receba um ponteiro do inicio de uma matriz quadrada formada e retorne um ponteiro de inicio de uma vetor com as diagonais da matriz.

12. Escreva um programa com uma função que receba dois ponteiro de inicio de uma matriz MxK e KxN respectivamente e retorne o ponteiro de inicio de uma matriz MxN do produto das matriz.

## Estrutura Heterogêneas

13. Escreva um programa com uma função que recebe 2 pontos e retorne a distancia euclidiana delas.

14. Escreva um programa com uma função que recebe dados de um funcionário de uma empresa e imprima os dados como: nome, idade, CPF, endereço e o estado Civil.

15. Escreva um programa com as funções de criar um número complexo, calcular a soma, subtração, multiplicação e divisão de 2 números complexo, o conjudado de número complexo e a pontencia por um número inteiro.

16. Escreva um programa com uma função que recebe um poligono na malha quadrada com número de pontos tocando na borda e de dentro do poligono e calcule sua area de acordo com Teorema do Pick.

17. Escreva um programa com uma função que recebe 3 equações com 3 icógnitas, e calcule os valores das icógnitas.

18. Escreva um programa com um função que recebe um ponteiro de inicio do vetor de pontos e calcule o ponto médio dos pontos.

19. Escreva um programa com uma função que recebe um ponteiro de inicio do vetor de pessoa com nome, sexo e idade, e determine o homem e a mulher com a maior idade e com a idade mais próximo da média.

20. Escreva um programa com uma função que recebe um ponteiro de inicio do vetor de pessoa com nome, peso e altura, e informe as pessoas com o IMC menores do que 18.5 e maiores do que 30.0. Lembrando a formula do IMC é `IMC = peso / (altura **2)`.

## Estruturas Autorreferencial

21. Escreva um programa com um função que recebe uma ilha, com nome da ilha e com outra ilha para entrada e com outra ilha para saída, e uma série de nomes de ilhas e verifique se é possivel fazer o trajeto de ilha até o final.

22. Escreva um programa com uma função que cria um número que informe quais seus 2 maiores divisores, caso o número seja 1: os dois maiores divisores são ele mesmo. Depois disso, calcule o segundo maior divisor do segundo maior divisor do segundo maior divisor de 120 e 625.

23. Escreva um programa com uma função que cria uma pessoa com uma idade e informe quem são seus irmãos, sendo os irmãos formado por um ponteiro de inicio de um vetor de pessoas. Após isso crie uma função que recebe um dos irmão que informe o irmão mais velho e o mais novo entre eles.

24. Escreva um programa com uma função que cria poligono formado por N retas, sendo as retas tendo conexão com 2 retas e com tamanho fixo, e calcule se é possivel formar esse poligono, e se é possivel formar calcule o perimetro desse poligono.

## Listas

Em breve...