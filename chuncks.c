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

void move_current_chunk_to_stackB(t_node **stackA, t_node **stackB, int current_chunk) {
    t_node *temp = *stackA;
    int moved_count = 0;

    // Conte quantos elementos no chunk atual existem em StackA
    while (temp) {
        if (temp->chunk == current_chunk) {
            moved_count++;
        }
        temp = temp->next;
    }

    // Mova elementos do chunk atual de StackA para StackB
    while (moved_count > 0) {
        if ((*stackA)->chunk == current_chunk) {
            pb(stackA, stackB);  // move o elemento do chunk atual para StackB
            moved_count--;
        } else {
            ra(stackA);  // Move para o fim de StackA caso não pertença ao chunk atual
        }
    }
}



