// -*- mode:c++; coding:cp1251; -*-
// $Id: user_dev.h 4145 2020-10-01 13:24:50Z lebedev $
//! 
//! \file      user_dev.h
//! \brief     Заголовочный файл поддержки пользовательских устройств для Спектра
//! \copyright МТУСИ НИО-48, 1997-2018
//! \author    Лебедев А.Н.
//!

#if !defined(_USER_DEV_H)
#define _USER_DEV_H //!< Защита от повторного включения

//#ifndef __cplusplus
//#error C++ only
//#endif

#include <windows.h>
#include <commctrl.h>

#pragma pack(push,4)

#define CM_PARAM_CHANGED 5010 //!< Команда-уведомление  - параметр был изменен

// Откатить, если не заработает... ///////////////////////////////////////
#define RTCS_FREQ      0x00000001 //!< Стиль - управление частотой (Герцы)
#define RTCS_PHASE     0x00000002 //!< Стиль - управление фазой (радианы и градусы)
#define RTCS_AMPL      0x00000004 //!< Стиль - управление амплитудой (Вольты)
#define RTCS_TIME      0x00000008 //!< Стиль - управление временем (секунды или отсчеты)
#define RTCS_UNITDB    0x00000010 //!< Стиль - управление усилением (разы и децибелы)
#define RTCS_TAKTIMP   0x00000020 //!< Стиль - управление длительностью импульсов (время, секунды)
#define RTCS_INTEGER   0x00020000 //!< Стиль - целочисленный контроллер
#define RTCS_ALLTYPES  0x0002003f //!< Все стили (для удобства)
//#define RTCS_INTEGER   0x00000800 //!< Стиль - целочисленный контроллер
//#define RTCS_ALLTYPES  0x0000083f //!< Все стили (для удобства)
#define RTCS_SYSPAUSE  0x00000040 //!< Приостановить работу системы на время изменения параметра
#define RTCS_MINIMIZED 0x00000080 //!< Дополнительный стиль - контроллер свернут

//#define RTCS_ISEDIT2   0x00010000 //!< Служебный флаг - в каком из двух полей ввода мы находимся

#define RTCP_FLOAT     0x00000100 //!< Тип параметра - float
#define RTCP_DOUBLE    0x00000200 //!< Тип параметра - double
#define RTCP_INT       0x00000400 //!< Тип параметра - целочисленный (int)
#define RTCP_ALLTYPES  0x00000700 //!< Все типы значений

#define RTCP_MINMAX    0x00000800 //!< Параметр вызова - переключение между свернутым и развернутым режимами отображения
#define RTCP_TEXT      0x00001000 //!< Параметр вызова - установка текста на плоской кнопке
#define RTCP_ADDRESS   0x00002000 //!< Параметр вызова - установка адреса значения параметра
#define RTCP_TYPE      0x00004000 //!< Параметр вызова - установка типа значения параметра (double,float,int)
#define RTCP_PARAM     0x00008000 //!< Параметр вызова - установка значения параметра
#define RTCP_ALL       0x0000f800 //!< Рассмотреть все параметры

#define RTCM_SETPARAM         (WM_USER + 40) //!< Сообщение - Установить параметр(ы)
#define RTCM_GETPARAM         (WM_USER + 41) //!< Сообщение - Получить параметр(ы)
#define RTCM_GETPARAMINDIRECT (WM_USER + 42) //!< Сообщение - Получить параметр непосредственно по адресу
#define RTCM_REDRAW_EDIT      (WM_USER + 43) //!< Сообщение - Перерисовать edit контролы (черная-белая темы)

//// ... до сюда. //////////////////////////////////////////////////////////
//#define RTCS_FREQ      0x00000001 //!< Стиль - управление частотой (Герцы)
//#define RTCS_PHASE     0x00000002 //!< Стиль - управление фазой (радианы и градусы)
//#define RTCS_AMPL      0x00000004 //!< Стиль - управление амплитудой (Вольты)
//#define RTCS_TIME      0x00000008 //!< Стиль - управление временем (секунды или отсчеты)
//#define RTCS_UNITDB    0x00000010 //!< Стиль - управление усилением (разы и децибелы)
//#define RTCS_TAKTIMP   0x00000020 //!< Стиль - управление длительностью импульсов (время, секунды)
//// Не работает
//#define RTCS_INTEGER   0x00010000 //!< Стиль - целочисленный контроллер
//#define RTCS_ALLTYPES  0x0000003f //!< Все стили (для удобства)
//#define RTCS_SYSPAUSE  0x00000040 //!< Приостановить работу системы на время изменения параметра
//#define RTCS_MINIMIZED 0x00000080 //!< Дополнительный стиль - контроллер свернут
//
//#define RTCP_FLOAT     0x00000100 //!< Тип параметра - float
//#define RTCP_DOUBLE    0x00000200 //!< Тип параметра - double
//#define RTCP_INT       0x00000400 //!< Тип параметра - целочисленный (int)
//#define RTCP_ALLTYPES  0x00000700 //!< Все типы значений
//
//#define RTCP_MINMAX    0x00000800 //!< Параметр вызова - переключение между свернутым и развернутым режимами отображения
//#define RTCP_TEXT      0x00001000 //!< Параметр вызова - установка текста на плоской кнопке
//#define RTCP_ADDRESS   0x00002000 //!< Параметр вызова - установка адреса значения параметра
//#define RTCP_TYPE      0x00004000 //!< Параметр вызова - установка типа значения параметра (double,float,int)
//#define RTCP_PARAM     0x00008000 //!< Параметр вызова - установка значения параметра
//#define RTCP_ALL       0x0000f800 //!< Рассмотреть все параметры
//
//#define RTCM_SETPARAM         (WM_USER + 40) //!< Сообщение - Установить параметр(ы)
//#define RTCM_GETPARAM         (WM_USER + 41) //!< Сообщение - Получить параметр(ы)
//#define RTCM_GETPARAMINDIRECT (WM_USER + 42) //!< Сообщение - Получить параметр непосредственно по адресу
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Тип устройства ////////////////////////////
#define SADF_NULL      0x00000000 //!< Нулевое устройство (пустая ячейка)
#define SADF_DEV       0x00000001 //!< Ненулевое устройство (в ячейке содержится "живое" устройство)
#define SADF_FREQ      0x00000002 //!< Устройство (пин) работает в частотной области
#define SADF_TIME      0x00000004 //!< Устройство (пин) работает во временной области
#define SADF_COMPLEX   0x00000008 //!< Устройство (пин) работает в комплексной области
#define SADF_INTEGER   0x00000010 //!< Устройство (пин) работает с битовыми (целочисленными отсчетами)
#define SADF_INITED    0x00000020 //!< Устройство проинициализировано
#define SADF_FILE      0x00000400 //!< Устройство работает с файлом

#define SADF_BEGSTREAM 0x00000800 //!< Устройство начинает поток вычислений (для 1-й версии)
#define SADF_ENDSTREAM 0x00001000 //!< Устройство завершает поток вычислений (для 1-й версии)
#define SADF_FEEDBACK  0x00002000 //!< Устройство может организовать обратную связь (вход независим) (для 1-й версии)

#define SADF_RT_PARAM  0x00100000 //!< Параметры устройства могут изменяться во время работы (содержится поддержка контроллеров)
#define SADF_NE_IN     0x00200000 //!< Устройство с неравнозначными входами (версия 1), требуется уточнять какой вход подключать
#define SADF_WINDOW    0x00400000 //!< Устройство имеет окно графического отображения

