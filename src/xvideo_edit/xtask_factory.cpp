#include "xtask_factory.h"
#include "fftask.h"

using namespace std;
std::unique_ptr<XTask> XTaskFactory::Create(int type)
{
	switch (type)
	{
	case 0:
		return make_unique<FFTask>();
	default:
		cerr << "XTask type :" << type << " not support!" << endl;
		break;
	}
	return nullptr;
}
