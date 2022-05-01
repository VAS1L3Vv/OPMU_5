#pragma once
#include <spectr2/basedevice.h>
#include <user_dev.h>


extern HINSTANCE hInst; // Дескриптор модуля необходим для вызова диалогов
extern LPSYSPARAM sysp; // Указатель на параметры системы


void  __stdcall tact_DIV(LPDEVPROP);//Тактовая функция 

namespace Spectr2 {

    //! Структура параметров 
    struct DIVPARAM
    {
        float CONST_DIV = 2;
    };
    typedef DIVPARAM* LPDIVPARAM; //!< Указатель 

    //! Рабочая структура. Для работы моего устройства доп. выделение памяти не требуется.
    struct DIVWORK
    {
    };
    typedef DIVWORK* LPDIVWORK; //!< Указатель 

     //! Производный класс для устройства
    class DIVDev : public DeviceBase
    {
    public:

        //! Функция инициализации
        virtual DWORD init(HWND hwnd)
        {
            LPDIVPARAM div = static_cast<LPDIVPARAM>(init_device(sizeof(DIVPARAM), 2, 2)); // указано 2 входа и 2 выхода
            div->CONST_DIV = 2;
            return 1;
        }

        //! Функция старта
        virtual DWORD start(DWORD pin)
        {
            if (!get_work_ptr()) {
                LPDIVPARAM mp = static_cast<LPDIVPARAM>(get_data_ptr()); //параметры модулятора

                mp->CONST_DIV = 2;
                //set_work_ptr(aw); // установить рабочую структуру
                set_tact_proc(tact_DIV);// иницаилизация тактовой процедуры

            }
            return 1;
        }

        //! Функция стоп
        virtual void stop(HWND hwnd)
        {

        }


        //Имя кубика, которое отображается в дереве слева.
        virtual void get_name(char* name) { set_name(name, "Sig_Divider"); }
        //!Установка типа кубика(где он будет лежать) Действительный (временной) тракт, Прочие
        virtual DWORD get_type() { return (DBDEV_ROOT_TIME | DBDEV_TIME_OTHER); }

        //! Инициализация пинов(ножек) 1 входной и 1 выходной пин,(номер, тип, название)
        virtual void init_pins(LPDEVPIN in, LPDEVPIN out) 
            /* Для наглядной работы устройства
            на первую пару вход - выход подающийся сигнал не подвергается обработке.
            А вторая пара вход-выход делит входной сигнал на константу и передает его на выход.
            См. на осцилографе изначальный сигнал(желтый) и обработанный(зеленый) */ 
        {
            init_pin(in[1], SADF_TIME, "Вход1: Режим ByPass", "ByPass", 2);
            init_pin(out[1], SADF_TIME, "Выход1: неизмененный сигнал", 0, 2);
            init_pin(in[2], SADF_TIME, "Вход2: Делитель", "Делитель", 2);
            init_pin(out[2], SADF_TIME, "Выход2: Делитель", 0, 2);
        }

        //! Правой кнопкой по кубику и выбрать справка. Будет окно с текстом.
        virtual void help(HWND hwnd)
        {
            MessageBox(hwnd, "Лабораторная работа №5",
                "", MB_OK | MB_ICONINFORMATION);
        }
    }; 
}
