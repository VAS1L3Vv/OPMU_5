// -*- mode:c++; coding:cp1251; -*-
// $Id: sp_complexf.h 1182 2007-06-17 16:29:32Z lebedev $
//! 
//! \file      sp_complexf.h
//! \brief     ��������� ����������� ����� � ������� ������-2
//! \copyright ����� ���-48, 2004-2007
//! \author    ������� �.�.
//!

#if !defined(_SP_COMPLEXF_H)
#define      _SP_COMPLEXF_H  //!< ������ �� ���������� ���������

#pragma pack(push,8)
//! ��������� � ����� �� ��� ������������ ������� � ������� �������
struct COMPLEXF {
    union {
        float re; //!< �������� �����
        float Re; //!< �������� �����
        float RE; //!< �������� �����
        float r;  //!< �������� �����
        float R;  //!< �������� �����
    };
    union {
        float jm; //!< ������ �����
        float im; //!< ������ �����
        float Im; //!< ������ �����
        float IM; //!< ������ �����
        float i;  //!< ������ �����
        float I;  //!< ������ �����
    };
};
typedef struct COMPLEXF *LPCOMPLEXF; //!< ��������� �� COMPLEXF
#pragma pack(pop)

#endif // _SP_COMPLEXF_H
