#pragma once

namespace Injector {
	void Init(void);

	namespace Inject {
		bool Checks(char* dll_name, PCSTR procName);
		bool Llib(void);
		bool Allocate(void* allocatedMemory, char* dll_path);
		bool Release(PCSTR dll_name, void* allocatedMemory);
	}
}