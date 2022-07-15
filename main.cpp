#include<ntifs.h>
#include<ntddk.h>
#include<wdm.h>
#include<intrin.h>

#define COM1_PORT   0x03f8
#define COM2_PORT   0x02f8
#define COM3_PORT   0x03e8
#define COM4_PORT   0x02e8

template<typename... types>
void print(types... args)
{
	DbgPrintEx(DPFLTR_DEFAULT_ID, DPFLTR_ERROR_LEVEL, args...);
}

void unload(PDRIVER_OBJECT drv) {
	return;
}

extern "C" NTSTATUS DriverEntry(PDRIVER_OBJECT drv, PUNICODE_STRING reg) {
	NTSTATUS Status = STATUS_SUCCESS;
	
	drv->DriverUnload = unload;

	while (1) {
		UCHAR t = __inbyte(COM1_PORT);
		if (t != 0) {
			print("[-]find kd\n");
		}
		YieldProcessor();  //_mm_pause
	}
	return Status;
}
