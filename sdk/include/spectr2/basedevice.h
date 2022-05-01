// -*- mode:c++; coding:cp1251; -*-
// $Id: basedevice.h 4126 2020-07-28 14:21:11Z lebedev $
//! 
//! \file      spectr2/basedevice.h
//! \brief     Поддержка объектноориентированного подхода при разработке пользовательских устройств для Спектра
//! \copyright МТУСИ НИО-48, 2007-2010
//! \author    Лебедев А.Н.
//!

#if !defined(_SPECTR2_BASEDEVICE_H)
#define      _SPECTR2_BASEDEVICE_H //!< Защита от повторного включения

#ifndef __cplusplus
#error C++ only
#endif

#include <user_dev.h>
#include <stdio.h>

//! Пространство имен для разработчиков пользовательских устройств Спектра-2
namespace Spectr2 {

    //! Базовая процедура - одна для всех устройств, написанных по ООП технологии
    DWORD __stdcall
    sa_base_proc( DWORD flag, //!< Ключ вызова
                   HWND hwnd, //!< Дескриптор окна рабочего поля
              LPDEVPROP   dp  //!< Указатель на \ref DEVPROP - структуру устройства
                );

    //! Тип тактовой процедуры на ЯВУ
    typedef void  (__stdcall *USERTACT_PROC)(LPDEVPROP);

    //! Абстрактный базовый класс для устройства
    class DeviceBase
    {
        public:
            //! Конструктор по умолчанию
            DeviceBase() 
            {
                //prtcw = 0;
            }

            //! Инициализация (пользователь установил устройство из дерева на рабочее поле) - 
            //! вызов с флагом \ref SAFUN_INIT - требует обязательного переопределения.
            //! Рекомендуется пользоваться служебной функцией \ref init_device
            //! \sa init_device
            //! \param hwnd - Дескриптор окна рабочей области редактора схем
            virtual DWORD init( HWND hwnd ) = 0;

            //! Пользователь запросил диалог настройки свойств (параметров) устройства - 
            //! вызов с флагом \ref SAFUN_PROP - по умолчанию ничего не делает, возвращает 1,
            //! если устройство инициализировано или 0 в противном случае.
            //! \param hwnd - Дескриптор окна рабочей области редактора схем
            virtual DWORD prop( HWND hwnd ) 
            { 
                if ( dp->flags & SADF_INITED ) return 1;
                else return 0;
            }
            //! Запуск (вызывается для каждого входа и выхода) - 
            //! вызов с флагом \ref SAFUN_TAKT0 - требует обязательного переопределения
            //! \param pin - номер входа или выхода, для которого вызывается инициализация
            //! \return Должна вернуть 1, если инициализация прошла успешно, иначе - 0.
            virtual DWORD start( DWORD pin ) = 0;

            //! Остановка (вызвается один раз) - 
            //! вызов с флагом \ref SAFUN_TAKTN - требует обязательного переопределения
            //! \param hwnd - Дескриптор окна рабочей области редактора схем
            virtual void stop( HWND hwnd ) = 0;

            //! Пользователь изменил текущий отсчет системы (пока не поддержано) - 
            //! вызов с флагом \ref SAFUN_TAKTC - по умолчанию ничего не делает, возвращает 1
            virtual DWORD change_cntr() { return 1; }

            //! Инициализация контроллеров управления параметрами на лету -
            //! вызов с флагом \ref SAFUN_RT_INIT - по умолчанию ничего не делает \n
            //! При реализации рекомендуется воспользоваться служебной функцией \ref create_rt_win
            //! \param rtcw - Указатель на структуру окна управления
            virtual void rt_init( LPRTCWDATA rtcw )  {}

            //! Пользователь изменил один из параметров в контроллере - 
            //! вызов с флагом \ref SAFUN_RT_PROP - по умолчанию ничего не делает
            virtual void rt_prop() {}
            
            //! Системе нужно получить имя устройства - 
            //! вызов с флагом \ref SAFUN_GETNAME - требует обязательного переопределения.
            //! Рекомендуется пользоваться безопасной служебной функцией \ref set_name.
            //! \param name [out] - Адрес текстового буфера для имени - максимум 32 символа, включая 0
            virtual void get_name( char* name ) = 0;

