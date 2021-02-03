#include <Keyboard.h>
#include "GyverButton.h"
#include "GyverEncoder.h"
#include "Periphery.h"
#include "Modes.h"
#include "Objects.h"

void setup() {
  ledPinSetup();
  ledSelectMode(wheel_selected_mod);
  Keyboard.begin();
}

void loop() {
  //Обработчики всей переферии
  allTick();

  if (_resize_in_.isPress()) { //Изменять начало клипа
    Keyboard.write(KEY_UPPERCASE_B);
    nudgeSubMode(NUDGE_ON);
  }
  else if (_resize_in_.isRelease()) {
    nudgeSubMode(NUDGE_OFF);
  }

  
  if (_resize_out_.isPress()) {  //Изменять конец клипа
    Keyboard.write(KEY_UPPERCASE_N);
    nudgeSubMode(NUDGE_ON);
  }
  else if (_resize_out_.isRelease()) {
    nudgeSubMode(NUDGE_OFF);
  }

  
  if (_roll_.isPress()) {  //Двигать склейку
    Keyboard.write(KEY_UPPERCASE_G);
    nudgeSubMode(NUDGE_ON);
  }
  else if (_roll_.isRelease()) {
    nudgeSubMode(NUDGE_OFF);
  }


  if (_previous_clip_edit_.isClick()) {  //Переход к предыдущей склейке 
    Keyboard.write(KEY_UP_ARROW);
  }

  
  if (_pause_start_playback_.isClick()) {  //Пауза\Воспроизведение
    Keyboard.write(KEY_SPACE);
    playback_speed = PLAYBACK_SPEED_DEFAULT; //Для алгоритмов колеса
  }

  
  if (_next_clip_edit_.isClick()) {  //Переход к следующей склейке
    Keyboard.write(KEY_DOWN_ARROW);
  }


  if (_shuttle_.isClick()) { //
    Keyboard.write(KEY_LOWERCASE_K); //Остановить воспроизведение
    playback_speed = PLAYBACK_SPEED_DEFAULT; //Сброс счетчика скорости
    wheel_selected_mod = SELECTED_MODE_SHUTTLE;
    ledSelectMode(wheel_selected_mod);
  }

  
  if (_jog_.isClick()) { //
    Keyboard.write(KEY_LOWERCASE_K); //Остановить воспроизведение
    wheel_selected_mod = SELECTED_MODE_JOG;
    ledSelectMode(wheel_selected_mod);
  }

  
  if (_scroll_.isClick()) {  //
    Keyboard.write(KEY_LOWERCASE_K); //Остановить воспроизведение
    wheel_selected_mod = SELECTED_MODE_SCROLL;
    ledSelectMode(wheel_selected_mod);
  }
  
  
  if (_source_timeline_viewer_.isClick()) {  //Источник\Таймлайн
    Keyboard.write(KEY_LOWERCASE_Q);
  }

  
  if (_source_clip_tape_.isClick()) {  //Источник клип\Источник лента
    Keyboard.write(KEY_UPPERCASE_Q);
  }

  
  if (_mark_in_.isClick()) { //Точка входа
    Keyboard.write(KEY_LOWERCASE_I);
  }

  
  if (_mark_out_.isClick()) {  //Точка выхода
    Keyboard.write(KEY_LOWERCASE_O);
  }
  
  
  if (_insert_.isClick()) {  //Вставить встык сдвинув вправо
    Keyboard.write(KEY_F9);
  }

  
  if (_overwrite_.isClick()) { //Вставить с заменой
    Keyboard.write(KEY_F10);
  }


  if (_replace_.isClick()) { //Вставить с заменой фрагмента
    Keyboard.write(KEY_F11);
  }

  
  if (_place_on_top_.isClick()) {  //Вставить на дорожку выше
    Keyboard.write(KEY_F12);
  }

  
  if (_fit_to_fill_.isClick()) { //Вставить вместо клипа
    Keyboard.write(KEY_F7);
  }

  
  if (_append_to_end_of_timeline_.isClick()) { //Добавить в конец таймлайна 
    Keyboard.write(KEY_F8);
  }

  
  if (_undo_.isClick()) {  //Отмена действия
    Keyboard.write(KEY_GRAVE_ACCENT);
  }

  
  if (_rotary_encoder_.isLeft()) {  //Поворот энкодера влево
    wheelTurn(TURN_LEFT);
  }
  
  if (_rotary_encoder_.isRight()) { //Поворот энкодера вправо
    wheelTurn(TURN_RIGHT);
  }
}
