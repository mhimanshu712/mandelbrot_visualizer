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
	const int WIDTH = 800;
	const int HEIGHT = 600;
	
	Bitmap img(WIDTH,HEIGHT);
	
	ZoomList zoomList(WIDTH,HEIGHT);
	zoomList.add(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));
	//zoomList.add(Zoom(295, HEIGHT-202, 0.1));
	//zoomList.add(Zoom(312,HEIGHT-304,0.1));
	
	unique_ptr<int[]> histo(new int[Mandelbrot::MAX_ITERATIONS +1]{0});
	
	for(int x=0;x<WIDTH;x++){
		for(int y=0;y<HEIGHT;y++){
			pair<double,double> coords = zoomList.doZoom(x, y);
			//cout<<coords.first<<"  "<<coords.second<<endl;
			
			int itr = Mandelbrot::getIterations(coords.first,coords.second);
			histo[itr]++;
			
			uint8_t color = (uint8_t)(256 * (double)itr/Mandelbrot::MAX_ITERATIONS);
			
			img.setPixel(x, y, color, color, color);
		}
	}
	
	img.write("img.bmp");
	
	cout<<"Done!"<<endl;
	return 0;
}