            //! Системе нужно получить тип устройства (место в дереве) - 
            //! вызов с флагом \ref SAFUN_GETTYPE - требует обязательного переопределения \n
            //! Если Вы не хотите размещать свое устройство в дереве (например, устаревшее устройство),
            //! то верните 0
            virtual DWORD get_type() = 0;

            //! Система просит получить текстовое описание параметров устройства - 
            //! вызов с флагом \ref SAFUN_GETPARAMS - по умолчанию ничего не делает, возвращает 0 -
            //! это означает, что устройство не содержит текстового описания параметров.
            //! Рекомендуется для получения доступа к параметрам устройства использовать \ref get_data_ptr
            //! \param txt - Адрес текстового буфера для описания параметров - максимум 512 символов, включая 0
            virtual DWORD get_params( char* txt ) { return 0; }

            //! Удаление устройства с поля (также вызывается при закрытии редактора схем) - 
            //! вызов с флагом \ref SAFUN_FREE - по умолчанию освобождает память, занятую lpp
            //! \param hwnd - Дескриптор окна рабочей области редактора схем
            virtual void free( HWND hwnd )
            {
                deinit_device();
            }

            //SAFUN_GETPINNAMES 0x00002000 Для 1-й версии - получить имена входов (выходов) устройства
            // Т.к. использовать этот код планируется только для 2-й версии, то не поддерживаем

            //! Инициализация всех входов и выходов устройства - 
            //! вызов с флагом \ref SAFUN_INITPINS - требует обязательного переопределения \n
            //! При реализации рекомендуется воспользоваться служебной функцией \ref init_pin
            //! \param in  - Массив входов (индексация с 1)
            //! \param out - Массив выходов (индексация с 1)
            virtual void init_pins( LPDEVPIN in, LPDEVPIN out ) = 0;
        
            //SAFUN_RESIZE      0x00008000 Изменение размеров устройства (пока не поддержано)

            //! Необходима справка об устройтсве - 
            //! вызов с флагом \ref SAFUN_HELP - по умолчанию ругается на разработчика \n
            //! Так как справка может быть вызвана из дерева устройств, то
            //! структура \ref DEVPROP dp может быть неинициализирована, поэтому исключена из параметров вызова
            //! \param hwnd - Дескриптор окна рабочей области редактора схем
            virtual void help( HWND hwnd )
            {
            MessageBox(hwnd,"Разработчик не предоставил справку","Справка", MB_OK | MB_ICONINFORMATION);
            }

            //! Служебная функция для установки указателя на \ref DEVPROP перед 
            //! вызовом функцций. Если переопределить, то поведение устройства
            //! и системы станет неопределенным.
            //! \param _dp    - Указатель на структуру устройства
            void _set_dp ( LPDEVPROP _dp ) { dp = _dp; }
        protected:
            //! Получить память для хранения своих параметров \n
            //! Перед вызовом необходимо проинициализировать поле  bSize \n
            //! Память инициализирована нулями \n
            //! Для инициализации устройства рекомендуется пользоваться служебной функцией \ref init_device,
            //! которая сама размещает необходимую память и дополнительно инициализирует основные поля структуры.
            void new_mem_for_lpp()
            {
                if ( dp->bSize ) dp->lpp = GlobalAlloc( 64, dp->bSize );
                else dp->lpp = 0;
            }
            //! Освободить память, занимаемую параметрами устройства lpp и деинициализировать устройство
            void deinit_device()
            {
                if ( dp->lpp ) {
                    GlobalFree( dp->lpp );
                    dp->lpp = 0;
                }
            }
            //! Создать окно управления параметрами на лету
            //! \param n - количество контроллеров
            //! \param rtcw - Указатель на структуру окна управления
            //! \param title - Указатель на строку текста - заголовка окна управления
            //! \return Возвращает указатель на массив из n контроллеров
            LPRTCPARAMETR create_rt_win( int n , LPRTCWDATA rtcw, const char* title ) 
            {
                LPRTCPARAMETR rtcp; // Указатель на массив контроллеров
                // Размещаем память для n контроллеров
                rtcp = (LPRTCPARAMETR)GlobalAlloc(64, n * sizeof(RTCPARAMETR));
                rtcw->rtcp = rtcp; // назначили массив контроллеров окну управления
                rtcw->nOfControls = n; // n контроллеров;
                strncpy( rtcw->title, title, 31);
                rtcw->title[31] = 0;
                //prtcw = rtcw;
                return rtcp;
            }
            //! Принудительное закрытие контроллера РТ управления
            //! обычно требуется для устройств, которые управляются на лету
            //! во время работы системы, а при незапущенной системе - через диалог.
            //! \param prtcw - Указатель на структуру окна управления
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
            //! Проинициализировать комплексный выход.
            //! Размещается память для одного комплексного отсчета.
            //! Содержимое инициализируется (0 + j0).
            //! Вызывается в функции \ref start() для устройств,
            //! содержащих комплексный выход, начинающий линию вычислений.
            //! \return Возвращает указатель на комплексный отсчет
            LPCOMPLEXF init_complex_out()
            {
                LPCOMPLEXF lpcf = (LPCOMPLEXF)GlobalAlloc(64, 8);
                return lpcf;
            }
            //! Освободить память, занимаемую комплексным входом.
            //! Применяется для устройств, содержащих комплексный вход, завершающий линию вычислений.
            //! \param lpin - адрес пина, память которого нужно освободить.
            void free_complex_in( LPCOMPLEXF lpin )
            {
                GlobalFree( (HGLOBAL)lpin );
                lpin = 0;
            }
            //! Получить указатель на структуру с параметрами устройства ( lpp ) \n
            //! Возвращает указатель типа (void*), т.к. неизвестена структура
            void* get_data_ptr() const { return dp->lpp; }

