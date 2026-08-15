// © 2026 : github.com/NMoroney
// MIT License 
//

#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

namespace n8m {

  using Point2D = std::array<int, 2>;
  using Points  = std::vector<Point2D>;

  template <typename T>
  auto min_and_max(const std::vector<T>& vs) {
    const auto [min_it, max_it] = std::minmax_element(vs.begin(), vs.end());
    return std::make_pair(*min_it, *max_it);
  }

  Points sunflower_sample_pixels(const int wide) {
    using T = float;

    const int size { 600 };
    const int seeds { size / 2 };

    const T pi  = std::acos(-1.0f);
    const T phi = (1.0f + std::sqrt(5.0f)) / 2.0f;

    std::vector<T> xs, ys;
    xs.reserve(seeds);
    ys.reserve(seeds);

    for (int i = 1; i <= seeds; ++i) {
      const T r = 2.0f * std::pow(static_cast<T>(i), phi) / static_cast<T>(seeds);
      const T theta = 2.0f * pi * phi * static_cast<T>(i);
      xs.push_back(r * std::sin(theta) + static_cast<T>(size) / 2.0f);
      ys.push_back(r * std::cos(theta) + static_cast<T>(size) / 2.0f);
    }

    const auto [x_min, x_max] = min_and_max(xs);
    const auto [y_min, y_max] = min_and_max(ys);
    const T x_range { x_max - x_min };
    const T y_range { y_max - y_min };

    const int high { wide };
    Points samples;
    samples.reserve(xs.size());

    for (std::size_t i = 0; i < xs.size(); ++i) {
      const int xp = static_cast<int>(((xs[i] - x_min) / x_range) * static_cast<T>(wide));
      const int yp = static_cast<int>(((ys[i] - y_min) / y_range) * static_cast<T>(high));
      samples.push_back({ xp, yp });
    }

    return samples;
  }

  void ocv_distance_transform() {
    std::cout << "ocv distance transform (C++17 version):\n";
    std::cout << "opencv version : " << CV_VERSION << "\n";

    constexpr int wide { 512 };
    constexpr int high { wide };
    const auto samples = sunflower_sample_pixels(wide);

    cv::Mat gray(high, wide, CV_8UC1, cv::Scalar(255));
    for (const auto& s : samples) {
      // Ensure coordinates are within bounds
      if (s[0] >= 0 && s[0] < wide && s[1] >= 0 && s[1] < high) {
        gray.at<uchar>(s[1], s[0]) = 0;
      }
    }

    cv::Mat distances;
    cv::distanceTransform(gray, distances, cv::DIST_L2, 3);

    cv::Mat normalized;
    cv::normalize(distances, normalized, 0, 255, cv::NORM_MINMAX, CV_8UC1);

    normalized = 255 - normalized;

    if (cv::imwrite("ocv_sunflower_distances_17.jpg", normalized)) {
      std::cout << "Saved ocv_sunflower_distances_17.jpg\n";
    } else {
      std::cerr << "Failed to save image.\n";
    }
  }

}

int main() {

  n8m::ocv_distance_transform();

  return 0;
}
