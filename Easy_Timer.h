/*
 * EasyTimer.h
 *
 *  Версия 1.0. Таймер обыкновенный 32 битный. ЧЧ:MM:CC:MC
 *  Максимальное время замера одного таймера примерно 49 дней, 17 часов, 2 минуты и 47,295 секунд. (32 бита в мс)
 *
 *  Created on: Apr 24, 2025
 *      Author: Oleg Volkov
 *
 *  YouTube: https://www.youtube.com/channel/UCzZKTNVpcMSALU57G1THoVw
 *  GitHub: https://github.com/Solderingironspb
 *  Группа ВК: https://vk.com/solderingiron.stm32
 *
 */

/* Пример работы:
 * Создаем переменную для времени в мс, например: uint32_t Timer_ms_1 = 0;
 * Создаем структуру таймера, чтоб потом в него класть значения ЧЧ:MM:CC:MC, например struct Easy_Timer_struct Easy_Timer1;
 *
 * Чтоб задать время, используем функцию Timer_ms_1 = Easy_Timer_Set_Timer(0, 3, 20, 150); // Т.е. 0 часов 3 минуты 20 секунд и 150 миллисекунд
 * Далее, мы запускаем этот таймер. Можем даже в systick его засунуть, чтоб переменная Timer_ms_1 уменьшалась каждую мс на 1.
 * Как пример кода в SysTick:
 *    if (Timer_ms_1){
 *       Timer_ms_1--;
 *    }
 * Если хотим в произвольный момент посмотреть, что у нас со временем таймера, то используем следующую функцию:
 * Easy_Timer_Get_Time(&Easy_Timer1, Timer_ms_1); 
 * где &Easy_Timer1 - структура таймера, в которую упадут преобразованные часы, минуты, секунды, миллисекунды
 *     Timer_ms_1 - переменная для времени в мс, которую будем преобразовывать.
 */


#ifndef INC_EASY_TIMER_H_
#define INC_EASY_TIMER_H_

#include <stdint.h>

struct Easy_Timer_struct {
    uint32_t hours;         // Часы
    uint32_t minutes;       // Минуты
    uint32_t seconds;       // Секунды
    uint32_t milliseconds;  // Миллисекунды
};

uint32_t Easy_Timer_Hours_to_Milliseconds(uint8_t hours);
uint32_t Easy_Timer_Minutes_to_Milliseconds(uint8_t minutes);
uint32_t Easy_Timer_Seconds_to_Milliseconds(uint8_t seconds);
uint32_t Easy_Timer_Milliseconds_to_Hours(uint32_t milliseconds);
uint32_t Easy_Timer_Milliseconds_to_Minutes(uint32_t milliseconds);
uint32_t Easy_Timer_Milliseconds_to_Seconds(uint32_t milliseconds);
uint32_t Easy_Timer_Milliseconds_to_Remaining_Milliseconds(uint32_t milliseconds);
uint32_t Easy_Timer_Set_Timer(uint16_t hours, uint8_t minutes, uint8_t seconds, uint16_t milliseconds);
void Easy_Timer_Get_Time(struct Easy_Timer_struct *p, uint32_t milliseconds);

#endif /* INC_EASY_TIMER_H_ */