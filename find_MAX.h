#pragma once
#include <spectr2/basedevice.h>
#include <user_dev.h>


extern HINSTANCE hInst; // ���������� ������ ��������� ��� ������ ��������
extern LPSYSPARAM sysp; // ��������� �� ��������� �������


void  __stdcall tact_MAX(LPDEVPROP);//�������� ������� 

namespace Spectr2 {

	//! ��������� ���������� 
	struct MAXPARAM
	{
	};
	typedef MAXPARAM* LPMAXPARAM; //!< ��������� 

	//! ������� ��������� 
	struct MAXWORK
	{
	};
	typedef MAXWORK* LPMAXWORK; //!< ��������� 

	 //! ����������� ����� ��� ����������
	class MAXDev : public DeviceBase
	{
	public:

		//! ������� �������������
		virtual DWORD init(HWND hwnd)
		{
			LPMAXPARAM b = static_cast<LPMAXPARAM>(init_device(sizeof(MAXPARAM), 2, 1)); // 2 �����, 1 �����
			return 1;
		}

		//! ������� ������
		virtual DWORD start(DWORD pin)
		{
			if (!get_work_ptr()) {
				LPMAXPARAM mp = static_cast<LPMAXPARAM>(get_data_ptr()); //��������� ����������
				//set_work_ptr(aw); // ���������� ������� ���������
				set_tact_proc(tact_MAX);// ������������� �������� ���������

			}
			return 1;
		}

		//! ������� ����
		virtual void stop(HWND hwnd)
		{

		}


		//��� ������, ������� ������������ � ������ �����.
		virtual void get_name(char* name) { set_name(name, "������������ ������"); }
		//!��������� ���� ������(��� �� ����� ������) �������������� (���������) �����, ������
		virtual DWORD get_type() { return (DBDEV_ROOT_TIME | DBDEV_TIME_OTHER); }

		//! ������������� �����(�����) 2 ������� � 1 �������� ���,(�����, ���, ��������)
		virtual void init_pins(LPDEVPIN in, LPDEVPIN out)
		{
			init_pin(in[1], SADF_TIME, "���� 1", "", 2);
			init_pin(in[2], SADF_TIME, "���� 2", "", 2);
			init_pin(out[1], SADF_TIME, "�����", 0, 2);
		}

		//! ������ ������� �� ������ � ������� �������. ����� ���� � �������.
		virtual void help(HWND hwnd)
		{
			MessageBox(hwnd, "������������ ������ �5",
				"", MB_OK | MB_ICONINFORMATION);
		}
	};
}

