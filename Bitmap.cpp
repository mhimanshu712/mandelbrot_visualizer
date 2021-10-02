#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

using namespace him;

namespace him {
	
Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pPixel(new uint8_t[width*height*3]{}) {
		
}

bool Bitmap::write(string filename) {
	return false;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue){
}
	
Bitmap::~Bitmap() {
		
}

}