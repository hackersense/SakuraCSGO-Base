#pragma once

#include "SDK\Offsets.h"

class MemoryRW
{
public:
	MemoryRW(HANDLE processHandle) {
		this->handle = processHandle;
	}

	template <class T>
	T read(DWORD_PTR address) {
		T buffer;
		ReadProcessMemory(handle, reinterpret_cast<LPVOID>(address), &buffer, sizeof(buffer), nullptr);
		return buffer;
	}

	template <typename T>
	bool write(DWORD_PTR address, T dataBuffer) {
		return WriteProcessMemory(handle, reinterpret_cast<LPVOID>(address), &dataBuffer, sizeof(dataBuffer), nullptr) == TRUE;
	}
private:
	HANDLE handle;
};