/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2012 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

#ifndef HKBASE_STRING_PTR_LAYOUT_HANDLER_H
#define HKBASE_STRING_PTR_LAYOUT_HANDLER_H

#include <Common/Base/Memory/Tracker/LayoutCalculator/hkTrackerLayoutCalculator.h>

class hkTrackerStringPtrLayoutHandler: public hkTrackerLayoutHandler
{
	public: 
		//+hk.MemoryTracker(ignore=True)
		HK_DECLARE_CLASS_ALLOCATOR(HK_MEMORY_CLASS_BASE);
		// implements hkTrackerLayoutHandler
		virtual hkTrackerTypeLayout* calcTypeLayout(const Node* type, hkTrackerLayoutCalculator* calc);			
		virtual void calcReferencedTypes(const hkTrackerTypeLayout* layout, hkTrackerLayoutCalculator* calc, const hkTrackerSnapshot* snapshot, void* data, hkArray<ReferenceInfo>& infosOut);
		virtual hkResult calcTypeInfo(const Node* type, hkTrackerLayoutCalculator* calc, hkTrackerLayoutTypeInfo& typeInfo);
};

#endif // HKBASE_STRING_PTR_LAYOUT_HANDLER_H

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
