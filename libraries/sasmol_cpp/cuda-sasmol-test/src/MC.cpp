//
// Hailiang Zhang
// NIST & UTK
//

#include "MC.h"

//////////////////////////////////////////////////////////
/// constructor
//////////////////////////////////////////////////////////
sascalc::MC::
MC(const int Npoints, const int seed):
_Npoints(Npoints), _seed(seed)
{
    CALL_CUDA(cudaMallocHost((void**)&_points, 3*_Npoints*sizeof(float)));
}

//////////////////////////////////////////////////////////
/// destruction
//////////////////////////////////////////////////////////
sascalc::MC::
~MC()
{
    CALL_CUDA(cudaFreeHost(_points));
}
