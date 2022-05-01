// -*- mode:c++; coding:cp1251; -*-
// $Id: sp_spectr.h 2032 2010-02-05 09:46:20Z lebedev $
//! 
//! \file      sp_spectr.h
//! \brief     Поддержка устройств частотной области (БПФ-ОБПФ) для Спектр-2
//! \copyright МТУСИ НИО-48, 2006-2010
//! \author    Лебедев А.Н.
//!

#if !defined(_SP_SPECTR_H)
#define      _SP_SPECTR_H  //!< Защита от повторного включения

// Поддержка комплексных отсчетов Спектра-2 COMPLEXF (LPCOMPLEXF)
#include <sp_complexf.h>

#define SPF_FLOAT      0x00000001 //!< Входные данные типа float
#define SPF_INTEGER    0x00000002 //!< Входные данные целочисленные s16
#define SPF_COMPLEX    0x00000004 //!< Входные данные комплексные (COMPLEXF или complexf)
#define SPF_ISFFT      0x00000010 //!< Было ли произведено БПФ
#define SPF_RJFFT      0x00000020 //!< Массив Re и Im содержит данные после БПФ (взведен), после ОБПФ (сброшен)

#pragma pack(push,4) // Необходимо для корректного выравнивания
//! Структура для БПФ-ОБПФ в формате Спектр-2
struct SPECTR
{
  unsigned long            N; //!< Размер пачки
  unsigned long            h; //!< Разрядность АЦП (необходимо для совместимости с Анализом)
  unsigned long            m; //!< Степень двойки
  int                    max; //!< Максимальное значение целочисленных отсчетов = 2 ^ (h-1)
  unsigned long        flags; //!< Флаги
  union {
    float                *xf; //!< Входные отсчеты действительные формата float
    signed short int      *X; //!< Входные отсчеты целочисленные формата s16
    LPCOMPLEXF           xfc; //!< Входные отсчеты комплексные формата complexf
  };
  LPCOMPLEXF              RJ; //!< Массив выходных отсчетов
  float                  *Cn; //!< Массив АЧХ
  float                  *Ph; //!< Массив ФЧХ
  LPCOMPLEXF             SCC; //!< float cos, float sin // sin cos
  unsigned long     *XchIndx; //!< Массив индексов обмена
  double              deltaT; //!< Шаг дискретизации
  double              deltaF; //!< Шаг по частоте между отсчетами спектра
  float                 Amax; //!< Амплитуда, соответствующая максимальному целочисленному отсчету
};
typedef struct SPECTR *LPSPECTR; //!< Указатель на SPECTR

#pragma pack(pop) // Необходимо для корректного выравнивания

#endif // _SP_SPECTR_H