//! Вызов процедуры устройства с ключем SAFUN_TAKT0 для 1-го входа. 
//! Поддержаны от 1 до 255 входов
#define SA_SOLVE_IN1    0x01000000
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#define SA_SOLVE_IN2    0x02000000
#define SA_SOLVE_IN3    0x04000000
#define SA_SOLVE_IN4	0x00000400
#define SA_SOLVE_IN5	0x00000500
#define SA_SOLVE_IN6	0x00000600
#define SA_SOLVE_IN7	0x00000700
#define SA_SOLVE_IN8	0x00000800
#define SA_SOLVE_IN9	0x00000900
#define SA_SOLVE_IN10	0x00000A00
#define SA_SOLVE_IN11	0x00000B00
#define SA_SOLVE_IN12	0x00000C00
#define SA_SOLVE_IN13	0x00000D00
#define SA_SOLVE_IN14	0x00000E00
#define SA_SOLVE_IN15	0x00000F00
#define SA_SOLVE_IN16	0x00001000
#define SA_SOLVE_IN17	0x00001100
#define SA_SOLVE_IN18	0x00001200
#define SA_SOLVE_IN19	0x00001300
#define SA_SOLVE_IN20	0x00001400
#define SA_SOLVE_IN21	0x00001500
#define SA_SOLVE_IN22	0x00001600
#define SA_SOLVE_IN23	0x00001700
#define SA_SOLVE_IN24	0x00001800
#define SA_SOLVE_IN25	0x00001900
#define SA_SOLVE_IN26	0x00001A00
#define SA_SOLVE_IN27	0x00001B00
#define SA_SOLVE_IN28	0x00001C00
#define SA_SOLVE_IN29	0x00001D00
#define SA_SOLVE_IN30	0x00001E00
#define SA_SOLVE_IN31	0x00001F00
#define SA_SOLVE_IN32	0x00002000
#define SA_SOLVE_IN33	0x00002100
#define SA_SOLVE_IN34	0x00002200
#define SA_SOLVE_IN35	0x00002300
#define SA_SOLVE_IN36	0x00002400
#define SA_SOLVE_IN37	0x00002500
#define SA_SOLVE_IN38	0x00002600
#define SA_SOLVE_IN39	0x00002700
#define SA_SOLVE_IN40	0x00002800
#define SA_SOLVE_IN41	0x00002900
#define SA_SOLVE_IN42	0x00002A00
#define SA_SOLVE_IN43	0x00002B00
#define SA_SOLVE_IN44	0x00002C00
#define SA_SOLVE_IN45	0x00002D00
#define SA_SOLVE_IN46	0x00002E00
#define SA_SOLVE_IN47	0x00002F00
#define SA_SOLVE_IN48	0x00003000
#define SA_SOLVE_IN49	0x00003100
#define SA_SOLVE_IN50	0x00003200
#define SA_SOLVE_IN51	0x00003300
#define SA_SOLVE_IN52	0x00003400
#define SA_SOLVE_IN53	0x00003500
#define SA_SOLVE_IN54	0x00003600
#define SA_SOLVE_IN55	0x00003700
#define SA_SOLVE_IN56	0x00003800
#define SA_SOLVE_IN57	0x00003900
#define SA_SOLVE_IN58	0x00003A00
#define SA_SOLVE_IN59	0x00003B00
#define SA_SOLVE_IN60	0x00003C00
#define SA_SOLVE_IN61	0x00003D00
#define SA_SOLVE_IN62	0x00003E00
#define SA_SOLVE_IN63	0x00003F00
#define SA_SOLVE_IN64	0x00004000
#define SA_SOLVE_IN65	0x00004100
#define SA_SOLVE_IN66	0x00004200
#define SA_SOLVE_IN67	0x00004300
#define SA_SOLVE_IN68	0x00004400
#define SA_SOLVE_IN69	0x00004500
#define SA_SOLVE_IN70	0x00004600
#define SA_SOLVE_IN71	0x00004700
#define SA_SOLVE_IN72	0x00004800
#define SA_SOLVE_IN73	0x00004900
#define SA_SOLVE_IN74	0x00004A00
#define SA_SOLVE_IN75	0x00004B00
#define SA_SOLVE_IN76	0x00004C00
#define SA_SOLVE_IN77	0x00004D00
#define SA_SOLVE_IN78	0x00004E00
#define SA_SOLVE_IN79	0x00004F00
#define SA_SOLVE_IN80	0x00005000
#define SA_SOLVE_IN81	0x00005100
#define SA_SOLVE_IN82	0x00005200
#define SA_SOLVE_IN83	0x00005300
#define SA_SOLVE_IN84	0x00005400
#define SA_SOLVE_IN85	0x00005500
#define SA_SOLVE_IN86	0x00005600
#define SA_SOLVE_IN87	0x00005700
#define SA_SOLVE_IN88	0x00005800
#define SA_SOLVE_IN89	0x00005900
#define SA_SOLVE_IN90	0x00005A00
#define SA_SOLVE_IN91	0x00005B00
#define SA_SOLVE_IN92	0x00005C00
#define SA_SOLVE_IN93	0x00005D00
#define SA_SOLVE_IN94	0x00005E00
#define SA_SOLVE_IN95	0x00005F00
#define SA_SOLVE_IN96	0x00006000
#define SA_SOLVE_IN97	0x00006100
#define SA_SOLVE_IN98	0x00006200
#define SA_SOLVE_IN99	0x00006300
#define SA_SOLVE_IN100	0x00006400
#define SA_SOLVE_IN101	0x00006500
#define SA_SOLVE_IN102	0x00006600
#define SA_SOLVE_IN103	0x00006700
#define SA_SOLVE_IN104	0x00006800
#define SA_SOLVE_IN105	0x00006900
#define SA_SOLVE_IN106	0x00006A00
#define SA_SOLVE_IN107	0x00006B00
#define SA_SOLVE_IN108	0x00006C00
#define SA_SOLVE_IN109	0x00006D00
#define SA_SOLVE_IN110	0x00006E00
#define SA_SOLVE_IN111	0x00006F00
#define SA_SOLVE_IN112	0x00007000
#define SA_SOLVE_IN113	0x00007100
#define SA_SOLVE_IN114	0x00007200
#define SA_SOLVE_IN115	0x00007300
#define SA_SOLVE_IN116	0x00007400
#define SA_SOLVE_IN117	0x00007500
#define SA_SOLVE_IN118	0x00007600
#define SA_SOLVE_IN119	0x00007700
#define SA_SOLVE_IN120	0x00007800
#define SA_SOLVE_IN121	0x00007900
#define SA_SOLVE_IN122	0x00007A00
#define SA_SOLVE_IN123	0x00007B00
#define SA_SOLVE_IN124	0x00007C00
#define SA_SOLVE_IN125	0x00007D00
#define SA_SOLVE_IN126	0x00007E00
#define SA_SOLVE_IN127	0x00007F00
#define SA_SOLVE_IN128	0x00008000
#define SA_SOLVE_IN129	0x00008100
#define SA_SOLVE_IN130	0x00008200
#define SA_SOLVE_IN131	0x00008300
#define SA_SOLVE_IN132	0x00008400
#define SA_SOLVE_IN133	0x00008500
#define SA_SOLVE_IN134	0x00008600
#define SA_SOLVE_IN135	0x00008700
#define SA_SOLVE_IN136	0x00008800
#define SA_SOLVE_IN137	0x00008900
#define SA_SOLVE_IN138	0x00008A00
#define SA_SOLVE_IN139	0x00008B00
#define SA_SOLVE_IN140	0x00008C00
#define SA_SOLVE_IN141	0x00008D00
#define SA_SOLVE_IN142	0x00008E00
#define SA_SOLVE_IN143	0x00008F00
#define SA_SOLVE_IN144	0x00009000
#define SA_SOLVE_IN145	0x00009100
#define SA_SOLVE_IN146	0x00009200
#define SA_SOLVE_IN147	0x00009300
#define SA_SOLVE_IN148	0x00009400
#define SA_SOLVE_IN149	0x00009500
#define SA_SOLVE_IN150	0x00009600
#define SA_SOLVE_IN151	0x00009700
#define SA_SOLVE_IN152	0x00009800
#define SA_SOLVE_IN153	0x00009900
#define SA_SOLVE_IN154	0x00009A00
#define SA_SOLVE_IN155	0x00009B00
#define SA_SOLVE_IN156	0x00009C00
#define SA_SOLVE_IN157	0x00009D00
#define SA_SOLVE_IN158	0x00009E00
#define SA_SOLVE_IN159	0x00009F00
#define SA_SOLVE_IN160	0x0000A000
#define SA_SOLVE_IN161	0x0000A100
#define SA_SOLVE_IN162	0x0000A200
#define SA_SOLVE_IN163	0x0000A300
#define SA_SOLVE_IN164	0x0000A400
#define SA_SOLVE_IN165	0x0000A500
#define SA_SOLVE_IN166	0x0000A600
#define SA_SOLVE_IN167	0x0000A700
#define SA_SOLVE_IN168	0x0000A800
#define SA_SOLVE_IN169	0x0000A900
#define SA_SOLVE_IN170	0x0000AA00
#define SA_SOLVE_IN171	0x0000AB00
#define SA_SOLVE_IN172	0x0000AC00
#define SA_SOLVE_IN173	0x0000AD00
#define SA_SOLVE_IN174	0x0000AE00
#define SA_SOLVE_IN175	0x0000AF00
#define SA_SOLVE_IN176	0x0000B000
#define SA_SOLVE_IN177	0x0000B100
#define SA_SOLVE_IN178	0x0000B200
#define SA_SOLVE_IN179	0x0000B300
#define SA_SOLVE_IN180	0x0000B400
#define SA_SOLVE_IN181	0x0000B500
#define SA_SOLVE_IN182	0x0000B600
#define SA_SOLVE_IN183	0x0000B700
#define SA_SOLVE_IN184	0x0000B800
#define SA_SOLVE_IN185	0x0000B900
#define SA_SOLVE_IN186	0x0000BA00
#define SA_SOLVE_IN187	0x0000BB00
#define SA_SOLVE_IN188	0x0000BC00
#define SA_SOLVE_IN189	0x0000BD00
#define SA_SOLVE_IN190	0x0000BE00
#define SA_SOLVE_IN191	0x0000BF00
#define SA_SOLVE_IN192	0x0000C000
#define SA_SOLVE_IN193	0x0000C100
#define SA_SOLVE_IN194	0x0000C200
#define SA_SOLVE_IN195	0x0000C300
#define SA_SOLVE_IN196	0x0000C400
#define SA_SOLVE_IN197	0x0000C500
#define SA_SOLVE_IN198	0x0000C600
#define SA_SOLVE_IN199	0x0000C700
#define SA_SOLVE_IN200	0x0000C800
#define SA_SOLVE_IN201	0x0000C900
#define SA_SOLVE_IN202	0x0000CA00
#define SA_SOLVE_IN203	0x0000CB00
#define SA_SOLVE_IN204	0x0000CC00
#define SA_SOLVE_IN205	0x0000CD00
#define SA_SOLVE_IN206	0x0000CE00
#define SA_SOLVE_IN207	0x0000CF00
#define SA_SOLVE_IN208	0x0000D000
#define SA_SOLVE_IN209	0x0000D100
#define SA_SOLVE_IN210	0x0000D200
#define SA_SOLVE_IN211	0x0000D300
#define SA_SOLVE_IN212	0x0000D400
#define SA_SOLVE_IN213	0x0000D500
#define SA_SOLVE_IN214	0x0000D600
#define SA_SOLVE_IN215	0x0000D700
#define SA_SOLVE_IN216	0x0000D800
#define SA_SOLVE_IN217	0x0000D900
#define SA_SOLVE_IN218	0x0000DA00
#define SA_SOLVE_IN219	0x0000DB00
#define SA_SOLVE_IN220	0x0000DC00
#define SA_SOLVE_IN221	0x0000DD00
#define SA_SOLVE_IN222	0x0000DE00
#define SA_SOLVE_IN223	0x0000DF00
#define SA_SOLVE_IN224	0x0000E000
#define SA_SOLVE_IN225	0x0000E100
#define SA_SOLVE_IN226	0x0000E200
#define SA_SOLVE_IN227	0x0000E300
#define SA_SOLVE_IN228	0x0000E400
#define SA_SOLVE_IN229	0x0000E500
#define SA_SOLVE_IN230	0x0000E600
#define SA_SOLVE_IN231	0x0000E700
#define SA_SOLVE_IN232	0x0000E800
#define SA_SOLVE_IN233	0x0000E900
#define SA_SOLVE_IN234	0x0000EA00
#define SA_SOLVE_IN235	0x0000EB00
#define SA_SOLVE_IN236	0x0000EC00
#define SA_SOLVE_IN237	0x0000ED00
#define SA_SOLVE_IN238	0x0000EE00
#define SA_SOLVE_IN239	0x0000EF00
#define SA_SOLVE_IN240	0x0000F000
#define SA_SOLVE_IN241	0x0000F100
#define SA_SOLVE_IN242	0x0000F200
#define SA_SOLVE_IN243	0x0000F300
#define SA_SOLVE_IN244	0x0000F400
#define SA_SOLVE_IN245	0x0000F500
#define SA_SOLVE_IN246	0x0000F600
#define SA_SOLVE_IN247	0x0000F700
#define SA_SOLVE_IN248	0x0000F800
#define SA_SOLVE_IN249	0x0000F900
#define SA_SOLVE_IN250	0x0000FA00
#define SA_SOLVE_IN251	0x0000FB00
#define SA_SOLVE_IN252	0x0000FC00
#define SA_SOLVE_IN253	0x0000FD00
#define SA_SOLVE_IN254	0x0000FE00
#define SA_SOLVE_IN255	0x0000FF00
#endif // DOXYGEN_SHOULD_SKIP_THIS
//! Вызов процедуры устройства с ключем SAFUN_TAKT0 для 1-го выхода. 
//! Поддержаны от 1 до 255 выходов
#define SA_SOLVE_OUT1   0x08000000
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#define SA_SOLVE_OUT2   0x10000000
#define SA_SOLVE_OUT3   0x20000000
#define SA_SOLVE_OUT4	0x00000004
#define SA_SOLVE_OUT5	0x00000005
#define SA_SOLVE_OUT6	0x00000006
#define SA_SOLVE_OUT7	0x00000007
#define SA_SOLVE_OUT8	0x00000008
#define SA_SOLVE_OUT9	0x00000009
#define SA_SOLVE_OUT10	0x0000000A
#define SA_SOLVE_OUT11	0x0000000B
#define SA_SOLVE_OUT12	0x0000000C
#define SA_SOLVE_OUT13	0x0000000D
#define SA_SOLVE_OUT14	0x0000000E
#define SA_SOLVE_OUT15	0x0000000F
#define SA_SOLVE_OUT16	0x00000010
#define SA_SOLVE_OUT17	0x00000011
#define SA_SOLVE_OUT18	0x00000012
#define SA_SOLVE_OUT19	0x00000013
#define SA_SOLVE_OUT20	0x00000014
#define SA_SOLVE_OUT21	0x00000015
#define SA_SOLVE_OUT22	0x00000016
#define SA_SOLVE_OUT23	0x00000017
#define SA_SOLVE_OUT24	0x00000018
#define SA_SOLVE_OUT25	0x00000019
#define SA_SOLVE_OUT26	0x0000001A
#define SA_SOLVE_OUT27	0x0000001B
#define SA_SOLVE_OUT28	0x0000001C
#define SA_SOLVE_OUT29	0x0000001D
#define SA_SOLVE_OUT30	0x0000001E
#define SA_SOLVE_OUT31	0x0000001F
#define SA_SOLVE_OUT32	0x00000020
#define SA_SOLVE_OUT33	0x00000021
#define SA_SOLVE_OUT34	0x00000022
#define SA_SOLVE_OUT35	0x00000023
#define SA_SOLVE_OUT36	0x00000024
#define SA_SOLVE_OUT37	0x00000025
#define SA_SOLVE_OUT38	0x00000026
#define SA_SOLVE_OUT39	0x00000027
#define SA_SOLVE_OUT40	0x00000028
#define SA_SOLVE_OUT41	0x00000029
#define SA_SOLVE_OUT42	0x0000002A
#define SA_SOLVE_OUT43	0x0000002B
#define SA_SOLVE_OUT44	0x0000002C
#define SA_SOLVE_OUT45	0x0000002D
#define SA_SOLVE_OUT46	0x0000002E
#define SA_SOLVE_OUT47	0x0000002F
#define SA_SOLVE_OUT48	0x00000030
#define SA_SOLVE_OUT49	0x00000031
#define SA_SOLVE_OUT50	0x00000032
#define SA_SOLVE_OUT51	0x00000033
#define SA_SOLVE_OUT52	0x00000034
#define SA_SOLVE_OUT53	0x00000035
#define SA_SOLVE_OUT54	0x00000036
#define SA_SOLVE_OUT55	0x00000037
#define SA_SOLVE_OUT56	0x00000038
#define SA_SOLVE_OUT57	0x00000039
#define SA_SOLVE_OUT58	0x0000003A
#define SA_SOLVE_OUT59	0x0000003B
#define SA_SOLVE_OUT60	0x0000003C
#define SA_SOLVE_OUT61	0x0000003D
#define SA_SOLVE_OUT62	0x0000003E
#define SA_SOLVE_OUT63	0x0000003F
#define SA_SOLVE_OUT64	0x00000040
#define SA_SOLVE_OUT65	0x00000041
#define SA_SOLVE_OUT66	0x00000042
#define SA_SOLVE_OUT67	0x00000043
#define SA_SOLVE_OUT68	0x00000044
#define SA_SOLVE_OUT69	0x00000045
#define SA_SOLVE_OUT70	0x00000046
#define SA_SOLVE_OUT71	0x00000047
#define SA_SOLVE_OUT72	0x00000048
#define SA_SOLVE_OUT73	0x00000049
#define SA_SOLVE_OUT74	0x0000004A
#define SA_SOLVE_OUT75	0x0000004B
#define SA_SOLVE_OUT76	0x0000004C
#define SA_SOLVE_OUT77	0x0000004D
#define SA_SOLVE_OUT78	0x0000004E
#define SA_SOLVE_OUT79	0x0000004F
#define SA_SOLVE_OUT80	0x00000050
#define SA_SOLVE_OUT81	0x00000051
#define SA_SOLVE_OUT82	0x00000052
#define SA_SOLVE_OUT83	0x00000053
#define SA_SOLVE_OUT84	0x00000054
#define SA_SOLVE_OUT85	0x00000055
#define SA_SOLVE_OUT86	0x00000056
#define SA_SOLVE_OUT87	0x00000057
#define SA_SOLVE_OUT88	0x00000058
#define SA_SOLVE_OUT89	0x00000059
#define SA_SOLVE_OUT90	0x0000005A
#define SA_SOLVE_OUT91	0x0000005B
#define SA_SOLVE_OUT92	0x0000005C
#define SA_SOLVE_OUT93	0x0000005D
#define SA_SOLVE_OUT94	0x0000005E
#define SA_SOLVE_OUT95	0x0000005F
#define SA_SOLVE_OUT96	0x00000060
#define SA_SOLVE_OUT97	0x00000061
#define SA_SOLVE_OUT98	0x00000062
#define SA_SOLVE_OUT99	0x00000063
#define SA_SOLVE_OUT100	0x00000064
#define SA_SOLVE_OUT101	0x00000065
#define SA_SOLVE_OUT102	0x00000066
#define SA_SOLVE_OUT103	0x00000067
#define SA_SOLVE_OUT104	0x00000068
#define SA_SOLVE_OUT105	0x00000069
#define SA_SOLVE_OUT106	0x0000006A
#define SA_SOLVE_OUT107	0x0000006B
#define SA_SOLVE_OUT108	0x0000006C
#define SA_SOLVE_OUT109	0x0000006D
#define SA_SOLVE_OUT110	0x0000006E
#define SA_SOLVE_OUT111	0x0000006F
#define SA_SOLVE_OUT112	0x00000070
#define SA_SOLVE_OUT113	0x00000071
#define SA_SOLVE_OUT114	0x00000072
#define SA_SOLVE_OUT115	0x00000073
#define SA_SOLVE_OUT116	0x00000074
#define SA_SOLVE_OUT117	0x00000075
#define SA_SOLVE_OUT118	0x00000076
#define SA_SOLVE_OUT119	0x00000077
#define SA_SOLVE_OUT120	0x00000078
#define SA_SOLVE_OUT121	0x00000079
#define SA_SOLVE_OUT122	0x0000007A
#define SA_SOLVE_OUT123	0x0000007B
#define SA_SOLVE_OUT124	0x0000007C
#define SA_SOLVE_OUT125	0x0000007D
#define SA_SOLVE_OUT126	0x0000007E
#define SA_SOLVE_OUT127	0x0000007F
#define SA_SOLVE_OUT128	0x00000080
#define SA_SOLVE_OUT129	0x00000081
#define SA_SOLVE_OUT130	0x00000082
#define SA_SOLVE_OUT131	0x00000083
#define SA_SOLVE_OUT132	0x00000084
#define SA_SOLVE_OUT133	0x00000085
#define SA_SOLVE_OUT134	0x00000086
#define SA_SOLVE_OUT135	0x00000087
#define SA_SOLVE_OUT136	0x00000088
#define SA_SOLVE_OUT137	0x00000089
#define SA_SOLVE_OUT138	0x0000008A
#define SA_SOLVE_OUT139	0x0000008B
#define SA_SOLVE_OUT140	0x0000008C
#define SA_SOLVE_OUT141	0x0000008D
#define SA_SOLVE_OUT142	0x0000008E
#define SA_SOLVE_OUT143	0x0000008F
#define SA_SOLVE_OUT144	0x00000090
#define SA_SOLVE_OUT145	0x00000091
#define SA_SOLVE_OUT146	0x00000092
#define SA_SOLVE_OUT147	0x00000093
#define SA_SOLVE_OUT148	0x00000094
#define SA_SOLVE_OUT149	0x00000095
#define SA_SOLVE_OUT150	0x00000096
#define SA_SOLVE_OUT151	0x00000097
#define SA_SOLVE_OUT152	0x00000098
#define SA_SOLVE_OUT153	0x00000099
#define SA_SOLVE_OUT154	0x0000009A
#define SA_SOLVE_OUT155	0x0000009B
#define SA_SOLVE_OUT156	0x0000009C
#define SA_SOLVE_OUT157	0x0000009D
#define SA_SOLVE_OUT158	0x0000009E
#define SA_SOLVE_OUT159	0x0000009F
#define SA_SOLVE_OUT160	0x000000A0
#define SA_SOLVE_OUT161	0x000000A1
#define SA_SOLVE_OUT162	0x000000A2
#define SA_SOLVE_OUT163	0x000000A3
#define SA_SOLVE_OUT164	0x000000A4
#define SA_SOLVE_OUT165	0x000000A5
#define SA_SOLVE_OUT166	0x000000A6
#define SA_SOLVE_OUT167	0x000000A7
#define SA_SOLVE_OUT168	0x000000A8
#define SA_SOLVE_OUT169	0x000000A9
#define SA_SOLVE_OUT170	0x000000AA
#define SA_SOLVE_OUT171	0x000000AB
#define SA_SOLVE_OUT172	0x000000AC
#define SA_SOLVE_OUT173	0x000000AD
#define SA_SOLVE_OUT174	0x000000AE
#define SA_SOLVE_OUT175	0x000000AF
#define SA_SOLVE_OUT176	0x000000B0
#define SA_SOLVE_OUT177	0x000000B1
#define SA_SOLVE_OUT178	0x000000B2
#define SA_SOLVE_OUT179	0x000000B3
#define SA_SOLVE_OUT180	0x000000B4
#define SA_SOLVE_OUT181	0x000000B5
#define SA_SOLVE_OUT182	0x000000B6
#define SA_SOLVE_OUT183	0x000000B7
#define SA_SOLVE_OUT184	0x000000B8
#define SA_SOLVE_OUT185	0x000000B9
#define SA_SOLVE_OUT186	0x000000BA
#define SA_SOLVE_OUT187	0x000000BB
#define SA_SOLVE_OUT188	0x000000BC
#define SA_SOLVE_OUT189	0x000000BD
#define SA_SOLVE_OUT190	0x000000BE
#define SA_SOLVE_OUT191	0x000000BF
#define SA_SOLVE_OUT192	0x000000C0
#define SA_SOLVE_OUT193	0x000000C1
#define SA_SOLVE_OUT194	0x000000C2
#define SA_SOLVE_OUT195	0x000000C3
#define SA_SOLVE_OUT196	0x000000C4
#define SA_SOLVE_OUT197	0x000000C5
#define SA_SOLVE_OUT198	0x000000C6
#define SA_SOLVE_OUT199	0x000000C7
#define SA_SOLVE_OUT200	0x000000C8
#define SA_SOLVE_OUT201	0x000000C9
#define SA_SOLVE_OUT202	0x000000CA
#define SA_SOLVE_OUT203	0x000000CB
#define SA_SOLVE_OUT204	0x000000CC
#define SA_SOLVE_OUT205	0x000000CD
#define SA_SOLVE_OUT206	0x000000CE
#define SA_SOLVE_OUT207	0x000000CF
#define SA_SOLVE_OUT208	0x000000D0
#define SA_SOLVE_OUT209	0x000000D1
#define SA_SOLVE_OUT210	0x000000D2
#define SA_SOLVE_OUT211	0x000000D3
#define SA_SOLVE_OUT212	0x000000D4
#define SA_SOLVE_OUT213	0x000000D5
#define SA_SOLVE_OUT214	0x000000D6
#define SA_SOLVE_OUT215	0x000000D7
#define SA_SOLVE_OUT216	0x000000D8
#define SA_SOLVE_OUT217	0x000000D9
#define SA_SOLVE_OUT218	0x000000DA
#define SA_SOLVE_OUT219	0x000000DB
#define SA_SOLVE_OUT220	0x000000DC
#define SA_SOLVE_OUT221	0x000000DD
#define SA_SOLVE_OUT222	0x000000DE
#define SA_SOLVE_OUT223	0x000000DF
#define SA_SOLVE_OUT224	0x000000E0
#define SA_SOLVE_OUT225	0x000000E1
#define SA_SOLVE_OUT226	0x000000E2
#define SA_SOLVE_OUT227	0x000000E3
#define SA_SOLVE_OUT228	0x000000E4
#define SA_SOLVE_OUT229	0x000000E5
#define SA_SOLVE_OUT230	0x000000E6
#define SA_SOLVE_OUT231	0x000000E7
#define SA_SOLVE_OUT232	0x000000E8
#define SA_SOLVE_OUT233	0x000000E9
#define SA_SOLVE_OUT234	0x000000EA
#define SA_SOLVE_OUT235	0x000000EB
#define SA_SOLVE_OUT236	0x000000EC
#define SA_SOLVE_OUT237	0x000000ED
#define SA_SOLVE_OUT238	0x000000EE
#define SA_SOLVE_OUT239	0x000000EF
#define SA_SOLVE_OUT240	0x000000F0
#define SA_SOLVE_OUT241	0x000000F1
#define SA_SOLVE_OUT242	0x000000F2
#define SA_SOLVE_OUT243	0x000000F3
#define SA_SOLVE_OUT244	0x000000F4
#define SA_SOLVE_OUT245	0x000000F5
#define SA_SOLVE_OUT246	0x000000F6
#define SA_SOLVE_OUT247	0x000000F7
#define SA_SOLVE_OUT248	0x000000F8
#define SA_SOLVE_OUT249	0x000000F9
#define SA_SOLVE_OUT250	0x000000FA
#define SA_SOLVE_OUT251	0x000000FB
#define SA_SOLVE_OUT252	0x000000FC
#define SA_SOLVE_OUT253	0x000000FD
#define SA_SOLVE_OUT254	0x000000FE
#define SA_SOLVE_OUT255	0x000000FF
#endif // DOXYGEN_SHOULD_SKIP_THIS
//////////////////////////////////

