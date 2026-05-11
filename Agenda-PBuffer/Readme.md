# Agenda pBuffer

**Nome:** Ian Xavier Freitas  
**Turma:** M2 AED  

# Descrição

Uma agenda de contatos feita SEM usar variáveis, só ponteiros. Tudo fica guardado em um buffer de memória (void *pBuffer), sem uso de structs. O buffer cresce e encolhe dinamicamente com realloc conforme pessoas são adicionadas e removidas.

# 3 Casos de Teste com Sucesso

1. **Adicionar e Listar:** Adicionei 3 pessoas com nomes e emails diferentes e listei todas 
2. **Buscar por Email:** Busquei um email existente e um que não existe — retornou corretamente em ambos os casos
3. **Remover Pessoa:** Removi uma pessoa pelo email, listei novamente e confirmei que saiu da lista — funcionou corretamente

# O que Funciona

- Adicionar pessoas com nome, email e idade
- Validação de email duplicado ao adicionar
- Validação de idade (rejeita texto no campo de idade)
- Remover pessoas por email
- Buscar pessoas por email
- Listar todas as pessoas
- Sem vazamento de memória (testado com Valgrind)

# O que Não Funciona

- Não salva os dados em arquivo (perde tudo ao fechar o programa)
- Não valida se o nome está vazio