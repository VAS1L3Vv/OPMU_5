#pragma once
#include <spectr2/basedevice.h>
#include <user_dev.h>


extern HINSTANCE hInst; // Дескриптор модуля необходим для вызова диалогов
extern LPSYSPARAM sysp; // Указатель на параметры системы


void  __stdcall tact_MAX(LPDEVPROP);//Тактовая функция 

namespace Spectr2 {

	//! Структура параметров 
	struct MAXPARAM
	{
	};
	typedef MAXPARAM* LPMAXPARAM; //!< Указатель 

	//! Рабочая структура 
	struct MAXWORK
	{
	};
	typedef MAXWORK* LPMAXWORK; //!< Указатель 

	 //! Производный класс для устройства
	class MAXDev : public DeviceBase
	{
	public:

		//! Функция инициализации
		virtual DWORD init(HWND hwnd)
		{
			LPMAXPARAM b = static_cast<LPMAXPARAM>(init_device(sizeof(MAXPARAM), 2, 1)); // 2 входа, 1 выход
			return 1;
		}

		//! Функция старта
		virtual DWORD start(DWORD pin)
		{
			if (!get_work_ptr()) {
				LPMAXPARAM mp = static_cast<LPMAXPARAM>(get_data_ptr()); //параметры модулятора
				//set_work_ptr(aw); // установить рабочую структуру
				set_tact_proc(tact_MAX);// иницаилизация тактовой процедуры

			}
			return 1;
		}

		//! Функция стоп
		virtual void stop(HWND hwnd)
		{

		}


		//Имя кубика, которое отображается в дереве слева.
		virtual void get_name(char* name) { set_name(name, "Максимальный сигнал"); }
		//!Установка типа кубика(где он будет лежать) Действительный (временной) тракт, Прочие
		virtual DWORD get_type() { return (DBDEV_ROOT_TIME | DBDEV_TIME_OTHER); }

		//! Инициализация пинов(ножек) 2 входных и 1 выходной пин,(номер, тип, название)
		virtual void init_pins(LPDEVPIN in, LPDEVPIN out)
		{
			init_pin(in[1], SADF_TIME, "Вход 1", "", 2);
			init_pin(in[2], SADF_TIME, "Вход 2", "", 2);
			init_pin(out[1], SADF_TIME, "Выход", 0, 2);
		}

		//! Правой кнопкой по кубику и выбрать справка. Будет окно с текстом.
		virtual void help(HWND hwnd)
		{
			MessageBox(hwnd, "Лабораторная работа №5",
				"", MB_OK | MB_ICONINFORMATION);
		}
	};
}

