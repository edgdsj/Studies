void initKeyboard(void);
void initLCD(void);
void readKeyBoard(void);
void updateDisplay(void);
void readSerial(void);
void calcValue(void);

void main(void){

    int state = 0;
    initKeyboard();
    initLCD();

    while(1){
        //Top Slot
        resetTimer(500);
        updateDisplay();
        switch (state)
        {
            case 0:
                readKeyBoard();
                state = 1;
                break;
            case 1:
                readSerial();
                state = 2;
                break;
            case 2:
                calcValue();
                state = 0;
                break;
        }
        waitTimer();
        //Top Slot
    }
}