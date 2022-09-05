typedef void (*fpointer)(void);

void printA(void){
    printf("Função A");
}

void printb(void){
    printf("Função B");
}

int main(void){
    fpointer teste;

    teste = printA;
    teste();
    
    teste = printb;
    teste();

    return 0;
}