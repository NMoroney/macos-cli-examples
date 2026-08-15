# © 2026 : github.com/NMoroney
# MIT License 
#

import cv2
import numpy as np
import math

def sunflower_sample_pixels(wide):
    size = 600
    seeds = size // 2
    phi = (1.0 + math.sqrt(5.0)) / 2.0
    pi = math.pi

    xs = []
    ys = []
    for i in range(1, seeds + 1):
        r = 2 * math.pow(i, phi) / seeds
        theta = 2 * pi * phi * i
        xs.append(r * math.sin(theta) + size / 2)
        ys.append(r * math.cos(theta) + size / 2)

    x_min, x_max = min(xs), max(xs)
    y_min, y_max = min(ys), max(ys)
    x_range = x_max - x_min
    y_range = y_max - y_min

    high = wide
    samples = []
    for i in range(len(xs)):
        xp = int(((xs[i] - x_min) / x_range) * wide)
        yp = int(((ys[i] - y_min) / y_range) * high)
        # Ensure points are within bounds for a 512x512 image
        xp = min(xp, wide - 1)
        yp = min(yp, high - 1)
        samples.append((xp, yp))

    return samples

def ocv_distance_transform():
    print("ocv distance transform :")
    print(f"opencv version : {cv2.__version__}")

    wide = 512
    high = wide
    samples = sunflower_sample_pixels(wide)

    # Initialize a white image (255)
    gray = np.full((high, wide), 255, dtype=np.uint8)

    # Set sunflower points to black (0)
    for x, y in samples:
        gray[y, x] = 0

    # Compute distance transform
    distances = cv2.distanceTransform(gray, cv2.DIST_L2, 3)

    # Normalize to [0, 255]
    normalized = cv2.normalize(distances, None, 0, 255, cv2.NORM_MINMAX, cv2.CV_8UC1)

    # Invert the normalized image
    normalized = 255 - normalized

    # Save the result
    cv2.imwrite("ocv_sunflower_distances.jpg", normalized)

if __name__ == "__main__":
    ocv_distance_transform()

