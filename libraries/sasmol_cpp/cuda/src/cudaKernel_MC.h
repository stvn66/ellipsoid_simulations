//
// Hailiang Zhang
// NIST & UTK
//

#ifndef H_CUDA_KERNEL_MC
#define H_CUDA_KERNEL_MC

// macros
#include "cudaCommon.h"

#include <math.h>
#include <stdio.h>
#include <cuda.h>
#include <cuda_runtime.h>
#include <curand_kernel.h>

__global__ void setupCurandKernel(curandState * const state, const int seed, const int n);

__global__ void cudaSetupGrid(const TYPE * const gpu_coor, const TYPE * const gpu_radii, int * const gpu_grid, const int Natoms,
                              const TYPE x0, const TYPE y0, const TYPE z0, const TYPE delta, const int Nx, const int Ny, const int Nz);

__global__ void cudaMC(const TYPE * const gpu_coor, const TYPE * const gpu_radii, const int * const gpu_grid, TYPE * const gpu_points,
                       const int Natoms, const int Npoints, int * const gpu_Npoints_tried,
                       const TYPE x0, const TYPE y0, const TYPE z0, const TYPE delta, const int Nx, const int Ny, const int Nz,
                       curandState * const state);


#endif
