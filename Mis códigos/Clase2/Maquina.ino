typedef enum{
    IDDLE,
    REMG,
    FilAmpEMG;
    ADC;
    Interpretacion;
    Servo;
}fsm;

fsm maquina=IDDLE;

int variable=valor;

void setup(){

}

void loop(){
    switch(maquina){
        case IDDLE:
            esperaboton();
            if(BOTON_PRESIONADO){
                maquina=REMG;
                break;
            }
        case REMG:
            maquina=FilAmpEMG;
            break;
        case FilAmpEMG:
            maquina=ADC;
            break;
        case ADC:
            maquina=Interpretacion;
            break;
        case Interpretacion:
            maquina=Servo;
            break;
        case Servo:
            maquina=IDDLE;
            break;
    }

}