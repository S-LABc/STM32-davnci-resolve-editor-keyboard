
void wheelTurn(boolean dir) {
  switch (wheel_selected_mod) {
    case SELECTED_MODE_SHUTTLE: //Shuttle
    shuttle(dir);
    break;
    case SELECTED_MODE_JOG: //Jog
    jog(dir);
    break;
    case SELECTED_MODE_SCROLL: //Scroll
    scroll(dir);
    break;
    case SELECTED_SUBMODE_NUDGE: //Nudge
    nudge(dir);
    break;
  }
}
//Поведение в режиме SHUTTLE
void shuttle(boolean _dir) {
  if (_dir) { //Вращение влево
    if (playback_speed > PLAYBACK_SPEED_MINIMUM && playback_speed <= PLAYBACK_SPEED_DEFAULT) { //Стоим или движемсЯ влево
        playback_speed --; //Уменьшить счетчик скорости
        Keyboard.write(KEY_LOWERCASE_J); //Проигрываем назад
      }
      else if (playback_speed > PLAYBACK_SPEED_DEFAULT && playback_speed <= PLAYBACK_SPEED_MAXIMUM) { //Двигались вправо, сменили навправление
        if (playback_speed > PLAYBACK_SPEED_DEFAULT + 1) { //Не стоим на нейтрали
          Keyboard.write(KEY_UPPERCASE_K); //Замедлить
        }
        else if (playback_speed == PLAYBACK_SPEED_DEFAULT + 1) {
          Keyboard.write(KEY_LOWERCASE_K); //Остановить
        }
        playback_speed --; //Уменьшить счетчик скорости
      }
      else if (playback_speed == PLAYBACK_SPEED_MAXIMUM + 1) { //Дошли до конца вправо и сменили направление
        playback_speed = PLAYBACK_SPEED_DEFAULT - 1; //Уменьшить скорость на 1 от нейтральной
        Keyboard.write(KEY_LOWERCASE_J); //Скорость 1х влево
      }
      else if (playback_speed == PLAYBACK_SPEED_MINIMUM) { //Дошли до конца влево, остановились
        playback_speed --; //Вышли за пределы условий поворота влево
        Keyboard.write(KEY_LOWERCASE_K); //Остановить перемотку
        Keyboard.write(KEY_UPPERCASE_I); //Перейти к началу
      }
  }
  else { //Вращение вправо
    if (playback_speed < PLAYBACK_SPEED_MAXIMUM && playback_speed >= PLAYBACK_SPEED_DEFAULT) { //Стоим или движемсЯ вправо
      playback_speed ++; //Увеличить счетчик скорости
      Keyboard.write(KEY_LOWERCASE_L); //Проигрываем вперед
    }
    else if (playback_speed < PLAYBACK_SPEED_DEFAULT && playback_speed >= PLAYBACK_SPEED_MINIMUM) { //Двигались влево, сменили навправление
      if (playback_speed < PLAYBACK_SPEED_DEFAULT - 1) { //Не стоим на нейтрали
        Keyboard.write(KEY_UPPERCASE_K); //Замедлить
      }
      else if (playback_speed == PLAYBACK_SPEED_DEFAULT - 1) {
        Keyboard.write(KEY_LOWERCASE_K); //Остановить
      }
      playback_speed ++; //Увеличить счетчик скорости
    }
    else if (playback_speed == PLAYBACK_SPEED_MINIMUM - 1) { //Дошли до конца влево и сменили напрвление
      playback_speed = PLAYBACK_SPEED_DEFAULT + 1; //Увеличить скорость на 1 от от нейтральной
      Keyboard.write(KEY_LOWERCASE_L); //Скорость 1х вправо
    }
    else if (playback_speed == PLAYBACK_SPEED_MAXIMUM) { //Дошли до конца вправо, остановились
      playback_speed ++; //Вышли за пределы условий поворота вправо
      Keyboard.write(KEY_LOWERCASE_K); //Остановить перемотку
      Keyboard.write(KEY_UPPERCASE_O); //Перейти к концу
    }
  }
}
//Поведение в режиме JOG
void jog(boolean _dir) {
  if (_dir) {
    Keyboard.write(KEY_LEFT_ARROW); //На кадр влево
  }
  else {
    Keyboard.write(KEY_RIGHT_ARROW); //На кадр вправо
  }
}
//Поведение в режиме SCROLL
void scroll(boolean _dir) {
  if (_dir) {
    Keyboard.write(KEY_UPPERCASE_Y); //На секунду влево
  }
  else {
    Keyboard.write(KEY_UPPERCASE_U); //На секунду вправо
  }
}
//Поведение в режиме NUDGE
void nudge(boolean _dir) {
  if (_dir) {
    Keyboard.write(KEY_COMMA); //На кадр влево Nudge
  }
  else {
    Keyboard.write(KEY_PERIOD); //На кадр вправо Nudge
  }
}
