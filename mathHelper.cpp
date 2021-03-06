#include "mathHelper.h"

int nearestPerfectSquare(int n)
{
    int squareJumpAmount = 3;
    int curSquare = 1;
    int prevSquare = 0;
    while(curSquare < n)
    {
        prevSquare = curSquare;
        curSquare += squareJumpAmount;
        squareJumpAmount += 2;  // the difference between consecutive squares is odd integer
    }
    if(n - prevSquare > curSquare - n)
    {
        return curSquare;
    }
    else
    {
        return prevSquare;
    }
}

int isqrt(int n)
{
    return round(sqrt(n));
}

Point2D chunkIDtoPoint2D(int n)
{
    int s = nearestPerfectSquare(n);
    int sq = isqrt(s);
    if(s % 2 == 0)
    {
        if(n >= s)
        {
            return {sq/2, -sq/2 + n - s};
        }
        else
        {
            return {sq/2 - s + n, -sq/2};
        }
    }
    else
    {
        if(n >= s)
        {
            return {-(sq + 1)/2, (sq + 1)/2 - 1 - n + s};
        }
        else
        {
            return {-(sq + 1)/2 + s - n, (sq + 1)/2 - 1};
        }
    }
}

int point2DtoChunkID(Point2D p)
{
    int a = p.x;
    int b = p.z;
    // Bottom Zone
    if(b > 0 && a >= -b && a < b)
    {
        return 4*b*b + 3*b - a;
    }
    // Left Zone
    else if(a < 0 && b < -a && b >= a)
    {
        return 4*a*a + 3*a - b;
    }
    // Top Zone
    else if(b < 0 && a <= -b && a > b)
    {
        return 4*b*b + b + a;
    }
    // Right Zone
    else if(a > 0 && b <= a && b > -a)
    {
        return 4*a*a + a + b;
    }
    // Only a=0, b=0 is not in a zone
    else
    {
        return 0;
    }
}

double distance2d(Point p1, Point p2)
{
    return distanceFormula(p1.x, p1.z, p2.x, p2.z);
}

double distanceFormula(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

std::vector<int> getChunkIDsAroundPoint(Point2D p, int radius)
{
    std::vector<int> result;

    // Start at the bottom of the diamond and work up from there
    for(int b = p.z + radius; b >= p.z - radius; b--)
    {
        int distanceFromZ = abs(b - p.z);
        for(int a = p.x - (radius - distanceFromZ); a <= p.x + (radius - distanceFromZ); a++)
        {
            result.push_back(point2DtoChunkID({a,b}));
        }
    }
    return result;
}

std::vector<Point2D> getChunkTopLeftCornersAroundPoint(Point2D p, int radius)
{
    std::vector<Point2D> result;

    // Start at the bottom of the diamond and work up from there
    for(int b = p.z + radius; b >= p.z - radius; b--)
    {
        int distanceFromZ = abs(b - p.z);
        for(int a = p.x - (radius - distanceFromZ); a <= p.x + (radius - distanceFromZ); a++)
        {
            result.push_back({a,b});
        }
    }
    return result;
}

std::vector<int> getChunkIDsAroundPoint(int chunkID, int radius)
{
    return getChunkIDsAroundPoint(chunkIDtoPoint2D(chunkID), radius);
}
std::vector<Point2D> getChunkTopLeftCornersAroundPoint(int chunkID, int radius)
{
    return getChunkTopLeftCornersAroundPoint(chunkIDtoPoint2D(chunkID), radius);
}

int getChunkIDContainingPoint(Point p, int chunkSize)
{
    int x = floor(p.x / chunkSize);
    int z = floor(p.z / chunkSize);
    return point2DtoChunkID({x, z});
}