#define PIN_MOTOR_DERECHO_DIR 
#define PIN_MOTOR_IZQUIERDO_DIR 
#define PIN_MOTOR_DERECHO_PWM 
#define PIN_MOTOR_IZQUIERDO_PWM

class Motor{
  private:
    int velocidad = 100;
    int speed;
    int pin_dir;
    int pin_pwm;
    bool invertir;
  public:
    Motor(int pindir, int pinpwm) {
        this->pin_dir = pindir;
        this->pin_pwm = pinpwm;
        pinMode(pin_dir, OUTPUT);
        pinMode(pin_pwm, OUTPUT);
        speed = velocidad;
    }
  void setSpeed(int speeding){
        if (speeding >= 100){
            speeding = 100;
        }
        else if (speeding <= 0){
            speeding = 0;
        }
        int value = (int)speeding * 255 / 100;
        speed = value;
    }
    void invertirdireccion(){
      invertir = !invertir;
    }
    void avanzar(){
      digitalWrite(pin_dir, invertir);
      analogWrite(pin_pwm, speed);
    }
    void retroceder(){
      digitalWrite(pin_dir, !invertir);
      analogWrite(pin_pwm, speed);
    }
    void frenar(){
      digitalWrite(pin_dir, LOW);
      analogWrite(pin_pwm, 0);
    }
};

Motor m1 = Motor(PIN_MOTOR_DERECHO_DIR, PIN_MOTOR_DERECHO_PWM);
Motor m2 = Motor(PIN_MOTOR_IZQUIERDO_DIR, PIN_MOTOR_IZQUIERDO_PWM);

void avanza(){
  m1.avanzar();
  m2.avanzar();
}

void retrocede(){
  m1.retroceder();
  m2.retroceder();
}

void irizquierda(){
  m1.avanzar();
  m2.retroceder();
}


void irderecha(){
  m1.avanzar();
  m2.retroceder();
}

void frenar(){
  m1.stop();
  m2.stop();
}

void setup(){
  m1.invertirdireccion(); //dl void
}

void loop(){
  avanza();
  delay(1000);
  retrocede();
  delay(1000);
  irizquierda();
  delay(1000);
  irderecha();
  delay(1000);
  frenar();
  delay(1000);
}
