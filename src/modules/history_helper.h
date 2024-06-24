#ifndef HISTORY_HELPER_H
#define HISTORY_HELPER_H

#define CASE_HEX_0x02A_TO_0x039 \
    case 0x02a: \
    case 0x02b: \
    case 0x02d: \
    case 0x02e: \
    case 0x02f: \
    case 0x030: \
    case 0x031: \
    case 0x032: \
    case 0x033: \
    case 0x034: \
    case 0x035: \
    case 0x036: \
    case 0x037: \
    case 0x038: \
    case 0x039

#define CASE_HEX_0x041_TO_0x05A \
    case 0x041: \
    case 0x042: \
    case 0x043: \
    case 0x044: \
    case 0x045: \
    case 0x046: \
    case 0x047: \
    case 0x048: \
    case 0x049: \
    case 0x04a: \
    case 0x04b: \
    case 0x04c: \
    case 0x04d: \
    case 0x04e: \
    case 0x04f: \
    case 0x050: \
    case 0x051: \
    case 0x052: \
    case 0x053: \
    case 0x054: \
    case 0x055: \
    case 0x056: \
    case 0x057: \
    case 0x058: \
    case 0x059: \
    case 0x05a

#define CASE_HEX_0x05E \
    case 0x05e

#define CASE_HEX_0x061_TO_0x07A \
    case 0x061: \
    case 0x062: \
    case 0x063: \
    case 0x064: \
    case 0x065: \
    case 0x066: \
    case 0x067: \
    case 0x068: \
    case 0x069: \
    case 0x06a: \
    case 0x06b: \
    case 0x06c: \
    case 0x06d: \
    case 0x06e: \
    case 0x06f: \
    case 0x070: \
    case 0x071: \
    case 0x072: \
    case 0x073: \
    case 0x074: \
    case 0x075: \
    case 0x076: \
    case 0x077: \
    case 0x078: \
    case 0x079: \
    case 0x07a: \
    case 0x020

void printHistory( void );
int handleHistoryFunction( char * token );
void historyGetLastElement( void );
void clearHistory( void );
void deleteLastHiostryElement( void );
void historyGetNthElement( void );
void historyEditAndExecute( void );

#endif