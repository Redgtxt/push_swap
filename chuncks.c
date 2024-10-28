#include "push_swap.h"

// Calcula o número de chunks com base na quantidade de elementos
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
        chunks = 1; 
    }

    return chunks;
}

// Função para atribuir chunks com base nos ranks
void assign_chunks(t_node *head) 
{
    int num_elements = stacklen(head); 
    int chunks = calculate_chunks(num_elements); 
    int chunk_size = num_elements / chunks; 

    // Atribuir chunks baseados nos ranks
    t_node *temp = head;
    while (temp != NULL) {
        temp->chunk = temp->rank / chunk_size;
        if (temp->chunk >= chunks) 
        {
            temp->chunk = chunks - 1; //Pode ter um a mais
        }
        temp = temp->next;
    }
}

// Função para mover o chunk atual de StackA para StackB baseado em ranks
void move_current_chunk_to_stackB(t_node **stackA, t_node **stackB, int current_chunk) 
{
    int moved_count = 0;
    t_node *temp = *stackA;

    // Contar quantos elementos pertencem ao chunk atual
    while (temp)
     {
        if (temp->chunk == current_chunk) {
            moved_count++;
        }
        temp = temp->next;
    }

    // Mover os elementos do chunk atual de StackA para StackB
    while (moved_count > 0) {
        if ((*stackA)->chunk == current_chunk) {
            pb(stackA, stackB);  // Move o elemento para StackB
            moved_count--;
        } else {
            ra(stackA);  // Roda StackA se o elemento não pertence ao chunk atual
        }
    }
}

// Função auxiliar para encontrar o índice do maior elemento em StackB
int find_max_position(t_node *stackB)
 {
    int max_rank = stackB->rank;
    int max_position = 0;
    int position = 0;
    t_node *temp = stackB;

    // Percorre StackB para encontrar o maior rank e sua posição
    while (temp) {
        if (temp->rank > max_rank) {
            max_rank = temp->rank;
            max_position = position;
        }
        temp = temp->next;
        position++;
    }
    return max_position;
}

// Função para transferir um chunk ordenado de StackB para StackA
void transfer_chunk_to_stackA(t_node **stackA, t_node **stackB) 
{
    while (*stackB) {
        int max_position = find_max_position(*stackB);
        int stackB_len = stacklen(*stackB);

        // Ajusta o maior elemento para o topo de StackB
        if (max_position <= stackB_len / 2) {
            // Se o maior elemento está na primeira metade, usa 'rb' para rotacionar para o topo
            while (max_position-- > 0)
                rb(stackB);
        } else {
            // Se o maior elemento está na segunda metade, usa 'rrb' para rotacionar reverso para o topo
            while (max_position++ < stackB_len)
                rrb(stackB);
        }

        // Move o maior elemento do topo de StackB para StackA
        pa(stackA, stackB);
    }
}
