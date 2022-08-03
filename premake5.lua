workspace "GraphicAlgorithm"
   configurations { "Debug", "Release" }
   platforms {"x64"}   
   
include "Frame"   
include "BRDF_Sampler"   
include "DepthToPositionAndNormal"   
include "FitLTCMatrix"   
include "SH_Sampler"   
include "01_Reflective_Shadow_Map"   
include "02_Non-interleaved Deferred Shading of Interleaved Sample"
include "03_Stochastic Light Culling"
include "04_Metalights Improved Interleaved Shading"
include "05__Interactive Order Independent Transparency"
include "06_Wang Tiles for Image and Texture Generation"
include "07_Tile Shading"
include "08_A Non-Photorealistic Lighting Model"
include "09_Spherical Harmonic Lighting The Gritty Details"
include "10_RealTimePolygonalLightShadingWithLinearlyTransformedCosine"
include "11_An Efficient Representation for Irradiance Environment Maps"
include "12_Real Time Concurrent Linked List Construction on the GPU"
include "13_Fourier Opacity Optimization for Scalable Exploration"
include "14_Approximating Dynamic Global Illumination in Image Space"
include "15_Image Space Horizon Based Ambient Occlusion"
include "16_(Incomplete)_Cascaded Light Propagation Volumes for Real-Time Indirect Illumination"
include "17_Forward Light Cuts A Scalable Approach to RealTime Global Illumination"
include "18_(Incomplete)Cascaded Shadow Maps"
include "19_A Survey of Efficient Representations  for Independent Unit Vectors"
include "20_Real-time Approximation to Large Convolution Kernel"
include "21_Real-time indirect illumination by virtual planar area lights"
include "22_Variance Shadow Maps" 
include "23_Efficient GPU Screen-Space Ray Tracing"
include "24_(Incomplete)Real-Time Global Illumination using Precomputed Light Field Probes"
include "25_Exponential Shadow Maps"
