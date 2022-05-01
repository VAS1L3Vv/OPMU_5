// -*- mode:c++; coding:cp1251; -*-
// $Id: basedevice.h 4126 2020-07-28 14:21:11Z lebedev $
//! 
//! \file      spectr2/basedevice.h
//! \brief     ��������� ������������������������ ������� ��� ���������� ���������������� ��������� ��� �������
//! \copyright ����� ���-48, 2007-2010
//! \author    ������� �.�.
//!

#if !defined(_SPECTR2_BASEDEVICE_H)
#define      _SPECTR2_BASEDEVICE_H //!< ������ �� ���������� ���������

#ifndef __cplusplus
#error C++ only
#endif

#include <user_dev.h>
#include <stdio.h>

//! ������������ ���� ��� ������������� ���������������� ��������� �������-2
namespace Spectr2 {

    //! ������� ��������� - ���� ��� ���� ���������, ���������� �� ��� ����������
    DWORD __stdcall
    sa_base_proc( DWORD flag, //!< ���� ������
                   HWND hwnd, //!< ���������� ���� �������� ����
              LPDEVPROP   dp  //!< ��������� �� \ref DEVPROP - ��������� ����������
                );

    //! ��� �������� ��������� �� ���
    typedef void  (__stdcall *USERTACT_PROC)(LPDEVPROP);

    //! ����������� ������� ����� ��� ����������
    class DeviceBase
    {
        public:
            //! ����������� �� ���������
            DeviceBase() 
            {
                //prtcw = 0;
            }

            //! ������������� (������������ ��������� ���������� �� ������ �� ������� ����) - 
            //! ����� � ������ \ref SAFUN_INIT - ������� ������������� ���������������.
            //! ������������� ������������ ��������� �������� \ref init_device
            //! \sa init_device
            //! \param hwnd - ���������� ���� ������� ������� ��������� ����
            virtual DWORD init( HWND hwnd ) = 0;

            //! ������������ �������� ������ ��������� ������� (����������) ���������� - 
            //! ����� � ������ \ref SAFUN_PROP - �� ��������� ������ �� ������, ���������� 1,
            //! ���� ���������� ���������������� ��� 0 � ��������� ������.
            //! \param hwnd - ���������� ���� ������� ������� ��������� ����
            virtual DWORD prop( HWND hwnd ) 
            { 
                if ( dp->flags & SADF_INITED ) return 1;
                else return 0;
            }
            //! ������ (���������� ��� ������� ����� � ������) - 
            //! ����� � ������ \ref SAFUN_TAKT0 - ������� ������������� ���������������
            //! \param pin - ����� ����� ��� ������, ��� �������� ���������� �������������
            //! \return ������ ������� 1, ���� ������������� ������ �������, ����� - 0.
            virtual DWORD start( DWORD pin ) = 0;

            //! ��������� (��������� ���� ���) - 
            //! ����� � ������ \ref SAFUN_TAKTN - ������� ������������� ���������������
            //! \param hwnd - ���������� ���� ������� ������� ��������� ����
            virtual void stop( HWND hwnd ) = 0;

            //! ������������ ������� ������� ������ ������� (���� �� ����������) - 
            //! ����� � ������ \ref SAFUN_TAKTC - �� ��������� ������ �� ������, ���������� 1
            virtual DWORD change_cntr() { return 1; }

            //! ������������� ������������ ���������� ����������� �� ���� -
            //! ����� � ������ \ref SAFUN_RT_INIT - �� ��������� ������ �� ������ \n
            //! ��� ���������� ������������� ��������������� ��������� �������� \ref create_rt_win
            //! \param rtcw - ��������� �� ��������� ���� ����������
            virtual void rt_init( LPRTCWDATA rtcw )  {}

            //! ������������ ������� ���� �� ���������� � ����������� - 
            //! ����� � ������ \ref SAFUN_RT_PROP - �� ��������� ������ �� ������
            virtual void rt_prop() {}
            
