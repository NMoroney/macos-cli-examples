
## macOS : Command Line Examples - *Eigen (2D Rotation)*

[Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) is a header only templated library for linear algebra.

It can be downloaded as a .zip from [this web page](https://eigen.tuxfamily.org/index.php?title=Main_Page) on the upper right of the page. As a header only library, to use simply link against the source headers.

As an example of using Eigen, a [2D rotation](https://eigen.tuxfamily.org/dox/classEigen_1_1Rotation2D.html) is applied to input XY data. A [rose (mathematical) sinusoid](https://en.wikipedia.org/wiki/Rose_(mathematics)) is sampled and used as the test data.

This [source](eigen_rotate_2d.cc) was compiled with this [Makefile](Makefile) (update the path the Eigen installation location).

```
./eigen_rotate_2d
eigen rotate 2d :
eigen version :
  world : 3
  major : 4
  minor : 0

radians : 1.0472
      0.5 -0.866025
 0.866025       0.5
```
The result plotted as a color scatter diagram with matplolib is shown below.

The input data is shown as teal colored and the Eigen 2D rotated (and scaled) data is shown in orange.

<img src="eigen_rotate_2d-scatter_xy.png" width=500px>

---

The python version [rose_rotate_2d.py](https://github.com/NMoroney/macos-cli-examples/blob/main/examples/mc_03_eigen/rose_rotate_2d.py) generated using this prompt :

```
Read the C++ file eigen_rotate_2d.cc.
Create a version in standard python.
At the end instead of creating a TSV file generate matplotlib code to plot the data.
Keep the teal and orange color coding for the plot.
Save the resulting python to rose_rotate_2d.py and save this prompt to the file prompt-rose_rotate.txt.
Once these files are saved stop.
```

And this model usage report :

```
Interaction Summary
  Tool Calls:                 5 ( ✓ 5 x 0 )
  Success Rate:               100.0%
  User Agreement:             100.0% (5 reviewed)
  Code Changes:               +80 -0

  Performance
  Wall Time:                  59.9s
  Agent Active:               25.7s
    » API Time:               16.0s (62.2%)
    » Tool Time:              9.7s (37.8%)


  Model Usage
  Use /model to view model quota information

  Model                           Reqs  Input Tokens   Cache Reads Output Token
  ─────────────────────────────────────────────────────────────────────────────
  gemini-3.1-flash-lite              1           755             0            1
    ↳ utility_summarizer             1           755             0            1
  gemini-3-flash-preview             4        47,632        11,232         1,29
    ↳ main                           4        47,632        11,232         1,29
╰──────────────────────────────────────────────────────────────────────────────
```


