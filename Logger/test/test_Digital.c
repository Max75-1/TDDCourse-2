/*#include "unity.h"
#include "Digital.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_Digital_Init_should_InitializeBitsForReading(void)
{
	Digital_Init();

	// Digital I/O are inputs ?
	TEST_ASSERT_EQUAL_HEX32(0x0,DIGITAL_PORT->FIODIR);

	//Digital I/O are GPIO ?
	TEST_ASSERT_EQUAL_HEX32(0x0,DIGITAL_PINSEL);

	// All inputs are pulldowns ?
	TEST_ASSERT_EQUAL_HEX32(0x00000FFF,DIGITAL_PINMODE);

    //TEST_IGNORE_MESSAGE("Need to Implement Digital_Init");
}

void test_Digital_GetBits_should_ReadDigitalInputsAndReturnCurrentValues(void)
{
	 LPC_GPIO2->FIOPIN = 0xFFFFFFFF;

	 TEST_ASSERT_EQUAL_HEX(0x0000003F, Digital_GetBits());

	//TEST_IGNORE_MESSAGE("Implement Digital_GetBits");
}*/
