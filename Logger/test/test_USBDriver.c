#include "unity.h"
#include "mock_Buffer.h"
#include "mock_serial_api.h"
#include "USBDriver.h"

void setUp(void)
{
}

void tearDown(void)
{
}

/*void test_USBDriver_NeedToImplement(void)
{
    TEST_IGNORE_MESSAGE("Need to Implement USBDriver");
}*/

void test_USBDriver_Init_should_InitTheBuffers_and_ConfigureTheSerialPort(void)
{
	Buffer_Init_ExpectAndReturn(&tx, tx_data, USB_BUFFER_MAX, STATUS_OK);
	Buffer_Init_ExpectAndReturn(&rx, rx_data, USB_BUFFER_MAX, STATUS_OK);

	serial_init_Expect(&USBDriver_serial, USBTX, USBRX);
	serial_clear_Expect(&USBDriver_serial);

	USBDriver_Init();
}
