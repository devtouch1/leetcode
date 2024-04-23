inline int ehAnagrama(int* contagemCaracteres, int i, int j){
    int k;
    for(k = 0; k<26; k++){
        if(contagemCaracteres[i*26 + k] != contagemCaracteres[j*26 + k]) return 0;
        
    }
    return 1;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    int i,j;
    int tamanhoLista = 0; //tamanho da lista final (o returnSize)
    int tamanhoSubLista = 0; //variavel utilizada para armazenar temporariamente tamanho sublista
    char*** listaAnagramas = NULL; //retorno
    char** subLista = NULL; //vetor de sublistas
    int* tamanhoColunas = NULL; //vetor com tamanhos das colunas
    char* caracterAtual; //char temporario utilizado na logica

    int* contagemCaracteres = (int*)calloc(strsSize, sizeof(int)*26);//cada palavra na string, ele marca
    for(i=0; i<strsSize; i++){//nesse loop, para cada palavra, ele armazena os caracteres;
        caracterAtual = strs[i];
        while(*caracterAtual){
            contagemCaracteres[i*26 + (*caracterAtual) - 'a']++;
            caracterAtual++;
        }
    }
    //logica que percorre todas as palavras, verifica os anagramas, e adiciona ao vetor
    for(i=0; i<strsSize; i++){
        tamanhoSubLista = 0;
        subLista = NULL;
        if(strs[i]!=NULL){
            tamanhoSubLista+=1;
            subLista = (char**) realloc(subLista, sizeof(char*) * tamanhoSubLista);
            subLista[tamanhoSubLista-1] = strs[i];
            for(j=i+1;j<strsSize;j++){
                if(strs[j]!=NULL){
                    if(ehAnagrama(contagemCaracteres, j, i)){
                        tamanhoSubLista+=1;
                        subLista = (char**) realloc(subLista, sizeof(char*) * tamanhoSubLista);
                        subLista[tamanhoSubLista-1] = strs[j];
                        strs[j] = NULL;
                    }
                }
            }
            tamanhoLista++;
            listaAnagramas = (char***)realloc(listaAnagramas, sizeof(char**)*tamanhoLista);
            listaAnagramas[tamanhoLista-1] = subLista;
            tamanhoColunas = (int*)realloc(tamanhoColunas, sizeof(int)*tamanhoLista);
            tamanhoColunas[tamanhoLista-1] = tamanhoSubLista;
        }
    }
    *returnSize = tamanhoLista;
    *returnColumnSizes = tamanhoColunas;
    free(contagemCaracteres);
    return listaAnagramas;

}
