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
#include "Cpu.h"

#include "memory/RAM.h"
#include "../debug/Log.h"


namespace Core
{

Cpu::Cpu()
:	ram(new Memory::RAM())
{}

bool Cpu::reset()
{
	regs.P.B = true;
	regs.P.I = true;
	regs.A = regs.X = regs.Y = 0x00;
	regs.SP = 0xFD;
	regs.PC = bus->read16(0xFFFC);

	Debug::LogRegisters(regs);
	Debug::LogMemory(0x8000, 300, bus);

	return true;
}

void Cpu::step(int cycles)
{
	//doInstruction();
}

u8 Cpu::fetch8()
{
	return bus->read8(regs.PC++);
}

u16 Cpu::fetch16()
{
	u16 retval = bus->read16(regs.PC);
	regs.PC += 2;
	return retval;
}

void Cpu::setBus(std::shared_ptr<Bus>& _bus)
{
	this->bus = _bus;
}

Memory::RAM* Cpu::getRAM()
{
	return ram;
}

} // namespace Core
