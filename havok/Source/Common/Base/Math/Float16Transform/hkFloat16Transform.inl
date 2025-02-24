/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2012 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */

//
//	Sets this transform from a hkTransform

template<hkMathRoundingMode R>
HK_FORCE_INLINE void hkFloat16Transform::_set(const hkTransform& transformIn)
{
	// Prepare column vectors
	hkVector4 vTranslation = transformIn.getTranslation();
	hkVector4 vCol0;	vCol0.setXYZ_W(transformIn.getColumn<0>(), vTranslation.getComponent<0>());
	hkVector4 vCol1;	vCol1.setXYZ_W(transformIn.getColumn<1>(), vTranslation.getComponent<1>());
	hkVector4 vCol2;	vCol2.setXYZ_W(transformIn.getColumn<2>(), vTranslation.getComponent<2>());

	// Set them in the half transform
	vCol0.store<4, HK_IO_NATIVE_ALIGNED, R>(getColumn<0>());
	vCol1.store<4, HK_IO_NATIVE_ALIGNED, R>(getColumn<1>());
	vCol2.store<4, HK_IO_NATIVE_ALIGNED, R>(getColumn<2>());
}

//
//	Sets this transform from a hkTransform.

template <hkMathRoundingMode R>
void hkFloat16Transform::set(const hkTransform& transformIn)
{
	_set<R>(transformIn);
}

//
//	Converts this to a hkTransform

HK_FORCE_INLINE void hkFloat16Transform::_getTransform(hkTransform& transformOut) const
{
	// Get columns
	hkVector4 vCol0;	vCol0.load<4, HK_IO_NATIVE_ALIGNED>(getColumn<0>());
	hkVector4 vCol1;	vCol1.load<4, HK_IO_NATIVE_ALIGNED>(getColumn<1>());
	hkVector4 vCol2;	vCol2.load<4, HK_IO_NATIVE_ALIGNED>(getColumn<2>());

	// Build translation
	const hkSimdReal tx		= vCol0.getComponent<3>();
	const hkSimdReal ty		= vCol1.getComponent<3>();
	const hkSimdReal tz		= vCol2.getComponent<3>();
	transformOut.getTranslation().set(tx, ty, tz, hkSimdReal_0);

	// Build rotation
	vCol0.zeroComponent<3>();	transformOut.setColumn<0>(vCol0);
	vCol1.zeroComponent<3>();	transformOut.setColumn<1>(vCol1);
	vCol2.zeroComponent<3>();	transformOut.setColumn<2>(vCol2);
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
