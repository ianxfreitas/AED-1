# Ian Xavier Freitas

# 775. Global And Local Inversions

# Descrição

Dado um array de inteiros nums de tamanho n que representa uma permutação de todos os inteiros no intervalo [0, n - 1], determinar se o número de inversões globais é igual ao número de inversões locais.

Uma inversão global é qualquer par (i, j) com i < j onde nums[i] > nums[j]. Uma inversão local é um par de elementos adjacentes (i, i+1) onde nums[i] > nums[i+1] (toda inversão local também é uma inversão global, então basta comparar as contagens).

A resolução usa uma árvore AVL para contar as inversões globais: cada valor é inserido na árvore na ordem em que aparece no array, e antes de cada inserção conta-se quantos valores já inseridos são maiores que o valor atual — usando o tamanho da subárvore de cada nó, sem precisar percorrer nó a nó. Essa contagem, somada a cada passo, dá o total de inversões globais em O(n log n).

# 3 Casos de Teste com Sucesso

[1,0,2]: Resultado esperado true (1 inversão global, 1 inversão local) — funcionou corretamente
[1,2,0]: Resultado esperado false (2 inversões globais, 1 inversão local) — funcionou corretamente
[4,3,2,1,0]: Resultado esperado false (10 inversões globais, 4 inversões locais) — funcionou corretamente

# O que Funciona

Conta corretamente as inversões globais usando a AVL (validado contra uma solução de força bruta O(n²) em 2000 testes aleatórios)
Conta corretamente as inversões locais em paralelo, em O(1) por passo
Funciona para arrays de tamanho 1 até o limite da restrição (testado com n = 100.000)
Sem vazamento de memória nem uso indevido de ponteiro (verificado com AddressSanitizer/UndefinedBehaviorSanitizer)
Poda: se as inversões globais já ultrapassaram as locais, o algoritmo retorna false sem terminar de inserir todos os elementos na árvore

# O que Não Funciona

Não é a solução mais eficiente para esse problema: existe uma solução O(n) baseada na observação de que o array só pode ser "ideal" se cada elemento estiver no máximo 1 posição fora do lugar (|nums[i] - i| <= 1 para todo i), o que dispensa qualquer estrutura de dados
Não há checagem do retorno de malloc (se a alocação falhar, o código não trata o caso)