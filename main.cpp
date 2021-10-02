#include <iostream>
#include "Bitmap.h"

using namespace std;
using namespace him;

int main()
{
	Bitmap img(800,600);
	img.write("img.bmp");
	cout<<"Done!"<<endl;
	return 0;
}
