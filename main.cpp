#include <iostream>
#include <cstdint>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace std;
using namespace him;

int main()
{
	const int WIDTH = 800;
	const int HEIGHT = 600;
	
	Bitmap img(WIDTH,HEIGHT);
	
	for(int x=0;x<WIDTH;x++){
		for(int y=0;y<HEIGHT;y++){
			double xFractal = (x - WIDTH/2) * 2.0/WIDTH;
			double yFractal = (y - HEIGHT/2) * 2.0/HEIGHT;
			
			
			int itr = Mandelbrot::getIterations(xFractal,yFractal);
			
			uint8_t red = (uint8_t)(256 * (double)itr/Mandelbrot::MAX_ITERATIONS);
			
			img.setPixel(x, y, red, red, red);
		}
	}
	
	img.write("img.bmp");
	cout<<"Done!"<<endl;
	return 0;
}
