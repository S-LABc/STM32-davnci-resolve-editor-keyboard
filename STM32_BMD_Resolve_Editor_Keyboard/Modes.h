#ifndef _MODES_H_
#define _MODES_H_
//Расширение набора клавиш
//Базовые https://www.arduino.cc/en/Reference/KeyboardModifiers
#define KEY_SPACE 0x20        //Старт\пауза
#define KEY_GRAVE_ACCENT 0x60 //Шаг назад
#define KEY_COMMA 0x2C        //Кадр назад (режим Nuge)
#define KEY_PERIOD 0x2E       //Кадр вперед (режим Nuge)
#define KEY_LESS_THAN 0x3C    //Несколько кадров назад (режим Nuge)
#define KEY_GREATER_THAN 0x3E //Несколько кадров вперед (режим Nuge)
//Буквы с зажатым SHIFT
#define KEY_UPPERCASE_B 0x42  //Склйка справа (режим Nuge)
#define KEY_UPPERCASE_G 0x47  //Склйка полностью (режим Nuge)
#define KEY_UPPERCASE_I 0x49  //Перейти к началу таймлайна
#define KEY_UPPERCASE_K 0x4B  //Медленное вопроизведение
#define KEY_UPPERCASE_N 0x4E  //Склйка слева (режим Nuge)
#define KEY_UPPERCASE_O 0x4F  //Перейти к концу таймлайна
#define KEY_UPPERCASE_Q 0x51  //Клип\последовательность клипов
#define KEY_UPPERCASE_U 0x55  //Перемещение на секунду вперед
#define KEY_UPPERCASE_Y 0x59  //Перемещение на секунду назад
//Буквы без зажатого SHIFT
#define KEY_LOWERCASE_I 0x69  //Точка входа
#define KEY_LOWERCASE_J 0x6A  //Играть назад (+перемотка)
#define KEY_LOWERCASE_K 0x6B  //Стоп
#define KEY_LOWERCASE_L 0x6C  //Играть вперед (+перемотка)
#define KEY_LOWERCASE_O 0x6F  //Точка выхода
#define KEY_LOWERCASE_Q 0x71  //Таймлайн\клип
//Дополнительный режим колеса
#define NUDGE_ON true
#define NUDGE_OFF false
//Направление вращения колеса
#define TURN_LEFT true
#define TURN_RIGHT false
//Режимы колеса
#define SELECTED_SUBMODE_NUDGE 0
#define SELECTED_MODE_SHUTTLE 1
#define SELECTED_MODE_JOG 2
#define SELECTED_MODE_SCROLL 3
//Пределы скорости перемотки
#define PLAYBACK_SPEED_MAXIMUM 4 //Всего скоростей вперед
#define PLAYBACK_SPEED_MINIMUM (PLAYBACK_SPEED_MAXIMUM * (-1)) //Всего скоростей назад
#define PLAYBACK_SPEED_DEFAULT 0 //Для нейтрального положения
//Настройка для библиотеки GyverButton
#define BUTTON_DEBOUNCE 0
#define BUTTON_CLICK_TIMEOUT 400

uint8_t wheel_selected_mod = SELECTED_MODE_JOG; //Текущий режим (при запуске JOG)
uint8_t previous_wheel_selected_mod = SELECTED_MODE_JOG; //Предыдущий режим (нужен для доп режима Nudge)
int8_t playback_speed = PLAYBACK_SPEED_DEFAULT; //Скорость перемотки, воспроизведения, замедления

#endif
