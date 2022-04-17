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
	serial_writable_IgnoreAndReturn(TRUE);
	Buffer_IsEmpty_IgnoreAndReturn(TRUE);
	Buffer_IsFull_IgnoreAndReturn(FALSE);
	serial_readable_IgnoreAndReturn(FALSE);

	USBDriver_Exec();
}

void test_USBDriver_Exec_should_DoNothing_when_TooFullToWrite_and_TooFullToRead(void)
{
	serial_writable_IgnoreAndReturn(FALSE);
	Buffer_IsEmpty_IgnoreAndReturn(FALSE);
	Buffer_IsFull_IgnoreAndReturn(TRUE);
	serial_readable_IgnoreAndReturn(TRUE);

	USBDriver_Exec();
}

void test_USBDriver_Exec_should_WriteAByte_when_OneBufferedAndWritable(void)
{
uint8_t test_char='$';

	serial_writable_IgnoreAndReturn(TRUE);
	Buffer_IsEmpty_IgnoreAndReturn(FALSE);
	Buffer_IsFull_IgnoreAndReturn(TRUE);
	serial_readable_IgnoreAndReturn(TRUE);

	Buffer_Get_ExpectAnyArgsAndReturn(STATUS_OK);
	Buffer_Get_ReturnThruPtr_Val(&test_char);
	serial_putc_Expect(&USBDriver_serial, test_char);

	//Buffer_Get_ExpectAnyArgsAndReturn(STATUS_NONE_YET);

	USBDriver_Exec();
}

void test_USBDriver_Exec_should_NotWriteAByte_when_CouldNotFetchByte(void)
{
//uint8_t test_char='$';

	serial_writable_IgnoreAndReturn(TRUE);
	Buffer_IsEmpty_IgnoreAndReturn(FALSE);
	Buffer_IsFull_IgnoreAndReturn(TRUE);
	serial_readable_IgnoreAndReturn(TRUE);

	Buffer_Get_ExpectAnyArgsAndReturn(STATUS_NONE_YET);
	//Buffer_Get_ReturnThruPtr_Val(&test_char);
	//serial_putc_Expect(&USBDriver_serial, test_char);

	USBDriver_Exec();
}

void test_USBDriver_Exec_should_WriteBytes_when_BytesBufferedAndWritable(void)
{
    uint8_t a = 'A';
    uint8_t b = 'B';
    //uint8_t c = 'C';

    //The first time through the loop, we have a character
    serial_writable_IgnoreAndReturn(TRUE);
    Buffer_IsEmpty_IgnoreAndReturn(FALSE);
    Buffer_Get_ExpectAnyArgsAndReturn(STATUS_OK);
    Buffer_Get_ReturnThruPtr_Val(&a);
    serial_putc_Expect(&USBDriver_serial, a);

    Buffer_IsFull_IgnoreAndReturn(TRUE);
    serial_readable_IgnoreAndReturn(TRUE);

    USBDriver_Exec();

    //The second time through the loop, we have a character
    serial_writable_IgnoreAndReturn(TRUE);
    Buffer_IsEmpty_IgnoreAndReturn(FALSE);
    Buffer_Get_ExpectAnyArgsAndReturn(STATUS_OK);
    Buffer_Get_ReturnThruPtr_Val(&b);
    serial_putc_Expect(&USBDriver_serial, b);

    Buffer_IsFull_IgnoreAndReturn(TRUE);
    serial_readable_IgnoreAndReturn(TRUE);

    USBDriver_Exec();

    //The third time through the loop, we have a character
    /*serial_writable_IgnoreAndReturn(TRUE);
    Buffer_IsEmpty_IgnoreAndReturn(FALSE);
    Buffer_Get_ExpectAnyArgsAndReturn(STATUS_OK);
    Buffer_Get_ReturnThruPtr_Val(&c);
    serial_putc_Expect(&USBDriver_serial, c);*/

    //The fourth time through the loop, we don't have a character any longer
    Buffer_IsEmpty_IgnoreAndReturn(TRUE);

    USBDriver_Exec();
}
