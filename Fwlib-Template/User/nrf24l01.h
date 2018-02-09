#ifndef _nrf24l01_H
#define _nrf24l01_H

#include "systick.h"
#include "gpio.h"

//NRF24L01�Ĵ�����������
#define NRF_READ_REG    0x00  //�����üĴ���,��5λΪ�Ĵ�����ַ
#define NRF_WRITE_REG   0x20  //д���üĴ���,��5λΪ�Ĵ�����ַ

#define READ_REG_CMD        	0x00  		// ����С����
#define WRITE_REG_CMD       	0x20 		// ����С����

#define RD_RX_PLOAD     0x61  //��RX��Ч����,1~32�ֽ�
#define WR_TX_PLOAD     0xA0  //дTX��Ч����,1~32�ֽ�
#define FLUSH_TX        0xE1  //���TX FIFO�Ĵ���.����ģʽ����
#define FLUSH_RX        0xE2  //���RX FIFO�Ĵ���.����ģʽ����
#define REUSE_TX_PL     0xE3  //����ʹ����һ������,CEΪ��,���ݰ������Ϸ���.
#define NOP             0xFF  //�ղ���,����������״̬�Ĵ���	 
//SPI(NRF24L01)�Ĵ�����ַ
#define CONFIG          0x00  //���üĴ�����ַ;bit0:1����ģʽ,0����ģʽ;bit1:��ѡ��;bit2:CRCģʽ;bit3:CRCʹ��;
                              //bit4:�ж�MAX_RT(�ﵽ����ط������ж�)ʹ��;bit5:�ж�TX_DSʹ��;bit6:�ж�RX_DRʹ��
#define EN_AA           0x01  //ʹ���Զ�Ӧ����  bit0~5,��Ӧͨ��0~5
#define EN_RXADDR       0x02  //���յ�ַ����,bit0~5,��Ӧͨ��0~5
#define SETUP_AW        0x03  //���õ�ַ����(��������ͨ��):bit1,0:00,3�ֽ�;01,4�ֽ�;02,5�ֽ�;
#define SETUP_RETR      0x04  //�����Զ��ط�;bit3:0,�Զ��ط�������;bit7:4,�Զ��ط���ʱ 250*x+86us
#define RF_CH           0x05  //RFͨ��,bit6:0,����ͨ��Ƶ��;
#define RF_SETUP        0x06  //RF�Ĵ���;bit3:��������(0:1Mbps,1:2Mbps);bit2:1,���书��;bit0:�������Ŵ�������
#define STATUS          0x07  //״̬�Ĵ���;bit0:TX FIFO����־;bit3:1,��������ͨ����(���:6);bit4,�ﵽ�����ط�
                              //bit5:���ݷ�������ж�;bit6:���������ж�;
#define MAX_TX  		0x10  //�ﵽ����ʹ����ж�
#define TX_OK   		0x20  //TX��������ж�
#define RX_OK   		0x40  //���յ������ж�

#define TX_DS					0x20	// ����С����
#define RX_DR					0x40		// ����С����
#define MAX_RT					0x10		// ����С����

#define OBSERVE_TX      0x08  //���ͼ��Ĵ���,bit7:4,���ݰ���ʧ������;bit3:0,�ط�������
#define CD              0x09  //�ز����Ĵ���,bit0,�ز����;
#define RX_ADDR_P0      0x0A  //����ͨ��0���յ�ַ,��󳤶�5���ֽ�,���ֽ���ǰ
#define RX_ADDR_P1      0x0B  //����ͨ��1���յ�ַ,��󳤶�5���ֽ�,���ֽ���ǰ
#define RX_ADDR_P2      0x0C  //����ͨ��2���յ�ַ,����ֽڿ�����,���ֽ�,����ͬRX_ADDR_P1[39:8]���;
#define RX_ADDR_P3      0x0D  //����ͨ��3���յ�ַ,����ֽڿ�����,���ֽ�,����ͬRX_ADDR_P1[39:8]���;
#define RX_ADDR_P4      0x0E  //����ͨ��4���յ�ַ,����ֽڿ�����,���ֽ�,����ͬRX_ADDR_P1[39:8]���;
#define RX_ADDR_P5      0x0F  //����ͨ��5���յ�ַ,����ֽڿ�����,���ֽ�,����ͬRX_ADDR_P1[39:8]���;
#define TX_ADDR         0x10  //���͵�ַ(���ֽ���ǰ),ShockBurstTMģʽ��,RX_ADDR_P0��˵�ַ���
#define RX_PW_P0        0x11  //��������ͨ��0��Ч���ݿ���(1~32�ֽ�),����Ϊ0��Ƿ�
#define RX_PW_P1        0x12  //��������ͨ��1��Ч���ݿ���(1~32�ֽ�),����Ϊ0��Ƿ�
#define RX_PW_P2        0x13  //��������ͨ��2��Ч���ݿ���(1~32�ֽ�),����Ϊ0��Ƿ�
#define RX_PW_P3        0x14  //��������ͨ��3��Ч���ݿ���(1~32�ֽ�),����Ϊ0��Ƿ�
#define RX_PW_P4        0x15  //��������ͨ��4��Ч���ݿ���(1~32�ֽ�),����Ϊ0��Ƿ�
#define RX_PW_P5        0x16  //��������ͨ��5��Ч���ݿ���(1~32�ֽ�),����Ϊ0��Ƿ�
#define NRF_FIFO_STATUS 0x17  //FIFO״̬�Ĵ���;bit0,RX FIFO�Ĵ����ձ�־;bit1,RX FIFO����־;bit2,3,����
                              //bit4,TX FIFO�ձ�־;bit5,TX FIFO����־;bit6,1,ѭ��������һ���ݰ�.0,��ѭ��;
