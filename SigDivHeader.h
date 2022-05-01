#pragma once
#include <spectr2/basedevice.h>
#include <user_dev.h>


extern HINSTANCE hInst; // ���������� ������ ��������� ��� ������ ��������
extern LPSYSPARAM sysp; // ��������� �� ��������� �������


void  __stdcall tact_DIV(LPDEVPROP);//�������� ������� 

namespace Spectr2 {

    //! ��������� ���������� 
    struct DIVPARAM
    {
        float CONST_DIV = 2;
    };
    typedef DIVPARAM* LPDIVPARAM; //!< ��������� 

    //! ������� ���������. ��� ������ ����� ���������� ���. ��������� ������ �� ���������.
    struct DIVWORK
    {
    };
    typedef DIVWORK* LPDIVWORK; //!< ��������� 

     //! ����������� ����� ��� ����������
    class DIVDev : public DeviceBase
    {
    public:

        //! ������� �������������
        virtual DWORD init(HWND hwnd)
        {
            LPDIVPARAM div = static_cast<LPDIVPARAM>(init_device(sizeof(DIVPARAM), 2, 2)); // ������� 2 ����� � 2 ������
            div->CONST_DIV = 2;
            return 1;
        }

        //! ������� ������
        virtual DWORD start(DWORD pin)
        {
            if (!get_work_ptr()) {
                LPDIVPARAM mp = static_cast<LPDIVPARAM>(get_data_ptr()); //��������� ����������

                mp->CONST_DIV = 2;
                //set_work_ptr(aw); // ���������� ������� ���������
                set_tact_proc(tact_DIV);// ������������� �������� ���������

            }
            return 1;
        }

        //! ������� ����
        virtual void stop(HWND hwnd)
        {

        }


        //��� ������, ������� ������������ � ������ �����.
        virtual void get_name(char* name) { set_name(name, "Sig_Divider"); }
        //!��������� ���� ������(��� �� ����� ������) �������������� (���������) �����, ������
        virtual DWORD get_type() { return (DBDEV_ROOT_TIME | DBDEV_TIME_OTHER); }

        //! ������������� �����(�����) 1 ������� � 1 �������� ���,(�����, ���, ��������)
        virtual void init_pins(LPDEVPIN in, LPDEVPIN out) 
            /* ��� ��������� ������ ����������
            �� ������ ���� ���� - ����� ���������� ������ �� ������������ ���������.
            � ������ ���� ����-����� ����� ������� ������ �� ��������� � �������� ��� �� �����.
            ��. �� ����������� ����������� ������(������) � ������������(�������) */ 
        {
            init_pin(in[1], SADF_TIME, "����1: ����� ByPass", "ByPass", 2);
            init_pin(out[1], SADF_TIME, "�����1: ������������ ������", 0, 2);
            init_pin(in[2], SADF_TIME, "����2: ��������", "��������", 2);
            init_pin(out[2], SADF_TIME, "�����2: ��������", 0, 2);
        }

        //! ������ ������� �� ������ � ������� �������. ����� ���� � �������.
        virtual void help(HWND hwnd)
        {
            MessageBox(hwnd, "������������ ������ �5",
                "", MB_OK | MB_ICONINFORMATION);
        }
    }; 
}
