// Copyright (C) 2020 Marina Terry
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "Bus.h"


namespace Core
{

Bus::Bus()
{}

u8 Bus::read8(u16 addr)
{
	return 0xFF;
}

void Bus::write8(u16 addr, u8 byte)
{

}

u16 Bus::read16(u16 addr)
{
	return 0xFFFF;
}

void Bus::write16(u16 addr, u16 word)
{
	
}

void Bus::writeBytes(const std::vector<u8>& src, u16 addr)
{
	u16 counter = 0;
	for(u8 byte : src) {
		write8(addr + counter, byte);
		counter++;
	}
}

void Bus::addComponent(Memory::MemoryComponent* component)
{
	components.push_back(component);
}

} // namespace Core
