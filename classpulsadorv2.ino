#define PIN_PULSADOR_1
#define PIN_PULSADOR_2
#define PIN_LED

class Led{
  private:
    int pin;
  public:
    Led(int p){
      pin = p;
      pinMode(pin, OUTPUT);
    }
    void prenderled(){
      digitalWrite(pin, HIGH);
    }
    void apagarled(){
      digitalWrite(pin, LOW);
    }
};

class Pulsador{
  private:
    int pin;
    bool flanco = HIGH;
    bool estado_anterior = !flanco;
  public:
    Pulsador(int p){
      pin = p;
      pinMode(pin, INPUT);
    }
    void flanco(bool f){
      flanco = f;
      estado_anterior = !flanco;
    }
    bool pulsadorispress(){
      bool estado_actual = digitalRead(pin);
      bool estado = (estado_anterior != estado_actual) && estado_actual == flanco;
      estado_anterior = estado_actual;
      return estado;
    }
    String estadopulsadorispress(){
      if (pulsadorispress()) return "PRESSED";
      else return "NOT PRESSED";
    }
};

Pulsador *p1 = new Pulsador(PIN_PULSADOR_1);
Pulsador *p2 = new Pulsador(PIN_PULSADOR_2);
Led *l1 = new Led(PIN_LED);

int contador = 0;
void setup() {
  Serial.begin(9600);
  p1->flanco(LOW);
  p2->flanco(HIGH);
}

void loop(){
  if (p1->pulsadorispress()){
    Serial.println("p1 pressed");
    l1->prenderled();
  }
  if (p2->pulsadorispress()){
    Serial.println("p2 pressed");
    l1->apagarled();
  }
};
