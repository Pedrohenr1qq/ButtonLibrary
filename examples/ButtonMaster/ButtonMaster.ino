/*
   ButtonLibrary.ino
   Autor: Pedro Henrique Pereira da Silva
   Date: 11/09/2022

*/

//=============LIBRARIES====================
#include <ButtonLibrary.h>

//=============CLASSES======================

//=============CONSTANTS====================

//=============VARIABLES====================

//=============OBJECTS======================

Button button(49,INPUT_PULLUP);

//=============FUNCTIONS_DECLARATIONS=======

////////////////////////////////////////////
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  button.SetPressedTime(1000);
}

/////////////////////////////////////////////
void loop() {
  // put your main code here, to run repeatedly:
  button.WaitForResponse(showFirstMensage, showSecondMensage);
}

void showFirstMensage(){
  Serial.println("first mensage");
}

void showSecondMensage(){
  Serial.println("Second mensage");
}


/////////////////////////////////////////////
//============FUNCTIONS=====================

/////////////////////////////////////////////
