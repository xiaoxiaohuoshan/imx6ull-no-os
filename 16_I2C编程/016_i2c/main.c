/***************************************************************
版本	   : V1.0
描述	   : I2C testapp
其他	   : 
***************************************************************/

#include "uart.h"
#include "i2c.h"
#include "type.h"
#include "ap3216c.h"
#include "my_printf.h"
int  main()
{
	int ret = 0;
	uint16_t ir;
	uint16_t ps;
	uint16_t als;
	int i;
 	Uart_Init()	 ;

	ret = ap3216c_init();
	if (ret)
	{
		printf("ap3216c_init fail!\n\r");
	}
	else
	{
		printf("ap3216c_init ok!\n\r");
	}

	while(1)
	{	
		for(i=0;i<50000;i++);
		/*环境光强度(ALS)、接近距离(PS)和红外线强度(IR)*/
		ap3216c_read_data(&ir,&ps,&als);
		
		printf("ir=%d ps=%d als=%d\n\r",ir,ps,als);
	}
					
	return 0;
}