// Тип вызова функции устройства /////////////////////////////////////////////////////
#define SAFUN_INIT        0x00000001 //!< Инициализация (пользователь установил устройство из дерева на рабочее поле)
#define SAFUN_PROP        0x00000002 //!< Пользователь запросил диалог настройки свойств (параметров) устройства
#define SAFUN_TAKT0       0x00000008 //!< Запуск (вызывается для каждого входа и выхода)
#define SAFUN_TAKTN       0x00000010 //!< Остановка (вызвается один раз)
#define SAFUN_TAKTC       0x00000020 //!< Пользователь изменил текущий отсчет системы (пока не поддержано)
#define SAFUN_RT_INIT     0x00000040 //!< Инициализация контроллеров управления параметрами на лету
#define SAFUN_RT_PROP     0x00000080 //!< Пользователь изменил один из параметров в контроллере
#define SAFUN_GETNAME     0x00000100 //!< Системе нужно получить имя устройства
#define SAFUN_GETTYPE     0x00000200 //!< Системе нужно получить тип устройства (место в дереве)
#define SAFUN_GETPARAMS   0x00000400 //!< Системе нужно получить текстовое описание параметров устройства
#define SAFUN_HELP        0x00000800 //!< Необходима справка об устройтсве
#define SAFUN_FREE        0x00001000 //!< Удаление устройства с поля (также вызывается при закрытии редактора схем)
#define SAFUN_GETPINNAMES 0x00002000 //!< Для 1-й версии - получить имена входов (выходов) устройства
#define SAFUN_INITPINS    0x00004000 //!< Инициализация всех входов и выходов устройства
#define SAFUN_RESIZE      0x00008000 //!< Изменение размеров устройства (пока не поддержано)

