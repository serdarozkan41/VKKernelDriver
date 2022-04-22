#include "Driver.h"
#include "Device.h"

#include <hidport.h>

_Use_decl_annotations_
NTSTATUS
DriverEntry(
	PDRIVER_OBJECT     driverObject,
	PUNICODE_STRING    registryPath)
{
	UNREFERENCED_PARAMETER(driverObject);
	UNREFERENCED_PARAMETER(registryPath);

	NTSTATUS                status = STATUS_SUCCESS;
	WDF_DRIVER_CONFIG       config;

	KdPrintEx((DPFLTR_IHVDRIVER_ID, DPFLTR_INFO_LEVEL, "KmdfHelloWorld: DriverEntry\n"));


	WDF_DRIVER_CONFIG_INIT(&config, DriverEvtDeviceAdd);



	return status;



	/* status = WdfDriverCreate(driverObject, registryPath, WDF_NO_OBJECT_ATTRIBUTES, &config, WDF_NO_HANDLE);

	 return status;*/


}

_Use_decl_annotations_
NTSTATUS
DriverEvtDeviceAdd(
	_In_ WDFDRIVER            driver,
	_Inout_ PWDFDEVICE_INIT   deviceInit)
{
	UNREFERENCED_PARAMETER(driver);
	return DeviceCreate(deviceInit);
}


