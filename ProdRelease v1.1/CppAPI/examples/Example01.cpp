#include <iostream>
#include <cstdio>
#include <cstring>
#include <cerrno>
#include "Smeshalist.h"
#include "Geometry.h"

using namespace std;

int N = 10;
double frand(){
	return ((double)((double)rand()/(double)RAND_MAX));
}
Point3D genPoint() {
	return Point3D(frand()*3.0, frand()*3.0,frand()*3.0);
}
int main() {

	GOOGLE_PROTOBUF_VERIFY_VERSION;
	cout << "checked protobuf version\n";
	Smeshalist tool = Smeshalist::GetInstance();
cout << "After getting instance\n";
	//srand(time(NULL));

	cout << "Before loop\n";
	for (int i = 0; i < N; i++){
		Face face = Face(genPoint(),genPoint(), genPoint());
		face.SetGroupId(4);
		tool.AddGeometry(face);
	}
	cout << "Before flushing\n";
    tool.FlushBuffer();
    tool.Render();
    tool.Breakpoint();

	for (int i = 0; i < N; i++){
		Block block= Block(genPoint(),genPoint(), genPoint(), genPoint());
		block.SetGroupId(5);
		tool.AddGeometry(block);
	}

    tool.FlushBuffer();
    tool.Render();


	google::protobuf::ShutdownProtobufLibrary();
	return 0;
}
