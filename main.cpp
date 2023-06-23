#include "Find_MAX.h"

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
	strcpy(info, "���������� � ����������� ���������� ����. �������");
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
	devs[0] = new MAXDev;

	return 1;
}

void  __stdcall tact_MAX(LPDEVPROP dp)//�������� ������� 
{
	LPMAXPARAM lpp = static_cast<LPMAXPARAM> (dp->lpp);
	if (dp->pins[1].f_in > dp->pins[2].f_in)
		* dp->pins[4].f_out = dp->pins[1].f_in;
	else *dp->pins[4].f_out = dp->pins[2].f_in;
}
