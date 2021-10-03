#include <iostream>
#include <cstdint>
#include <memory>
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "ZoomList.h"

using namespace std;
using namespace him;

int main()
{
	const int WIDTH = 1200;
	const int HEIGHT = 800;
	
	Bitmap img(WIDTH,HEIGHT);
	
	ZoomList zoomList(WIDTH,HEIGHT);
	zoomList.add(Zoom(WIDTH/2,HEIGHT/2,1));
	
	unique_ptr<int[]> histo(new int[Mandelbrot::MAX_ITERATIONS +1]{0});
	for(int x=0;x<WIDTH;x++){
		for(int y=0;y<HEIGHT;y++){
			double xFractal = (x - WIDTH/2-200) * 2.3/HEIGHT;
			double yFractal = (y - HEIGHT/2) * 2.3/HEIGHT;
			
			
			int itr = Mandelbrot::getIterations(xFractal,yFractal);
			histo[itr]++;
			
			uint8_t color = (uint8_t)(256 * (double)itr/Mandelbrot::MAX_ITERATIONS);
			
			img.setPixel(x, y, color, color, color);
		}
	}
	
	img.write("img.bmp");
	
	cout<<"Done!"<<endl;
	return 0;
}
