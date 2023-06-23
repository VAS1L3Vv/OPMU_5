#include "SigDivHeader.h"

using namespace Spectr2;

#define DEVS_MAX 1 //!< Текущее значение количества устройств в библиотеке

// Глобальные переменные
HINSTANCE hInst; // дескриптор модуля
LPSYSPARAM sysp; // Указатель на параметры системы

// Входная точка библиотеки. Вызывается Windows'ом
//#pragma argsused
BOOL WINAPI  DllMain(HINSTANCE hDLL, DWORD dwReason, LPVOID)
{
    switch (dwReason) {
    case DLL_PROCESS_ATTACH:
        hInst = hDLL; // Запомним наш дескриптор.
                      // Сюда вставляется Ваш код инициализации библиотеки,
                      // если, конечно, он Вам необходим
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        // Вызов библиотечной функции для освобождения ресурсов.

        // Сюда вставляется Ваш код деинициализации библиотеки,
        // если, конечно, он Вам необходим
        break;
    }
    return TRUE;
}


DWORD __stdcall
devGetDllInfo(char* info)
{
    strcpy(info, "Библиотека с устройством Лабораторной работы №5");
    return DEVS_MAX; // Библиотека содержит DEVS_MAX устройств
}

DWORD __stdcall
devGetDevices(int n0,          // Индекс первого устройства (получаем от основной программы)
    LPSYSPARAM _sysp,// Указатель на параметры системы (они общие для всех библиотек)
    SA_PROC* saproc, // Указатель на основной массив процедур устройств
    HIMAGELIST himl  // Набор иконок всех устрйоств
)
{
    int i;

    // Вызов функции инициализации базовых устройств
    lpDeviceBase* devs = init_base_device(n0, DEVS_MAX, saproc);

    sysp = _sysp; // Запомним указатель полученными данными

                  // Заполняем массив указателей на базовые устройства через указатели на 
                  // производные классы.
    devs[0] = new DIVDev;

    return 1;
}

void  __stdcall tact_DIV(LPDEVPROP dp)//Тактовая функция 
{
    LPDIVPARAM lpp = static_cast<LPDIVPARAM> (dp->lpp);
    *dp->pins[4].f_out = dp->pins[1].f_in;
    *dp->pins[5].f_out = dp->pins[2].f_in / lpp->CONST_DIV;
}