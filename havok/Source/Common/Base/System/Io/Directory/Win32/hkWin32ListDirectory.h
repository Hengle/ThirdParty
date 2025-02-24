/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2012 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */
#ifndef HK_BASE_WIN32LISTDIRECTORY_H
#define HK_BASE_WIN32LISTDIRECTORY_H

#include <Common/Base/System/Io/FileSystem/hkFileSystem.h>

// Browse the file system for files and subdirectories in the directory specified by pathIn
extern hkResult HK_CALL hkWin32ListDirectory( const char* pathIn, hkFileSystem::DirectoryListing& directoryListingOut );
// Get the absolute path of a relative file.
extern const char* HK_CALL hkWin32GetFullPathName( const char* relativePathIn, hkStringBuf& buffer );

#define hkNativeFileSystem_ListDirectory hkWin32ListDirectory
#define hkNativeFileSystem_GetFullPathName hkWin32GetFullPathName

#endif //HK_BASE_WIN32LISTDIRECTORY_H

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
