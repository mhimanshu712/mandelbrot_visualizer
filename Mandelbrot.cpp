#include <complex>
#include "Mandelbrot.h"

using namespace std;

namespace him {

Mandelbrot::getIterations(double x, double y){
	complex<double> z = 0;
	complex<double> c(x, y);
	
	int itr = 0;
	
	while(itr < MAX_ITERATIONS) {
		z = z*z + c;
		
		if(abs(z) > 2){
			break;
		}
		
		itr++;
	}
	
	
	return itr;
}

}