// -*- mode:c++; coding:cp1251; -*-
// $Id: sp_complexf.h 1182 2007-06-17 16:29:32Z lebedev $
//! 
//! \file      sp_complexf.h
//! \brief     Поддержка комплексных чисел в формате Спектр-2
//! \copyright МТУСИ НИО-48, 2004-2007
//! \author    Лебедев А.Н.
//!

#if !defined(_SP_COMPLEXF_H)
#define      _SP_COMPLEXF_H  //!< Защита от повторного включения

#pragma pack(push,8)
//! Структура в стиле си для комплексного отсчета в формате Спектра
struct COMPLEXF {
    union {
        float re; //!< Реальная часть
        float Re; //!< Реальная часть
        float RE; //!< Реальная часть
        float r;  //!< Реальная часть
        float R;  //!< Реальная часть
    };
    union {
        float jm; //!< Мнимая часть
        float im; //!< Мнимая часть
        float Im; //!< Мнимая часть
        float IM; //!< Мнимая часть
        float i;  //!< Мнимая часть
        float I;  //!< Мнимая часть
    };
};
typedef struct COMPLEXF *LPCOMPLEXF; //!< Указатель на COMPLEXF
#pragma pack(pop)

#endif // _SP_COMPLEXF_H