            //! Получить указатель на рабочую структуру устройства ( lpw ) \n
            //! Возвращает указатель типа (void*), т.к. неизвестена структура
            void* get_work_ptr() const { return dp->lpw; }

            //! Установить (запомнить) указатель на рабочую структуру устройства ( lpw ) \n
            //! \param pw  - Указатель на рабочую структуру устройства
            void set_work_ptr( void* pw ) const { dp->lpw = pw; }

            //! Установить тактовцю процедуру устройства ( userproc ) \n
            //! \param utp - Адрес процедуры устройства
            void set_tact_proc( USERTACT_PROC utp ) const { dp->userproc = (USERTAKT_PROC)utp; }

            //! Установить тактовцю процедуру устройства ( taktproc ), \n
            //! написанную на ассемблере
            //! \param asmproc - Адрес процедуры устройства
            void set_tact_proc( DLL_PROC asmproc ) const { dp->taktproc = asmproc; }

            //! Начальная инициализация устройства.
            //! Возвращает указатель (типа void*) на память, размещенную для 
            //! параметров устройства
            void* init_device( int        datasize, //!< Размер структуры параметров в байтах
                               unsigned char   ins, //!< Количество входов
                               unsigned char  outs, //!< Количество выходов
                               unsigned long flags = SADF_DEV | SADF_INITED //!< Комбинация флагов
                             )
            { 
                dp->bSize = datasize;
                new_mem_for_lpp ();

                dp->flags = flags | SADF_DEV; // Это всегда устройство
                dp->lpw = 0;
                dp->nIns  = ins;
                dp->nOuts = outs;

                return dp->lpp;
            }
            //! Инициализация входа (выхода) - пина, устройства
            void init_pin( DEVPIN&               pin, //!< Структура пина по ссылке
                           unsigned char        type, //!< Тип ( допустимые значения \ref SADF_TIME \ref SADF_COMPLEX \ref SADF_INTEGER \ref SADF_FREQ - комбинации не допускаются)
                           const char          *name, //!< Полное имя 32 символа, включая ноль
                           const char *shortname = 0, //!< Короткое имя - 8 символов, включая ноль - можно опустить
                           unsigned   char   ver = 1, //!< Версия - допустимые значения 1 или 2
                           unsigned char   flags = 0  //!< Флаги - пока поддержаны значения 0 и \ref PINF_FEEDBACK
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
            //! Задать имя устройства.
            //! Функция копирует не более 32-х символов
            //! \param name [out]  - адрес, куда копировать имя
            //! \param myname [in] - адрес строки имени устройства для копирования
            void set_name( char* name, const char* myname )
            {
                strncpy( name, myname, 31);
                name[31] = 0;
            }
            //! Установка (сброс) флага \ref SADF_INITED
            //! \param isset - true (по умолчанию) - установить, false - сбросить
            void set_inited( bool isset = true )
            {
                if ( isset ) dp->flags |=  SADF_INITED;
                else         dp->flags &= ~SADF_INITED;
            }
            //! Установка (сброс) флага \ref SADF_FILE
            //! \param isset - true (по умолчанию) - установить, false - сбросить
            void set_hasfile( bool isset = true )
            {
                if ( isset ) dp->flags |=  SADF_FILE;
                else         dp->flags &= ~SADF_FILE;
            }
            //! Установка (сброс) флага \ref SADF_WINDOW
            //! \param isset - true (по умолчанию) - установить, false - сбросить
            void set_haswindow( bool isset = true )
            {
                if ( isset ) dp->flags |=  SADF_WINDOW;
                else         dp->flags &= ~SADF_WINDOW;
            }
            //! Установка (сброс) флага \ref SADF_RT_PARAM
            //! \param isset - true (по умолчанию) - установить, false - сбросить
            void set_rt_control( bool isset = true )
            {
                if ( isset ) dp->flags |=  SADF_RT_PARAM;
                else         dp->flags &= ~SADF_RT_PARAM;
            }
            LPDEVPROP dp; //!< Указатель на структуру устройства. Может изменяться.
            // Нельзя так делать. Это класс управления не конкретным экземпляром кубика, а
            // всеми кубиками такого типа. Так что сохранять указатель нужно где-то в рабочей структуре
            // самому устройству.
            //LPRTCWDATA prtcw; //!< Указатель на окно управления на лету (для поддержки как в режиме работы, так и при остановленной системе)

    }; // DeviceBase
    typedef DeviceBase *lpDeviceBase; //!< Определение указателя для удобства

