#include "push_swap.h"

int calculate_chunks(int num_elements)
 {
    int divisor;

    if (num_elements <= 20) {
        divisor = 5; // Menos chunks para listas pequenas
    } else if (num_elements <= 100) {
        divisor = 20;
    } else {
        divisor = 40; // Mais chunks para listas grandes
    }

    int chunks = num_elements / divisor;
    if (num_elements % divisor != 0) {
        chunks += 1; // Arredonda para cima se houver sobra na divisão
    }

    if (chunks == 0) {
        chunks = 1; // Garante ao menos 1 chunk
    }

    return chunks;
}

void assign_chunks(t_node *head)
 {
    int num_elements;
    int chunks;
    int chunk_size;
    int current_chunk = 0;
    int current_count = 0;

    num_elements = stacklen(head); // Função que calcula o número de elementos
    chunks = calculate_chunks(num_elements); // Função que calcula o número de chunks

    chunk_size = num_elements / chunks; // Tamanho de cada chunk

    // Percorre a lista e atribui chunks
    while (head != NULL) {
        if (current_count >= chunk_size) {
            current_chunk++; // Move para o próximo chunk
            current_count = 0; // Reinicia a contagem
        }

        head->chunk = current_chunk; // Atribui o chunk atual
        head = head->next; // Avança para o próximo nó
        current_count++;
    }
}
