void initKeyboard(void);
void initLCD(void);
void readKeyBoard(void);
void updateDisplay(void);
void readSerial(void);
void calcValue(void);

void ext10_irqHandler(void){
    readKeyBoard();
}

void timer0_irqHandler(void){
    updateDisplay();
}

void main(void){

    int A, B, C;

    initKeyboard();
    initLCD();

    while(1){
        sleep();
    }
}