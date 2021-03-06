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
#pragma once
#include <string>


enum AddressingMode {
	Acc, Abs, AbsX, AbsY, Imm, Impl,
	Ind, IndX, IndY, Rel, Zpg, ZpgX, ZpgY
};

struct Instruction {
	std::string mnemonic;
	AddressingMode mode;
	int bytes;
	int cycles;
};

static Instruction instrs[256] = {
	/////////// 0x00 ///////////
	{"BRK impl", AddressingMode::Impl, 1, 1},
	{"ORA (X,ind)", AddressingMode::IndX, 2, 4},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"ORA zpg", AddressingMode::Zpg, 2, 0},
	{"ASL zpg", AddressingMode::Zpg, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"PHP impl", AddressingMode::Impl, 1, 0},
	{"ORA #", AddressingMode::Imm, 2, 0},
	{"ASL A", AddressingMode::Acc, 1, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"ORA abs", AddressingMode::Abs, 3, 0},
	{"ASL abs", AddressingMode::Abs, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	/////////// 0x10 ///////////
	{"BPL rel", AddressingMode::Rel, 2, 1},
	{"ORA (ind,Y)", AddressingMode::IndY, 2, 4},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"ORA zpg", AddressingMode::Zpg, 2, 0},
	{"ASL zpg", AddressingMode::Zpg, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"CLC impl", AddressingMode::Impl, 1, 0},
	{"ORA (abs,Y)", AddressingMode::AbsY, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"ORA (abs,X)", AddressingMode::AbsX, 3, 0},
	{"ASL (abs,X)", AddressingMode::AbsX, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	/////////// 0x20 ///////////
	{"JSR abs", AddressingMode::Abs, 3, 1},
	{"AND (X,ind)", AddressingMode::IndX, 2, 4},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"BIT zpg", AddressingMode::Zpg, 2, 0},
	{"AND zpg", AddressingMode::Zpg, 2, 0},
	{"ROL zpg", AddressingMode::Zpg, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"PLP impl", AddressingMode::Impl, 1, 0},
	{"AND #", AddressingMode::Imm, 2, 0},
	{"ROL A", AddressingMode::Acc, 1, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"BIT abs", AddressingMode::Abs, 3, 0},
	{"AND abs", AddressingMode::Abs, 3, 0},
	{"ROL abs", AddressingMode::Abs, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	/////////// 0x30 ///////////
	{"BMI rel", AddressingMode::Rel, 2, 1},
	{"AND (ind,Y)", AddressingMode::IndY, 2, 4},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"AND (zpg,X)", AddressingMode::ZpgX, 2, 0},
	{"ROL (zpg,X)", AddressingMode::ZpgX, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"SEC impl", AddressingMode::Impl, 1, 0},
	{"AND (abs,Y)", AddressingMode::AbsY, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"AND (abs,X)", AddressingMode::AbsX, 3, 0},
	{"ROL (abs,X)", AddressingMode::AbsX, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	/////////// 0x40 ///////////
	{"RTI impl", AddressingMode::Impl, 1, 1},
	{"EOR (X,ind)", AddressingMode::IndX, 2, 4},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"EOR zpg", AddressingMode::Zpg, 2, 0},
	{"LSR zpg", AddressingMode::Zpg, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"PHA impl", AddressingMode::Impl, 1, 0},
	{"EOR #", AddressingMode::Imm, 2, 0},
	{"LSR A", AddressingMode::Acc, 1, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"JMP abs", AddressingMode::Abs, 3, 0},
	{"EOR abs", AddressingMode::Abs, 3, 0},
	{"LSR abs", AddressingMode::Abs, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	/////////// 0x50 ///////////
	{"BVC rel", AddressingMode::Rel, 2, 1},
	{"EOR (ind,Y)", AddressingMode::IndY, 2, 4},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"EOR (zpg,X)", AddressingMode::ZpgX, 2, 0},
	{"LSR (zpg,X)", AddressingMode::ZpgX, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"CLI impl", AddressingMode::Impl, 1, 0},
	{"EOR (abs,Y)", AddressingMode::AbsY, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"EOR (abs,X)", AddressingMode::AbsX, 3, 0},
	{"LSR (abs,X)", AddressingMode::AbsX, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	/////////// 0x60 ///////////
	{"RTS impl", AddressingMode::Impl, 1, 1},
	{"ADC (X,ind)", AddressingMode::IndX, 2, 4},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"ADC zpg", AddressingMode::Zpg, 2, 0},
	{"ROR zpg", AddressingMode::Zpg, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"PLA impl", AddressingMode::Impl, 1, 0},
	{"ADC #", AddressingMode::Imm, 2, 0},
	{"ROR A", AddressingMode::Acc, 1, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"JMP ind", AddressingMode::Ind, 3, 0},
	{"ADC abs", AddressingMode::Abs, 3, 0},
	{"ROR abs", AddressingMode::Abs, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	/////////// 0x70 ///////////
	{"BVS rel", AddressingMode::Rel, 2, 1},
	{"ADC (ind,Y)", AddressingMode::IndY, 2, 4},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"ADC (zpg,X)", AddressingMode::ZpgX, 2, 0},
	{"ROR (zpg,X)", AddressingMode::ZpgX, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"SEI impl", AddressingMode::Impl, 1, 0},
	{"ADC (abs,Y)", AddressingMode::AbsY, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"ADC (abs,X)", AddressingMode::AbsX, 3, 0},
	{"ROR (abs,X)", AddressingMode::AbsX, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	/////////// 0x80 ///////////
	{"NULL", AddressingMode::Impl, 0, 0},
	{"STA (X,ind)", AddressingMode::IndX, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"STY zpg", AddressingMode::Zpg, 2, 0},
	{"STA zpg", AddressingMode::Zpg, 2, 0},
	{"STX zpg", AddressingMode::Zpg, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"DEY impl", AddressingMode::Impl, 1, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"TXA impl", AddressingMode::Impl, 1, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"STY abs", AddressingMode::Abs, 3, 0},
	{"STA abs", AddressingMode::Abs, 3, 0},
	{"STX abs", AddressingMode::Abs, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	/////////// 0x90 ///////////
	{"BCC rel", AddressingMode::Rel, 2, 0},
	{"STA (ind,Y)", AddressingMode::IndY, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"STY (zpg,X)", AddressingMode::ZpgX, 2, 0},
	{"STA (zpg,X)", AddressingMode::ZpgX, 2, 0},
	{"STX (zpg,Y)", AddressingMode::ZpgY, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"TYA impl", AddressingMode::Impl, 1, 0},
	{"STA (abs,Y)", AddressingMode::AbsY, 3, 0},
	{"TXS impl", AddressingMode::Impl, 1, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"STA (abs,X)", AddressingMode::AbsX, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	/////////// 0xA0 ///////////
	{"LDY #", AddressingMode::Imm, 2, 0},
	{"LDA (X,ind)", AddressingMode::IndX, 2, 0},
	{"LDX #", AddressingMode::Imm, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"LDY zpg", AddressingMode::Zpg, 2, 0},
	{"LDA zpg", AddressingMode::Zpg, 2, 0},
	{"LDX zpg", AddressingMode::Zpg, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"TAY impl", AddressingMode::Impl, 1, 0},
	{"LDA #", AddressingMode::Imm, 2, 0},
	{"TAX impl", AddressingMode::Impl, 1, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"LDY abs", AddressingMode::Abs, 3, 0},
	{"LDA abs", AddressingMode::Abs, 3, 0},
	{"LDX abs", AddressingMode::Abs, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	/////////// 0xB0 ///////////
	{"BCS rel", AddressingMode::Rel, 2, 0},
	{"LDA (ind,Y)", AddressingMode::IndY, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"LDY (zpg,X)", AddressingMode::ZpgX, 2, 0},
	{"LDA (zpg,X)", AddressingMode::ZpgX, 2, 0},
	{"LDX (zpg,Y)", AddressingMode::ZpgY, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"CLV impl", AddressingMode::Impl, 1, 0},
	{"LDA (abs,Y)", AddressingMode::AbsY, 3, 0},
	{"TSX impl", AddressingMode::Impl, 1, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"LDY (abs,X)", AddressingMode::AbsX, 3, 0},
	{"LDA (abs,X)", AddressingMode::AbsX, 3, 0},
	{"LDX (abs,Y)", AddressingMode::AbsY, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	/////////// 0xC0 ///////////
	{"CPY #", AddressingMode::Imm, 2, 0},
	{"CMP (X,ind)", AddressingMode::IndX, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"CPY zpg", AddressingMode::Zpg, 2, 0},
	{"CMP zpg", AddressingMode::Zpg, 2, 0},
	{"DEC zpg", AddressingMode::Zpg, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"INY impl", AddressingMode::Impl, 1, 0},
	{"CMP #", AddressingMode::Imm, 2, 0},
	{"DEX impl", AddressingMode::Impl, 1, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"CPY abs", AddressingMode::Abs, 3, 0},
	{"CMP abs", AddressingMode::Abs, 3, 0},
	{"DEC abs", AddressingMode::Abs, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	/////////// 0xD0 ///////////
	{"BNE rel", AddressingMode::Rel, 2, 0},
	{"CMP (ind,Y)", AddressingMode::IndY, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"CMP (zpg,X)", AddressingMode::ZpgX, 2, 0},
	{"DEC (zpg,X)", AddressingMode::ZpgX, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"CLD impl", AddressingMode::Impl, 1, 0},
	{"CMP (abs,Y)", AddressingMode::AbsY, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"CMP (abs,X)", AddressingMode::AbsX, 3, 0},
	{"DEC (abs,X)", AddressingMode::AbsX, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	/////////// 0xE0 ///////////
	{"CPX #", AddressingMode::Imm, 2, 0},
	{"SBC (X,ind)", AddressingMode::IndX, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"CPX zpg", AddressingMode::Zpg, 2, 0},
	{"SBC zpg", AddressingMode::Zpg, 2, 0},
	{"INC zpg", AddressingMode::Zpg, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"INX impl", AddressingMode::Impl, 1, 0},
	{"SBC #", AddressingMode::Imm, 2, 0},
	{"NOP impl", AddressingMode::Impl, 1, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"CPX abs", AddressingMode::Abs, 3, 0},
	{"SBC abs", AddressingMode::Abs, 3, 0},
	{"INC abs", AddressingMode::Abs, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	/////////// 0xF0 ///////////
	{"BEQ rel", AddressingMode::Rel, 2, 0},
	{"SBC (ind,Y)", AddressingMode::IndY, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"SBC (zpg,X)", AddressingMode::ZpgX, 2, 0},
	{"INC (zpg,X)", AddressingMode::ZpgX, 2, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"SED impl", AddressingMode::Impl, 1, 0},
	{"SBC (abs,Y)", AddressingMode::AbsY, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"NULL", AddressingMode::Impl, 0, 0},
	{"SBC (abs,X)", AddressingMode::AbsX, 3, 0},
	{"INC (abs,X)", AddressingMode::AbsX, 3, 0},
	{"NULL", AddressingMode::Impl, 0, 0}
};
