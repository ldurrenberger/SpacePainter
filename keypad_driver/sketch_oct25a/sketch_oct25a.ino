#include <Keypad.h>

const byte ROWS = 4; 
const byte COLS = 3; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3}; 

int state;
char curr_key;
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  state = 0;
}
 
void loop(){
  
  if(state == 0){
    char customKey = customKeypad.getKey();
    if(customKey && customKey != '#'){
      curr_key = customKey;
      state = 1;
    }
  }
  else if(state == 1){
    char customKey = customKeypad.getKey();
    if(customKey){
      if(customKey == '#'){
        if(curr_key == '1'){
          
        }
        else if(curr_key == '2'){
          
        }
        else if(curr_key == '3'){
          
        }
      }
      else{
        curr_key == customKey;
      }
    }
  }
}
