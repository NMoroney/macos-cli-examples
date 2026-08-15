#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

#include <array>
#include <fstream>
#include <iostream>
#include <vector>


namespace n8m {

  using Point2D = std::array<int, 2>;
  using Points  = std::vector<Point2D>;


  template <typename T>
  auto min_and_max(const std::vector<T> vs) {
    struct result { T min, max; };
    return result {
      *std::min_element(vs.begin(), vs.end()),
      *std::max_element(vs.begin(), vs.end())
    };
  }

  Points sunflower_sample_pixels(const int wide) {
    using T = float;

    int size { 600 }, seeds { size / 2 };;

    T pi { (T)acos(-1.0) }, phi { (T)((1.0 + sqrt(5.0)) / 2.0) };

    std::vector<T> xs, ys; 
    for (int i = 1; i <= seeds; ++i) {
      T r = 2 * pow(i, phi)/seeds;
      T theta = 2 * pi * phi * i;
      xs.push_back((T)(r * sin(theta) + size/2));
      ys.push_back((T)(r * cos(theta) + size/2));
    }

    auto [x_min, x_max] = min_and_max<T>(xs);
    auto [y_min, y_max] = min_and_max<T>(ys);
    T x_range { x_max - x_min }, y_range { y_max - y_min };

    int high { wide };
    Points samples;
    for (int i = 0; i < xs.size(); ++i) {
      int xp { (int)(((xs[i] - x_min) / x_range) * wide) },
          yp { (int)(((ys[i] - y_min) / y_range) * high) };
      samples.push_back(Point2D { xp, yp } );
    }

    return samples;
  }

  void ocv_distance_transform() {
    using std::cout;
    cout << "ocv distance transform :\n";

    cout << "opencv version : " << CV_VERSION << "\n";

    int wide { 512 }, high { wide };
    auto samples = sunflower_sample_pixels(wide);

    cv::Mat gray(high, wide, CV_8UC1, cv::Scalar(255));
    for (auto s : samples) {
      gray.at<char>(s[1], s[0]) = 0;
    }

    cv::Mat distances(gray.rows, gray.cols, CV_32F);
    cv::distanceTransform(gray, distances, cv::DIST_L2, 3);

    cv::Mat normalized;
    cv::normalize(distances, normalized, 0, 255, cv::NORM_MINMAX, CV_8UC1);

    normalized = 255 - normalized;

    cv::imwrite("ocv_sunflower_distances.jpg", normalized);
  }

}


int main() {

  n8m::ocv_distance_transform();      // sunflower sample pixels and then
                                      // compute inverted distance transform

  return 0;

}