// Место в дереве устройств
#define DBDEV_NULL              0x00000000 //!< Не размещать в дереве устройств

#define DBDEV_ROOT_TIME         0x00010000 //!< Временной тракт
#define DBDEV_TIME_DEV          0x00000001 //!< Временной тракт Устройства
#define DBDEV_TIME_FILTR        0x00000002 //!< Временной тракт Фильтры
#define DBDEV_TIME_MODULATOR    0x00000003 //!< Временной тракт Модуляторы
#define DBDEV_TIME_DETECTOR     0x00000004 //!< Временной тракт Детекторы
#define DBDEV_TIME_DELAYLINE    0x00000005 //!< Временной тракт Линии задержки
#define DBDEV_TIME_FUNCTION     0x00000006 //!< Временной тракт Функции
#define DBDEV_TIME_CONTROL      0x00000007 //!< Временной тракт Управляемые устройства
#define DBDEV_TIME_OTHER        0x00000008 //!< Временной тракт Прочие

#define DBDEV_ROOT_FREQ         0x00020000 //!< Частотный тракт
#define DBDEV_FREQ_DEV          0x00000001 //!< Частотный тракт Устройства
#define DBDEV_FREQ_FUNCTION     0x00000002 //!< Частотный тракт Функции
#define DBDEV_FREQ_OTHER        0x00000003 //!< Частотный тракт Прочие

