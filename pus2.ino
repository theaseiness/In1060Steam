// Knapper
const int ROD_KNAPP = A1;
const int BLAA_KNAPP = 2; 
const int GRONN_KNAPP = 5;

const int MOTOR = 4;

// Belønning
const int SANG = 6;
const int BRA = 7; 
const int FLINK = 9; 

//Berøringspunkter
const int MAGE = 8;
const int BENA = 10;
const int NESEN = 11;
const int ARMENE = 12;

const int PRESENTER_NAVN = 13;

void setup() {
  Serial.begin(9600);
  const int lydfiler[] = {PRESENTER_NAVN, ARMENE, NESEN, BENA, FLINK, MAGE, BRA, SANG};

  for (int i = 0; i < 8; i++) {
    pinMode(lydfiler[i], OUTPUT);
    digitalWrite(lydfiler[i], HIGH);
  }

  pinMode(BLAA_KNAPP, INPUT_PULLUP);
  pinMode(GRONN_KNAPP, INPUT_PULLUP);
  pinMode(ROD_KNAPP, INPUT_PULLUP);

  pinMode(MOTOR, OUTPUT);
  digitalWrite(MOTOR, LOW);

  randomSeed(analogRead(ROD_KNAPP)); // Brukes for å velge lydfiler tilfeldig
}

// Egne funksjoner for de ulike lydfilene
void presenterNavn() {
  spillLyd(PRESENTER_NAVN, "Spiller lydfil: PRESENTER_NAVN");
}

void pekPaaArmene() {
  spillLyd(ARMENE, "Spiller lydfil: ARMENE");
}


void pekPaaNesen() {
  spillLyd(NESEN, "Spiller lydfil: NESEN");
}

void pekPaaBena() {
  spillLyd(BENA, "Spiller lydfil: BENA");
}

void skrytFlink() {
  spillLyd(FLINK, "Spiller lydfil: FLINK");
}

void skytBra() {
  spillLyd(BRA, "Spiller lydfil: BRA");
}

void sang() {
  spillLyd(SANG, "Spiller lydfil: SANG");
}

// Hjelpefunksjon
void spillLyd(int lydfil, String melding) {
  digitalWrite(lydfil, LOW);
  Serial.println(melding);

  delay(300);

  digitalWrite(lydfil, HIGH);
}

void loop() { 
  // Rød knapp trykkes 
  if (digitalRead(BLAA_KNAPP) == LOW) {
    int tilfeldig = random(1, 5);

    switch (tilfeldig) {
      case 1: presenterNavn(); break;
      case 2: pekPaaArmene(); break;
      case 3: pekPaaNesen(); break;
      case 4: pekPaaBena(); break;
  }
}

// Grønn knapp trykkes 
  if (digitalRead(GRONN_KNAPP) == LOW){
    delay(10); // Kort pause for å unngå feilregistreringer
    
    int tilfeldig = random(1, 3);

    switch (tilfeldig) {
      case 1: skrytFlink(); break;
      case 2: skytBra(); break;
    }

    digitalWrite(MOTOR, HIGH);
    Serial.println("Belønning er aktivert");

    delay(3000);
    digitalWrite (MOTOR, LOW);
  }

// Blås knapp trykkes 
  if (digitalRead(ROD_KNAPP) == LOW){
    delay(10); // Kort pause for å unngå feilregistreringer

    sang();
    digitalWrite(MOTOR, HIGH);
    Serial.println("Sang spilles av og propellen snurrer");

    delay(8000);
    digitalWrite (MOTOR, LOW);
  }
  delay(100);
}