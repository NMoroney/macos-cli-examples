#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>

#include <algorithm>
#include <array>
#include <cmath>
#include <filesystem>
#include <format>
#include <iostream>
#include <numbers>
#include <print>
#include <ranges>
#include <vector>

namespace n8m {

using Point2D = std::array<int, 2>;
using Points = std::vector<Point2D>;

template <typename T>
auto min_and_max(const std::vector<T>& vs) {
    auto [min_it, max_it] = std::ranges::minmax_element(vs);
    return std::make_pair(*min_it, *max_it);
}

Points sunflower_sample_pixels(int wide) {
    using T = float;

    constexpr int size = 600;
    constexpr int seeds = size / 2;

    constexpr T pi = std::numbers::pi_v<T>;
    const T phi = (1.0f + std::sqrt(5.0f)) / 2.0f;

    std::vector<T> xs, ys;
    xs.reserve(seeds);
    ys.reserve(seeds);

    for (int i : std::views::iota(1, seeds + 1)) {
        T r = 2.0f * std::pow(static_cast<T>(i), phi) / static_cast<T>(seeds);
        T theta = 2.0f * pi * phi * static_cast<T>(i);
        xs.push_back(r * std::sin(theta) + static_cast<T>(size) / 2.0f);
        ys.push_back(r * std::cos(theta) + static_cast<T>(size) / 2.0f);
    }

    auto [x_min, x_max] = min_and_max(xs);
    auto [y_min, y_max] = min_and_max(ys);
    T x_range = x_max - x_min;
    T y_range = y_max - y_min;

    int high = wide;
    Points samples;
    samples.reserve(xs.size());

    for (auto [x, y] : std::views::zip(xs, ys)) {
        int xp = static_cast<int>(((x - x_min) / x_range) * wide);
        int yp = static_cast<int>(((y - y_min) / y_range) * high);
        samples.push_back(Point2D{xp, yp});
    }

    return samples;
}

void ocv_distance_transform() {
    std::println("ocv distance transform :");
    std::println("opencv version : {}", CV_VERSION);

    int wide = 512;
    int high = wide;
    auto samples = sunflower_sample_pixels(wide);

    cv::Mat gray(high, wide, CV_8UC1, cv::Scalar(255));
    for (const auto& s : samples) {
        // Basic bounds checking for safety, though sunflower points should be within range
        if (s[0] >= 0 && s[0] < wide && s[1] >= 0 && s[1] < high) {
            gray.at<uchar>(s[1], s[0]) = 0;
        }
    }

    cv::Mat distances;
    // cv::distanceTransform(gray, distances, ::cv::DIST_L2, 3);
    // cv::distanceTransform(gray, distances, CV_DIST_L2, 3);
    // cv::distanceTransform(gray, distances, cv::DistanceTypes::DIST_L2, 3);
    // cv::distanceTransform(gray, distances, cv::DIST_L2, 3);
    cv::distanceTransform(gray, distances, 2, 3);

    cv::Mat normalized;
    cv::normalize(distances, normalized, 0, 255, cv::NORM_MINMAX, CV_8UC1);

    normalized = 255 - normalized;

    const std::string filename = "ocv_sunflower_distances.jpg";
    if (cv::imwrite(filename, normalized)) {
        std::println("Result saved to {}", filename);
    } else {
        std::println(std::cerr, "Error: Could not save image to {}", filename);
    }
}

} // namespace n8m

int main() {
    try {
        n8m::ocv_distance_transform();
    } catch (const std::exception& e) {
        std::println(std::cerr, "Unhandled exception: {}", e.what());
        return 1;
    }
    return 0;
}