#define DBDEV_ROOT_CMPLX        0x00030000 //!< Комплексный тракт
#define DBDEV_CMPLX_DEV         0x00000001 //!< Комплексный тракт Устройства
#define DBDEV_CMPLX_FUNCTION    0x00000002 //!< Комплексный тракт Функции
#define DBDEV_CMPLX_CONTROL     0x00000003 //!< Комплексный тракт Управляемые устройства
#define DBDEV_CMPLX_OTHER       0x00000004 //!< Комплексный тракт Прочие
#define DBDEV_CMPLX_FILTR       0x00000005 //!< Комплексный тракт Фильтры
#define DBDEV_CMPLX_MODULATOR   0x00000006 //!< Комплексный тракт Модуляторы
#define DBDEV_CMPLX_DEMOD       0x00000007 //!< Комплексный тракт Детекторы
#define DBDEV_CMPLX_CONVERT     0x00000008 //!< Комплексный тракт Преобразователи

// Тоже самое. Синонимы
#define DBDEV_ROOT_COMPLEX      0x00030000 //!< Комплексный тракт
#define DBDEV_COMPLEX_DEV       0x00000001 //!< Комплексный тракт Устройства
#define DBDEV_COMPLEX_FUNCTION  0x00000002 //!< Комплексный тракт Функции
#define DBDEV_COMPLEX_CONTROL   0x00000003 //!< Комплексный тракт Управляемые устройства
#define DBDEV_COMPLEX_OTHER     0x00000004 //!< Комплексный тракт Прочие
#define DBDEV_COMPLEX_FILTER    0x00000005 //!< Комплексный тракт Фильтры
#define DBDEV_COMPLEX_MODULATOR 0x00000006 //!< Комплексный тракт Модуляторы
#define DBDEV_COMPLEX_DEMOD     0x00000007 //!< Комплексный тракт Детекторы
#define DBDEV_COMPLEX_CONVERT   0x00000008 //!< Комплексный тракт Преобразователи

