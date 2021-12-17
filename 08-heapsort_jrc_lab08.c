#include <stdio.h>
#include <stdlib.h>

void troca(long int *x, long int *y){
    long int t = *x;
    *x = *y;
    *y = t; 
}

long int filho_esquerdo(int position){
    long int son = (2*position) + 1;
    return son;
}

long int filho_direito(int position){
    long int son = (2*position) + 2;
    return son;
}

//realiza troca de elementos caso o maior filho de um nó for maior que seu pai(o proprio nó), dessa forma, trocamos a posicao do pai com seu maior filho
void organiza_heap(long int *v_heap, int n, int posit){
    int big_son;
    if (filho_esquerdo(posit) < n){
        big_son = filho_esquerdo(posit);
    if (filho_direito(posit) < n && v_heap[filho_esquerdo(posit)] < v_heap[filho_direito(posit)])
        big_son = filho_direito(posit);
    else{
        if(filho_esquerdo(posit) < n && filho_direito(posit) < n && v_heap[filho_esquerdo(posit)] > v_heap[filho_direito(posit)])
            big_son = filho_esquerdo(posit);
    }
    if (v_heap[posit] < v_heap[big_son]){
        troca(&v_heap[posit], &v_heap[big_son]);
        organiza_heap(v_heap, n, big_son);
        }
    }
}

void heapsort(long int *arr, int n){
    int posicao;
    for(posicao = n/2; posicao >= 0; posicao--)
        organiza_heap(arr, n, posicao);
    while(n > 1){
        troca(&arr[0], &arr[n-1]);
        n--;
        organiza_heap(arr, n, 0);
    }
}

int main (void){

    int tamanho;
    scanf("%d", &tamanho);
    long int *vetor = malloc(tamanho * sizeof(long int));

    int i = 0;
    while(i < tamanho){
        scanf("%ld", &vetor[i]);
        i++;
    }

    heapsort(vetor, tamanho);

    for(int i = 0; i < tamanho; i++)
        printf("%ld ", vetor[i]);
    printf("\n");
}