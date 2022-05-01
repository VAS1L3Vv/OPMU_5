// -*- mode:c++; coding:cp1251; -*-
// $Id: sp_spectr.h 2032 2010-02-05 09:46:20Z lebedev $
//! 
//! \file      sp_spectr.h
//! \brief     ��������� ��������� ��������� ������� (���-����) ��� ������-2
//! \copyright ����� ���-48, 2006-2010
//! \author    ������� �.�.
//!

#if !defined(_SP_SPECTR_H)
#define      _SP_SPECTR_H  //!< ������ �� ���������� ���������

// ��������� ����������� �������� �������-2 COMPLEXF (LPCOMPLEXF)
#include <sp_complexf.h>

#define SPF_FLOAT      0x00000001 //!< ������� ������ ���� float
#define SPF_INTEGER    0x00000002 //!< ������� ������ ������������� s16
#define SPF_COMPLEX    0x00000004 //!< ������� ������ ����������� (COMPLEXF ��� complexf)
#define SPF_ISFFT      0x00000010 //!< ���� �� ����������� ���
#define SPF_RJFFT      0x00000020 //!< ������ Re � Im �������� ������ ����� ��� (�������), ����� ���� (�������)

#pragma pack(push,4) // ���������� ��� ����������� ������������
//! ��������� ��� ���-���� � ������� ������-2
struct SPECTR
{
  unsigned long            N; //!< ������ �����
  unsigned long            h; //!< ����������� ��� (���������� ��� ������������� � ��������)
  unsigned long            m; //!< ������� ������
  int                    max; //!< ������������ �������� ������������� �������� = 2 ^ (h-1)
  unsigned long        flags; //!< �����
  union {
    float                *xf; //!< ������� ������� �������������� ������� float
    signed short int      *X; //!< ������� ������� ������������� ������� s16
    LPCOMPLEXF           xfc; //!< ������� ������� ����������� ������� complexf
  };
  LPCOMPLEXF              RJ; //!< ������ �������� ��������
  float                  *Cn; //!< ������ ���
  float                  *Ph; //!< ������ ���
  LPCOMPLEXF             SCC; //!< float cos, float sin // sin cos
  unsigned long     *XchIndx; //!< ������ �������� ������
  double              deltaT; //!< ��� �������������
  double              deltaF; //!< ��� �� ������� ����� ��������� �������
  float                 Amax; //!< ���������, ��������������� ������������� �������������� �������
};
typedef struct SPECTR *LPSPECTR; //!< ��������� �� SPECTR

#pragma pack(pop) // ���������� ��� ����������� ������������

#endif // _SP_SPECTR_H
