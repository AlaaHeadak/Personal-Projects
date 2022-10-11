#ifndef _LCD_INTERFACE_H_
#define _LCD_INTERFACE_H_




void LCD_VidInt(void);

void LCD_VidWriteCommand(u8 Command);

void LCD_VidWriteData(u8 Data);

void LCD_VidSetPosition(u8 Row, u8 Col);

void LCD_Clear();

void LCD_VidWriteString(u8 *StringOfCharacters);\

void LCD_VidWriteNum(u16 num);

#endif
