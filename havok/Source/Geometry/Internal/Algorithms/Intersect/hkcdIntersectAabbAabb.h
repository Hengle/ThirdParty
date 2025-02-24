/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2012 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */
//HK_REFLECTION_PARSER_EXCLUDE_FILE

#ifndef	HKCD_INTERSECTIONS_AABB_AABB
#define HKCD_INTERSECTIONS_AABB_AABB

#include <Common/Base/Types/Geometry/Aabb/hkAabb.h>

	/// Transformed AABBs overlap test.
	/// \return true if the aabbs overlap
HK_FORCE_INLINE	hkBool32	hkcdIntersectAabbAabb(const hkAabb& aabbA, const hkAabb& aabbB, const hkTransform& BtoA, const hkTransform& AtoB);

	/// Transformed AABBs overlap test.
	/// \return true if the aabbs overlap
HK_FORCE_INLINE	hkBool32	hkcdIntersectAabbAabb(const hkAabb& aabbA, const hkAabb& aabbB, const hkTransform& BtoA);

#include <Geometry/Internal/Algorithms/Intersect/hkcdIntersectAabbAabb.inl>

#endif // HKCD_INTERSECTIONS_AABB_AABB

/*
 * Havok SDK - NO SOURCE PC DOWNLOAD, BUILD(#20120831)
 * 
 * Confidential Information of Havok.  (C) Copyright 1999-2012
 * Telekinesys Research Limited t/a Havok. All Rights Reserved. The Havok
 * Logo, and the Havok buzzsaw logo are trademarks of Havok.  Title, ownership
 * rights, and intellectual property rights in the Havok software remain in
 * Havok and/or its suppliers.
 * 
 * Use of this software for evaluation purposes is subject to and indicates
 * acceptance of the End User licence Agreement for this product. A copy of
 * the license is included with this software and is also available at www.havok.com/tryhavok.
 * 
 */
