// -*- mode:c++; coding:cp1251; -*-
// $Id: adcfileheader.h 1182 2007-06-17 16:29:32Z lebedev $
//! 
//! \file      adcfileheader.h
//! \brief     Заголовочный файл поддержки файлов АЦП в формате Спектра
//! \copyright МТУСИ НИО-48, 1997-2007
//! \author    Лебедев А.Н.
//!

#if !defined(_ADCFILEHEADER_H)
#define      _ADCFILEHEADER_H //!< Защита от повторного включения

//! Структура заголовка файла АЦП (ADC)
struct ADCFILEHEADER {
  double           dt; //!< Период дискретизации в секундах
  unsigned long     h; //!< Разрядность АЦП
  unsigned long    fN; //!< Общее количество отсчетов в файле
  float            Am; //!< Амплитуда, соответствующая максимальному значению целочисленного отсчета
  unsigned long flags; //!< Флаги
  char      reserv[8]; //!< Резерв
};
typedef struct ADCFILEHEADER *LPADCFILEHEADER; //!< Указатель на ADCFILEHEADER

#define ADCF_DATA_INTEGER 0x00000000 //!< Тип данных - целочисленные
#define ADCF_DATA_FLOAT   0x00000001 //!< Тип данных - float
#define ADCF_TYPE_REAL    0x00000000 //!< Тип отсчетов - действительные
#define ADCF_TYPE_COMPLEX 0x00000002 //!< Тип отсчетов - комплексные

#endif // _ADCFILEHEADER_H
