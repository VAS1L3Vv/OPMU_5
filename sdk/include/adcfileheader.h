// -*- mode:c++; coding:cp1251; -*-
// $Id: adcfileheader.h 1182 2007-06-17 16:29:32Z lebedev $
//! 
//! \file      adcfileheader.h
//! \brief     ������������ ���� ��������� ������ ��� � ������� �������
//! \copyright ����� ���-48, 1997-2007
//! \author    ������� �.�.
//!

#if !defined(_ADCFILEHEADER_H)
#define      _ADCFILEHEADER_H //!< ������ �� ���������� ���������

//! ��������� ��������� ����� ��� (ADC)
struct ADCFILEHEADER {
  double           dt; //!< ������ ������������� � ��������
  unsigned long     h; //!< ����������� ���
  unsigned long    fN; //!< ����� ���������� �������� � �����
  float            Am; //!< ���������, ��������������� ������������� �������� �������������� �������
  unsigned long flags; //!< �����
  char      reserv[8]; //!< ������
};
typedef struct ADCFILEHEADER *LPADCFILEHEADER; //!< ��������� �� ADCFILEHEADER

#define ADCF_DATA_INTEGER 0x00000000 //!< ��� ������ - �������������
#define ADCF_DATA_FLOAT   0x00000001 //!< ��� ������ - float
#define ADCF_TYPE_REAL    0x00000000 //!< ��� �������� - ��������������
#define ADCF_TYPE_COMPLEX 0x00000002 //!< ��� �������� - �����������

#endif // _ADCFILEHEADER_H
