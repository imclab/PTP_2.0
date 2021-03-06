#ifndef __PTPOBJHANDLEPARSER_H__
#define __PTPOBJHANDLEPARSER_H__

#include <inttypes.h>
#include <avr/pgmspace.h>
#include <printhex.h>
#include <message.h>
#include <hexdump.h>
#include <parsetools.h>
#include "ptpcallback.h"
#include "ptpdebug.h"

class PTPObjHandleParser : public PTPReadParser
{
	MultiValueBuffer					theBuffer;
	uint32_t						varBuffer;
	uint8_t							nStage;
	PTPListParser						arrayParser;

	static void PrintHandle(MultiValueBuffer *p, uint32_t count) 
	{ 
		Serial.print(count, DEC); 
		Notify(PSTR("\t")); 
		PrintHex<uint32_t>(*((uint32_t*)p->pValue));
                //Serial.print(*((uint32_t*)p->pValue), HEX);
		Notify(PSTR("\r\n")); 
	};

public:
	PTPObjHandleParser() : nStage(0) { theBuffer.valueSize = 4; theBuffer.pValue = &varBuffer; arrayParser.Initialize(4, 4, &theBuffer); };
	virtual void Parse(const uint16_t len, const uint8_t *pbuf, const uint32_t &offset);
};


#endif // __PTPOBJHANDLEPARSER_H__
