/*
   ButtonLibrary.cpp
   Autor: Pedro Henrique Pereira da Silva
   Date: 11/09/2022

*/

#include "Arduino.h"
#include "ButtonLibrary.h"


Button::Button(uint8_t pin, uint8_t default_mod) {

  _pin = pin;
  if (default_mod == INPUT_PULLUP) _pressed_state = 0;
  else _pressed_state = 1;

  last_state_button = state_button;
  is_pressed = false;
  pinMode(pin, default_mod);

}

void Button::SetDebounceTime(unsigned long new_debounce_time){
  _debounce_time = new_debounce_time;
}

void Button::SetPressedTime(unsigned long new_pressed_time){
  _pressed_time = new_pressed_time;
}

bool Button::GetStateButton(){
  return state_button;
}

void Button::WaitForClicked(){
  while(true){
    state_button = digitalRead(_pin);
    if((state_button == _pressed_state) && (state_button != last_state_button)){
    	_now_time = millis();
    	is_pressed = true;
    }
    if(is_pressed){
    	while(millis() - _now_time < _debounce_time);
    	is_pressed = false;
    	break;
    }
    
    last_state_button = state_button; 
  }
}

void Button::WaitForReleased(){
  while(true){
    state_button = digitalRead(_pin);
    if((state_button == _pressed_state) && (state_button != last_state_button)){
    	_now_time = millis();
    	is_pressed = true;
    }
    if( (is_pressed) && (millis() - _now_time > _debounce_time) ){
    	if( (state_button != _pressed_state) && (state_button != last_state_button) ){
    	  is_pressed = false;
    	  break;
    	}
    }
    last_state_button = state_button; 
  }
}

void Button::WaitForResponse(void function1(), void function2()) {
  while (true) {
    state_button = digitalRead(_pin);
    if ((state_button == _pressed_state) && (state_button != last_state_button) ) {
      _now_time = millis();
      is_pressed = true;
    }

    if ((is_pressed)) {
      if ((state_button != _pressed_state) && (state_button != last_state_button) ) is_released = true;
      if ((is_released) && (millis() - _now_time > _pressed_time)) {
        is_pressed = false;
        is_released = false;
        function2();
        break;
      }
      else if ((is_released) && (millis() - _now_time < _pressed_time)) {
        if(millis() - _now_time > _debounce_time){
          is_pressed = false;
          is_released = false;
          function1();
          break;
        }
      }
    }
    last_state_button = state_button;
  }
}