            //! ������� ����� �������� ��� ���������� - 
            //! ����� � ������ \ref SAFUN_GETNAME - ������� ������������� ���������������.
            //! ������������� ������������ ���������� ��������� �������� \ref set_name.
            //! \param name [out] - ����� ���������� ������ ��� ����� - �������� 32 �������, ������� 0
            virtual void get_name( char* name ) = 0;

            //! ������� ����� �������� ��� ���������� (����� � ������) - 
            //! ����� � ������ \ref SAFUN_GETTYPE - ������� ������������� ��������������� \n
            //! ���� �� �� ������ ��������� ���� ���������� � ������ (��������, ���������� ����������),
            //! �� ������� 0
            virtual DWORD get_type() = 0;

            //! ������� ������ �������� ��������� �������� ���������� ���������� - 
            //! ����� � ������ \ref SAFUN_GETPARAMS - �� ��������� ������ �� ������, ���������� 0 -
            //! ��� ��������, ��� ���������� �� �������� ���������� �������� ����������.
            //! ������������� ��� ��������� ������� � ���������� ���������� ������������ \ref get_data_ptr
            //! \param txt - ����� ���������� ������ ��� �������� ���������� - �������� 512 ��������, ������� 0
            virtual DWORD get_params( char* txt ) { return 0; }

            //! �������� ���������� � ���� (����� ���������� ��� �������� ��������� ����) - 
            //! ����� � ������ \ref SAFUN_FREE - �� ��������� ����������� ������, ������� lpp
            //! \param hwnd - ���������� ���� ������� ������� ��������� ����
            virtual void free( HWND hwnd )
            {
                deinit_device();
            }

            //SAFUN_GETPINNAMES 0x00002000 ��� 1-� ������ - �������� ����� ������ (�������) ����������
            // �.�. ������������ ���� ��� ����������� ������ ��� 2-� ������, �� �� ������������

            //! ������������� ���� ������ � ������� ���������� - 
            //! ����� � ������ \ref SAFUN_INITPINS - ������� ������������� ��������������� \n
            //! ��� ���������� ������������� ��������������� ��������� �������� \ref init_pin
            //! \param in  - ������ ������ (���������� � 1)
            //! \param out - ������ ������� (���������� � 1)
            virtual void init_pins( LPDEVPIN in, LPDEVPIN out ) = 0;
        
            //SAFUN_RESIZE      0x00008000 ��������� �������� ���������� (���� �� ����������)

            //! ���������� ������� �� ���������� - 
            //! ����� � ������ \ref SAFUN_HELP - �� ��������� �������� �� ������������ \n
            //! ��� ��� ������� ����� ���� ������� �� ������ ���������, ��
            //! ��������� \ref DEVPROP dp ����� ���� ������������������, ������� ��������� �� ���������� ������
            //! \param hwnd - ���������� ���� ������� ������� ��������� ����
            virtual void help( HWND hwnd )
            {
            MessageBox(hwnd,"����������� �� ����������� �������","�������", MB_OK | MB_ICONINFORMATION);
            }

