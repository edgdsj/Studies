int tick = 0;
int task = 0;

void printA(void){
    printf("Função A");
}

void printB(void){
    printf("Função B");
}

typedef void (*fpointer)(void);
fpointer funcs[2];

int main(void){
    funcs[0] = printA;
    funcs[1] = printB;
    startScheduler();
}

int startScheduler(void){
    while (1)
    {   
        if(tick <= 5)       task++;             //Executa proxima
        else if( tick <= 5) task = (task+1)%3;  //Executa só de 0-2
        else                task =0;            //Executa somente a função 0;

        funcs[task]();
        return 0;
    }
}