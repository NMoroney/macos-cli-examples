
# macOS CLI Examples

I had to use [recovery mode](https://support.apple.com/en-us/HT204904) to install macOS on a 5 year old MacBook Air. This included an upgrade to Sonoma (14.2.1).

Then I used the terminal to build and test a series of familiar libraries and software tools from the unix command line

This repository is a snap-shot (aka "**note-to-future-self**") on the specifics of these examples. Likewise this code might be helpful for others experimenting with these libraries and tools.

These examples are also being used to test Gemini porting (such as generating Python and C++23 versions).

---

| Example | Description | Result |
| --- | --- | --- |
| [mc_01_hello_world](examples/mc_01_hello_world) | An obligatory **ᚺƏᒹᒹ◉ ש◉ℜᒹ₫** using g++ (clang 15.0.0) and make (3.81). | <img src="examples/mc_01_hello_world/2401-hello_world.png" width=96px> |
| [mc_02_opencv](examples/mc_02_opencv) | Distance transform of a [Fibonacci fractal](https://fractalfoundation.org/OFC/OFC-11-3.html) using **OpenCV** (4.8.0) and CMake (3.28.0). | <img src="examples/mc_02_opencv/ocv_sunflower_distances.jpg" width=96px> |
| [mc_03_eigen](examples/mc_03_eigen) | Apply 2D rotation to [Rose sinusoid](https://en.wikipedia.org/wiki/Rose_(mathematics)) XY data using **Eigen** (3.4.0). | <img src="examples/mc_03_eigen/eigen_rotate_2d-scatter_xy-cropped.png" width=96px> |
| [mc_04_libigl](examples/mc_04_libigl) | Blue noise sample a mesh surface using **libigl** (2.5.0). | <img src="examples/mc_04_libigl/libigl_blue_noise_sample_surface.jpg" width=96px> |
| [mc_05_libsvm](examples/mc_05_libsvm) | Train a [support vector machine](https://en.wikipedia.org/wiki/Support_vector_machine) as an orange color classifier using **libsvm** (3.32). | <img src="examples/mc_05_libsvm/libsvm_orange_classifier-scatter_xyz_rgb-cropped_02.jpg" width=96px> |
| [mc_06_bvh_v1](examples/mc_06_bvh_v1) | Implement a single view virtual 3D scanner using [**BVH**](https://github.com/madmann91/bvh) ([v1](https://github.com/madmann91/bvh/tree/v1)) and [**happly**](https://github.com/nmwsharp/happly) (v2). | <img src="examples/mc_06_bvh_v1/bvh-virtual_3d_scanner-cropped.jpg" width=96px> |
| [mc_07_pip3](examples/mc_07_pip3) | Generate simplex noise using the **opensimplex** (0.4.5) Python package installed with **Pip3** (21.2.4). | <img src="examples/mc_07_pip3/simplex_noise_2d_200x200.jpg" width=96px>|
| [mc_08_virtualenv](examples/mc_08_virtualenv) | Draw random lobster graphs with **virtualenv** (20.25.0) and **networkx** (3.2.1). | <img src="examples/mc_08_virtualenv/random_lobster.png" width=96px> |
| [mc_09_brew](examples/mc_09_brew) | Use **brew** (4.1.24) to install **wget** (1.21.4) and download an iceberg image. | <img src="examples/mc_09_brew/underwater_surface_structures_of_an_iceberg_in_Svalbard-cropped.jpg" width=96px> |
| [mc_10_boost](examples/mc_10_boost) | Create phase of moon toned calendar using **Boost** (1.83.0) and [**MoonPhase**](https://github.com/signetica/MoonPhase). | <img src="examples/mc_10_boost/2024-boost-moon_tone-cropped.jpg" width=96px> |
| [mc_11_armadillo](examples/mc_11_armadillo) | Fit a sphere to 3D points using **Armadillo** (12.6.6) and a variant of the [**Thiel-Sen estimator**](https://en.wikipedia.org/wiki/Theil–Sen_estimator). | <img src="examples/mc_11_armadillo/armadillo-thiel-sen_fit_sphere_to_points_3d-cropped.jpg" width=96px> |
| [mc_12_ceres](examples/mc_12_ceres) | Fit a non-linear model to measured display luminances using the **Ceres Solver** (2.2.0_1). | <img src="examples/mc_12_ceres/ceres-display_fit-cropped-02.png" width=96px> |
| [mc 13 ffmpeg](examples/mc_13_ffmpeg) | Create boomerang gifs using **FFmpeg** (6.0). | <img src="examples/mc_13_ffmpeg/rotating_earth_boomerang.gif" width=96px> |
| [mc 14 mlpack](examples/mc_14_mlpack) | The **mlpack** (4.3.0) library is used to autoencode the spectra of a Munsell Book of Color.  | <img src="examples/mc_14_mlpack/mlpack-spectral_autoencoder-munsell_matte.jpg" width=96px> |
| [mc 15 ensmallen](examples/mc_15_ensmallen) | Align two 2D contours using **ensmallen's** (2.21.0) particle swarm optimization. | <img src="examples/mc_15_ensmallen/initial_contours-xy_rgb.png" width=96px>  |
| [mc 16 cgal](examples/mc_16_cgal) | Compute 3D convex hull of mesh vertices using **CGAL** (5.6). | <img src="examples/mc_16_cgal/cgal-convex_hull.jpg" width=96px> |
| [mc 17 ranger](examples/mc_17_ranger) | Train another orange classifer using [**Ranger**'s](https://github.com/imbs-hl/ranger) (0.16.0) [random forests](https://en.wikipedia.org/wiki/Random_forest). | <img src="examples/mc_17_ranger/ranger-random_forest-orange_classifier-02.gif" width=96px> |
| [mc 18 tesseract](examples/mc_18_tesseract) | Apply optical character recognition to an input image using **Tesseract** (5.3.3). | <img src="examples/mc_18_tesseract/camera_image_quality_benchmarking-page_9-cropped.jpg" width=96px> |
| [mc 19 pytorch midas](examples/mc_19_pytorch_midas) | Derive depth estimates for an input image using the pre-trained **MiDaS** (DPT large)  **PyTorch** (1.11.0) model. | <img src="examples/mc_19_pytorch_midas/Knight_Triceratops_depth-cropped.jpg" width=96px> |
| [mc 20 matplotlib](examples/mc_20_matplotlib) | Contour plot simplex noise using **matplotlib** (3.8.2) and automatically create a PNG from input TSV. | <img src="examples/mc_20_matplotlib/contour-simplex_noise-copper-cropped.jpg" width=96px> |
| [mc 21 stable diffusion cpp](examples/mc_21_stable_diffusion_cpp) | Use [**stable-diffusion.cpp**](https://github.com/leejet/stable-diffusion.cpp) with version 1.4 of the weights and integrate with depth estimation and FFmpge. | <img src="examples/mc_21_stable_diffusion_cpp/stable_diffusion_then_depth_estimation_02.gif" width=96px> |
| [mc 22 pcl](examples/mc_22_pcl) | Filter outliers in a point cloud with the  **Point Cloud Library** (1.13.1). | <img src="examples/mc_22_pcl/pcl-filter_outliers.jpg" width=96px> |
| [mc 23 pcl_viewer](examples/mc_23_pcl_viewer) | A **PCL** (1.13.1) viewer is used to visualize a color point cloud (and generate a depth gif). | <img src="examples/mc_23_pcl_viewer/pcl-color_cloud-02.jpg" width=96px> |
| [mc 24 vcglib](examples/mc_24_vcglib) | Generate a 3D torus using **VCGLib** (2023.12) and save the result as a PLY file. | <img src="examples/mc_24_vcglib/vcglib_torus.jpg" width=96px> |
| [mc 25 vtk](examples/mc_25_vtk) | **VTK** (9.2.6_5) render the [Z-Anatomy model](https://github.com/LluisV/Z-Anatomy) of the [cardiovascular system](https://github.com/LluisV/Z-Anatomy/tree/PC-Version/Resources/Models/FBX). | <img src="examples/mc_25_vtk/vtk_render_ply.jpg" width=96px> |
| [mc 26 qt6](examples/mc_26_qt6)  | Create an interactive RGB color picker using **Qt** (6.6.0_1). | <img src="examples/mc_26_qt6/qt6-rgb_color_picker-256.jpg" width=96px> |