            //! ��������� ������� ��� ��������� ��������� �� \ref DEVPROP ����� 
            //! ������� ��������. ���� ��������������, �� ��������� ����������
            //! � ������� ������ ��������������.
            //! \param _dp    - ��������� �� ��������� ����������
            void _set_dp ( LPDEVPROP _dp ) { dp = _dp; }
        protected:
            //! �������� ������ ��� �������� ����� ���������� \n
            //! ����� ������� ���������� ������������������� ����  bSize \n
            //! ������ ���������������� ������ \n
            //! ��� ������������� ���������� ������������� ������������ ��������� �������� \ref init_device,
            //! ������� ���� ��������� ����������� ������ � ������������� �������������� �������� ���� ���������.
            void new_mem_for_lpp()
            {
                if ( dp->bSize ) dp->lpp = GlobalAlloc( 64, dp->bSize );
                else dp->lpp = 0;
            }
            //! ���������� ������, ���������� ����������� ���������� lpp � ������������������ ����������
            void deinit_device()
            {
                if ( dp->lpp ) {
                    GlobalFree( dp->lpp );
                    dp->lpp = 0;
                }
            }
            //! ������� ���� ���������� ����������� �� ����
            //! \param n - ���������� ������������
            //! \param rtcw - ��������� �� ��������� ���� ����������
            //! \param title - ��������� �� ������ ������ - ��������� ���� ����������
            //! \return ���������� ��������� �� ������ �� n ������������
            LPRTCPARAMETR create_rt_win( int n , LPRTCWDATA rtcw, const char* title ) 
            {
                LPRTCPARAMETR rtcp; // ��������� �� ������ ������������
                // ��������� ������ ��� n ������������
                rtcp = (LPRTCPARAMETR)GlobalAlloc(64, n * sizeof(RTCPARAMETR));
                rtcw->rtcp = rtcp; // ��������� ������ ������������ ���� ����������
                rtcw->nOfControls = n; // n ������������;
                strncpy( rtcw->title, title, 31);
                rtcw->title[31] = 0;
                //prtcw = rtcw;
                return rtcp;
            }
            //! �������������� �������� ����������� �� ����������
            //! ������ ��������� ��� ���������, ������� ����������� �� ����
            //! �� ����� ������ �������, � ��� ������������ ������� - ����� ������.
            //! \param prtcw - ��������� �� ��������� ���� ����������
            void close_rt_win( LPRTCWDATA prtcw )
            {
                //if (  prtcw ) {
                //    try
                //    {
                //        //int *a = 0;
                //        //a[0] = 1;
                //        printf( "prtcw != 0\n" );
                //        if( GlobalFlags( prtcw ) != GMEM_INVALID_HANDLE ) {
                //            printf( "GlobalFlags( prtcw ) != GMEM_INVALID_HANDLE\n" );
                //            if( GlobalSize( prtcw ) ) {
                //                printf( "GlobalSize( prtcw ) != 0\n" );
                //                if( prtcw->indxDev == dp->indx ) {
                //                    printf( "prtcw->indxDev == dp->indx\n" );
                //                    if( IsWindow( prtcw->hwnd ) ) {
                //                        printf( "IsWindow( prtcw->hwnd) == TRUE\n" );
                //                        PostMessage( prtcw->hwnd, WM_CLOSE, 0, 0 );
                //                    }
                //                }
                //            }
                //            else printf( "GlobalSize( prtcw ) == 0\n" );
                //        }
                //    }
                //    catch( ... )
                //    {
                //        printf( "exeption close_rt_win()\n" );
                //        prtcw = 0;
                //    }
                //}
                if (  prtcw ) {
                    try
                    {
                        //printf( "prtcw != 0\n" );
                        if( prtcw->indxDev == dp->indx ) {
                            //printf( "prtcw->indxDev == dp->indx\n" );
                            if( IsWindow( prtcw->hwnd ) ) {
                                //printf( "IsWindow( prtcw->hwnd) == TRUE\n" );
                                PostMessage( prtcw->hwnd, WM_CLOSE, 0, 0 );
                            }
                        }
                    }
                    catch (...)
                    {
                        printf( "exeption close_rt_win(). Invalid handle LPRTCWDATA\n" );
                        prtcw = 0;
                    }
                }
                prtcw = 0;
            }
            //! 
            void init_rt_control()
            {
            }
            //! ������������������� ����������� �����.
            //! ����������� ������ ��� ������ ������������ �������.
            //! ���������� ���������������� (0 + j0).
            //! ���������� � ������� \ref start() ��� ���������,
            //! ���������� ����������� �����, ���������� ����� ����������.
            //! \return ���������� ��������� �� ����������� ������
            LPCOMPLEXF init_complex_out()
            {
                LPCOMPLEXF lpcf = (LPCOMPLEXF)GlobalAlloc(64, 8);
                return lpcf;
            }
            //! ���������� ������, ���������� ����������� ������.
            //! ����������� ��� ���������, ���������� ����������� ����, ����������� ����� ����������.
            //! \param lpin - ����� ����, ������ �������� ����� ����������.
            void free_complex_in( LPCOMPLEXF lpin )
            {
                GlobalFree( (HGLOBAL)lpin );
                lpin = 0;
            }
            //! �������� ��������� �� ��������� � ����������� ���������� ( lpp ) \n
            //! ���������� ��������� ���� (void*), �.�. ����������� ���������
            void* get_data_ptr() const { return dp->lpp; }

