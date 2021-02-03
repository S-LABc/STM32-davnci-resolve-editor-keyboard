//Группа обработчиков действий периферией
void allTick() {
  //Обработчики кнопок
  _resize_in_.tick();
  _resize_out_.tick();
  _roll_.tick();
  _previous_clip_edit_.tick();
  _pause_start_playback_.tick();
  _next_clip_edit_.tick();
  _shuttle_.tick();
  _jog_.tick();
  _scroll_.tick();
  _source_timeline_viewer_.tick();
  _source_clip_tape_.tick();
  _mark_in_.tick();
  _mark_out_.tick();
  _insert_.tick();
  _overwrite_.tick();
  _replace_.tick();
  _place_on_top_.tick();
  _fit_to_fill_.tick();
  _append_to_end_of_timeline_.tick();
  _undo_.tick();
  //Обработчик энкодера
  _rotary_encoder_.tick();
}
void ledPinSetup() {
  pinMode(LED_SHUTTLE, OUTPUT);
  pinMode(LED_JOG, OUTPUT);
  pinMode(LED_SCROLL, OUTPUT);
}
//Управление светодиодами режимов
void ledSelectMode(uint8_t selected_mode) {
  switch (selected_mode) {
    case SELECTED_SUBMODE_NUDGE: //Nudge SubMode
      digitalWrite(LED_SHUTTLE, HIGH);
      digitalWrite(LED_JOG, HIGH);
      digitalWrite(LED_SCROLL, HIGH);
    break;
    case SELECTED_MODE_SHUTTLE: //Shuttle
      digitalWrite(LED_SHUTTLE, HIGH);
      digitalWrite(LED_JOG, LOW);
      digitalWrite(LED_SCROLL, LOW);
    break;
    case SELECTED_MODE_JOG: //Jog
      digitalWrite(LED_SHUTTLE, LOW);
      digitalWrite(LED_JOG, HIGH);
      digitalWrite(LED_SCROLL, LOW);
    break;
    case SELECTED_MODE_SCROLL: //Scroll
      digitalWrite(LED_SHUTTLE, LOW);
      digitalWrite(LED_JOG, LOW);
      digitalWrite(LED_SCROLL, HIGH);
    break;
  }
}
//Дополнительный режим колеса Nudge
void nudgeSubMode(boolean on_off) {
  if (on_off == NUDGE_ON) {
    previous_wheel_selected_mod = wheel_selected_mod; //Сохранить предыдущий режим
    wheel_selected_mod = SELECTED_SUBMODE_NUDGE; //Выбрать доп режим
    ledSelectMode(wheel_selected_mod);
  }
  else if (on_off == NUDGE_OFF) {
    wheel_selected_mod = previous_wheel_selected_mod; //Вернуть предыдущий режим
    ledSelectMode(wheel_selected_mod);
  }
}