#define DBDEV_ROOT_IN           0x00040000 //!< Вход 
#define DBDEV_IN_DEV            0x00000001 //!< Вход Аппаратные устройства
#define DBDEV_IN_GENERATOR      0x00000002 //!< Вход Генераторы
#define DBDEV_IN_FILE           0x00000003 //!< Вход Файлы
#define DBDEV_IN_OTHER          0x00000004 //!< Вход Прочие

#define DBDEV_ROOT_OUT          0x00050000 //!< Выход
#define DBDEV_OUT_DEV           0x00000001 //!< Выход Аппаратные устройства
#define DBDEV_OUT_FILE          0x00000002 //!< Выход Файлы
#define DBDEV_OUT_OTHER         0x00000003 //!< Выход Прочие

#define DBDEV_ROOT_WAVE         0x00060000 //!< Обработка звука
#define DBDEV_WAVE_DEV          0x00000001 //!< Обработка звука Аппаратные устройства
#define DBDEV_WAVE_FILE         0x00000002 //!< Обработка звука Файлы
#define DBDEV_WAVE_SM           0x00000003 //!< Обработка звука Моно Стерео (скорее всего будет удалено)
#define DBDEV_WAVE_OTHER        0x00000004 //!< Обработка звука Прочие

#define DBDEV_ROOT_OTHER        0x00070000 //!< Прочие
#define DBDEV_OTHER_1           0x00000001 //!< Прочие 1
#define DBDEV_OTHER_2           0x00000002 //!< Прочие 2
#define DBDEV_OTHER_3           0x00000003 //!< Прочие 3
#define DBDEV_OTHER_4           0x00000004 //!< Прочие 4
#define DBDEV_OTHER_5           0x00000005 //!< Прочие 5
#define DBDEV_OTHER_6           0x00000006 //!< Прочие 6

#define DBDEV_ROOT_BIT          0x00080000 //!< Битовые данные
#define DBDEV_BIT_INTEGER       0x00000001 //!< Битовые данные Целочисленные отсчеты
#define DBDEV_BIT_1BIT          0x00000002 //!< Битовые данные Биты
#define DBDEV_BIT_CONVERT       0x00000003 //!< Битовые данные Преобразователи 
#define DBDEV_BIT_OTHER         0x00000004 //!< Битовые данные Прочие
#define DBDEV_BIT_CODEC         0x00000005 //!< Битовые данные Кодеки

// Флаги для определения типа файла ////////////////////////////
#define FTF_LOAD   0x00010000 //!< Устройство читает из файла (обязательно наличие такого файла)
#define FTF_SAVE   0x00020000 //!< Устройство пишет в файл (необязательно наличие такого файла)
#define FTF_ADC    0x00040000 //!< Файл АЦП (ADC)
#define FTF_TXT    0x00080000 //!< Текстовый файл
#define FTF_WAVE   0x00100000 //!< Звуковой файл
#define FTF_FIR    0x00200000 //!< Файл с коэффициентами КИХ фильтра
#define FTF_IIR    0x00400000 //!< Файл с коэффициентами БИХ фильтра
#define FTF_XLS    0x00800000 //!< Файл Exel
#define FTF_BIN    0x01000000 //!< Бинарный файл
#define FTF_MCAD   0x02000000 //!< Файл MathCAD
#define FTF_BMP    0x04000000 //!< Файл битовой карты
#define FTF_ANALIZ 0x10000000 //!< Файл Анализа (EZSoft)
#define FTF_NODEF  0x80000000 //!< Файл неопределенного ипа

