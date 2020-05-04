#pragma once

namespace Injector {
	void Init(void);

	namespace Inject {
		bool Checks(PCSTR dll_name, char* dll_path, PCSTR procName);
		bool Llib(void);
		bool Allocate(void* allocatedMemory, char* dll_path);
		bool Release(PCSTR dll_name, void* allocatedMemory);
	}
}