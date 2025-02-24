/*
 *
 * Confidential Information of Telekinesys Research Limited (t/a Havok). Not for disclosure or distribution without Havok's
 * prior written consent. This software contains code, techniques and know-how which is confidential and proprietary to Havok.
 * Product and Trade Secret source code contains trade secrets of Havok. Havok Software (C) Copyright 1999-2012 Telekinesys Research Limited t/a Havok. All Rights Reserved. Use of this software is subject to the terms of an end user license agreement.
 *
 */
#ifndef HKBASE_hkFreeListSystem_H
#define HKBASE_hkFreeListSystem_H

#include <Common/Base/Memory/System/hkMemorySystem.h>
#include <Common/Base/Memory/Allocator/Thread/hkThreadMemory.h>
#include <Common/Base/Memory/Allocator/Malloc/hkMallocAllocator.h>
#include <Common/Base/Memory/Allocator/FreeList/hkFreeListAllocator.h>
#include <Common/Base/Memory/Allocator/Solver/hkSolverAllocator.h>
#include <Common/Base/Memory/Allocator/Checking/hkLeakDetectAllocator.h>
#include <Common/Base/Memory/Allocator/Lifo/hkLifoAllocator.h>
#include <Common/Base/Memory/Allocator/Stats/hkStatsAllocator.h>


	///  A memory system which wraps the free list.
	///  It also wraps the heap memory with hkThreadMemory to speed up thread local memory allocs/frees
class hkFreeListMemorySystem : public hkMemorySystem
{
	//+hk.MemoryTracker(ignore=True)
	public:
			/// Constructor flags
		enum SetupFlags
		{
				/// Use the LIFO allocator for temp allocations, otherwise temp and heap are shared.
			USE_LIFO_ALLOCATOR_FOR_TEMP = 1,
				/// Use the solver buffer to supply the LIFO temp allocator. Not enabled by default
				/// since it may interfere with memory limiting.
			USE_SOLVER_ALLOCATOR_FOR_LIFO_SLABS = 2,

				/// Thread memory is being used
			USE_THREAD_MEMORY = 4,

			DEFAULT_SETUP_FLAGS = USE_LIFO_ALLOCATOR_FOR_TEMP | USE_THREAD_MEMORY
		};

		enum { THREAD_MAX=64 };

			/// Some information for each thread.
		struct ThreadData
		{
			HK_DECLARE_NONVIRTUAL_CLASS_ALLOCATOR(HK_MEMORY_CLASS_BASE,ThreadData);
			ThreadData() : m_name(HK_NULL), m_inUse(false) {}
			hkThreadMemory m_heapThreadMemory; ///< A thread local wrapper around heap memory to speed allocs/free up
			hkMemoryRouter* m_memoryRouter; ///< The thread local memory router
			const char* m_name; ///< The name of the thread
			hkBool m_inUse; ///< Set to true if this ThreadData is used by a thread
		};
			

			/// The heapAllocator provides the underlying heap allocator implementation. The heapExtended parameter should be the implementation of
			/// the ExtendedInterface on the heapAllocator. If the heapAllocator does not implement the interface, passing in HK_NULL will work -
			/// but not all of the extended features (such as garbage collection) will be accessible from the hkMemorySystem.
		hkFreeListMemorySystem(hkMemoryAllocator* systemAllocator, hkMemoryAllocator* heapAllocator, hkMemoryAllocator::ExtendedInterface* heapExtended, SetupFlags flags = DEFAULT_SETUP_FLAGS);
			/// Dtor
		~hkFreeListMemorySystem();

		virtual hkMemoryRouter* mainInit(const FrameInfo& info, Flags f=FLAG_ALL);
		virtual hkResult mainQuit(Flags f=FLAG_ALL);
		virtual void threadInit(hkMemoryRouter& r, const char* name, Flags f=FLAG_ALL);
		virtual void threadQuit(hkMemoryRouter& r, Flags f=FLAG_ALL);

			/// This function is used to receive callbacks for any heap allocation performed.
			/// It is used for instance by the memory snapshot system.
			/// Included in this list is memory which has been given to some thread
			/// local memory manager. The system and the allocator have no knowledge on
			/// how this memory is actually used (it might just be cached inside the
			/// hkThreadMemory without being used).
			/// For this reason it is recommended to collect all garbage from all threads
			/// before using walkMemory (e.g. to take a snapshot). Depending on the status
			/// of the game, this might require some synchronization on thread execution.
		virtual hkResult walkMemory(MemoryWalkCallback callback, void* param);
		virtual void garbageCollectThread(hkMemoryRouter&);
		virtual void garbageCollectShared();

		hkMemoryAllocator* getAllocator() { return m_systemAllocator; }

		virtual void printStatistics(hkOstream& ostr);
		virtual void getHeapStatistics(hkMemoryAllocator::MemoryStatistics& stats);

		virtual hkResult setHeapSoftLimit(int nbytes);
		virtual int getHeapSoftLimit() const;
		virtual bool solverCanAllocSingleBlock( int numBytes );
		virtual bool heapCanAllocTotal( int numBytes );
		virtual hkMemoryAllocator* getUncachedLockedHeapAllocator();

		virtual void setHeapScrubValues(hkUint32 allocValue, hkUint32 freeValue);

	protected:

			//
			//	Some buffers, they should not be used directly
			//

			/// Next 2 members are hierarchy to "System" memory
			// The order is important for the destructor
		hkMemoryAllocator* m_systemAllocator;
		
		FrameInfo m_frameInfo;

			//
			//	Normal Member variables
			//

			/// The heap allocator which should be used.
		hkMemoryAllocator* m_heapAllocator;

		hkMemoryAllocator::ExtendedInterface* m_heapExtended;

			/// Passthrough allocator so we can distinguish debug mem stats.
		hkStatsAllocator m_debugAllocator;

			/// The main threads router
		hkMemoryRouter m_mainRouter;

			/// The solver memory, shared between all threads
		hkSolverAllocator m_solverAllocator;

			///	Thread local memory stuff
		ThreadData m_threadData[THREAD_MAX];

			/// Lock for thread local data
		hkCriticalSection m_threadDataLock;

		int m_flags;
};

#endif // HKBASE_hkFreeListSystem_H

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
