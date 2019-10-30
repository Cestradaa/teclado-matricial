
#include <Keypad.h>

const byte rowsCount = 4;
const byte columsCount = 4;
String clave = "564";
char vector[3];
String clave2;


char keys[rowsCount][columsCount] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};

const byte rowPins[rowsCount] = { 11, 10, 9, 8 };
const byte columnPins[columsCount] = { 7, 6, 5, 4 };

Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);

void setup() {
  Serial.begin(9600);

}

void loop() {

  char key = keypad.getKey();
  if (key) {
    if (key != '*') {
      clave2 = String(clave2 + key);
    }
  }

  if (key == '*') {
    Serial.println(clave2);
    validar(clave2);
    clave2 = "";

  
  }

  if (key == '#') {
    clave2 = "";
  } 
}

void validar(String clave2){

if (clave2 == clave){
  Serial.println(1);  
} else {
  Serial.println(0);
}

}
