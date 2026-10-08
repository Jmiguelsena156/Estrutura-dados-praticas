# Questões para estudar estrutura de dados

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

20. Escreva um programa com uma função que recebe um ponteiro de inicio do vetor de pessoa com nome, peso e altura, e informe as pessoas com o IMC menores do que 18.5 e maiores do que 24.9. Lembrando a formula do IMC é `IMC = peso / (altura **2)`.

## Estruturas Autorreferencial

21. Escreva um programa com um função que recebe uma ilha, com nome da ilha e com outra ilha para entrada e com outra ilha para saída, e uma série de nomes de ilhas e verifique se é possivel fazer o trajeto de ilha até o final.

22. Escreva um programa com uma função que cria um número que informe quais seus 2 maiores divisores, caso o número seja 1: os dois maiores divisores são ele mesmo. Depois disso, calcule o segundo maior divisor do segundo maior divisor do segundo maior divisor de 120 e 625.

23. Escreva um programa com uma função que cria uma pessoa com uma idade e informe quem são seus irmãos, sendo os irmãos formado por um ponteiro de inicio de um vetor de pessoas. Após isso crie uma função que recebe um dos irmão que informe o irmão mais velho e o mais novo entre eles.

24. Escreva um programa com uma função que cria poligono formado por N retas, sendo as retas tendo conexão com 2 retas e com tamanho fixo, e calcule se é possivel formar esse poligono, e se é possivel formar calcule o perimetro desse poligono.

## Listas Estaticas

### Busca

25. Escreva um programa com uma função, que recebe uma lista de 50 números inteiros ordenados e um numero inteiro N, que retorne o N-ésimo maior número da lista.

26. Escreva um programa com uma função, que recebe uma lista de 50 números inteiros ordenados e um numero inteiro N, que retorne o N-ésimo menor número da lista.

27. Escreva um programa com uma função, que recebe uma lista de 50 números inteiros ordenados, que retorne a mediana da lista.

28. Escreva um programa com uma função, que recebe uma lista de 50 números inteiros ordenados e um numero inteiro N, que retorne o endereço do N presente no vetor.

29. Escreva um programa com uma função, que recebe uma lista de 50 números inteiros ordenados e dois números inteiros M e N, que troca o valor do index M pelo index N.

30. Um mágico tem 52 cartas de baralho ordenados de Naipes (Espadas, Copas, Ouros e Paus) e de cartas por naípes (Ás, 2, 3, 4, 5, 6, 7, 8, 9, 10, Valete, Dama e Rei). No entanto o mágico precisa do Ás de Ouros, 8 de Espadas e Rei de Copas, que não sabe onde está localizado. Sabendo disso, escreva um programa com uma registro Carta, onde está informa os naípes e a carta, e com as funções que crie as cartas ordenadas e que informe o endereço da lista que está as cartas que o mágico precisa.

### Movimentação

31. Escreva um programa com uma função, que recebe uma lista de 5 números inteiros, que mova todos os elementos uma casa para frente e o último número coloca na primeira posição.

32. Escreva um programa com uma função, que recebe uma lista de 5 números inteiros, que mova todos os elementos uma casa para trás e o primeiro número coloca na ultima posição.

33. Escreva um programa com uma função, que recebe uma lista de 10 números inteiros, e desloque o maior número para a primeira posição com o resto permanendo na mesma ordem. Exemplo:
  ```
  mover_maior([3, 7, 9, 4, 10, 2, 3, 1, 8, 2]) = [10, 3, 7, 9, 4, 2, 3, 1, 8, 2]
  ```

34. Escreva um programa com uma função, que recebe uma lista de 10 números inteiros, e desloque os números primos para as primeiras posições com o resto permanendo na mesma ordem. Exemplo:
  ```
  mover_maior([3, 7, 9, 4, 10, 2, 3, 1, 8, 2]) = [2, 2, 3, 3, 7, 9, 4, 10, 1, 8]
  ```

### Ordenação

35. Escreva um programa com uma função, que recebe uma lista de 10 números inteiros, que informe em ordem crescente, depois informe a lista original.

36. Escreva um programa com uma função, que recebe uma lista de 10 números inteiros, que ordene em ordem crescente.

37. Escreva um programa com uma função, que recebe uma lista de 10 números inteiros positivos, que ordene em ordem do número de divisores crescente.

38. Escreva um programa com uma função, que recebe uma lista de 10 números inteiros positivos, que ordene em ordem lexicográfica.

39. Escreva um programa com um função que ordena as cartas como da questão 30 .

## Listas Encadeadas

40. Escreva um programa com estrutura de Lista de números inteiros e com as funções de criar Lista, inserir no inicio da Lista, inserir no endereço N da Lista, remover valor do endereço N, verificar se a lista é vazia e remover Lista da memoria.

41. Usando o programa da questão 40, Escreva um programa que leia varios números inteiros do usuário até informar o 0, após isso informe em ordem inversa.

42. Usando o programa da questão 40, Escreva um programa que leia varios números inteiros do usuário até informar o 0, após isso informe os valores menores que a média.

43. Usando o programa da questão 40, Escreva as seguintes funções:
* Função Somar: soma os valores dos endereços correspondentes de 2 listas
* Função Subtrair: Subtrae os valores dos endereços correspondentes de uma lista pela outra.
* Função Produto escalar: a soma de todos os produtos dos itens de mesmo endereço da lista A e B.
* Função Concatenar na frente: retorna lista com a concatenação da lista A apos a lista B.
* Função Concatenar intercalados: retorna lista com a concatenação da lista A e B com os dados alternando os seus elementos de A e B e B e A.
* Função União: retorna uma Lista com a união das 2 Listas.
* Função Intersecção: retorne uma Lista com a intersecção das 2 Listas.
* Função Diferença: retorne uma Lista com Diferença de uma Lista pela outra.

44. Escreva um programa com estrutura de Lista de pessoas (Nome, idade e sexo Biológico) com quartos reservados e simula que no dia 1 adiciona 3 pessoas, no dia 2 remove 1 homem, no dia 3 adiciona 2 mulheres e no dia 4 remove a primeira pessoa que reservou um quarto.

45. Escreva um programa com estrutura de lista de turmas numa escolas e em cada turma tem uma lista de alunos (Matricula aleatória) e simula que no mês 1 foi adicionado 2 turmas, uma com 30 alunos e outro com 25 alunos, no mês 2 a metade da turma com 25 alunos foram substituido e adicionaram mais 3 alunos e no mês 3 foram adicionado uma nova turma com 40 alunos.