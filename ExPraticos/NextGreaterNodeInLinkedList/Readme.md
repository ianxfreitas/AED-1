# Ian Xavier Freitas

# 1019. Next Greater Node In Linked List

# Descrição

Dado o head de uma lista ligada com n nós, para cada nó encontrar o valor do próximo nó maior. Ou seja, o primeiro nó à frente que tem valor estritamente maior. Se não existir, retorna 0.

# 3 Casos de Teste com Sucesso

1. **[2,1,5]:** Resultado esperado [5,5,0] — funcionou corretamente
2. **[2,7,4,3,5]:** Resultado esperado [7,0,5,5,0] — funcionou corretamente
3. **[1,7,5,1,9,2,5,1]:** Resultado esperado [7,9,9,9,0,5,0,0] — funcionou corretamente

# O que Funciona

- Encontra o próximo nó maior para cada nó da lista
- Retorna 0 quando não existe nó maior à frente
- Funciona para listas de qualquer tamanho

# O que Não Funciona

- Complexidade O(n²) — para listas muito grandes pode ser lento