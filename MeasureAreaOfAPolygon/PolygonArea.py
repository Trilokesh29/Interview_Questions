import numpy as np


def polygon_area(lats, lons, radius=6378137):
    """
    Computes area of spherical polygon, assuming spherical Earth.
    Returns result in ratio of the sphere's area if the radius is specified.
    Otherwise, in the units of provided radius.
    lats and lons are in degrees.
    """
    if len(lats) < 3 or len(lons) < 3:
        raise ValueError("provide at least 3 lats and longs")

    from numpy import arctan2, cos, sin, sqrt, pi, power, append, diff, deg2rad
    lats = np.deg2rad(lats)
    lons = np.deg2rad(lons)

    # Line integral based on Green's Theorem, assumes spherical Earth

    # close polygon
    if lats[0] != lats[-1]:
        lats = append(lats, lats[0])
        lons = append(lons, lons[0])

    # colatitudes relative to (0,0)
    a = sin(lats/2)**2 + cos(lats) * sin(lons/2)**2
    colat = 2*arctan2(sqrt(a), sqrt(1-a))

    # azimuths relative to (0,0)
    az = arctan2(cos(lats) * sin(lons), sin(lats)) % (2*pi)

    # Calculate diffs
    # daz = diff(az) % (2*pi)
    daz = diff(az)
    daz = (daz + pi) % (2 * pi) - pi

    deltas = diff(colat)/2
    colat = colat[0:-1]+deltas

    # Perform integral
    integrands = (1-cos(colat)) * daz

    # Integrate
    area = abs(sum(integrands))/(4*pi)

    area = min(area, 1-area)
    if radius is not None:  # return in units of radius
        return area * 4*pi*radius**2
    else:  # return in ratio of sphere total area
        return area
