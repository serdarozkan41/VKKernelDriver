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
	KdPrintEx((0, 0, "[Loaded] Driver has been loaded!"));

	return STATUS_SUCCESS;

	// For Map
	/*
	NTSTATUS                status = STATUS_SUCCESS;
	WDF_DRIVER_CONFIG       config;

	WDF_DRIVER_CONFIG_INIT(&config, DriverEvtDeviceAdd);

	status = WdfDriverCreate(driverObject, registryPath, WDF_NO_OBJECT_ATTRIBUTES, &config, WDF_NO_HANDLE);

	return status;
	*/
}

_Use_decl_annotations_
NTSTATUS
SpecialDriverEntry(
	PDRIVER_OBJECT     driverObject,
	PUNICODE_STRING    registryPath)
{

	// For Map
	
	NTSTATUS                status = STATUS_SUCCESS;
	WDF_DRIVER_CONFIG       config;

	WDF_DRIVER_CONFIG_INIT(&config, DriverEvtDeviceAdd);

	status = WdfDriverCreate(driverObject, registryPath, WDF_NO_OBJECT_ATTRIBUTES, &config, WDF_NO_HANDLE);

	return status;
	
}

_Use_decl_annotations_
NTSTATUS
DriverEvtDeviceAdd(
	_In_ WDFDRIVER            driver,
	_Inout_ PWDFDEVICE_INIT   deviceInit)
{
	UNREFERENCED_PARAMETER(driver);
	KdPrintEx((0, 0, "[UnLoaded] Driver has been unloaded!"));
	return DeviceCreate(deviceInit);
}


