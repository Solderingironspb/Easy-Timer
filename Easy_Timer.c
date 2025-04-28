/*
 * EasyTimer.c
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
#include "Easy_Timer.h"

/**
 ******************************************************************************
 *  @breif Функция преобразования часов в миллисекунды
 ******************************************************************************
 */

uint32_t Easy_Timer_Hours_to_Milliseconds(uint8_t hours) {
    return hours * 1000ULL * 60 * 60;
}

/**
 ******************************************************************************
 *  @breif Функция преобразования минут в миллисекунды
 ******************************************************************************
 */

uint32_t Easy_Timer_Minutes_to_Milliseconds(uint8_t minutes) {
    return minutes * 1000ULL * 60;
}

/**
 ******************************************************************************
 *  @breif Функция преобразования секунд в миллисекунды
 ******************************************************************************
 */

uint32_t Easy_Timer_Seconds_to_Milliseconds(uint8_t seconds) {
    return seconds * 1000ULL;
}

/**
 ******************************************************************************
 *  @breif Функция преобразования миллисекунд в часы
 ******************************************************************************
 */

uint32_t Easy_Timer_Milliseconds_to_Hours(uint32_t milliseconds) {
    return milliseconds / (1000ULL * 60 * 60);
}

/**
 ******************************************************************************
 *  @breif Функция преобразования миллисекунд в минуты
 ******************************************************************************
 */

uint32_t Easy_Timer_Milliseconds_to_Minutes(uint32_t milliseconds) {
    return (milliseconds % (1000ULL * 60 * 60)) / (1000ULL * 60);
}

/**
 ******************************************************************************
 *  @breif Функция преобразования миллисекунд в секунды
 ******************************************************************************
 */

uint32_t Easy_Timer_Milliseconds_to_Seconds(uint32_t milliseconds) {
    return (milliseconds % (1000ULL * 60)) / 1000ULL;
}

/**
 ******************************************************************************
 *  @breif Функция преобразования миллисекунд в остаточные миллисекунды
 *  (если меньше секунды)
 ******************************************************************************
 */

uint32_t Easy_Timer_Milliseconds_to_Remaining_Milliseconds(uint32_t milliseconds) {
    return milliseconds % 1000ULL;
}

/**
 ******************************************************************************
 *  @breif Функция преобразования времени в миллисекунды. 
 *  Т.е. задать время для обратного отсчета.
 *  @Attention Следите за переполнением таймера. Не выходите за рамки 49 дней, 17 часов, 2 минуты и 47,295 секунд
 *  @param hours - часы
 *  @param minutes - минуты
 *  @param seconds - секунды
 *  @param milliseconds - миллисекунды
 ******************************************************************************
 */

uint32_t Easy_Timer_Set_Timer(uint16_t hours, uint8_t minutes, uint8_t seconds, uint16_t milliseconds) {
    uint32_t total_ms = 0;
    total_ms = Easy_Timer_Hours_to_Milliseconds(hours) + Easy_Timer_Minutes_to_Milliseconds(minutes) + Easy_Timer_Seconds_to_Milliseconds(seconds) + milliseconds;
    return total_ms;
}

/**
 ******************************************************************************
 *  @breif Функция получения времени из миллисекунд
 *  @param *p - Структура Easy_Timer_struct, которая заберет себе преобразованное время
 *  @param milliseconds - миллисекунды, которые будет преобразовывать в время.
 ******************************************************************************
 */

void Easy_Timer_Get_Time(struct Easy_Timer_struct *p, uint32_t milliseconds){
    p->hours = Easy_Timer_Milliseconds_to_Hours(milliseconds);
    p->minutes = Easy_Timer_Milliseconds_to_Minutes(milliseconds);
    p->seconds = Easy_Timer_Milliseconds_to_Seconds(milliseconds);
    p->milliseconds = Easy_Timer_Milliseconds_to_Remaining_Milliseconds(milliseconds);
}