# ian xavier freitas

# LeetCode 454. 4Sum II

# Descrição
O problema pede para descobrir quantas combinações de quatro números (pegando um de cada array) somam zero. Para não fazer um loop de O(n^4) que demoraria uma 
eternidade, dividi o problema no meio.
Primeiro, criei um array juntando todas as somas possíveis de nums1 e nums2, e fiz o mesmo para nums3 e nums4. Depois de ordenar esses dois arrays gigantes, usei a 
técnica de "dois ponteiros": um começando do início do primeiro array (valores menores) e outro do final do segundo (valores maiores). Quando a soma deles dá zero, o 
código conta quantas vezes esses números se repetem em bloco e multiplica as ocorrências, resolvendo o problema no tempo exigido de O(n^2 \log n).

# 3 Casos de Teste com Sucesso
Exemplo padrão: [1,2], [-2,-1], [-1,2], [0,2] -> Retornou 2 corretamente.
Arrays unitários: [0], [0], [0], [0] -> Retornou 1 corretamente.
Repetições assimétricas: [1,-1], [1,-1], [1,-1], [1,-1] -> Retornou 6 (validou muito bem a lógica de contar em bloco).

# O que Funciona 
- A técnica de dois ponteiros acha as somas que dão zero certinho, dentro do tempo limite.
- A contagem em bloco acelera muito o processo quando existem vários números iguais (ele multiplica as ocorrências em vez de andar casa por casa).
- A função que compara os valores no qsort está blindada contra overflow de inteiros.
- Os arrays dinâmicos são liberados com free() no final, sem deixar vazamento de memória.

# O que Não Funciona 
- Dá para ser mais rápido: usar uma Hash Table baixaria o tempo para O(n^2), mas implementar isso do zero em C seria bem mais complexo e trabalhoso do que o qsort.
- O código gasta bastante memória, já que aloca dois arrays de tamanho n x n ao mesmo tempo.
- Não coloquei checagem no retorno do malloc. Se o sistema ficar sem memória RAM para rodar um teste gigantesco, o código vai dar Segmentation Fault.