            //! �������� ��������� �� ������� ��������� ���������� ( lpw ) \n
            //! ���������� ��������� ���� (void*), �.�. ����������� ���������
            void* get_work_ptr() const { return dp->lpw; }

            //! ���������� (���������) ��������� �� ������� ��������� ���������� ( lpw ) \n
            //! \param pw  - ��������� �� ������� ��������� ����������
            void set_work_ptr( void* pw ) const { dp->lpw = pw; }

            //! ���������� �������� ��������� ���������� ( userproc ) \n
            //! \param utp - ����� ��������� ����������
            void set_tact_proc( USERTACT_PROC utp ) const { dp->userproc = (USERTAKT_PROC)utp; }

            //! ���������� �������� ��������� ���������� ( taktproc ), \n
            //! ���������� �� ����������
            //! \param asmproc - ����� ��������� ����������
            void set_tact_proc( DLL_PROC asmproc ) const { dp->taktproc = asmproc; }

            //! ��������� ������������� ����������.
            //! ���������� ��������� (���� void*) �� ������, ����������� ��� 
            //! ���������� ����������
            void* init_device( int        datasize, //!< ������ ��������� ���������� � ������
                               unsigned char   ins, //!< ���������� ������
                               unsigned char  outs, //!< ���������� �������
                               unsigned long flags = SADF_DEV | SADF_INITED //!< ���������� ������
                             )
            { 
                dp->bSize = datasize;
                new_mem_for_lpp ();

                dp->flags = flags | SADF_DEV; // ��� ������ ����������
                dp->lpw = 0;
                dp->nIns  = ins;
                dp->nOuts = outs;

                return dp->lpp;
            }
            //! ������������� ����� (������) - ����, ����������
            void init_pin( DEVPIN&               pin, //!< ��������� ���� �� ������
                           unsigned char        type, //!< ��� ( ���������� �������� \ref SADF_TIME \ref SADF_COMPLEX \ref SADF_INTEGER \ref SADF_FREQ - ���������� �� �����������)
                           const char          *name, //!< ������ ��� 32 �������, ������� ����
                           const char *shortname = 0, //!< �������� ��� - 8 ��������, ������� ���� - ����� ��������
                           unsigned   char   ver = 1, //!< ������ - ���������� �������� 1 ��� 2
                           unsigned char   flags = 0  //!< ����� - ���� ���������� �������� 0 � \ref PINF_FEEDBACK
                         )
            {
                pin.type  = type;
                pin.flags = flags;
                pin.ver   = ver;
                strncpy(pin.pinname, name, 31);
                pin.pinname[31] = 0;
                if ( shortname ) {
                    strncpy(pin.shortpinname, shortname, 7 );
                    pin.shortpinname[7] = 0;
                }
                else pin.shortpinname[0] = 0;
            }
            //! ������ ��� ����������.
            //! ������� �������� �� ����� 32-� ��������
            //! \param name [out]  - �����, ���� ���������� ���
            //! \param myname [in] - ����� ������ ����� ���������� ��� �����������
            void set_name( char* name, const char* myname )
            {
                strncpy( name, myname, 31);
                name[31] = 0;
            }
            //! ��������� (�����) ����� \ref SADF_INITED
            //! \param isset - true (�� ���������) - ����������, false - ��������
            void set_inited( bool isset = true )
            {
                if ( isset ) dp->flags |=  SADF_INITED;
                else         dp->flags &= ~SADF_INITED;
            }
            //! ��������� (�����) ����� \ref SADF_FILE
            //! \param isset - true (�� ���������) - ����������, false - ��������
            void set_hasfile( bool isset = true )
            {
                if ( isset ) dp->flags |=  SADF_FILE;
                else         dp->flags &= ~SADF_FILE;
            }
            //! ��������� (�����) ����� \ref SADF_WINDOW
            //! \param isset - true (�� ���������) - ����������, false - ��������
            void set_haswindow( bool isset = true )
            {
                if ( isset ) dp->flags |=  SADF_WINDOW;
                else         dp->flags &= ~SADF_WINDOW;
            }
            //! ��������� (�����) ����� \ref SADF_RT_PARAM
            //! \param isset - true (�� ���������) - ����������, false - ��������
            void set_rt_control( bool isset = true )
            {
                if ( isset ) dp->flags |=  SADF_RT_PARAM;
                else         dp->flags &= ~SADF_RT_PARAM;
            }
            LPDEVPROP dp; //!< ��������� �� ��������� ����������. ����� ����������.
            // ������ ��� ������. ��� ����� ���������� �� ���������� ����������� ������, �
            // ����� �������� ������ ����. ��� ��� ��������� ��������� ����� ���-�� � ������� ���������
            // ������ ����������.
            //LPRTCWDATA prtcw; //!< ��������� �� ���� ���������� �� ���� (��� ��������� ��� � ������ ������, ��� � ��� ������������� �������)

    }; // DeviceBase
    typedef DeviceBase *lpDeviceBase; //!< ����������� ��������� ��� ��������

