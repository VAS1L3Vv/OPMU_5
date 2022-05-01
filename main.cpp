#include "SigDivHeader.h"

using namespace Spectr2;

#define DEVS_MAX 1 //!< ������� �������� ���������� ��������� � ����������

// ���������� ����������
HINSTANCE hInst; // ���������� ������
LPSYSPARAM sysp; // ��������� �� ��������� �������

// ������� ����� ����������. ���������� Windows'��
//#pragma argsused
BOOL WINAPI  DllMain(HINSTANCE hDLL, DWORD dwReason, LPVOID)
{
    switch (dwReason) {
    case DLL_PROCESS_ATTACH:
        hInst = hDLL; // �������� ��� ����������.
                      // ���� ����������� ��� ��� ������������� ����������,
                      // ����, �������, �� ��� ���������
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        // ����� ������������ ������� ��� ������������ ��������.

        // ���� ����������� ��� ��� ��������������� ����������,
        // ����, �������, �� ��� ���������
        break;
    }
    return TRUE;
}


DWORD __stdcall
devGetDllInfo(char* info)
{
    strcpy(info, "���������� � ����������� ������������ ������ �5");
    return DEVS_MAX; // ���������� �������� DEVS_MAX ���������
}

DWORD __stdcall
devGetDevices(int n0,          // ������ ������� ���������� (�������� �� �������� ���������)
    LPSYSPARAM _sysp,// ��������� �� ��������� ������� (��� ����� ��� ���� ���������)
    SA_PROC* saproc, // ��������� �� �������� ������ �������� ���������
    HIMAGELIST himl  // ����� ������ ���� ���������
)
{
    int i;

    // ����� ������� ������������� ������� ���������
    lpDeviceBase* devs = init_base_device(n0, DEVS_MAX, saproc);

    sysp = _sysp; // �������� ��������� ����������� �������

                  // ��������� ������ ���������� �� ������� ���������� ����� ��������� �� 
                  // ����������� ������.
    devs[0] = new DIVDev;

    return 1;
}

void  __stdcall tact_DIV(LPDEVPROP dp)//�������� ������� 
{
    LPDIVPARAM lpp = static_cast<LPDIVPARAM> (dp->lpp);
    *dp->pins[4].f_out = dp->pins[1].f_in;
    *dp->pins[5].f_out = dp->pins[2].f_in / lpp->CONST_DIV;
}