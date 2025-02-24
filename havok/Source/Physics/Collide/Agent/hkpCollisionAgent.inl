/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2012 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

#define HK_MISSING_CONTACT_MANAGER_ERROR_TEXT "No contact manager defined: You probably called processCollision on an Agent which is created without a valid hkpContactMgr (e.g. like hkpShapePhantom)"

inline hkpCollisionAgent::~hkpCollisionAgent() 
{
}

inline hkpCollisionAgent::hkpCollisionAgent( hkpContactMgr* contactMgr ) 
{
	m_contactMgr = contactMgr;
}

inline hkpContactMgr* hkpCollisionAgent::getContactMgr()
{
	return m_contactMgr;
}

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
