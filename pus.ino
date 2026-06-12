

const int hilsen = 13;
const int arm = 12;
const int nese = 11;
const int ben = 10;
const int flink = 9;
const int magen = 8;
const int brajobba = 7;
const int sang = 6;
const int blaknapp = 2; 
const int gronnknapp = 5;
const int rodknapp = A1;
const int motor= 4;


void setup() {
  Serial.begin(9600);

  pinMode(hilsen, OUTPUT);
  pinMode(arm, OUTPUT);
  pinMode(nese, OUTPUT);
  pinMode(ben, OUTPUT);
  pinMode(flink, OUTPUT);
  pinMode(magen, OUTPUT);
  pinMode(brajobba, OUTPUT);
  pinMode (sang, OUTPUT);

  pinMode(2, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(A1, INPUT_PULLUP);
  pinMode(motor, OUTPUT);

  digitalWrite(hilsen, HIGH);
  digitalWrite(arm, HIGH);
  digitalWrite(nese, HIGH);
  digitalWrite(ben, HIGH);
  digitalWrite(flink, HIGH);
  digitalWrite(magen, HIGH);
  digitalWrite(brajobba, HIGH);
  digitalWrite(sang, HIGH);

  randomSeed(analogRead(A0));
}

void spillLyd1() {
  Serial.println("Spiller lyd 1");
  digitalWrite(hilsen, LOW);
  delay(300);
  digitalWrite(hilsen, HIGH);
}

void spillLyd2() {
  Serial.println("Spiller lyd 2");
  digitalWrite(arm, LOW);
  delay(300);
  digitalWrite(arm, HIGH);
}

void spillLyd3() {
  Serial.println("Spiller lyd 3");
  digitalWrite(nese, LOW);
  delay(300);
  digitalWrite(nese, HIGH);
}

void spillLyd4() {
  Serial.println("Spiller lyd 4");
  digitalWrite(ben, LOW);
  delay(300);
  digitalWrite(ben, HIGH);
}
void spillLyd5() {
  Serial.println("Spiller lyd 5");
  digitalWrite(flink, LOW);
  delay(300);
  digitalWrite(flink, HIGH);
}

void spillLyd6() {
  Serial.println("Spiller lyd 6");
  digitalWrite(brajobba, LOW);
  delay(300);
  digitalWrite(brajobba, HIGH);
}
void spillLyd7() {
  Serial.println("Spiller av sang");
  digitalWrite(sang, LOW);
  delay(300);
  digitalWrite(sang, HIGH);
}

void loop() { 

  if (digitalRead(blaknapp)==LOW){
    
    int tilfeldig = random(1, 5);
    switch (tilfeldig) {
      case 1:
      spillLyd1();
      break;
      
      case 2:
      spillLyd2();
      break;
      
      case 3:
      spillLyd3();
      break;

      case 4:
      spillLyd4();
      break;
  }
  }

  if (digitalRead(gronnknapp)== LOW){
    delay(10);
    Serial.println("Spinn hjulet");
    
    int tilfeldig = random(1, 3);
    switch (tilfeldig) {
      case 1:
      spillLyd5();
      break;
      
      case 2:
      spillLyd6();
      break;
    }
    digitalWrite(motor, HIGH);
    delay(3000);
    digitalWrite (motor, LOW);

  }
  if (digitalRead(rodknapp)== LOW){
    delay(10);
    Serial.println("Spill av Sang og hjulet");

    spillLyd7();

    digitalWrite(motor, HIGH);
    delay(8000);
    digitalWrite (motor, LOW);

  }
  delay(100);

  }
