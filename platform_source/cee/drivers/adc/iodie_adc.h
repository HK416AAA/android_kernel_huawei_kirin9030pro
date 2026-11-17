#ifndef __HKADC_IODIE_H__
#define __HKADC_IODIE_H__

#ifndef HKADC_OK
#define	HKADC_OK			(0)
#endif

#ifndef HKADC_ERROR
#define HKADC_ERROR		        (-1)
#endif

#ifndef BIT
#define BIT(n)                          (1ul << ((UINT32)(n)))
#endif

/* HKADC register address */
#define	HKADC_CLK_EN		    	(0x0C00)
#define	HKADC_RESET_DIS                 (0x0C10)
#define	HKADC_CHANNEL_EN	    	(0x001C)
#define	HKADC_CHANNEL_SEL	    	(0x0018)
#define	HKADC_BGR_TOP_EN	    	(0x0014)
#define	HKADC_EN		        (0x0000)
#define	HKADC_RESET	         	(0x0008)
#define	HKADC_DATA	            	(0x0060)

#define	HKADC_DATA_THRESHOLD_ADDR       (0x0068)
#define	HKADC_DATA_ABORT_INTR           (0x006C)
#endif
