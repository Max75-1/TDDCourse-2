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
	TEST_ASSERT_FALSE(USBDriver_Connected());

	serial_init_Expect(&USBDriver_serial, USBTX, USBRX);
	serial_clear_Expect(&USBDriver_serial);

	Buffer_Init_ExpectAndReturn(&tx, tx_data, USB_BUFFER_MAX, STATUS_OK);
	Buffer_Init_ExpectAndReturn(&rx, rx_data, USB_BUFFER_MAX, STATUS_OK);

	USBDriver_Init();

	TEST_ASSERT_TRUE(USBDriver_Connected());
}

void test_USBDriver_Exec_should_DoNothing_when_NothingToWrite_and_NothingToRead(void)
{
	Buffer_IsEmpty_ExpectAndReturn(&tx, TRUE);
	serial_readable_ExpectAndReturn(&USBDriver_serial, FALSE);

	USBDriver_Exec();
}

void test_USBDriver_Exec_should_DoNothing_when_TooFullToWrite_and_TooFullToRead(void)
{
	serial_writable_ExpectAndReturn(&USBDriver_serial, FALSE);
	Buffer_IsEmpty_ExpectAndReturn(&rx, TRUE);

	USBDriver_Exec();
}