// смещение полей в структуре устройства для использования в Ассемблере
#ifndef DOXYGEN_SHOULD_SKIP_THIS
#define dpflags	      0
#define dptype	      4
#define dpindx	      8
#define dpnIns	      10
#define dpnOuts	      11
#define dpL	      12
#define dpT	      13
#define dpR	      14
#define dpB	      15
#define dpbSize	      16
#define dp_pin1	      20
#define dp_pin2	      24
#define dp_pin3	      28
#define dp_pin4	      32
#define dp_lpp	      36
#define dp_lpw	      40
#define dp_userproc   44
#define dptaktproc    48
#define dpdpi	      52
#define dpsysp1	      56
#define dpsysp2	      60

#define dp_inpin1     20
#define dp_inpin2     24
#define dp_inpin3     28
#define dp_outpin3    24
#define dp_outpin2    28
#define dp_outpin1    32
#endif // DOXYGEN_SHOULD_SKIP_THIS


//! Тип тактовой процедуры на ассемблере
typedef void  (__stdcall *DLL_PROC)(void);
//! Тип тактовой процедуры на ЯВУ
typedef void  (__stdcall *USERTAKT_PROC)(void*);

#include <sp_spectr.h>

//! Параметр, управляемый на лету
//! \sa RTCONTROL RTCWDATA
struct RTCPARAMETR
{
  DWORD   flags; //!< Флаги
  void	 *param; //!< Адрес значения параметра
  int	 iparam; //!< Целочисленное значение параметра
  double dparam; //!< Значение параметра с плавающей точкой
  int	   imin; //!< Минимальное допустимое значение параметра
  int	   imax; //!< Максимальное допустимое значение параметра
  double   dmin; //!< Минимальное допустимое значение параметра
  double   dmax; //!< Максимальное допустимое значение параметра
  char name[20]; //!< Название параметра (20 знаков, включая завершающий 0)
};
typedef struct RTCPARAMETR* LPRTCPARAMETR; //!< Объявление указателя на RTCPARAMETR

//! Контроллер параметра, управляемого на лету
//! \sa RTCPARAMETR RTCWDATA
struct RTCONTROL
{
  DWORD      flags; //!< Флаги
  int       iparam; //!< Целочисленное значение параметра
  double    dparam; //!< Значение параметра с плавающей точкой
  double       dTi; //!< Для поддержки параметра тактовых импульсов
  void      *param; //!< Адрес значения параметра
  double dparamOld; //!< Предыдущее значение параметра (для поддержки динамического изменения)
  int         ypos; //!< Размер по вертикали 22(свернут), 48(без кнопок), 64(с кнопками)
  double     fmult; //!< Коэффициент, участвующий в вычислении приращения
  double      dmax; //!< Максимальное допустимое значение параметра
  double      dmin; //!< Минимальное допустимое значение параметра
  int         imax; //!< Максимальное допустимое значение параметра
  int         imin; //!< Минимальное допустимое значение параметра
  HWND      stName; //!< Дескриптор плоской кнопки
  HWND         trW; //!< Дескриптор ползунка
  HWND         ed1; //!< Дескриптор первого окна ввода
  HWND         ed2; //!< Дескриптор второго окна ввода (если есть)
  HWND        edTi; //!< Дескриптор вывода символьной скорости (для соответствующего контроллера)
};
typedef struct RTCONTROL *LPRTCONTROL; //!< Объявление указателя на RTCONTROL

//! Окно с контроллерами управления параметрами на лету (для устройства)
//! \sa RTCPARAMETR RTCONTROL
struct RTCWDATA
{
  DWORD        flags; //!< Флаги
  HWND          hwnd; //!< Дескриптор окна управления
  int           xpos; //!< Ширина окна управления
  int           ymin; //!< Размер свернутого окна управления
  int           ymax; //!< Размер развернутого окна управления
  int        indxDev; //!< Индекс устройства, к которому принадлежит контроллер
  int    nOfControls; //!< Количество контроллеров в окне
  char     coord[32]; //!< Текстовое отображение координат устройства
  char     title[32]; //!< Название окна
  HWND    rtchwnd[5]; //!< Массив дескрипторов контроллеров (5 и менее)
  HWND*    lprtchwnd; //!< Массив дескрипторов контроллеров (больше пяти - совместимость обеспечена v.2.2.1.93)
  LPRTCPARAMETR rtcp; //!< Указатель на массив параметров (количество не ограничено, лишь бы помещались на экране)
  int   currentfocus; //!< Информация о контроллере, имеющем фокус ввода
};
typedef struct RTCWDATA *LPRTCWDATA; //!< Объявление указателя на RTCWDATA

//! Структура описания пина девайса
//! \sa DEVPROP DEVPROPSAVE
struct DEVPIN
{
  union {
    float                f_in; //!< Временной вход
    LPSPECTR            sp_in; //!< Спектральный вход
    LPCOMPLEXF          rj_in; //!< Комплексный вход
    DWORD               dw_in; //!< Битовый (целочисленный) вход
    float              *f_out; //!< Временной выод
    LPSPECTR          *sp_out; //!< Спектральный выход
    LPCOMPLEXF        *rj_out; //!< Комплексный выход
    DWORD             *dw_out; //!< Битовый (целочисленный) выход
    DWORD               dwpin; //!< Для преобразования типов
    LPVOID              lppin; //!< Для преобразования типов
  };
  BYTE                 depend; //!< Зависимость
  BYTE                    ver; //!< Версия
  signed short int dependindx; //!< Индекс устройства, от которого зависит
  signed short int    conindx; //!< Индекс соединения в котором участвует
  BYTE                   type; //!< Тип пина (временной, комплексный, спектральный, битовый)
  BYTE                  flags; //!< Флаги (0x02 - независимый, может организовать обратную связь)
  char            pinname[32]; //!< Имя пина
  char        shortpinname[8]; //!< Короткое имя пина
  DWORD     *AddressOfRealPin; //!< Реальный адрес (для 2-й версии)
};
typedef struct DEVPIN *LPDEVPIN; //!< Указатель на DEVPIN

// Флаги для типов пина ///////
#define PINF_FEEDBACK 0x02 //!< Вход не зависим (может организовать обратную связь)

