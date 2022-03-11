#include "unity.h"
#include "LED.h"

void test_LED_Init_Should_SetLEDsAsGPIO(void)
{
	LED_PINSEL=BIT_TO_MASK(LED_0_BIT) | BIT_TO_MASK(LED_1_BIT) | BIT_TO_MASK(LED_2_BIT) | BIT_TO_MASK(LED_3_BIT);

	LED_Init();

	TEST_ASSERT_EQUAL_HEX32( 0xFFFF30CF,LED_PINSEL);
}

void test_LED_Init_Should_SetLEDsToEnableIO(void)
{
	LED_PORT->FIOMASK= BIT_TO_MASK(LED_0_BIT) | BIT_TO_MASK(LED_1_BIT) | BIT_TO_MASK(LED_2_BIT) | BIT_TO_MASK(LED_3_BIT);

	LED_Init();

	TEST_ASSERT_EQUAL_HEX32( 0xFF4BFFFF,LED_PORT->FIOMASK);
}

void test_LED_Init_Should_SetLEDsASOutputs(void)
{
	LED_PORT->FIODIR= ~(BIT_TO_MASK(LED_0_BIT) | BIT_TO_MASK(LED_1_BIT) | BIT_TO_MASK(LED_2_BIT) | BIT_TO_MASK(LED_3_BIT) );

	LED_Init();

	TEST_ASSERT_EQUAL_HEX32( 0xB40000,LED_PORT->FIODIR);
}

void test_LED_Init_Should_SetPulldownsForTheseLEDs(void)
{
	LED_PINMODE = LED_PIN_BIT(LED_0_BIT) | LED_PIN_BIT(LED_1_BIT) | LED_PIN_BIT(LED_2_BIT) | LED_PIN_BIT(LED_3_BIT);

	LED_Init();

	TEST_ASSERT_EQUAL_HEX32( 0xFFFF30CF,LED_PINMODE);
}

void test_LED_Init_Should_SetHighLED1AndSetLowOtherLEDs(void)
{
	LED_PORT->FIOSET= ~BIT_TO_MASK(LED_0_BIT);
	LED_PORT->FIOCLR= ~( BIT_TO_MASK(LED_1_BIT) | BIT_TO_MASK(LED_2_BIT) | BIT_TO_MASK(LED_3_BIT) );

	LED_Init();

	TEST_ASSERT_EQUAL_HEX32(0x40000,LED_PORT->FIOSET);
	TEST_ASSERT_EQUAL_HEX32(0xB00000,LED_PORT->FIOCLR);
}

void test_LED_Toggle_should_ToggleTheCorrectOutput(void)
{
	TEST_IGNORE_MESSAGE("Implement LED_Toggle");
}

void test_LED_On_should_EnableTheCorrectOutput(void)
{
	TEST_IGNORE_MESSAGE("Implement LED_On");
}

void test_LED_Off_should_DisableTheCorrectOutput(void)
{
	TEST_IGNORE_MESSAGE("Implement LED_Off");
}