    //! Инициализация Базового устройства вызывается в начале экспортируемой функции \ref devGetDevices
    //! \param indxdev0 - индекс нулевого устройства разрабатываемой библиотеки в общем массиве
    //! \param maxdevs - количество устройств в библиотеке
    //! \param saproc  - указатель на массив процедур устройств, получаемый от ядра программы
    lpDeviceBase* init_base_device( int indxdev0, int maxdevs, SA_PROC* saproc );

    //! Удаление производных классов - вызывается при деинициализации библиотеки
    void free_base_device();

    //! Получить флаг признака того, что система скомпилирована и запущена
    //! При этом она может находиться в режиме паузы, работать, или 
    //! находиться в пошаговом режиме. Если возвращаемое значение
    //! false, значит система не запущена.
    //! \param lpsysp - указатель на структуру параметров системы
    inline bool is_system_started( LPSYSPARAM lpsysp ) { return ( (lpsysp->flags & SYSPF_START) != 0 ); }

    //! Получить флаг признака того, что система скомпилирована, запущена
    //! и находится в режиме паузы.
    //! false - любое другое состояние
    //! \param lpsysp - указатель на структуру параметров системы
    inline bool is_system_pause(   LPSYSPARAM lpsysp )
    { 
        if ( (lpsysp->flags & SYSPF_WORK_ALL) == SYSPF_START ) return true;
        else return false;
    }
    //! Получить флаг признака того, что система скомпилирована, запущена
    //! и находится в основном режиме работы - все вызовы тактовой 
    //! функции осуществляются из отдельно запущенной нити обработки.
    //! false - любое другое состояние
    //! \param lpsysp - указатель на структуру параметров системы
    inline bool is_system_work(   LPSYSPARAM lpsysp )
    { 
        if ( (lpsysp->flags & SYSPF_WORK_ALL) == (SYSPF_START | SYSPF_WORK) ) return true;
        else return false;
    }
    //! Получить флаг признака того, что система скомпилирована, запущена
    //! и находится в пошаговом режиме работы - все вызовы тактовой 
    //! функции осуществляются из главной нити программы.
    //! false - любое другое состояние
    //! \param lpsysp - указатель на структуру параметров системы
    inline bool is_system_step(   LPSYSPARAM lpsysp )
    { 
        if ( (lpsysp->flags & SYSPF_WORK_ALL) == (SYSPF_START | SYSPF_STEP) ) return true;
        else return false;
    }

} // namespace Spectr2

#endif // _SPECTR2_BASEDEVICE_H
