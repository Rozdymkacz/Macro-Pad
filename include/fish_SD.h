const int fish_SD_HEIGHT = 128;
const int fish_SD_WIDTH = 64;
// 'rozdymka_SD', 128x64px
const unsigned char epd_bitmap_rozdymka_SD [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x3f, 0xe0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf0, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x00, 0x1c, 0x00, 0x00, 0x07, 0xc0, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0x80, 0x3c, 0x00, 0x00, 0x07, 0xc0, 0x00, 0x3c, 0xff, 0xc0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xe0, 0x3e, 0x00, 0x00, 0x07, 0x80, 0x00, 0x3c, 0x1f, 0xe0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xf0, 0x76, 0x00, 0x00, 0x07, 0x80, 0x00, 0x3c, 0x07, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x01, 0xbf, 0xff, 0x00, 0x00, 0x07, 0x80, 0x00, 0x3c, 0x03, 0xf8, 0x00, 0x00, 
	0x00, 0x00, 0x0f, 0x03, 0xff, 0xff, 0xe0, 0x00, 0x07, 0xc0, 0x00, 0x3c, 0x01, 0xf8, 0x00, 0x00, 
	0x00, 0x00, 0x1f, 0xc3, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xe0, 0x00, 0x3c, 0x01, 0xfc, 0x00, 0x00, 
	0x06, 0x00, 0x3f, 0xff, 0xe0, 0x00, 0xff, 0x00, 0x07, 0xe0, 0x00, 0x3c, 0x00, 0xfc, 0x00, 0x00, 
	0x0f, 0x80, 0x38, 0xff, 0x00, 0x00, 0x1f, 0x80, 0x07, 0xfc, 0x00, 0x3c, 0x00, 0x7e, 0x00, 0x00, 
	0x1f, 0xe0, 0x38, 0xfc, 0x1e, 0x00, 0x03, 0xe0, 0x03, 0xff, 0xc0, 0x3c, 0x00, 0x3e, 0x00, 0x00, 
	0x1d, 0xf8, 0x3b, 0xf0, 0x1f, 0x00, 0x01, 0xf0, 0x01, 0xff, 0xf0, 0x3c, 0x00, 0x3f, 0x00, 0x00, 
	0x1c, 0x7f, 0xff, 0xc0, 0x0c, 0x00, 0x18, 0x78, 0x00, 0xff, 0xf8, 0x3c, 0x00, 0x3f, 0x00, 0x00, 
	0x38, 0x3f, 0xff, 0x00, 0x0c, 0x00, 0x18, 0x78, 0x00, 0x1f, 0xfc, 0x3c, 0x00, 0x1f, 0x00, 0x00, 
	0x38, 0x7f, 0xfc, 0x00, 0x04, 0x00, 0x00, 0x78, 0x00, 0x03, 0xfe, 0x3c, 0x00, 0x1f, 0x00, 0x00, 
	0x38, 0x70, 0x00, 0x00, 0x01, 0xff, 0x80, 0xf0, 0x00, 0x00, 0xff, 0x3c, 0x00, 0x0f, 0x00, 0x00, 
	0x38, 0x70, 0x00, 0x00, 0x01, 0xff, 0x01, 0xe0, 0x00, 0x00, 0x3f, 0xbc, 0x00, 0x0f, 0x80, 0x00, 
	0x38, 0x78, 0x00, 0x00, 0x01, 0x80, 0x03, 0xf8, 0x00, 0x00, 0x1f, 0xbc, 0x00, 0x0f, 0x80, 0x00, 
	0x38, 0x3f, 0xfe, 0x00, 0x01, 0x80, 0x03, 0xfc, 0x00, 0x00, 0x0f, 0xbc, 0x00, 0x0f, 0x80, 0x00, 
	0x18, 0x7f, 0xff, 0x00, 0x00, 0xc1, 0x81, 0xfc, 0x00, 0x00, 0x0f, 0xbc, 0x00, 0x07, 0x80, 0x00, 
	0x1c, 0xfc, 0x7f, 0x80, 0x00, 0xe3, 0x80, 0x38, 0x00, 0x00, 0x07, 0xbc, 0x00, 0x07, 0x80, 0x00, 
	0x1f, 0xf0, 0x3b, 0xc0, 0x18, 0x73, 0x00, 0x38, 0x00, 0x00, 0x07, 0xbc, 0x00, 0x07, 0x80, 0x00, 
	0x0f, 0xc0, 0x31, 0xe0, 0x18, 0x3e, 0x00, 0x78, 0x00, 0x00, 0x07, 0xbc, 0x00, 0x07, 0x80, 0x00, 
	0x0f, 0x00, 0x39, 0xe0, 0x38, 0x1e, 0x00, 0x70, 0x00, 0x00, 0x0f, 0xbc, 0x00, 0x07, 0x80, 0x00, 
	0x00, 0x00, 0x3f, 0xf0, 0x3e, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x0f, 0xbc, 0x00, 0x07, 0x80, 0x00, 
	0x00, 0x00, 0x1f, 0xf8, 0x3e, 0x00, 0x01, 0xe0, 0x00, 0x00, 0x3f, 0xbc, 0x00, 0x07, 0x80, 0x00, 
	0x00, 0x00, 0x07, 0x3c, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x7f, 0x3c, 0x00, 0x07, 0x80, 0x00, 
	0x00, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x01, 0xff, 0x3c, 0x00, 0x0f, 0x80, 0x00, 
	0x00, 0x00, 0x00, 0x1b, 0x80, 0x00, 0x0f, 0x60, 0x00, 0x03, 0xfe, 0x3c, 0x00, 0x0f, 0x80, 0x00, 
	0x00, 0x00, 0x00, 0x11, 0xe0, 0x00, 0x3f, 0xb0, 0x00, 0x0f, 0xfc, 0x3c, 0x00, 0x0f, 0x80, 0x00, 
	0x00, 0x00, 0x00, 0x3b, 0xfc, 0x03, 0xfc, 0xf0, 0x00, 0xff, 0xf8, 0x3c, 0x00, 0x1f, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x2f, 0x7f, 0xff, 0xf0, 0x20, 0x07, 0xff, 0xe0, 0x3c, 0x00, 0x1f, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x38, 0x1f, 0xff, 0x10, 0x00, 0x07, 0xff, 0xc0, 0x3c, 0x00, 0x1f, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x19, 0xfb, 0x10, 0x00, 0x07, 0xff, 0x00, 0x3c, 0x00, 0x3f, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x09, 0x81, 0xb0, 0x00, 0x07, 0xe0, 0x00, 0x3c, 0x00, 0x3e, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x0b, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x3e, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x7e, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0x7c, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0xfc, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x00, 0xfc, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x01, 0xf8, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x07, 0xf8, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xf0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xe0, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xe0, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};