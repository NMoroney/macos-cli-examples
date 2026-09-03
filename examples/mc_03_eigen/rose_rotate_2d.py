# [2609] n8
#
import math
import matplotlib.pyplot as plt


# https://commons.wikimedia.org/wiki/File:Rose-rhodonea-curve-7x9-chart-improved.svg
#
def generate_rose_sinusoid(n, d, a, max_radians, steps):
    k = n / d
    radians_step = max_radians / steps
    theta = 0
    samples = []
    for _ in range(steps):
        r = a * math.cos(k * theta)
        x = r * math.cos(theta)
        y = r * math.sin(theta)
        samples.append((x, y))
        theta += radians_step
    return samples

def to_rotated_2d(xys, radians):
    cos_r = math.cos(radians)
    sin_r = math.sin(radians)
    
    # Rotation matrix in 2D:
    # [[cos, -sin],
    #  [sin,  cos]]
    # rx = x * cos - y * sin
    # ry = x * sin + y * cos
    
    rotated = []
    for x, y in xys:
        rx = (x * cos_r) - (y * sin_r)
        ry = (x * sin_r) + (y * cos_r)
        rotated.append((rx, ry))
    return rotated

def rose_rotate_2d():
    n, d, a = 3.0, 1.0, 10.0
    pi = math.pi
    max_radians = 2 * pi
    steps = 1000

    samples = generate_rose_sinusoid(n, d, a, max_radians, steps)

    degrees = 60.0
    radians = math.radians(degrees)
    rotated = to_rotated_2d(samples, radians)

    scale = 0.5
    rotated_scaled = [(r[0] * scale, r[1] * scale) for r in rotated]

    # Colors
    teal = (52/255, 179/255, 168/255)
    orange = (248/255, 125/255, 31/255)

    # Plotting
    plt.figure(figsize=(8, 8))
    
    # Original samples
    xs, ys = zip(*samples)
    plt.plot(xs, ys, color=teal, linewidth=7.0, label='Original')
    
    # Rotated and scaled samples
    rxs, rys = zip(*rotated_scaled)
    plt.plot(rxs, rys, color=orange, linewidth=7.0, label='Rotated & Scaled')

    plt.axis('equal')
    plt.legend()
    plt.title('Rose Sinusoid: Original and Rotated/Scaled')
    plt.grid(True, linestyle='--', alpha=0.6)
    
    print("Saving plot to rose_rotate_2d.png")
    plt.savefig("rose_rotate_2d.png")
    plt.show()

if __name__ == "__main__":
    rose_rotate_2d()
