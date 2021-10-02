#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace him {
	
class Mandelbrot {
public:
	static const int MAX_ITERATIONS = 30;
	
public:
	Mandelbrot();
	
	static int getIterations(double x, double y);
	
};

}

#endif