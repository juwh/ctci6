#pragma region Interview Question
/*
16.3 Intersection: Given two straight line segments (represented as a start point and an end point),
compute the point of intersection, if any. 
*/
#pragma endregion
#pragma region Hints
/*
Hints: 
#465. Think about what you're going to design for.

#472. Will all lines intercept? What determines if two lines intercept?

#497. Infinite lines will almost always intersect-unless they're parallel. Parallel lines might
still "intercept"-if they're the same lines. What does this mean for line segments?

#517. How can we find the intersection between two lines? If two line segments intercept,
then this must be at the same point as their "infinite" extensions. Is this intersection
point within both lines?

#527. Think carefully about how to handle the case of line segments that have the same slope
and y-intercept.
*/
#pragma endregion