//! Структура свойств и параметров устройства
//! \sa DEVPIN DEVPROPSAVE
struct DEVPROP
{
  DWORD flags;            //!< Флаги
  DWORD type;             //!< Тип устройства (номер в массиве saproc)
  WORD  indx;             //!< Место
  BYTE  nIns;             //!< Количество входов
  BYTE  nOuts;            //!< Количество выходов
  union {
    //! Для 1-й версии
    struct {
      BYTE L;             //!< Состояние левого   пина
      BYTE T;             //!< Состояние верхнего пина
      BYTE R;             //!< Состояние правого  пина
      BYTE B;             //!< Состояние нижнего  пина
    };
    LPDEVPIN pins;        //!< Указатель на массив пинов (2-я версия)
  };
  DWORD		bSize;    //!< размер дополнительной структуры параметров в байтах
  //! 1-й вход
  union { 
    float       f_in1;    //!< 1-й вход временной
    LPSPECTR   sp_in1;    //!< 1-й вход спектральный
    LPCOMPLEXF rj_in1;    //!< 1-й вход комплексный
    DWORD      dw_in1;    //!< 1-й вход битовый (целочисленный)
    DWORD        pin1;    //!< 1-й вход (для удобства преобразования типов)
  };
  //! 2-й вход или адрес для 3-го выхода
  union { 
    float         f_in2;  //!< 2-й вход временной
    LPSPECTR     sp_in2;  //!< 2-й вход спектральный
    LPCOMPLEXF   rj_in2;  //!< 2-й вход комплексный
    DWORD        dw_in2;  //!< 2-й вход битовый (целочисленный)
    float       *f_out3;  //!< адрес для 3-го выхода временной
    LPSPECTR   *sp_out3;  //!< адрес для 3-го выхода спектральный
    LPCOMPLEXF *rj_out3;  //!< адрес для 3-го выхода комплексный
    DWORD      *dw_out3;  //!< адрес для 3-го выхода битовый (целочисленный)
    DWORD          pin2;  //!< 2-й вход или адрес для 3-го выхода (для удобства преобразования типов)
  };
  //! 3-й вход или адрес для 2-го выхода
  union {
    float         f_in3;  //!< 3-й вход временной
    LPSPECTR     sp_in3;  //!< 3-й вход спектральный
    LPCOMPLEXF   rj_in3;  //!< 3-й вход комплексный
    DWORD        dw_in3;  //!< 3-й вход битовый (целочисленный)
    float       *f_out2;  //!< адрес для 2-го выхода временной
    LPSPECTR   *sp_out2;  //!< адрес для 2-го выхода спектральный
    LPCOMPLEXF *rj_out2;  //!< адрес для 2-го выхода комплексный
    DWORD      *dw_out2;  //!< адрес для 2-го выхода битовый (целочисленный)
    DWORD          pin3;  //!< 3-й вход или адрес для 2-го выхода (для удобства преобразования типов)
  };
  //! адрес для 1-го выхода
  union { 
    float       *f_out1;  //!< адрес для 1-го выхода временной
    LPSPECTR   *sp_out1;  //!< адрес для 1-го выхода спектральный
    LPCOMPLEXF *rj_out1;  //!< адрес для 1-го выхода комплексный
    DWORD      *dw_out1;  //!< адрес для 1-го выхода битовый (целочисленный)
    DWORD          pin4;  //!< адрес для 1-го выхода (для удобства преобразования типов)
  };
  LPVOID             lpp; //!< Адрес дополнительной структуры с параметрами, подлежащими сохранению в файле
  LPVOID             lpw; //!< Адрес для работы устройства
  USERTAKT_PROC userproc; //!< Адрес тактовой процедуры на ЯВУ
  DLL_PROC      taktproc; //!< Адрес тактовой процедуры на ассемблере
  LPVOID             dpi; //!< Адрес следующего устройства в потоке
  DWORD            sysp1; //!< Системный параметр
  DWORD            sysp2; //!< Системный параметр
};
typedef struct DEVPROP *LPDEVPROP; //!< Указатель на DEVPROP
//! Макрос для обращения ко входным пинам в точке SAFUN_INITPINS
#define  INPIN(macro_number,macro_dp)      ((macro_dp)->pins[(macro_number)])
//! Макрос для обращения к выходным пинам в точке SAFUN_INITPINS
#define OUTPIN(macro_number,macro_dp)      ((macro_dp)->pins[(macro_number)+1+(macro_dp)->nIns])

//! Структура для устройств, работающих с файлами
struct TFILEINFO
{
  DWORD	flags;    //!< Флаги
  char	fn[260];  //!< Имя файла
};
typedef struct TFILEINFO *LPTFILEINFO; //!< Указатель на TFILEINFO

//! Параметры системы
struct SYSPARAM
{
  DWORD    flags; //!< Флаги системы
  DWORD       Nf; //!< Всего отсчетов в системе
  DWORD        N; //!< Размер пачки
  DWORD        h; //!< Разрядность АЦП (глобальная)
  DWORD      cnt; //!< Счетчик в пределах текущей пачки
  DWORD   curcnt; //!< Текущий отсчет в системе ( 0 -- 0xffffffff ) 
  double      dT; //!< Период дискретизации
  LPCOMPLEXF SCC; //!< Нужно для БПФ-ОБПФ
  DWORD *XchIndx; //!< Нужно для БПФ-ОБПФ
  HWND       hWS; //!< Дескриптор окна рабочей области
  BYTE      maxh; //!< Размер по ширине в ячейках
  BYTE      maxv; //!< Размер по высоте в ячейках
  BYTE      left; //!< Горизонтальная координата левого верхнего устройства в ячейках
  BYTE       top; //!< Вертикальная координата левого верхнего устройства в ячейках
};
typedef struct SYSPARAM *LPSYSPARAM; //!< Указатель на SYSPARAM
// Флаги работы системы
//! Система скомпилирована и запущена, но может
//! находиться в режиме паузы, пошаговом режиме
//! или работать в нити (F5)
#define SYSPF_START    0x00000001
#define SYSPF_WORK     0x00000002 //!< Основной режим
#define SYSPF_STEP     0x00000004 //!< Пошаговый режим
#define SYSPF_WORK_ALL 0x00000007 //!< Объединение для удобства
#define SYSPF_WHITE    0x00000008 //!< Графические устройства с белым фоном
#define SYSPF_CELLSIZE 0x00000070 //!< Три бита для описания размера ячейки 0-4 (48,64,80,96,112 пикс.)

//! Имя пинов для 1-ой версии
struct PINNAMES
{
  DWORD        InOut; //!< Флаг ( 0-входы, 1-выходы)
  union {
    struct {
      char  pin1[32]; //!< Имя пеового в(ы)хода
      char  pin2[32]; //!< Имя второго в(ы)хода
      char  pin3[32]; //!< Имя третьего в(ы)хода
    };
    char pins[3][32]; //!< Имена в(ы)ходов (для удобства)
  };
};
typedef struct PINNAMES *LPPINNAMES; //!< Указатель на PINNAMES

#include <adcfileheader.h>

//! Тип процедуры устройства
typedef DWORD (__stdcall *SA_PROC)(DWORD flag, HWND hwnd, LPDEVPROP dp);
//! Тип тактовой процедуры устройства на ЯВУ
typedef DWORD (__stdcall *TAKT_PROC)(LPDEVPROP dp);
//! Тип процедуры получения информации о пользовательской библиотеке
typedef DWORD (__stdcall *DEVDLLINFO_PROC)(char*);
//! Тип процедуры получения устройств из пользовательской библиотеки
typedef DWORD (__stdcall *GETDEVICES_PROC)(int,LPSYSPARAM,SA_PROC*,HIMAGELIST);


#ifdef __cplusplus
extern "C" {
#endif

//! Получить информацию о библиотеке
//! \param[out] info Адрес строки текста
//! \return Количество устройств, содержащихся в библиотеке
DWORD __stdcall devGetDllInfo( char* info );
//! Получить устройства из библиотеки
//! \param n0 Индекс для первого (нулевого) устройства
//! \param sysp Адрес структуры с параметрами системы
//! \param saproc Адрес массива процедур устройств, в который нужно прописать адреса своих процедур
//! \param himl Дескриптор массива иконок, в который нужно добавить свои иконки
//! \return ненулевое значение означает корректное завершение, нулевое - сбой
DWORD __stdcall devGetDevices(int n0,LPSYSPARAM sysp,SA_PROC* saproc,HIMAGELIST himl);

#ifdef __cplusplus
};
#endif

//! Макро для получения такта (лучше пользоваться dsp::BitData )
#define BIT_IS_TACT(a)  (( (a) >> 31 ) & 1)
//! Макро для получения количества бит (лучше пользоваться dsp::BitData )
#define BIT_NUMBER(a)   ( ((a) & 0x1F000000) >> 24 )
//! Макро для получения бит (лучше пользоваться dsp::BitData )
#define BIT_GETBITS(a)  ( (a) & ((1 << ( ((a) & 0x1F000000) >> 24 )) - 1))

#pragma pack(pop)

#endif //_USER_DEV_H
