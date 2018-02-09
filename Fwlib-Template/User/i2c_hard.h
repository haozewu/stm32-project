#ifndef __I2C_HARD_H
#define	__I2C_HARD_H


#include "stm32f10x.h"


/**************************I2C参数定义，I2C1或I2C2********************************/
#define             I2Cx_Hard                                I2C1
//#define             I2C_APBxClock_FUN                   RCC_APB1PeriphClockCmd
#define             I2C_CLK                             RCC_APB1Periph_I2C1
//#define             I2C_GPIO_APBxClock_FUN              RCC_APB2PeriphClockCmd
#define             I2C_GPIO_CLK                        RCC_APB2Periph_GPIOB     
#define             I2C_SCL_PORT                        GPIOB   
#define             I2C_SCL_PIN                         GPIO_Pin_6
#define             I2C_SDA_PORT                        GPIOB 
#define             I2C_SDA_PIN                         GPIO_Pin_7



/* STM32 I2C 快速模式 */
#define I2C_Speed              400000  //*

/* 这个地址只要与STM32外挂的I2C器件地址不一样即可 */
#define I2Cx_OWN_ADDRESS7      0X0A   


/*等待超时时间*/
#define I2CT_FLAG_TIMEOUT         ((uint32_t)0x1000)
#define I2CT_LONG_TIMEOUT         ((uint32_t)(10 * I2CT_FLAG_TIMEOUT))


/*信息输出*/
#define EEPROM_DEBUG_ON  0

#define I2C_INFO(fmt,arg...)           printf("<<-EEPROM-INFO->> "fmt"\n",##arg)
#define I2C_ERROR(fmt,arg...)          printf("<<-EEPROM-ERROR->> "fmt"\n",##arg)
#define I2C_DEBUG(fmt,arg...)          do{\
                                          if(EEPROM_DEBUG_ON)\
                                          printf("<<-EEPROM-DEBUG->> [%d]"fmt"\n",__LINE__, ##arg);\
                                          }while(0)


uint32_t I2C_Read_FromRegister(u8* pBuffer, uint16_t ADDR,u8 ReadAddr, u16 NumByteToRead);
uint32_t I2C_ByteWrite_ToRegister(u8* pBuffer, uint16_t ADDR ,u8 WriteAddr) ;
void I2C_Hard_Conf(void);



#endif 


