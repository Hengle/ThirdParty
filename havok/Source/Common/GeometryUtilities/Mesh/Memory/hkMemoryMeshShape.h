/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2012 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

#ifndef HK_MEMORY_MESH_SHAPE_H
#define HK_MEMORY_MESH_SHAPE_H

#include <Common/GeometryUtilities/Mesh/hkMeshShape.h>

extern const hkClass hkMemoryMeshShapeClass;

	/// A memory based implementation of a hkMeshShape
class hkMemoryMeshShape: public hkMeshShape
{
    public:
		HK_DECLARE_REFLECTION();

		HK_DECLARE_CLASS_ALLOCATOR(HK_MEMORY_CLASS_SCENE_DATA);

            /// Ctor
        hkMemoryMeshShape(const hkMeshSectionCinfo* sections, int numSections);

			/// Serialization Ctor
		hkMemoryMeshShape( hkFinishLoadedObjectFlag flag );

            /// Dtor
        virtual ~hkMemoryMeshShape();

            // hkMeshShape implementation
        virtual int getNumSections() const;

            // hkMeshShape implementation
        virtual void lockSection(int sectionIndex, hkUint8 accessFlags, hkMeshSection& sectionOut) const;

            // hkMeshShape implementation
        virtual void unlockSection(const hkMeshSection& section) const;

            // hkReferencedObject Implementation
        virtual const hkClass* getClassType() const { return &hkMemoryMeshShapeClass; }

		virtual const char* getName() const { return m_name; }
		virtual void setName(const char* n) { m_name = n; }

    protected:

        hkArray<struct hkMeshSectionCinfo> m_sections;

        hkArray<hkUint16> m_indices16;
        hkArray<hkUint32> m_indices32;

		hkStringPtr m_name;
};



#endif // HK_MEMORY_MESH_SHAPE_H

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