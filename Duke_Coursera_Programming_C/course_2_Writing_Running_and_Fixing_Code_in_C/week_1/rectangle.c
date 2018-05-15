// a rectangle with left, bottom, top, and right
struct rect_t
{
    float left;
    float bottom;
    float top;
    float right;
};
typedef struct rect_t rect;

float max(float f1, float f2)
{
    // see if f1 is bigger than f2
    if (f1 > f2)
    {
        return f1;
    }
    else
    {
        return f2;
    }
}

float min(float f1, float f2)
{
    // see if f1 is bigger than f2
    if (f1 < f2)
    {
        return f1;
    }
    else
    {
        return f2;
    }
}

// Translate the algorithm from step 1-4 to code.
// to find the intersection of two rectangles, r1 and r2:
rect intersection(rect r1, rect r2)
{
    // make a rectangle (called ans) with
    rect ans;
    // left: maximum of r1's left and r2's left
    ans.left = max(r1.left, r2.left);
    // bottom: maximum of r1's bottom and r2's bottom
    ans.bottom = max(r1.bottom, r2.bottom);
    // top: minimum of r1's top and r2's top
    ans.top = min(r1.top, r2.top);
    // right: minimum of r1's right and r2's right
    ans.right = min(r1.right, r2.right);
    // the rectangle called ans is your answer
    return ans;
}

