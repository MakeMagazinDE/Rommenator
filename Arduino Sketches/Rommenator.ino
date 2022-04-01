//********************************************//
//**************** Romménator ****************//
//********************************************//
//* Version : 1.0                            *//
//* Author  : Tobias Vogel                   *//
//* Für mehr als 4 Spieler können die        *//
//* ausgeklammerten Zeilen eingefügt werden. *//
//********************************************//

void setup() {
  //Eingänge vorbereiten

  pinMode(2, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  //pinMode(10, INPUT_PULLUP);
  //pinMode(12, INPUT_PULLUP);

  //Ausgänge vorbereiten
  
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(9, OUTPUT);
  //pinMode(11, OUTPUT);
  //pinMode(13, OUTPUT);
    
  digitalWrite(3, HIGH); //Alles wieder an
  digitalWrite(5, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(9, HIGH);
  //digitalWrite(11, HIGH);
  //digitalWrite(13, HIGH);
}

void klopfwin(int pin){

    digitalWrite(3, LOW); //Alles aus
    digitalWrite(5, LOW);
    digitalWrite(7, LOW);
    digitalWrite(9, LOW);
    //digitalWrite(11, LOW);
    //digitalWrite(13, LOW);
    
    for (int i = 0; i < 10; i++) 
    {
      digitalWrite(pin, HIGH);
      delay(85);
      digitalWrite(pin, LOW);
      delay(85);
    }
    
    digitalWrite(pin, HIGH);
    delay(3500); //Wartezeit bis neustart
    digitalWrite(pin, LOW);

    digitalWrite(3, HIGH); //Alles wieder an
    digitalWrite(5, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(9, HIGH);
    //digitalWrite(11, HIGH);
    //digitalWrite(13, HIGH);
}

void loop() {

  //Nacheinander werden die Eingangspins abgefragt, und wenn einer "LOW" ist, wird "klopfwin" gesprungen.
  //Hier wird der Gewinner angezeigt.
  
       if (digitalRead(2) == LOW) {klopfwin(3);} 
       if (digitalRead(4) == LOW) {klopfwin(5);} 
       if (digitalRead(6) == LOW) {klopfwin(7);} 
       if (digitalRead(8) == LOW) {klopfwin(9);} 
       //if (digitalRead(10) == LOW) {klopfwin(11);} 
       //if (digitalRead(12) == LOW){klopfwin(13);} 
}
