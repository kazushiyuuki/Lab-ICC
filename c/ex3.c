
//Calcula a soma da maior subsequência
int somaCruzada(int a[], int inicio, int final){
    int i, maior_esq, maior_dir, meio, soma;
    meio = (inicio+final)/2;
    for(i = meio; i <= inicio; i--){
        soma += a[i];
        if(soma >= maior_esq){
            maior_esq = soma;
        }
    }
    soma = 0;
    for(i = meio+1; i<=final; i++){
        soma += a[i];
        if(soma >= maior_dir){
            maior_dir = soma;
        }
    }
    return maior_dir+maior_esq;
}

int subseqMaior(int a[], int inicio, int final){
    if(inicio == final){
        return a[inicio];
    }
    int meio = (inicio+final)/2;
    int soma_esq = subseqMaior(a, inicio, meio);
    int soma_dir = subseqMaior(a, meio+1, final);
    int soma_cruzada = somaCruzada(a, inicio, final);
    if(soma_esq>=soma_dir){
        if(soma_esq>=soma_cruzada){
            return soma_esq;
        }
        else{
            return soma_cruzada;
        }
    }
    else{
        if(soma_dir>=somaCruzada){
            return soma_dir;
        }
        else{
            return soma_cruzada;
        }
    }
    return 1;
}