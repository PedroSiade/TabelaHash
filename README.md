# tabelaHash-ed2-pedro

Programa realizado em c++

Explicação sobre o algoritmo:

Uma tabela hash, também conhecida como hash table, é uma estrutura de dados utilizada para armazenar e recuperar informações de forma eficiente. Ela é amplamente utilizada em ciência da computação e programação devido à sua capacidade de proporcionar acesso rápido a dados, em média, em tempo constante (O(1)), quando implementada corretamente.

A ideia fundamental por trás de uma tabela hash é usar uma função de hash para mapear chaves (ou chaves de pesquisa) para índices em uma estrutura de armazenamento, geralmente um array. Essa função de hash calcula um valor hash único para cada chave, que serve como um índice para acessar os dados associados àquela chave. Quando você deseja inserir, recuperar ou excluir um elemento da tabela hash, a função de hash é usada para calcular a posição do elemento no array subjacente, permitindo acesso rápido.

Aqui estão os principais conceitos relacionados a tabelas hash:

Função de Hash: É uma função que recebe uma chave como entrada e produz um valor hash, que é geralmente um número inteiro. A função de hash deve ser determinística, ou seja, para a mesma chave, ela sempre deve produzir o mesmo valor hash. O objetivo é espalhar as chaves uniformemente pelo array subjacente para minimizar colisões.

Array ou Vetor de Armazenamento: A tabela hash utiliza um array (ou vetor) para armazenar os dados. Cada elemento do array é chamado de "slot" e é acessado pelo valor hash da chave correspondente.

Colisões: Uma colisão ocorre quando duas chaves diferentes têm o mesmo valor hash. Isso pode acontecer devido à natureza finita do espaço de valores hash. Existem várias técnicas para lidar com colisões, como encadeamento separado (cada slot contém uma lista ligada de elementos com o mesmo valor hash) e endereçamento aberto (procurar o próximo slot disponível).

Inserção, Recuperação e Exclusão: Para inserir um elemento, a chave é primeiro passada pela função de hash para encontrar o slot apropriado no array, e o elemento é armazenado lá. Para recuperar um elemento, a chave é novamente passada pela função de hash para encontrar o slot e, em seguida, o elemento é retornado. Para excluir um elemento, o processo é semelhante à recuperação, mas o slot é marcado como vazio ou removido.

Fator de Carga: É a relação entre o número de elementos armazenados na tabela hash e o número de slots disponíveis. Manter um fator de carga baixo (geralmente < 0,7) ajuda a manter o desempenho da tabela hash, reduzindo o risco de colisões.

Redimensionamento: Quando o fator de carga se torna muito alto, a tabela hash é redimensionada (geralmente duplicando o tamanho do array) para acomodar mais elementos e manter um fator de carga baixo.
