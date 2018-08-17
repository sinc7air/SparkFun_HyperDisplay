#include "bareNecessities.h"


// Constructor: at minimum pass in the size of the display 
/*
	xSize: number of pixels in the x direction of the display
	ySize: number of pixels in the y direction of the display

	*Note:
	This notation allows you to explicitly state what variables are passed to the parent class's constructor when the derived class' constructor is called.
	Additional direct or virtual base classes can also be initialized by a comma separated list with the same syntax - the 'deepest' base class is listed first.
*/
bareMinDerived::bareMinDerived(uint16_t xSize, uint16_t ySize /* Additional Parameters */) : hyperdisplay(xSize, ySize)	/* , anotherVirtualBaseClass(params), aDirectBaseClass(moreParams) */
{
	// Perform setup of the derived class with any additional parameters here.
}

	

// getoffsetColor: allows hyperdisplay to use your custom color type
/*
	base: the pointer to the first byte of the array that holds the color data
	numPixels: the number of pixels away from the beginning that the function should return the pointer to
*/
color_t 	bareMinDerived::getOffsetColor(color_t base, uint32_t numPixels)
{
	// This method is requried so that your color type can be totally flexible - be it an enumeration of three colors for an E-ink
	// display or a structure of bytes for 24-bit color it is totally up to you and how your display works.

	// This implementation will depend on how you choose to store colors, however one decent way to do it is provided as a reference:
	// This function returns an offset pointer according to the number of pixels and the _colorMode of the object
	
	// color_t pret = NULL;										
	// your_color_type * ptemp = (your_color_type *)base;	// Here's the magic. Cast the base pointer to a pointer of your color type to allow pointer arithmetic
	// pret = (color_t)(ptemp + numPixels);					// The offset by the number of pixels. This will account for the number of bytes that your color type occupies
	// return pret; 										// And return the offset pointer
}

// hwPixel: the method by which hyperdisplay actually changes your screen
/*
	x0, y0: the x and y coordinates at which to place the pixel. 0,0 is the upper-left corner of the screen, x is horizontal and y is vertical
	data: the pointer to where the color data is stored
	colorCycleLength: this indicates how many pixels worth of valid color data exist contiguously after the memory location pointed to by color.  
	startColorOffset: this indicates how many pixels to offset by from the color pointer to arrive at the actual color to display
*/
void 		bareMinDerived::hwpixel(uint16_t x0, uint16_t y0, color_t data, uint16_t colorCycleLength, uint16_t startColorOffset)
{
	// Here you write the code that sets a pixel. It is up to you what to do with that data. Here are two basic options:

	// 1) Write directly to display ram: if you choose this option and your display supports it then this is all you need to show an image
	// 2) Write to a scratch space: you might use this option to compose a whole image and then show it all on the screen at once. 
	// 		In that case you would need your own function that actually gets all that information to the display when the time is right.
}

// Additional hardware drawing functions
/*
	There are additional hardware drawing functions beyond hwpixel. They are already implemented by default using
	hwpixel so they are not required in order to start drawing. However implementing them with more efficient 
	methods for your particular hardware can reduce overhead and speed up the drawing process.  

	In these functions the coordiantes x0, x1, y0, and y1 are always with respect to the hardware screen. (0,0) is the upper-left pixel
	The variables pertaining to color sequences (data, colorCycleLength, and startColorOffset) always have the same meaning as in hwpixel
	Additional variables will be described in the function prototype in bareMinimumDerivedClass.cpp
*/
// void bareMinDerived::hwxline(uint16_t x0, uint16_t y0, uint16_t len, color_t data, uint16_t colorCycleLength = 1, uint16_t startColorOffset = 0, bool goLeft = false)	
// void bareMinDerived::hwyline(uint16_t x0, uint16_t y0, uint16_t len, color_t data, uint16_t colorCycleLength = 1, uint16_t startColorOffset = 0, bool goUp = false); 			
// void bareMinDerived::hwrectangle(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, color_t data, bool filled = false, uint16_t colorCycleLength = 1, uint16_t startColorOffset = 0, bool gradientVertical = false, bool reverseGradient = false); 	
// void bareMinDerived::hwfillFromArray(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint32_t numPixels, color_t data); 			

// Additional optional implementations by the user:
// ================================================

// getCharInfo: you can create custom fonts without changing how printing functions work
/*
	character: the byte-sized character to show on screen
	pchar: a pointer to a valid char_info_t object that needs to be filled out peroperly for the given character
*/
// void getCharInfo(uint8_t character, char_info_t * pchar);       
									

	// write: you decide what happens when someone calls bareMinDerived.print or bareMinDerived.println
/*
	val: the byte-sized character value to display
*/
// size_t write(uint8_t val);  