//////////////////////////////////////////////////////////////////////////////////////////////////////////
//24L01������
#define NRF24L01_CE   PFout(8) //24L01Ƭѡ�ź�
#define NRF24L01_CSN  PFout(9) //SPIƬѡ�ź�	   
#define NRF24L01_IRQ  PDin(3)  //IRQ������������

//24L01���ͽ������ݿ��ȶ���
#define TX_ADR_WIDTH    5   	//5�ֽڵĵ�ַ����
#define RX_ADR_WIDTH    5   	//5�ֽڵĵ�ַ����
#define TX_PLOAD_WIDTH  11  	//32�ֽڵ��û����ݿ���
#define RX_PLOAD_WIDTH  12  	//32�ֽڵ��û����ݿ���
									   	   
u8 TX_ADDRESS[TX_ADR_WIDTH] = {0x34,0x43,0x10,0x10,0x01};	//????????????RX??????????????
u8 RX_ADDRESS[RX_ADR_WIDTH] = {0x34,0x43,0x10,0x10,0x01};

//��������TX_MODE��RX_MODE

//GPIO����
#define NRF_GPIO_CE_CLK              RCC_APB2Periph_GPIOF
#define NRF_GPIO_CE_PORT             GPIOF
#define NRF_GPIO_CE_PIN              GPIO_Pin_8

//GPIO����
#define NRF_GPIO_CSN_CLK              RCC_APB2Periph_GPIOF
#define NRF_GPIO_CSN_PORT             GPIOF
#define NRF_GPIO_CSN_PIN              GPIO_Pin_9

//GPIO����
#define NRF_GPIO_IRQ_CLK              RCC_APB2Periph_GPIOD
#define NRF_GPIO_IRQ_PORT             GPIOD
#define NRF_GPIO_IRQ_PIN              GPIO_Pin_3

#define NRF_EXTI_IRQ          				EXTI3_IRQn
#define NRF_EXTI_Line         			  EXTI_Line3   
#define NRF_EXTI_SourcePort   			  GPIO_PortSourceGPIOD
#define NRF_EXTI_SourcePin    			  GPIO_PinSource3
#define NRF_EXTI_IRQHandler  			    EXTI3_IRQHandler



void NRF24L01_GPIO_Conf(void);						//��ʼ��
void NRF24L01_EXTI_Conf(void);
void NRF_Conf(void);
void NRF24L01_RX_Mode(void);					//����Ϊ����ģʽ
void NRF24L01_TX_Mode(void);					//����Ϊ����ģʽ
u8 NRF24L01_Write_Buf(u8 reg, u8 *pBuf, u8 u8s);//д������
u8 NRF24L01_Read_Buf(u8 reg, u8 *pBuf, u8 u8s);	//��������		  
u8 NRF24L01_Read_Reg(u8 reg);					//���Ĵ���
u8 NRF24L01_Write_Reg(u8 reg, u8 value);		//д�Ĵ���
u8 NRF24L01_Check(void);						//���24L01�Ƿ����
u8 NRF24L01_TxPacket(u8 *txbuf);				//����һ����������
u8 NRF24L01_RxPacket(u8 *rxbuf);				//����һ����������

#endif