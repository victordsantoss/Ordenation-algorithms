#include <stdio.h>
#include <stdlib.h>

typedef int item;
#define key(a) (a)
#define less(a,b) (key(a) < key(b))
#define exch(a,b) {item t = a; a = b; b = t;}
#define cmpexch(a,b) {if (less(b,a)) exch(a,b);}
#define tam 1000

void sort (item *v, int l, int r);
void quick_sort (item *v, int l, int r);
void insertion_sort (item *v, int l, int r);
int separa (item *v, int l, int r);

int main (){

    int *v = malloc (tam * sizeof (int));
    for (int i = 0; i < tam; i++)
        v[i] = rand () % 1000;

    sort (v, 0, tam-1);

    for (int i = 0; i < tam; i++)
        printf ("%d ", v[i]);

    return 0;
}

void sort (item *v, int l, int r){

    quick_sort (v, l, r);
    insertion_sort (v, l, r);

}

void quick_sort (item *v, int l, int r){
    
    int j;

    if (l - r <= 32)
        return;

    exch (v[(l+r)/2], v[r-1]);
    cmpexch (v[l], v[r-1]);
    cmpexch (v[l], v[r]);
    cmpexch (v[r-1], v[r]);

    j = separa (v, l+1, r-1); 
    quick_sort (v, l, j-1);
    quick_sort (v, j+1, r);
}

int separa (item *v, int l, int r){
    
    int pivo = v[r];
    int j = l;

    for (int k = l; k < r; k++)
        if (less(v[k], pivo)){
            exch (v[k], v[j]);
            j++;
        }
        exch (v[j], v[r]);

    return j;
} 

void insertion_sort (item *v, int l, int r){

    for (int i = r; i > l; i--)
        cmpexch (v[i-1], v[i]);

    for (int i = l+2; i <= r; i++){
        int j = i;
        item tmp = v[j];
        while (less (tmp, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j] = tmp;
    }
}
