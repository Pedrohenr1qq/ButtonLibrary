/*
   ButtonLibrary.h
   Autor: Pedro Henrique Pereira da Silva
   Date: 11/09/2022

*/
#ifndef ButtonLibrary
#define ButtonLibrary




class Button {

  public:
    Button(uint8_t pin, uint8_t default_mod);
    void SetPressedTime(unsigned long new_pressed_time);
    void SetDebounceTime(unsigned long new_debounce_time);
    bool GetStateButton();
    void WaitForClicked();
    void WaitForReleased();
    void WaitForResponse(void function1(), void function2());

  private:
    bool state_button, last_state_button,_pressed_state, is_pressed, is_released = false;
    uint8_t _pin;
    unsigned long _pressed_time = 1000;
    unsigned long _debounce_time = 100;
    unsigned long _now_time = 0;
};

#endif