    //! ������������� �������� ���������� ���������� � ������ �������������� ������� \ref devGetDevices
    //! \param indxdev0 - ������ �������� ���������� ��������������� ���������� � ����� �������
    //! \param maxdevs - ���������� ��������� � ����������
    //! \param saproc  - ��������� �� ������ �������� ���������, ���������� �� ���� ���������
    lpDeviceBase* init_base_device( int indxdev0, int maxdevs, SA_PROC* saproc );

    //! �������� ����������� ������� - ���������� ��� ��������������� ����������
    void free_base_device();

    //! �������� ���� �������� ����, ��� ������� �������������� � ��������
    //! ��� ���� ��� ����� ���������� � ������ �����, ��������, ��� 
    //! ���������� � ��������� ������. ���� ������������ ��������
    //! false, ������ ������� �� ��������.
    //! \param lpsysp - ��������� �� ��������� ���������� �������
    inline bool is_system_started( LPSYSPARAM lpsysp ) { return ( (lpsysp->flags & SYSPF_START) != 0 ); }

    //! �������� ���� �������� ����, ��� ������� ��������������, ��������
    //! � ��������� � ������ �����.
    //! false - ����� ������ ���������
    //! \param lpsysp - ��������� �� ��������� ���������� �������
    inline bool is_system_pause(   LPSYSPARAM lpsysp )
    { 
        if ( (lpsysp->flags & SYSPF_WORK_ALL) == SYSPF_START ) return true;
        else return false;
    }
    //! �������� ���� �������� ����, ��� ������� ��������������, ��������
    //! � ��������� � �������� ������ ������ - ��� ������ �������� 
    //! ������� �������������� �� �������� ���������� ���� ���������.
    //! false - ����� ������ ���������
    //! \param lpsysp - ��������� �� ��������� ���������� �������
    inline bool is_system_work(   LPSYSPARAM lpsysp )
    { 
        if ( (lpsysp->flags & SYSPF_WORK_ALL) == (SYSPF_START | SYSPF_WORK) ) return true;
        else return false;
    }
    //! �������� ���� �������� ����, ��� ������� ��������������, ��������
    //! � ��������� � ��������� ������ ������ - ��� ������ �������� 
    //! ������� �������������� �� ������� ���� ���������.
    //! false - ����� ������ ���������
    //! \param lpsysp - ��������� �� ��������� ���������� �������
    inline bool is_system_step(   LPSYSPARAM lpsysp )
    { 
        if ( (lpsysp->flags & SYSPF_WORK_ALL) == (SYSPF_START | SYSPF_STEP) ) return true;
        else return false;
    }

} // namespace Spectr2

#endif // _SPECTR2_BASEDEVICE_H
