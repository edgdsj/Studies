void initKeyboard(void);
void initLCD(void);
void readKeyBoard(void);
void updateDisplay(void);
void readSerial(void);
void calcValue(void);

void main(void){

    int A, B, C;

    initKeyboard();
    initLCD();

    while(1){
        readKeyBoard();
        updateDisplay();
        readSerial();
        calcValue();
    }
}