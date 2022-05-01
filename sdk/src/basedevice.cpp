// -*- mode:c++; coding:cp1251; -*-
// $Id: basedevice.cpp 3006 2013-12-08 16:10:24Z lebedev $
//! 
//! \file      src/spectr2/basedevice.cpp
//! \brief     Реализация базового устройства по технологии ООП
//! \copyright МТУСИ НИЛ-48, 2007
//! \author    Лебедев А. Н.
//!

#include <spectr2/basedevice.h>

static int dev0; //!< Индекс первого устройства для текущего сеанса работы

namespace Spectr2 {
    //! Массив для хранения указателей на производные классы (по описанию библиотека содержит не более 256 устройств)
    static lpDeviceBase devs[256];

    // Инициализация массива производных классов устройств и получение указателя на него
    lpDeviceBase* init_base_device( int indxdev0, int maxdevs, SA_PROC* saproc )
    {
        dev0 = indxdev0;
        for ( int i = 0; i < maxdevs; i++ ) {
            saproc[i+dev0] = (SA_PROC)sa_base_proc;
            devs[i] = 0;
        }
        return &devs[0];
    }

    void free_base_device()
    {
        for ( int i = 0; i < 256; i++ ) if ( devs[i] ) delete devs[i];
    }

    // Реализация процедуры базового устройтсва
    DWORD __stdcall 
    sa_base_proc( DWORD flag, HWND hwnd, LPDEVPROP dp )
    {
        switch ( flag ) {
            case  SAFUN_INIT:
                devs[dp->type - dev0]->_set_dp( dp );
                return devs[dp->type - dev0]->init( hwnd );
            case  SAFUN_PROP:
                devs[dp->type - dev0]->_set_dp( dp );
                return devs[dp->type - dev0]->prop( hwnd );
            case  SAFUN_TAKT0:
                devs[dp->type - dev0]->_set_dp( dp );
                return devs[dp->type - dev0]->start( (DWORD)hwnd );
            case  SAFUN_TAKTN:
                devs[dp->type - dev0]->_set_dp( dp );
                devs[dp->type - dev0]->stop( hwnd );
                break;
            case  SAFUN_TAKTC:
                devs[dp->type - dev0]->_set_dp( dp );
                return devs[dp->type - dev0]->change_cntr();
            case  SAFUN_RT_INIT:
                devs[dp->type - dev0]->_set_dp( dp );
                devs[dp->type - dev0]->rt_init( (LPRTCWDATA)hwnd );
                break;
            case  SAFUN_RT_PROP:
                devs[dp->type - dev0]->_set_dp( dp );
                devs[dp->type - dev0]->rt_prop();
                break;
            case  SAFUN_GETNAME:
                devs[dp->type - dev0]->get_name( (char*)hwnd );
                break;
            case  SAFUN_GETTYPE:
                return devs[dp->type - dev0]->get_type();
            case  SAFUN_GETPARAMS:
                devs[dp->type - dev0]->_set_dp( dp );
                return devs[dp->type - dev0]->get_params( (char*)hwnd );
            case  SAFUN_HELP:
                devs[dp->type - dev0]->help( hwnd );
                break;
            case  SAFUN_FREE:
                devs[dp->type - dev0]->_set_dp( dp );
                devs[dp->type - dev0]->free( hwnd );
                break;
            case  SAFUN_GETPINNAMES: break;
            case  SAFUN_INITPINS:
                devs[dp->type - dev0]->_set_dp( dp );
                devs[dp->type - dev0]->init_pins( dp->pins, &dp->pins[dp->nIns + 1] );
                break;
            case  SAFUN_RESIZE: break;
        } // switch ( flag )
        return 1;
    }
} // namespace Spectr2
